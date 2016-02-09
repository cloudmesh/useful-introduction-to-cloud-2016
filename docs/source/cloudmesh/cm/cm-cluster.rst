.. _cloudmesh-cm-cluster-ref:


Deploying Virtual Cluster with Cloudmesh ``cm``
===============================================

To support the creation of a virtual compute cluster (e.g. Hadoop or
Slurm) on cloudmesh, we are offering the command ``cluster`` to start,
configure, manage or update a number of virtual machines.

Preparation (Optional)
----------------------

The ``cluster`` command is available in the cloudmesh shell. There are
certain steps to make sure you are all set to deploy a new cluster. You
can SKIP these steps if you have configured cloudmesh previously.

.. code:: python

    cm cluster

Before starting a cluster, please make sure you activate a cloud:

.. code:: python

    cm "cloud on india"

Activation however does not select the cloud as the default cloud to
start virtual machines. This is achieved by the select command

.. code:: python

    cm "cloud select india"

.. note: this is a bit unintuitive and shold probably be done with
``cloud default india``

Default keypair
~~~~~~~~~~~~~~~

To gain access to the virtual machines, you need to have a key
registered with the cloud. If you don't have a default keypair, you need
to set or need to specify which keypair you are going use for the vm.

.. code:: python

    cm "key default test-key"

VM Name
~~~~~~~

You can also define the name of VMs which contains a prefix and an index
with the ``label`` command. However, the name of the vms must be unique.
By default your username and a number will be used that will be
automatically increased. Thus we recommend that you avoid using this
command.

.. code:: python

    cm "label --prefix=test --id=1"

Default Image
~~~~~~~~~~~~~

You can choose a default image to create a virtual machine. In this
example, we use ubuntu-14.04 image as a default.

.. code:: python

    cm "default image --name=futuregrid/ubuntu-14.04"

Default Flavor
~~~~~~~~~~~~~~

You can chose a default flavor. However, make sure that the falvor
actially works with the specified image. Some images require a minimal
flavor.

.. code:: python

    cm "default flavor --name=m1.small"

Create Cluster
--------------

Then you may start the cluster with command 'cluster create' by
providing the following values:

| ``--count``
|  specify amount of VMs in the cluster

| ``--group``
|  specify a group name of the cluster, make sure it's UNIQUE

| ``--ln``
|  login name for VMs, e.g. ubuntu

Create 3 virtual machines
~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: python

    Let us create a cluster with the group name test that contains 3 virtual machines.

.. code:: python

    cm "cluster create --count=3 --group=test --ln=ubuntu"

You may also provide a cloud name, flavor or image as parameter in the
command if you do not want to use the defaults. For example you can use
the following do do so:

.. code:: python

    cm "cluster create --count=3 --group=test0 --ln=ubuntu --cloud=india --flavor=m1.small --image=futuregrid/ubuntu-14.04"

You can display the status of vms for the cluster with the ``vm list``
command:

.. code:: python

    cm "vm list --refresh --group=test"
