Nosetests
=========

.. highlight:: bash

If you would like to verify installation and other features of Cloudmesh, 
we provide couple of nosetests to make sure that you have working Cloudmesh.
These test cases perform several tasks towards Cloudmesh installation, vm
creation, termination and others on cm console, cm API, and cm shell.

What does the test involve?
----------------------------
For API, shell, and cm, the nosetests checks activation, list, refresh, start
, stop and other features of vm instances. With these tests, we can assure 
that Cloudmesh users can start or stop vm instances on any interfaces
including web gui. The nosetest for the installation does perform actual 
process of the installation so all the required packages and files will be 
re-installed and re-configured.

Installation
------------------

.. warning:: your $HOME/.cloudmesh and packages will be re-installed.

Try to run the following command::

  $ nosetests -v --nocapture ~/cloudmesh/tests/test_cm.py


API
---

Try to run the following command::

  $ nosetests -v --nocapture ~/cloudmesh/tests/test_cm_api.py

cm shell
--------

Try to run the following command::

  $ nosetests -v --nocapture ~/cloudmesh/tests/test_cm_shell.py

cm console
----------

Try to run the following command::

  $ nosetests -v --nocapture ~/cloudmesh/tests/test_cm_console.py
  
vm test
-------

This nosetest performs 14 tests regarding vm management.
It includes::

  - activation test (`cloud on CLOUDNAME`)
  - vm creation (`vm start`)
  - vm list (`vm list`)
  - vm deletion (`vm delete`)
  
Try to run the following command::

  $ nosetests -v --nocapture ~/cloudmesh/tests/test_cm_console_ext.py
