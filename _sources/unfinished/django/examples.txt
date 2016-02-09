
Example: Simple
======================================================================

Description
----------------------------------------------------------------------

This example demonstrates how to setup a very elementary Django
application.


To do this from scratch you have to execute the following commands::

     export PROJECT=simple
     mkdir $PROJECT
     django-admin.py startproject $PROJECT
     cd $PROJECT
     python manage.py syncdb
     python manage.py runserver

To view the server open your web browser at::

     http://127.0.0.1:8000/admin


Ready made example
----------------------------------------------------------------------

A ready made example for you is contained in the directory
``management/django/simple``. Please cd into the directory.

In this directory you will also find a Makefile that you can use to
execute the above steps. To start the server, you can say::

  make start

To view the web pages, say::

  make view

In case you need to recreate the server please say::

  make create

To cleanup you say::

  make clean

To stop the server please say::

  make stop

The steps are implicitly included in the makefile

.. include:: ../../../django/simple/Makefile 
   :literal:


Tips
----------------------------------------------------------------------

Tips for running   

start::

   cd django/simple/simple
   python manage.py syncdb
   python manage.py runserver

View::
   
   firefox http://127.0.0.1:8000/

Cleanup::

  rm db.sqlite3 
