Code Listings
======================================================================

Booting a virtual machine
----------------------------------------------------------------------


Boot with  a shell command
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: ../../../programs/boot-vm.sh
   :literal:

Boot with python calling a shell command
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: ../../../programs/boot-vm.py
   :literal:

Boot with cloudmesh
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are two ways to boot a VM with cloudmesh other than cloudmesh GUI,
you may choose cloudmesh API or CLI. For example, boot a VM with API:

.. code:: python

    import cloudmesh
.. code:: python

    mesh = cloudmesh.mesh("mongo")
.. code:: python

    username = cloudmesh.load().username()
.. code:: python

    mesh.activate(username)
.. code:: python

    mesh.start(cloud="india", cm_user_id=username flavor="m1.small", image="futuregrid/ubuntu-14.04")
boot a VM with CLI: (note here we use a convenient way to call cloudmesh
shell commands by using cloudmesh.shell, so that we can illustrate our
CLI in ipython notebook)

.. code:: python

    cloudmesh.shell("vm start --cloud=india --flavor=m1.medium --image=futuregrid/ubuntu-12.04")
There are other ways to boot VMs with CLI, for more details about CLI
command vm:

.. code:: python

    print cloudmesh.shell("vm -h")


Deleting virtual machines
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Delete with  a shell command
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: ../../../programs/delete-vm.sh
   :literal:

Delete with python calling a shell command
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. include:: ../../../programs/delete-vm.py
   :literal:

Delete with cloudmesh
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Similar as booting a VM, we can also delete a VM with API and CLI of
cloudmesh. For example, delete a VM with API: (note here you need to
provide the ID of VM to delete. If you want to test this, please follow
the initialization steps of the previous section 'boot with cloudmesh'
first)

.. code:: python

    mesh.delete(cloud="india", server="provvide vm id", username)
delete a VM with CLI:

.. code:: python

    cloudmesh.shell("vm delete --id=provvide vm id --cloud=india --force")
There are other ways to delete VMs with CLI, for more details about CLI
command vm:

.. code:: python

    print cloudmesh.shell("vm -h")


Query to Cloud
----------------------------------------------------------------------

List Flavors
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

API:

.. code:: python

    mesh.flavors(cm_user_id=username, clouds=["india"])
CLI:

.. code:: python

    cloudmesh.shell("list flavor india --refresh")

List Images
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

API:

.. code:: python

    mesh.images(clouds=['india'],cm_user_id=username)
CLI:

.. code:: python

    cloudmesh.shell("list image india --refresh")

List Virtual Machines
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

API:

.. code:: python

    mesh.servers(clouds=['india'],cm_user_id=username)
CLI:

.. code:: python

    cloudmesh.shell("list vm india --refresh")


TO INTEGARTE
======================================================================


cloud0-satrt-vm-simulator.py
----------------------------------------------------------------------

.. include:: ../../../programs/cloud0-satrt-vm-simulator.py
   :literal:


cloud1.py
----------------------------------------------------------------------

.. include:: ../../../programs/cloud1.py
   :literal:

cloud2.py
----------------------------------------------------------------------

.. include:: ../../../programs/cloud2.py
   :literal:

cloud3.py
----------------------------------------------------------------------

.. include:: ../../../programs/cloud3.py
   :literal:

cloud4.py
----------------------------------------------------------------------

.. include:: ../../../programs/cloud4.py
   :literal:


tabel2.py
----------------------------------------------------------------------

.. include:: ../../../programs/tabel2.py
   :literal:

table1.py
----------------------------------------------------------------------

.. include:: ../../../programs/table1.py
   :literal:

table3.py
----------------------------------------------------------------------

.. include:: ../../../programs/table3.py
   :literal:

table4.py
----------------------------------------------------------------------

.. include:: ../../../programs/table4.py
   :literal:

table5.py
----------------------------------------------------------------------

.. include:: ../../../programs/table5.py
   :literal:

table6.py
----------------------------------------------------------------------

.. include:: ../../../programs/table6.py
   :literal:

table7.py
----------------------------------------------------------------------

.. include:: ../../../programs/table7.py
   :literal:

table8.py
----------------------------------------------------------------------

.. include:: ../../../programs/table8.py
   :literal:


