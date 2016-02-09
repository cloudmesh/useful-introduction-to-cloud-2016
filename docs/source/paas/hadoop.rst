.. _s-hadoop:

**********************************************************************
Using Hadoop in FutureSystems
**********************************************************************

.. sidebar:: Screencast

   A screenncast of a subset of the information presented her is
   available at |video-hadoop|.


We have various platforms that support Hadoop on FutureSystems. MyHadoop
is probably the easiest solution offered for you. It provides the
advantage that it is integrated into the queuing system and allows
hadoop jobs to be run as batch job. This is of especial interest for
classes that may run quickly out of resources if every students wants
to run their hadoop application at the same time.


.. _s-myhadoop:


Running Hadoop as a Batch Job using MyHadoop
======================================================================

MapReduce is a programming model developed by Google. Their
definition of MapReduce is as follows:  "MapReduce is a programming
model and an associated implementation for processing and generating
large data sets. Users specify a map function that processes a key/value
pair to generate a set of intermediate key/value pairs, and a reduce
function that merges all intermediate values associated with the same
intermediate key."  For more information about MapReduce, please see the
Google paper `here <http://labs.google.com/papers/mapreduce.html>`__.

The `Apache Hadoop Project <http://hadoop.apache.org>`__ provides an
open source implementation of MapReduce and HDFS (Hadoop Distributed
File System).   

This tutorial illustrates how to run Apache Hadoop thru the batch
systems on FutureSystems using the MyHadoop tool.  

myHadoop on FutureSystems
----------------------------------------------------------------------

`MyHadoop <http://sourceforge.net/projects/myhadoop/>`__ is a set of
scripts that configure and instantiate Hadoop as a batch job. 

myHadoop 0.20.2 is currently installed on Alamo, Hotel, India, and Sierra
FutureSystems systems. 


Login into a machine tha has myHadoop installed
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To run the example we need to firts log into a FutureSystems system that
has myHadoop available.  In this tutorial, we are executing from the sierral machine::

       $ ssh portalname@sierra.futuregrid.org

Note that this also works on other FutureSystems machines such as india.

This machine accepts SSH public key and One Time Password (OTP) logins
only.  If you do not have a public key set up, you will be prompted
for a password.  This is *not* your FutureSystems password, but the One
Time Password generated from your OTP token.  Do not type your
FutureSystems password, it will not work.  If you do not have a token or
public key, you will not be able to login.  The portalname is your
account name that allows you to log into the FutureSystems portal.

Load the needed modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Next, we need to load the myHadoop module.  On some FutureSystems
systems, you may also need to load the "torque" module as well if
qstat is not already in your environment::

       $ module load myhadoop
       SUN Java JDK version 1.6.0 (x86_64 architecture) loaded
       Apache Hadoop Common version 0.20.203.0 loaded
       myHadoop version 0.2a loaded

Before we can submit it we still need to load the module java as
Haddop relies on java::

       module add java

Run the Example
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To run the example we need to create a script to tell the queing
system how to run it. We are providing the following script that you
can store in a file pbs-example.sh. 

You can paste and copy it from here, or just copy it via::

    cp $MY_HADOOP_HOME/pbs-example.sh .

This script includes information about
which queue hadoop should be run in. To find out more about the
queuing system, please see the HPC services section. The pbs-example.sh
script we use in this example looks as follows::


    #!/bin/bash

    #PBS -q batch
    #PBS -N hadoop_job
    #PBS -l nodes=4:ppn=8
    #PBS -o hadoop_run.out
    #PBS -j oe
    #PBS -V

    module add java

    ### Run the myHadoop environment script to set the appropriate variables
    #
    # Note: ensure that the variables are set correctly in bin/setenv.sh
    . /N/soft/myHadoop/bin/setenv.sh

    #### Set this to the directory where Hadoop configs should be generated
    # Don't change the name of this variable (HADOOP_CONF_DIR) as it is
    # required by Hadoop - all config files will be picked up from here
    #
    # Make sure that this is accessible to all nodes
    export HADOOP_CONF_DIR="${HOME}/myHadoop-config"

    #### Set up the configuration
    # Make sure number of nodes is the same as what you have requested from PBS
    # usage: $MY_HADOOP_HOME/bin/pbs-configure.sh -h
    echo "Set up the configurations for myHadoop"
    # this is the non-persistent mode
    $MY_HADOOP_HOME/bin/pbs-configure.sh -n 4 -c $HADOOP_CONF_DIR
    # this is the persistent mode
    # $MY_HADOOP_HOME/bin/pbs-configure.sh -n 4 -c $HADOOP_CONF_DIR -p -d /oasis/cloudstor-group/HDFS
    echo

    #### Format HDFS, if this is the first time or not a persistent instance
    echo "Format HDFS"
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR namenode -format
    echo

    #### Start the Hadoop cluster
    echo "Start all Hadoop daemons"
    $HADOOP_HOME/bin/start-all.sh
    #$HADOOP_HOME/bin/hadoop dfsadmin -safemode leave
    echo

    #### Run your jobs here
    echo "Run some test Hadoop jobs"
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -mkdir Data
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -copyFromLocal $MY_HADOOP_HOME/gutenberg Data
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -ls Data/gutenberg
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR jar $HADOOP_HOME/hadoop-0.20.2-examples.jar wordcount Data/gutenberg Outputs
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -ls Outputs
    $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -copyToLocal Outputs ${HOME}/Hadoop-Outputs
    echo

    #### Stop the Hadoop cluster
    echo "Stop all Hadoop daemons"
    $HADOOP_HOME/bin/stop-all.sh
    echo

    #### Clean up the working directories after job completion
    echo "Clean up"
    $MY_HADOOP_HOME/bin/pbs-cleanup.sh -n 4 -c $HADOOP_CONF_DIR
    echo

Details of the Script
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let us examine this script in more detail. In the example script, a temporary directory to store Hadoop
configuration files is specified as ${HOME}/myHadoop-config::

       #### Set this to the directory where Hadoop configs should be generated
       # Don't change the name of this variable (HADOOP_CONF_DIR) as it is
       # required by Hadoop - all config files will be picked up from here
       #
       # Make sure that this is accessible to all nodes
       export HADOOP_CONF_DIR="${HOME}/myHadoop-config"

The pbs-example.sh script runs the "wordcount" program from
the hadoop-0.20.2-examples.jar.  There is sample text data from the
`Project Gutenberg website <http://www.gutenberg.org/>`__ located a
$MY_HADOOP_HOME/gutenberg::

       $ ls $MY_HADOOP_HOME/gutenberg
       1342.txt.utf8

The following lines in the script create a data directory in HDFS. This directory is
specified in $MY_HADOOP_HOME/bin/setenv.sh. To activate the
environment, pleas execute::

    source $MY_HADOOP_HOME/bin/setenv.sh 

The next lines in the script will copy over the gutenberg data, executes the Hadoop
job, and then copies the output back your ${HOME}/Hadoop-Outputs
directory. ::

       #### Run your jobs here
       echo "Run some test Hadoop jobs"
       $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -mkdir Data
       $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -copyFromLocal $MY_HADOOP_HOME/gutenberg Data
       $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -ls Data/gutenberg
       $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR jar $HADOOP_HOME/hadoop-0.20.2-examples.jar wordcount Data/gutenberg Outputs
       $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -ls Outputs
       $HADOOP_HOME/bin/hadoop --config $HADOOP_CONF_DIR dfs -copyToLocal Outputs ${HOME}/Hadoop-Outputs

Submission of the Hadoop job
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now submit the pbs-example.sh script to Hotel::

       $ qsub $MY_HADOOP_HOME/pbs-example.sh 
       40256.svc.uc.futuregrid.org

The job will take about 5 minutes to complete.  To monitor its
status, type 'qstat'.  The "R" means the job is running::

       $ qstat
       Job id                    Name             User            Time Use S Queue
       ------------------------- ---------------- --------------- -------- - -----
       40256.svc                  hadoop_job       albert                0 R batch                  

When it is done, the status of the job will be "C" meaning the job has
completed (or it will no longer be displayed in qstat output).  You
should see a new hadoop_run.out file and an "Hadoop-Outputs" directory
::

       $ qstat
       Job id                    Name             User            Time Use S Queue
       ------------------------- ---------------- --------------- -------- - -----
       40256.svc                  hadoop_job       albert         00:00:05 C batch                   
       $ ls
       Hadoop-Outputs hadoop_run.out

View results of the word count operation::

       $ head Hadoop-Outputs/part-r-00000  
       "'After    1
       "'My   1
       "'Tis  2
       "A 12
       "About 2
       "Ah!   2
       "Ah!" 1
       "Ah,   1
       "All   2
       "All!  1

Now to run you own custom Hadoop job, make a copy of the
$MY_HADOOP_HOME/pbs-example.sh script and modify the lines described
in Step 7.

Persistent Mode
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The above example copies input to local HDFS scratch space you specified
in $MY_HADOOP_HOME/bin/setenv.sh, runs MapReduce, and copies output
from HDFS back to your home directory.  This is called non-persistent
mode and is good for small amounts of data.  Alternatively, you can run
in persistent mode which is good if you have access to a parallel file
system or have a large amount of data that will not fit in scratch
space.  To enable persistent mode, follow the directions in
pbs-example.sh.


Customizing Hadoop Settings
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To modify any of the Hadoop settings
like maximum_number_of_map_task, maximum_number_of_reduce_task,
etc., make you own copy of myHadoop and customize the settings
accordingly.  For example:

#. Copy the $MY_HADOOP_HOME directory to your home directory::

       $ cp -r $MY_HADOOP_HOME $HOME/myHadoop

#. Then edit $HOME/myHadoop/pbs-example.sh and on line 16, replace it
   with::

       . ${HOME}/myHadoop/bin/setenv.sh

#. Similarly edit $HOME/myHadoop/bin/setenv.sh and on line 4, replace it
   with::

       export MY_HADOOP_HOME=$HOME/myHadoop

#. Customize the settings in the Hadoop files as needed in
   $HOME/myHadoop/etc

#. Submit your copy of pbs-example.sh::

       $ qsub $HOME/myHadoop/pbs-example.sh

Using a Different Installation of Hadoop
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you would like to use a different version of my Hadoop or have
customized the Hadoop code in some way, you can specify a different
installation of Hadoop by redefining the HADOOP_HOME variable after
$MY_HADOOP_HOME/bin/setenv.sh is called within your own copy of
pbs-example.sh::

    ### Run the myHadoop environment script to set the appropriate variables
    #
    # Note: ensure that the variables are set correctly in bin/setenv.sh
    . /opt/myHadoop/bin/setenv.sh
    export HADOOP_HOME=${HOME}/my-custom-hadoop

References
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Much of this information is copied from `The MyHadoop Installation Instructions <https://portal.futuregrid.org/sites/default/files/myHadoop.pdf>`__
* A screenncast of a subset of the information presented her is
  available at |video-hadoop|.


.. |video-hadoop| replace:: |video-image| :youtube:`PC8h1CtVzH4`
.. |video-image| image:: /images/glyphicons_402_youtube.png 

