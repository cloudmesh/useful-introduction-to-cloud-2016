
Command Shell Orchestration Tool (Launcher)
===========================================

Launcher provides orchestration for creating ready-to-use cloud
applications with Chef Cookbooks and shell scripts.

.. note: Openstack is only supported

Launcher import command
-----------------------

Launcher registers local cookbooks from the yaml file
(cloudmesh\_launcher.yaml)

::

    cm launcher import

.. parsed-literal::

    launcher 'bigdata_mooc' added.
    launcher 'slurm' added.
    launcher 'hadoop' added.
    launcher 'ganglia' added.
    launcher 'nagios' added.

Launcher menu command
---------------------

``menu`` command provides available local cookbooks that are registered
by ``import``. These cookbooks represent Chef Cookbooks registered in
Cloudmesh. You can choose one of the names to start ``Launcher``.

.. note:: Registered Cookbooks can be found at:
https://github.com/cloudmesh/chef

::

    cm launcher menu

.. parsed-literal::

    +--------------+----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | launcher     | name                 | description                                                                                                                                                      |
    +--------------+----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | bigdata_mooc | Big Data Class at IU | Deploys an Image for a class taught on Big Data.                                                                                                                 |
    |              |                      |                                                                                                                                                                  |
    | ganglia      | Ganglia              | Deploys a Ganglia service for the vms specified. The ganglia server will be the first node in the list.                                                          |
    |              |                      |                                                                                                                                                                  |
    | hadoop       | Hadoop               | Deploys a haddop cluster on the VMs specified                                                                                                                    |
    |              |                      |                                                                                                                                                                  |
    | nagios       | Nagios               | Deploys a Nagios service for the vms specified. The ganglia server will be the first node in the list.                                                           |
    |              |                      |                                                                                                                                                                  |
    | slurm        | Slurm Cluster        | Deploys a Slurm cluster. One of the Vms is the Master, while the others register with the master as worker nodes. The master will be the first node in the list. |
    |              |                      |                                                                                                                                                                  |
    +--------------+----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Launcher start command
----------------------

If you decide which cookbook you are going to use, you are ready to
create a new ``launcher`` with the cookbook name. In this tutorial, we
use ``hadoop`` as a desired cookbook.

::

    cm launcher start hadoop

.. parsed-literal::

    * india
    Refreshing albert servers india ->
    Refresh time: 0.219480037689
    Store time: 0.0358941555023


Launcher list command
---------------------

If your launcher has been successfully created, you can see it in the
list of running launchers with ``list`` command.

::

    cm launcher list

Launcher stop command
---------------------

``stop`` command terminates your launcher.

::

   cm launcher stop [name]

Launcher export command
-----------------------

Your loaded cookbooks in the database can be exported to a yaml file
with ``export`` command. For example, we can generate a
``/tmp/cloudmesh_launcher.yaml`` file by exporting a registered
cookbooks in the database.

::

    cm launcher export /tmp/cloudmesh_launcher.yaml
