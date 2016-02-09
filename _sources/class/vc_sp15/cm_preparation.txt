Cloudmesh Preparation
======================

Cloudmesh needs to be configured on your desired machine to use Cloudmesh
interactive shell commands. With a proper installation and configuration, you
are ready to create a virtual machine (VM) or a virtual cluster on
FutureSystems.

.. note:: Don't have an FutureSystems account? Please `register <account.html>`_

Table of Contents

* `Installation <#id1>`_
* `Configuration <#id2>`_

Installation 
------------

Cloudmesh can be installed in different environments such as your desktop,
OpenStack, or VirtualBox.  |quickstart| *(external link)*
describes easy installation on OpenStack India.  If you are looking for other
methods to install Cloudmesh, please refer |cloudmeshsetup| *(external link)*

.. |quickstart| raw:: html

        <a href="http://cloudmesh.github.io/introduction_to_cloud_computing/cloudmesh/setup/setup_openstack.html" target="_blank">QuickStart</a>

.. |cloudmeshsetup| raw:: html

        <http://cloudmesh.github.io/introduction_to_cloud_computing/cloudmesh/setup/index.html>

.. tip:: Approximate time: 30 minutes

Configuration
---------------

Once you have installed Cloudmesh, you need to configure Cloudmesh. For
example, you need to setup Cloudmesh with your account information and
keypairs. The following sections provide instructions to configure Cloudmesh
properly.

.. tip:: Approximate time: 10 minutes

Active cloud
~~~~~~~~~~~~
Before starting any command, please make sure you have an active cloud (IaaS).
For example, you can simple choose *india* as your active cloud host::

    cm cloud on india

Activation however does not select the cloud as the default cloud to
start virtual machines. This can be achieved by the ``select`` command::

    cm cloud select india

.. note: this is a bit unintuitive and should probably be done with

To set the india cloud to be the default cloud you can use in addition
the command::

    cm cloud default india

Default keypair
~~~~~~~~~~~~~~~

To gain access to the virtual machines, you need to have a key
registered with the cloud. If you don't have a default keypair, you need
to set or need to specify which keypair you are going use for
the vm. As you may be in a group and other users also could store
their keys in the group key repository, it is necessary to distinguich
them. On india you have a username that you can print with::

  echo $USER

and use this name as it is a unique prefix::

    cm key default $USER-key

VM Name
~~~~~~~

You can also define the name of VMs which contains a prefix and an index
with the ``label`` command. However, the name of the vms must be unique.
By default your username and a number will be used that will be
automatically increased. Thus we recommend that you avoid using this
command::

    cm label --prefix=$USER --id=1

    
Default Image
~~~~~~~~~~~~~

You can choose a default image to create a virtual machine. In this
example, we use ubuntu-14.04 image as a default::

    cm default image --name=futuresystems/ubuntu-14.04

Default Flavor
~~~~~~~~~~~~~~

You can chose a default flavor. However, make sure that the flavor
actually works with the specified image. Some images require a minimal
flavor::

    cm default flavor --name=m1.small

Exercise
--------

* Can you create a virtual machine?
* Can you see a list of running virtual machine?


Next Step
---------

In the next page, we deploy a virtual cluster on FutureSystems using Cloudmesh.

.. toctree::
   :maxdepth: 1

   Next - Deploying Virtual Cluster <virtual_cluster>
