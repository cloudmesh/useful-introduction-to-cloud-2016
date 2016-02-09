Parallel Shell
======================================================================

Traditionally system administrators and developers using parallel
computing need tools to manage a significant number of machines. One
of the requirements is to execute a command in parallel on many
machines and gather its output. There are many tools that can achieve
this task. We focus here on the introduction of the following tools:

#. pdsh - a parallel distributed shell
#. fabric - python framework to execute commands on remote computers
#. Cloudmesh Sequential and Parallel python functions for 
   executing repeatedly commands with caching


Parallel Distributed Shell (pdsh)
----------------------------------------------------------------------

The parallel distributed shell (pdsh) is a shell command line program
that allows the execution of commands not just on one computer but on
a list of computers.

An online version of the manual pages is located at 

* http://linux.die.net/man/1/pdsh

An important feature is that the list of hosts can be specified in a
convenient form that is also kwon as hostlists. This format allows you
to define a list of hosts based on some abbreviation. For example the
string::

  host[0-3]

will create a host list containing the hosts::

  host0, host1, host2, host3

Furthermore, substitutions for the user and the hostname to login to
the remote machine while leveraging ssh config files make this tool
real easy to use. One such example::

  pdsh -R exec -w host[0-3] ssh -x -l %u %h hostname 

executes the command hostname on all specified machines.



.. todo:: Hyungro, check with allan and Koji if we have pdsh on
	  india. At this time we are not aware that pdsh is installed by
          default on india. check with the systems group and have them
          provide a documentation on how we activate it.


Fabric
----------------------------------------------------------------------

Fabric is a Python command-line tool and library for assisting system
administration tasks related to the execution of command via ssh. It
includes the ability to execute commands on the local machine, but
also on a remote machine. Due to the integration with Python function
definitions, it has also somewhat the ability to write "target" like
specifications that we may know from makefiles. However it is more
sophisticated as we can use the full feature richness of python.

The web page of Fabric which includes several examples and tutorials
is located at:

* http://www.fabfile.org

Similar to the previous command we like to start the command hostname
on a number of machines. To install fabric you simply say::

   pip install fabric 

in your virtualenv. Next, we define a file called fabfile.py with the
following contents::

  from fabric.api import run

  def hostname():
      run('hostname')

Next let us run this command on the local computer and test it out::


  fab -H localhost hostname

This will execute the function defined with the name hostname and
print it via the run command. To execute the command on multiple
hosts, you can simply specify them as part of the -H argument::

  fab -H host0,host1,host2,host3 hostname


Cloudmesh Parallel API
----------------------------------------------------------------------

The previous commands are all developed with a single user in mind,
i.e. a single user executes the command. However in the age of
cloud computing what would happen if thousands of users were to execute
the same task, or even when ten users execute the same task, but the
task would take considerable compute time to calculate? The answer is
obvious, we would waste valuable compute resources as we do not take
into consideration that the same task may be run by multiple
people. To overcome this challenge we have started a simple
demonstration program in our cloudmesh repository to partially address
this issue.

To do so we are at this time we are only focussing on the consecutive
execution of a command in a particular time period. Instead of
executing the command over and over, we will simply return the result
from a result cache. The cache has a specific time to life in which no
new results are created but the result is read from the cache. New
requests are cached.

We recognize that the example we provide is not a complete solution to
our problem, but a step in the right direction. I also has the
advantage of being relatively simple and introducing you to a number
of tools and concepts that will become important when dealing with
parallelism in the cloud.

Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. A computer with python 2.7
#. Using a python virtualenv
#. Having downloaded the cloudmesh code with git clone as discussed 
   elsewhere
#. Having installed the cloudmesh code and libraries as discussed 
   elsewhere

Code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The code is located in the directory::

    cloudmesh_examples/example_mongo

within the cloudmesh code you have cloned from github. The code
contains two python functions called Sequential and Parallel, that
allow users to run commands either sequentially or in parallel on a
number of hosts. The hosts can be specified in a yaml file located
in::

  ~/.cloudmesh/cloudmesh_hpc.yaml

An example would be::

  meta:
    yaml_version: 3.0
    kind: hpc
  cloudmesh:
      hpc:
	  alamo:
	      cm_host: alamo.futuregrid.org
	      cm_type: hpc
	      username: albert
	  india:
	      cm_host: india.futuregrid.org
	      cm_type: hpc
	      username: albert
	  sierra:
	      cm_host: sierra.futuregrid.org
	      cm_type: hpc
	      username: albert
	  bigred:
	      cm_host: bigred2.uits.iu.edu
	      cm_type: hpc
	      username: albert

This file is used to specify the username for each host and define the
host names. In case you want to run commands on the hosts you can do
this with the following python program. 


The first command executes the task sequentially over the array given
in the first parameter. The second one executes it in
parallel. Instead of just presenting you with a bare bones program we
present you with some additional features that are worth noting and
may come in handy in future. This includes the availability of a named
stopwatch and the ability to read configuration parameters easily from
a yaml file. Sometimes it is also nice to have very visible debug
messages that we create with a banner function. Results are often more
readable when using the python pprint function instead of just the
print function. This is especially true when we print data-structures
such as arrays and dicts. Next we will present the program and explain
a selected number of features by commenting them in the code. We
assume you know by now elementary python.

.. code-block:: python

   from cloudmesh_task.tasks import cm_ssh
   from cloudmesh_task.parallel import Parallel, Sequential
   from cloudmesh.util.stopwatch import StopWatch
   from cloudmesh_common.util import banner
   from pprint import pprint
   from cloudmesh.config.cm_config import cm_config
   from cloudmesh.config.ConfigDict import ConfigDict
   import sys

   
   # read the information from the yaml file into a dict called config
   config = ConfigDict(filename="~/.cloudmesh/cloudmesh_hpc.yaml")["cloudmesh"]["hpc"]

   # a function to extract from the config file the username from all
   # hostnames in the array hosts
   def  get_credentials(hosts):
       credential = {}
       for host in hosts:
	   credential[host] = config[host]['username']
       return credential

   # find all hostnames from the config file 
   hosts = config.keys()

   # find all credentials (username, hostname) from the hosts in the
   #  config file
   credentials = get_credentials(hosts)


   # create a stop watch
   watch = StopWatch()

   # execute is a python function. It is either Parallel or Sequential
   # * modify 
   #    for execute in [Sequential]:
   #    for execute in [Parallel]:
 
   for execute in [Sequential, Parallel]:

       # get the name of the function
       name = execute.__name__

       # print the name of the function and start the timer
       banner(name)
       watch.start(name)

       # execute the function and return the result in a dict
       result = execute(credentials, cm_ssh, command="qstat")

       # stop the timer and print the result dict
       watch.stop(name)
       pprint(result)

       # only print the output from the command we executed
       banner("PRINT")        
       for host in result:
	   print result[host]["output"]

   # print the timers
   for timer in watch.keys():
       print timer, watch.get(timer), "s"


Bug: Before you start the command, you have to start a new window and
say fab fab manage.mongo in the cloudmesh directory where your
fabfiles are located. This will give something like::

  $ fab manage.mongo
  [localhost] local: make -f cloudmesh/management/Makefile mongo
  mongod --noauth --dbpath . --port 27777
  all output going to: /usr/local/var/log/mongodb/mongo.log


To run the command you will need to start the caching backend
services. to do so we created a simple program cm-task.py that will be
used to start and stop the services::


   ./cm-tasks.py menu

   Queue Management
   ================

       1 - all start
       2 - all stop
       3 - rabbit start
       4 - celery start
       5 - rabbit stop
       6 - celery stop
       7 - mongo start
       q - quit

   Select between 1 - 7: 

Now select the number::

    1 - all start

This will bring up the necessary services and look similar to::

    -------------- celery@host.local v3.1.13 (Cipater)
   ---- **** ----- 
   --- * ***  * -- Darwin-13.3.0-x86_64-i386-64bit
   -- * - **** --- 
   - ** ---------- [config]
   - ** ---------- .> app:         cloudmesh_task:0x10365bcd0
   - ** ---------- .> transport:   amqp://guest:**@localhost:5672//
   - ** ---------- .> results:     amqp
   - *** --- * --- .> concurrency: 10 (prefork)
   -- ******* ---- 
   --- ***** ----- [queues]
    -------------- .> celery           exchange=celery(direct) key=celery


   [tasks]
     . cloudmesh_task.tasks.cm_ssh

   [2014-08-19 15:46:24,060: INFO/MainProcess] Connected to amqp://guest:**@localhost:5672//
   [2014-08-19 15:46:24,071: INFO/MainProcess] mingle: searching for neighbors
   [2014-08-19 15:46:25,098: INFO/MainProcess] mingle: sync with 10 nodes
   [2014-08-19 15:46:25,099: INFO/MainProcess] mingle: sync complete
   [2014-08-19 15:46:25,109: WARNING/MainProcess] celery@host.local ready.
   [2014-08-19 15:46:28,352: INFO/MainProcess] Events of group {task} enabled by remote.

After this you can start the program repeatedly with::

  $ python prg.py

We are committing some of the output but at the end ist should look
something like::


   # ######################################################################
   # PRINT
   # ######################################################################
   Tue Aug 19 15:48:29 EDT 2014
   Job id                    Name             User            Time Use S Queue
   ------------------------- ---------------- --------------- -------- - -----
   1589570.i136               sub18248.sub     aaaa                   0 Q delta          
   1589589.i136               sub15366.sub     aaaa                   0 Q delta          
   1589669.i136               sub12428.sub     aaaa                   0 Q delta          
   1795838.i136               twisterJob       bbbbbb                 0 Q batch          
   1872981.i136               sub9593.sub      aaaa                   0 Q delta          
   1904453.i136               sub2114.sub      aaaa                   0 Q delta          
   1904930.i136               dimer_in_sol_ph7 cccccccc        883:55:5 R batch          
   1904931.i136               dimer_in_sol_ph5 cccccccc        902:18:4 R batch          
   1904957.i136               suffix           dddddddd        360:36:1 R echo           
   1904961.i136               dimer_in_sol_ph7 cccccccc               0 H batch          
   1904963.i136               dimer_in_sol_ph5 cccccccc               0 H batch          
   1904993.i136               blast            eeee            15:08:00 R bravo          
   1904995.i136               blast            eeee            14:33:19 R bravo          
   1905016.i136               papi-inca        aaaa                   0 Q bravo          
   1905021.i136               vampir-inca      aaaa                   0 Q bravo          
   1905044.i136               papi-inca        aaaa                   0 Q bravo          
   1905057.i136               STDIN            ffffffff        00:10:17 R delta          
   1905062.i136               ...Script.i21500 gggggg          00:00:11 R batch          

   Sequential 12.12866169 s 
   Parallel    0.00446796417236 s

Please note that we have replaced the real usernames.

When you execute this command you will notice That the parallel
execution time is much faster. In this case it was within the TTL and
thus read the cache value from the cache. Executing the command again
within the TTL will give you also for the sequential time a real short
value::

   Sequential 0.00726103782654 s
   Parallel   0.000990867614746 s

It is not surprising the parallel result is even faster than the
sequential one as the information gathering even from reading it out
from the cache is done in parallel and no resource congestion exists
at the scale we use for our example.

Let us now compare the true time between sequential and parallel
execution. Simply modify the code in the * line and replace the loop accordingly::

  Sequential 12.681866169 s
  Parallel    6.51530909538 s

Thus we see two interesting performance improvements

First, the performance improvement for running the queries in
parallel. Second, the improvement of retrieving the results from a
cache. The later is important if we have many user on the system
executing the same command. 

The lesson we learn is that clouds must make use of execution
parallelism as well as addressing reuse of repeated results.


Exercises
----------------------------------------------------------------------

#. Is pdsh installed? Where
#. Return the hostname of the machines sierra, india and foxtrot via
   the fabric command
#. Execute the command qstat with fabric on sierra and india. If you
   have an account on bigred2, please try it also there 
#. Run the cloudmesh Sequential and parallel program. Modify your
   cloudmesh file accordingly 
#. Advanced: compare the performance of the cache backend between
   Mongodb and the use of RabbitMQ while switching RabbitMQ out with
   Redis in the Celery code.  
#. Advanced: provide a documentation on how to run celery for this
   example  on Redis.
