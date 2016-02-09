
Deploying Hadoop Cluster
=========================

Slides
----------------------------------------------------------------------

* Deploying hadoop clusters may not be as easy as one may think. (Tutorial 2.2.)

    * Setup keys, setup permissions, reserve compute servers
      
* In conlusion we have a much easier way to set up hadop clusters. (`Tutorial 2.1. <hadoop_cluster_cm.html>`_)

.. * Alternatives: openstack ??? technology
  
`Next Tutorial>> Deploying MongoDB Shard Cluster <mongodb_cluster.html>`_

Introduction
-------------

Hadoop Cluster is a computational cluster especially for MapReduce data
analysis applications. OpenStack on FutureSystems offers Hadoop Cluster with
virtual instances so that large amounts of distributed processing data can be
analyzed with better speed. Deploying Hadoop Cluster on OpenStack FutureSystems
is offered by a manual and an automated instruction. 

With Cloudmesh, Cloud Management Software, Hadoop Cluster can be deployed with
a simple command execution. ``launcher`` command in Cloudmesh helps you deploy
Hadoop Cluster with default settings automatically.  You can deploy Hadoop
Cluster with ``cm launcher`` by following this page: `Deploying Hadoop Cluster
with cm launcher <hadoop_cluster_cm.html>`_.  This tutorial taks 15-20 minutes.
For more information of ``launcher``, see `here <cm_launcher.html>`_

If you are willing to configure Hadoop Cluster manually, please follow the
page: `Deploying Hadoop Cluster on India OpenStack
<hadoop_cluster_manual.html>`_. This tutorial takes 30-45 minutes.

Hadoop Cluster Installation with ``cm launcher``
---------------------------------------------------

.. toctree::
   :maxdepth: 1

   Tutorial 2.1. Deploying Hadoop Cluster with Cloudmesh ``launcher``
   <hadoop_cluster_cm>

Hadoop Cluster (Manual Installation)
------------------------------------

.. toctree::
   :maxdepth: 1

   Tutorial 2.2. Deploying Hadoop Cluster (Manual Installation)
   <hadoop_cluster_manual>

Next Step
------------------------------------

The next topic is deploying MongoDB Shard Cluster on FutureSystems.

`Next Tutorial>> Deploying MongoDB Shard Cluster <mongodb_cluster.html>`_

.. .. toctree::
..   :maxdepth: 1

..   *Next* - Deploying MongoDB Shard Cluster <hadoop_cluster_cm>

