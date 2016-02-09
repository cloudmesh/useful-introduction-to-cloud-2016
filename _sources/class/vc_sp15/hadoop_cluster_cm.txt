.. _ref-class-lesson-deploying-hadoop-cluster-with-cloudmesh:

Deploying Hadoop Cluster with Cloudmesh ``launcher``
===============================================================================

To support a compute cluster (e.g. Hadoop or Slurm) with applications,
Cloudmesh provides a new command ``launcher`` to start, configure, manage or
update compute nodes (VMs) with selected applications. ``launcher`` command
applies default settings to configure clusters with applications so users can
avoid hassles of building clusters.

Table of Contents

* `Start Cluster with launcher <#start-cluster>`_
* `Check Status <#check-status-of-cluster>`_
* `Login to Cluster <#id1>`_
* `Terminate Cluster <#id2>`_

`Next Tutorial>> Deploying MongoDB Shard Cluster <mongodb_cluster.html>`_

Tutorial: Deploying Hadoop Cluster with ``cm launcher``
-------------------------------------------------------------------------------

.. tip:: approximate time 30 minutes

In this tutorial, we are going to deploy a Hadoop cluster using Cloudmesh
``launcher`` command.

Start Cluster
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``launcher start`` command deploys a cluster with a selected application.

::

        cm launcher start hadoop

Check Status of Cluster
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Initializing a cluster requires some time for installing packages,
configuring networks, etc.  While it is initiated, you can check the
status of your cluster deployment.

::

        cm launcher list

You expect the result similar to:

.. parsed-literal::

        +--------------------------------------+-------------------------------+------------------------------------+--------------------+----------------------+----------+
        | launcher_id                          | stack_name                    | description                        | stack_status       | creation_time        | cm_cloud |
        +--------------------------------------+-------------------------------+------------------------------------+--------------------+----------------------+----------+
        | 14ec7ceb-ce12-4b18-9c31-d398c6e76b78 | launcher-albert-hadoop-DB8JDK | Hadoop cluster with OpenStack Heat | CREATE_IN_PROGRESS | 2015-01-22T16:25:23Z | india    |
        +--------------------------------------+-------------------------------+------------------------------------+--------------------+----------------------+----------+

* CREATE_IN_PROGRESS: cluster is not available because creating the
  cluster is in progress.
* CREATE_COMPLETE: cluster has been created and it is ready to use.

Login to Cluster
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

We use ``cm vm login`` command to ssh to one of the nodes in the
cluster.  Issue ``vm list`` first to see the list of virtual
instances.

* Checking a node name to login

::

        cm vm list

You expect the result similar to:

.. parsed-literal::

        +---------------------------+----------+----------------------------+----------+----------------------------+
        | name                      | status   | addresses                  | flavor   | image                      |
        +===========================+==========+============================+==========+============================+
        | **hadoop1**                   | ACTIVE   | 10.39.1.48, 149.165.159.02 | m1.small | futuresystems/ubuntu-14.04 |
        +---------------------------+----------+----------------------------+----------+----------------------------+
        | hadoop2                   | ACTIVE   | 10.39.1.52                 | m1.small | futuresystems/ubuntu-14.04 |
        +---------------------------+----------+----------------------------+----------+----------------------------+
        | hadoop3                   | ACTIVE   | 10.39.1.51                 | m1.small | futuresystems/ubuntu-14.04 |
        +---------------------------+----------+----------------------------+----------+----------------------------+
        | hadoop4                   | ACTIVE   | 10.39.1.53                 | m1.small | futuresystems/ubuntu-14.04 |
        +---------------------------+----------+----------------------------+----------+----------------------------+
        | hadoop5                   | ACTIVE   | 10.39.1.54                 | m1.small | futuresystems/ubuntu-14.04 |
        +---------------------------+----------+----------------------------+----------+----------------------------+
        | albert-server-54zmzloc5tp | ACTIVE   | 10.39.1.41, 149.165.159.01 | m1.small | cloudmesh/ipynb-n-java     |
        +---------------------------+----------+----------------------------+----------+----------------------------+

We found that hadoop1 is a node to log in.

* SSH to a node

::

        cm vm login [node name]

In this example, we try to ssh to ``hadoop1`` with ``ec2-user`` user name.

::

        cm vm login hadoop1 --ln=ec2-user

You expect the result similar to:

.. parsed-literal::

        Welcome to Ubuntu 14.04.1 LTS (GNU/Linux 3.13.0-40-generic x86_64)

         * Documentation:  https://help.ubuntu.com/

           System information as of Thu Jan 22 19:28:05 UTC 2015

           System load:  0.01              Processes:           72
           Usage of /:   6.9% of 19.65GB   Users logged in:     0
           Memory usage: 23%               IP address for eth0: 10.39.1.48
           Swap usage:   0%

           Graph this data and manage this system at:
             https://landscape.canonical.com/

           Get cloud support with Ubuntu Advantage Cloud Guest:
             http://www.ubuntu.com/business/services/cloud


       $ 

* Switch to ``root`` user

  You are expected to run hadoop commands as a root superuser.
 
::

        sudo su -

MapReduce Example: Word Count
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Once you installed a Hadoop cluster, you may want to run a program using the
cluster.  One of the popular examples of Hadoop is a Word Count MapReduce
program which counts how often words occur from the input text file. We have a
separate page for this program here.

:ref:`Word Count Program <ref-class-lesson-hadoop-word-count>`

Terminate Cluster
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Once you completed your task on the cluster, you can terminate the cluster with
``cm launcher stop [name]`` command.

* Check a cluster name to stop

::

        cm launcher list

You expect the result similar to:

.. parsed-literal::

        +--------------------------------------+-------------------------------+------------------------------------+-----------------+----------------------+----------+
        | launcher_id                          | stack_name                    | description                        | stack_status    | creation_time        | cm_cloud |
        +--------------------------------------+-------------------------------+------------------------------------+-----------------+----------------------+----------+
        | 14ec7ceb-ce12-4b18-9c31-d398c6e76b78 | **launcher-albert-hadoop-DB8JDK** | Hadoop cluster with OpenStack Heat | CREATE_COMPLETE | 2015-01-22T16:25:23Z | india    |
        +--------------------------------------+-------------------------------+------------------------------------+-----------------+----------------------+----------+

* Terminate a cluster

::

        cm launcher stop [name]

In this tutorial, we terminate ``launcher-albert-hadoop-DB8JDK`` like this:

::

        cm launcher stop launcher-albert-hadoop-DB8JDK


* DELETE_IN_PROGRESS: shutting down instances is in progress.
* DELETE_COMPLETE: the lease of resources is ended, all resources are returned.


Next Step
-------------------------------------------------------------------------------

In the next page, we deploy a Sharded MongoDB cluster on FutureSystems using
Cloudmesh.

`Next Tutorial>> Deploying MongoDB Shard Cluster <mongodb_cluster.html>`_

.. .. toctree::
..   :maxdepth: 1

..   Next - Deploying MongoDB Cluster <mongodb_cluster> 
