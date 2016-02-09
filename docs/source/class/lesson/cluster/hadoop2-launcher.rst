.. _ref-class-lesson-hadoop2-launcher:

Hadoop v2 with Cloudmesh Launcher (Under Development)
===============================================================================

.. tip:: Approximate time: 30 minutes

Quick Guide
-------------------------------------------------------------------------------

There are a few things to keep in mind during this tutorial.

* REPLACE ``albert`` with your portal id.
* Cloudmesh installation is required.
* ``dev2.0`` branch is a main repository for Cloudmesh
* One Hadoop cluster per user **TERMINATE AFTER USE**

Overview
-------------------------------------------------------------------------------

This tutorial explains how to deploy Hadoop V2 Cluster with Cloudmesh software. 
Four VM instances are used to deploy Hadoop V2 Cluster, one master node  and
three slave nodes. ``launcher`` command deploys software stacks on Cloudmesh
using OpenStack Heat and customized templates. Hadoop v2 cluster will be
deployed with the ``launcher`` command in the development Cloudmesh. 

You will use:

* Four VMs (one master, three slaves)
   * master name: $USER-hc-master
   * slave names: $USER-hc-slave1, $USER-hc-slave2, $USER-hc-slave3
* ``launcher`` command
   * ``launcher start hadoop-2.7-image`` will deploy Hadoop v2 Cluster using 
     Cloudmesh.

Preparation
-------------------------------------------------------------------------------

If you have installed Cloudmesh, skip this section and follow `dev2.0`
installation.

Have you not created a VM instance and installed Cloudmesh?:

:ref:`Cloudmesh Installation on a virtual machine OpenStack <s-cloudmesh-vm-quickstart>`

Development (`dev2.0`) Installation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Hadoop V2 cluster deployment is available in the ``dev2.0`` development branch.

Download `dev2.0` branch on your cloudmesh.

::

  cd ~/cloudmesh
  git checkout dev2.0
  git pull
  python setup.py install

.. warning:: This should be done on your VM instance, Cloudmesh installed. Do
   not try to run on india.futuresystems.org which is a login node of OpenStack
   of FutureSystems.

It looks like this, for example:

::

  (ENV)ubuntu@albert-cloudmesh:~$ cd ~/cloudmesh
  (ENV)ubuntu@albert-cloudmesh:~/cloudmesh$ git checkout dev2.0
  Already up-to-date. (or updating messages)
  (ENV)ubuntu@albert-cloudmesh:~/cloudmesh$ python setup.py install
  # ######################################################################
  # Generate and Install Version
  # ######################################################################
  running install
  running bdist_egg
  ...
  ...
  ...
  Using /home/ubuntu/ENV/lib/python2.7/site-packages
  Finished processing dependencies for cloudmesh==2.3.0
  (ENV)ubuntu@albert-cloudmesh:~/cloudmesh$

 ``launcher`` New Templates
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you installed ``dev2.0``, the new ``launcher`` template needs to be applied
to ``~/.cloudmesh``, the Cloudmesh configuration directory. Otherwise, your
``launcher`` command won't recognize a new template e.g. ``launcher start
hadoop2.7-image``. 

.. note:: ``launcher`` command deploys software stacks on Cloudmesh using
   OpenStack Heat and customized templates. Hadoop v2 cluster can be deployed
   with the ``launcher`` command in the development Cloudmesh.

Copy the new template to your ``.cloudmesh`` directory:

::

  cp ~/cloudmesh/etc/cloudmesh_launcher.yaml ~/.cloudmesh


Confirm that you have metadata for ``hadoop`` software packages in your new
yaml.::

  grep hadoop ~/.cloudmesh/cloudmesh_launcher.yaml

You expect to see like so::

  hadoop:
      label: hadoop  
      shortdescription: Deploys a hadoop cluster on the VMs specified.
              Deploys a hadoop cluster on the VMs specified
      template: https://raw.githubusercontent.com/cloudmesh/cloudmesh/master/heat-templates/ubuntu-14.04/hadoop-cluster/hadoop-cluster.yaml
      image: /static/img/launcher/hadoop.jpg
  hadoop2.7:
      image: /static/img/launcher/hadoop.jpg            
      template: https://raw.githubusercontent.com/cloudmesh/cloudmesh/dev2.0/heat-templates/ubuntu-14.04/hadoop-cluster/hadoop2.7-cluster.yaml
  hadoop2.7-image:                                                                                                                                          
      image: /static/img/launcher/hadoop.jpg                  
      template: https://raw.githubusercontent.com/cloudmesh/cloudmesh/dev2.0/heat-templates/hadoop-v2/hadoop-cluster/hadoop2.7-with-hadoop-v2-image.yaml
 
Deploying Hadoop V2 
-------------------------------------------------------------------------------

Now, we are ready to deploy Hadoop V2 using Cloudmesh development. Let's open a
Cloudmesh Shell:

::

  source ~/ENV/bin/activate
  cm

You will see welcome message::

  
  ======================================================
   ____ _                 _                     _
   / ___| | ___  _   _  __| |_ __ ___   ___  ___| |__
   | |   | |/ _ \| | | |/ _` | '_ ` _ \ / _ \/ __| '_ \
   | |___| | (_) | |_| | (_| | | | | | |  __/\__ \ | | |
   \____|_|\___/ \__,_|\__,_|_| |_| |_|\___||___/_| |_|
   ======================================================
                     Cloudmesh Shell

   cm> 

Simple command is ``launcher start hadoop2.7-image``. Try it on Cloudmesh
Shell::

  cm> launcher start hadoop2.7-image
  CM /cloudmesh-2.3.0-py2.7.egg/cloudmesh_cmd3/plugins/cm_shell_launcher.pyc... site:78:   INFO - {'--column': None,
   '--force': False,
   ...
   ...
   ...
  CM /cloudmesh-2.3.0-py2.7.egg/cloudmesh/iaas/openstack/cm_compute.pyc... site:518:  DEBUG - 518:POST PARAMS {'stack_name': 'launcher-albert-hadoop2.7-image-NOAO5A', 'template_url': 'https://raw.githubusercontent.com/cloudmesh/cloudmesh/dev2.0/heat-templates/hadoop-v2/hadoop-cluster/hadoop2.7-with-hadoop-v2-image.yaml', 'parameters': {'UserName': 'albert', 'PrivateKeyString': '...', 'KeyName': u'albert_ubuntu-key', 'PublicKeyString': 'ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCiqKmihZWU3q6GhTnBVZh4Ry4B5vjuJsSefpfT8nU+VkljRPhClWo3kj8hdkSfcxUUa/1fq9UCqA+c7SoAgXzB2G/ThFgI5nTLbkbyuNDire92natl43vu0jRcnW87zLwM/YDonBMHHZ4/LOquET6h0cJGp22V3JYvmLHLujiy1une26wlBZ7sb+8dOGmpeiqbKdJuh1dItAJEfwf+DkuolBCT///KD8olqmuYsNoLcHUPvkgqveAGIBSX8KaVc70bGTiC/d0DcY/rX0V3Pjm0qvgGVsR/Q0AFRlx6Z3hCNcccSDQflXhvTOpZV1Sq/7zCrXFUUwP1/cc2Mbsos7hN'}, 'timeout_mins': '60'}
  CM /cloudmesh-2.3.0-py2.7.egg/cloudmesh_cmd3/plugins/cm_shell_launcher.pyc... site:228:  DEBUG - {u'stack': {u'id': u'7881c97f-5ce8-4c25-9a80-a6bec9299869', u'links': [{u'href': u'http://i5r.idp.iu.futuregrid.org:8004/v1/c713809dee494dccac34fcd02e012acb/stacks/launcher-albert-hadoop2.7-image-NOAO5A/7881c97f-5ce8-4c25-9a80-a6bec9299869', u'rel': u'self'}]}}

List Launcher
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Check launcher to see your Hadoop2.7 stack.

:: 

  launcher list

You expect to see::

  +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+
  | launcher_id                          | stack_name                             | description                        | stack_status    | creation_time        | cm_cloud |
  +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+
  | 7881c97f-5ce8-4c25-9a80-a6bec9299869 | launcher-albert-hadoop2.7-image-NOAO5A | Hadoop cluster with OpenStack Heat | CREATE_COMPLETE | 2015-01-25T14:16:34Z | india    |
  +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+

List Nodes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Your Hadoop2.7 stack uses four vm instances as cluster nodes. You can find them
in ``vm list`` command.

::

   vm list

You exepct see like so::

  +----------------------------------------------------------+----------+------------------------------+-------------+-------------+
  | name                                                     | status   | addresses                    | flavor      | image       |
  +==========================================================+==========+==============================+=============+=============+
  ...
  +----------------------------------------------------------+----------+------------------------------+-------------+-------------+
  | albert-hc-slave2                                         | ACTIVE   | 10.23.1.26                   | unavailable | unavailable |
  +----------------------------------------------------------+----------+------------------------------+-------------+-------------+
  | albert-hc-master                                         | ACTIVE   | 10.23.1.28, 149.165.159.48   | unavailable | unavailable |
  +----------------------------------------------------------+----------+------------------------------+-------------+-------------+
  | albert-hc-slave1                                         | ACTIVE   | 10.23.1.27                   | unavailable | unavailable |
  +----------------------------------------------------------+----------+------------------------------+-------------+-------------+
  | albert-hc-slave3                                         | ACTIVE   | 10.23.1.25                   | unavailable | unavailable |
  +----------------------------------------------------------+----------+------------------------------+-------------+-------------+

Login to Master Node
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can get access to the master node using ``vm login`` command. Note that,
``ec2-user`` is a login name, not ``ubuntu``.

::

  vm login albert-hc-master --ln=ec2-user

You expect to see::

  Warning: Permanently added '149.165.159.48' (ECDSA) to the list of known hosts.
  Welcome to Ubuntu 14.04.2 LTS (GNU/Linux 3.13.0-46-generic x86_64)

   * Documentation:  https://help.ubuntu.com/

   System information as of Mon Jan 25 14:21:50 UTC 2015

   System load:  0.63              Processes:           81
   Usage of /:   8.5% of 19.65GB   Users logged in:     0
   Memory usage: 9%                IP address for eth0: 10.23.1.28
   Swap usage:   0%

   Graph this data and manage this system at:
   https://landscape.canonical.com/

   Get cloud support with Ubuntu Advantage Cloud Guest:
   http://www.ubuntu.com/business/services/cloud

  57 packages can be updated.
  27 updates are security updates.



  The programs included with the Ubuntu system are free software;
  the exact distribution terms for each program are described in the
  individual files in /usr/share/doc/*/copyright.

  Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
  applicable law.

  $

Switch to ``root`` Account
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Hadoop package installed on ``root`` account. Let's switch to ``root``
account::

   $ sudo su -

Status Check
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

check HDFS datanodes and YARN nodemanager.

* HDFS: ``hdfs dfsadmin -report``
* YARN: ``yarn node -list``

Check hdfs nodes::

         root@hc-master:~# hdfs dfsadmin -report

Example of ``hdfs`` report::

   ::

        root@hc-master:~# hdfs dfsadmin -report
        Configured Capacity: 63309729792 (58.96 GB)
        Present Capacity: 55276732416 (51.48 GB)
        DFS Remaining: 55276658688 (51.48 GB)
        DFS Used: 73728 (72 KB)
        DFS Used%: 0.00%
        Under replicated blocks: 0
        Blocks with corrupt replicas: 0
        Missing blocks: 0
        Missing blocks (with replication factor 1): 0

        -------------------------------------------------
        Live datanodes (3):

        Name: 10.23.1.25:50010 (hc-slave3)
        Hostname: hc-slave3
        Decommission Status : Normal
        Configured Capacity: 21103243264 (19.65 GB)
        DFS Used: 24576 (24 KB)
        Non DFS Used: 2677665792 (2.49 GB)
        DFS Remaining: 18425552896 (17.16 GB)
        DFS Used%: 0.00%
        DFS Remaining%: 87.31%
        Configured Cache Capacity: 0 (0 B)
        Cache Used: 0 (0 B)
        Cache Remaining: 0 (0 B)
        Cache Used%: 100.00%
        Cache Remaining%: 0.00%
        Xceivers: 1
        Last contact: Mon Jan 25 14:46:49 UTC 2015


        Name: 10.23.1.27:50010 (hc-slave1)
        Hostname: hc-slave1
        Decommission Status : Normal
        Configured Capacity: 21103243264 (19.65 GB)
        DFS Used: 24576 (24 KB)
        Non DFS Used: 2677665792 (2.49 GB)
        DFS Remaining: 18425552896 (17.16 GB)
        DFS Used%: 0.00%
        DFS Remaining%: 87.31%
        Configured Cache Capacity: 0 (0 B)
        Cache Used: 0 (0 B)
        Cache Remaining: 0 (0 B)
        Cache Used%: 100.00%
        Cache Remaining%: 0.00%
        Xceivers: 1
        Last contact: Mon Jan 25 14:46:49 UTC 2015


        Name: 10.23.1.26:50010 (hc-slave2)
        Hostname: hc-slave2
        Decommission Status : Normal
        Configured Capacity: 21103243264 (19.65 GB)
        DFS Used: 24576 (24 KB)
        Non DFS Used: 2677665792 (2.49 GB)
        DFS Remaining: 18425552896 (17.16 GB)
        DFS Used%: 0.00%
        DFS Remaining%: 87.31%
        Configured Cache Capacity: 0 (0 B)
        Cache Used: 0 (0 B)
        Cache Remaining: 0 (0 B)
        Cache Used%: 100.00%
        Cache Remaining%: 0.00%
        Xceivers: 1
        Last contact: Mon Jan 25 14:46:48 UTC 2015

Remember, we have 4 VMs with:

* Hostname ``hc-master``
* Hostname ``hc-slave1``
* Hostname ``hc-slave2``
* Hostname ``hc-slave3``

Check YARN nodes::

  root@hc-master:~# yarn node -list

Example of ``yarn`` list::

        15/01/25 14:50:00 INFO client.RMProxy: Connecting to ResourceManager at hc-master/10.23.1.28:8032
        Total Nodes:3
        Node-Id             Node-State Node-Http-Address       Number-of-Running-Containers
        hc-slave2:51545                RUNNING    hc-slave2:8042                                  0
        hc-slave3:53114                RUNNING    hc-slave3:8042                                  0
        hc-slave1:43613                RUNNING    hc-slave1:8042                                  0


Remember, ``Master`` has

* HDFS NameNode
* YARN ResourceManager
 
And ``Slaves`` have

* HDFS DataNode
* YARN NodeManager

We will start these applications.

HDFS NameNode
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If NameNode is started on Master, you will see::

  $ ps -ef|grep namenode
  root    8443     1  0 05:07 ?        00:00:25 /usr/lib/jvm/default-java//bin/java -Dproc_namenode -Xmx1000m -Djava.net.preferIPv4Stack=true -Dhadoop.log.dir=/root/hadoop-2.7.0/logs ...
  ...  org.apache.hadoop.hdfs.server.namenode.NameNode


YARN ResourceManager
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If ResourceManager is started on Master, you will see:

::

  $ ps -ef|grep resourcemanager
  root    8675     1  0 05:07 ?        00:01:07 /usr/lib/jvm/default-java//bin/java -Dproc_resourcemanager -Xmx1000m -Dhadoop.log.dir=/root/hadoop-2.7.0/logs ... 
  ... org.apache.hadoop.yarn.server.resourcemanager.ResourceManager

MapReduce Example: Word Count
-------------------------------------------------------------------------------

Once you installed a Hadoop cluster, you may want to run a program using the
cluster. One of the popular examples of Hadoop is a Word Count MapReduce
program which counts how often words occur from the input text file. We have a
separate page for this program here.

:ref:`Word Count Program <ref-class-lesson-hadoop-word-count>`

Launcher Termination
-------------------------------------------------------------------------------

If you've completed your tasks or jobs on Hadoop 2.7.0 cluster, you need to
terminate your hadoop stack on launcher.

Check your existing launcher stack.

:: 

  cm launcher list

My example is::

        +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+
        | launcher_id                          | stack_name                             | description                        | stack_status    | creation_time        | cm_cloud |
        +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+
        | 7881c97f-5ce8-4c25-9a80-a6bec9299869 | launcher-albert-hadoop2.7-image-NOAO5A | Hadoop cluster with OpenStack Heat | CREATE_COMPLETE | 2015-01-25T14:16:34Z | india    |
        +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+

Terminate it with the stack_name::

  cm launcher stop launcher-albert-hadoop2.7-image-NOAO5A

You expect to see like so::

  ...
  CM /cloudmesh-2.3.0-py2.7.egg/cloudmesh/iaas/openstack/cm_compute.pyc... site:684:  DEBUG - 684: AUTH URL http://i5r.idp.iu.futuregrid.org:8004/v1/c713809dee494dccac34fcd02e012acb/stacks/launcher-hrlee-hadoop2.7-image-NOAO5A
  CM /cloudmesh-2.3.0-py2.7.egg/cloudmesh/iaas/openstack/cm_compute.pyc... site:690:  DEBUG - 690: Response <Response [200]>
  CM /cloudmesh-2.3.0-py2.7.egg/cloudmesh_cmd3/plugins/cm_shell_launcher.pyc... site:241:  DEBUG - {'msg': 'success'}

Confirm that your launcher stack is deleted::

  cm launcher list
  +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+
  | launcher_id                          | stack_name                             | description                        | stack_status    | creation_time        | cm_cloud |
  +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+
  +--------------------------------------+----------------------------------------+------------------------------------+-----------------+----------------------+----------+


FAQs
-------------------------------------------------------------------------------

Q. How to stop Masters or Slaves?
A. Use the commands below::

   (On Master)
   yarn-daemon.sh stop resourcemanager
   hadoop-daemon.sh --script hdfs stop namenode

   (On Slaves)
   yarn-daemon.sh stop nodemanager
   hadoop-daemon.sh --script hdfs stop datanode

Q. Where can I see log files?
A. ``~/hadoop/logs/`` contains log files.
   See files with ``.log`` extention. e.g.
   ``hadoop-ubuntu-namenode-hc-master.log``

Q. DataNode won't start. If I remove data storage, would it help?
A. Probably, yes. Stop datanode and remove the storage. If you used default
configuration, the HDFS storage is located under ``/tmp``.  ::

   hadoop-daemon.sh --script hdfs stop datanode
   rm -rf /tmp/hadoop-*


