.. _ref-class-lesson-deploying-virtual-cluster-with-cloudmesh:

Deploying Virtual Cluster with Cloudmesh ``cm``
===============================================

To support the creation of a virtual compute cluster on Cloudmesh, the command
``cluster`` can be used to start, configure, manage or update a number of
virtual machines.

.. note:: Don't have Cloudmesh? see the `preparation <cm_preparation.html>`_

**Table of Contents**

* `Create Virtual Cluster <#create-virtual-cluster-with-3-virtual-machines>`_
* `Login to Virtual Cluster <#id1>`_
* `Terminate Virtual Cluster <#id2>`_

*Navigation*

`Next Page - Deploying Hadoop Cluster <hadoop_cluster.html>`_

Tutorial: Creating Virtual Cluster 
-----------------------------------

To perform distributed processing software, you may need to use clusters for
better performance.  Cloudmesh allows users to choose different images, flavors
or a node size of clusters, so that users use virtual instances efficiently for
their analysis with less wasting resources.

In this tutorial, we create Virtual Cluster with three virtual instances. Each
virtual instance uses a m1.small flavor (1 vCPU, 2GB Memory, 20GB disk) and a
Ubuntu 14.04 distribution.

Each node is supposed to communicate with other nodes in the same cluster and
public IP address is also assigned to the node using floating IPs.

* Cluster Name: virtual_cluster
* VMs: 3 virtual instances
* Flavor: m1.small
* Image: futuresystems/ubuntu-14.04
* Cloud: India

.. tip:: Approximate time: 10 minutes

Create Virtual Cluster with 3 virtual machines
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You can create a virtual cluster with a group name *test* and 3 virtual instances.

::

    cm cluster create virtual_cluster --count=3

You may also provide a cloud name, flavor or image as parameter in the
command if you do not want to use the defaults. For example you can use
the following do do so::

    cm cluster create virtual_cluster_ext --count=3 --ln=ubuntu --cloud=india --flavor=m1.small --image=futuresystems/ubuntu-14.04

You can display the status of vms for the cluster with the ``vm list``
command::

    cm vm list --refresh --group=virtual_cluster

Login to Virtual Cluster
~~~~~~~~~~~~~~~~~~~~~~~~~~

``vm login`` command can be used to ssh one of the nodes in the cluster.

::

    cm vm login albert_1 --ln=ubuntu

*albert_1 is a virtual instance name in the cluster.*

Terminate Virtual Cluster
~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you completed your task on the cluster, you may terminate the virtual cluster using Cloudmesh.

``cluster remove [name]`` simply shuts down a node(s) of the cluster.

.. _ref-class-lesson-deploying-virtual-cluster-with-cloudmesh-exercise:

Exercise
---------

- Try to access a master node of your cluster. (Make a screenshot)
- Create a Virtual Cluster with 2 VMs. (Make a screenshot)
- Submit two screenshots

Cloudmesh ``cluster`` command
-----------------------------

To create, list, or remove clusters, use ``cm cluster`` command.

.. tip:: latest repository is required (dev1.3). Please `download latest cloudmesh <cm_download.html>`_

Create Cluster
~~~~~~~~~~~~~~~~~

Cloudmesh provides a simple command to create a virtual cluster.
``cluster create`` can be executed along with the following options:

| ``--count``
|  specify amount of VMs in the cluster

| ``--cloud``
|  specify a cloud name, e.g. india

| ``--flavor``
|  specify a flavor name among m1.tiny, m1.small, m1.medium, m1.large

| ``--ln``
|  login name for VMs, e.g. ubuntu

| ``--image``
|  specify an image name.  ``list image`` command allows you to find registered images.

List Cluster
~~~~~~~~~~~~

``cluster list [name]`` shows running clusters with a number of nodes.

Remove Cluster
~~~~~~~~~~~~~~

``cluster remove [name]`` automatically terminates all nodes of the cluster.

FAQ
----

- Q. How do I delete a Virtual Cluster?
- A. ``cluster remove [name]``

- Q. I cannot find ``cluster`` command on my cloudmesh.
- A. You need to download latest cloudmesh on Github. Please see `the download page <cm_download.html>`_

Other questions?
----------------

- Forum via Git Issues: `Git Issues <https://github.com/CourseMaterial/introduction_to_cloud_computing/issues>`_
- Email: `Contact Us <contact.html>`_

Next Step
---------

In the next page, we deploy a Hadoop cluster on FutureSystems using Cloudmesh.

.. toctree::
   :maxdepth: 1

   Next Tutorial - Deploying Hadoop Cluster <hadoop_cluster>
