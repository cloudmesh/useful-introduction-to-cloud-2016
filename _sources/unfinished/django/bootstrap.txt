Example: Bootstrap1
==============================================================================

Description 
-----------------------------------------------------------------------------

This example demonstrates how to setup the Bootstrap theme to the newly Django
server.

To do this from scratch you have to execute the following steps/commands::
	
	pip install django-admin-bootstrapped
	Add ``'django_admin_bootstrapped'`` in the ``INSTALLED_APPS ()`` 
	before ``'django.contrib.admin'``
	
	
Ready Made Example
------------------------------------------------------------------------------

A ready made example for you is contained in the directory 
``management/django/bootstrap1``. Please cd into the directory.

In this directory you will also find a Makefile that you can use to execute
the above steps.  To start the server, you can say::
	
	make start

To view the web pages, say::

	make view
.. note::
	After you click on http://127.0.0.1.8000/, go to http://127.0.0.1.8000/admin
	
In case you need to recreate the server please say::

	make create

To cleanup you say::

	make clean

To stop the server please say::

	make stop

The steps are implicitly included in the makefile

.. include:: ../../../django/bootstrap1/Makefile
  :literal:
