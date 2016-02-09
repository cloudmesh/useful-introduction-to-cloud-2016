Environment Modules (modules) on FutureSystems
===============================================================================

If you need to use ``nova`` client tool on India FutureSystems?  Try ``module
load openstack``. It will automatically enable ``nova`` client tool on your
terminal.  While you are using ``nova`` client tool, you may want to switch
other versions of ``nova``.  It is also possible with the environment modules.
Try ``module unload openstack`` and ``module load novaclient``. It will enable
old version of ``nova`` client on your terminal. Environment Modules is a tool
to set environment variables such as $PATH, $MANPATH or $LD_LIBRARY_LOAD on
your terminal. With this changes, your can choose appropriate environments for
your application. This is useful to use different versions of compilers or
programs e.g. Python, MPI, or gcc. 

Overview
----------------------------------------------------------------------

Modules
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Tutorial I: list modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``module avail``

Select module
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``module load``

Examples
~~~~~~~~~~~~~~

* Try to combine two modules. Load both ``nova`` client and ``heat`` client.

Reference
~~~~~~~~~~

`Modules official site <http://modules.sourceforge.net/>`_

Next Step
---------

In the next page, we learn 

``_
