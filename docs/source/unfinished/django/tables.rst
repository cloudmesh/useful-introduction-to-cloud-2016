Examples: Tables in Django (with Mongodb as a backend)
=======================================================================

Description
-----------------------------------------------------------------------

This is an example of how to create a Table in Django with mongodb as a 
backend

.. note::
	Follow previous tutorials in order to have a bootstrapped theme
	table
	
In your ``settings.py`` file in your Django Project, do a ``pip install django-tables2`` and then add ``'django_tables2'`` to your ``INSTALLED_APPS`` function.  Finally add ``'django.core.context_processors.request'`` to ``TEMPLATE_CONTEXT_PROCESSORS``. 
	
In your ``templates`` directory, make your desired html file and let it have
this format at the top::
	
	{% extends "base.html" %}
	{% load render_table from django_tables2 %}

Now the body of the html should be enclosed with ``{% block content %}`` & ``{% endblock %}``
tags. Similar to below::
	
	{% block content %}
		<!doctype html>
		<html>
			<head>
				<link rel="stylesheet" href="{{ STATIC_URL }}django_tables2/themes/paleblue/css/screen.css" />
			</head>
			<body>
				{% render_table table %}
			</body>
		</html>

	{% endblock %}
	
Now go into your app (see previous tutorial on creating apps) and go to your 
``models.py`` file and do the following::
	
	from django.db import models
	import django_tables2 as tables

	class Person(models.Model):
		name = models.CharField(max_length=200)
		
Now create a ``tables.py`` file in your app and in the file write this::
	
	import django_tables2 as tables
	from tables_app.models import Person


	class PersonTable(tables.Table):
		name = tables.Column(verbose_name = "full name")

	class Meta:
       		model = Person
       		attrs = {"class": "paleblue"}

       	class NameTable(tables.Table):
       		name = tables.Column()
       		ID = tables.Column()
       		
Now go to your ``views.py`` file and write the following commands::
	
	from django.shortcuts import render
	from django_tables2   import RequestConfig
	from tables_app.models  import Person
	from tables_app.tables  import PersonTable
	from tables_app.tables import NameTable

	def people(request):
	
	data = [
    		{"name": "Bradley", "ID": 1},
    		{"name": "Stevie", "ID" : 2},
	]	

	table = NameTable(data)
	RequestConfig(request).configure(table)
	return render(request, "tables_example.html", {'table': table})
	
Now make sure that in the project folder, that your ``urls.py`` is connected to 
your newly created view and you should see a table when you type 
http://127.0.0.1.8000/people !


Ready Made Example
-------------------------------------------------------------------------

A ready made example for you is contained in the directory
``management/django/tables``. Please cd into the directory.

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

.. include:: ../../../django/tables/Makefile
  :literal:

