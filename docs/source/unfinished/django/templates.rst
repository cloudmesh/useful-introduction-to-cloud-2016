Example: Template 
===================================================================

Description
----------------------------------------------------------------------
This example demonstrates how to setup a template in django with a 
bootstrapped theme

Create an app ``python manage.py startapp exampleapp_name``

Then, In project do the following::
	
	mkdir templates 
	mkdir static
	cd exampleproject
	texteditor settings.py
	
In the ``settings.py`` file go to ``TEMPLATE_DIRS ()``,
``TEMPLATE_LOADERS ()``, ``STATIC_ROOT``,
and ``TEMPLATE_CONTEXT_PROCESSORS``functions and write the path to the
templates folder you just created and add these parameters to
``TEMPLATE_LOADERS ()``::
	
	TEMPLATE_CONTEXT_PROCESSORS = (
		'django.contrib.auth.context_processors.auth',
		'django.core.context_processors.debug',
		'django.core.context_processors.i18n',
		'django.core.context_processors.media',
		'django.core.context_processors.static',
		'django.core.context_processors.tz',
		'django.contrib.messages.context_processors.messages',
	)
	..........
	TEMPLATE_LOADERS = (
		'django.template.loaders.filesystem.Loader',
		'django.template.loaders.app_directories.Loader',
	)
	.........
	TEMPLATE_DIRS = (
		'/home/django/examplesite/templates',
	)
	..........
	STATIC_URL = (
		'/static/',
	)
	..........
	STATIC_ROOT = '/home/django/example/static/'
	
Now go to your newly created Template directory and create a file named ``base.html``.
In this file, copy and paste the html from your desired template from the 
``http://getbootstrap.com`` website or your own created html

1) View the source code of your chosen template and click on the link below
``<! -- Bootstrap core.css -->`` and ``<!-- Custom styles for this template -->``

2) After clicking on both of these links - right-click on the page of the code 
and choose ``save as`` and save files to css folder in static directory 

Repeat Steps 1 and 2 with the link at the bottom of the source code (Below
``<!-- Placed at the end of the document so the pages load faster -->``)
and save in js folder in static directory. 


	
Now go back to the ``base.html`` file and create the section ``{% block content %}``
and ``{% endblock %}`` (for syntax go to www.djangobook.com/en/2.0/chapter04.html)

In the templates directory, create another html file and in the file do the 
following::
	
	{% extends "base.html" %}
	
	{% block content %} The template works! {% endblock %}
	
Now go into your app and create your view::
	
	from django.shortcuts import render 
	 
	def index(request):  
		return render(request, 'your_html_file.html',)
		
Now go into your templates directory and go to your ``base.html`` file and add
the paths to your created files in the static folder for both css and js. For example::
	
	<link href = "/static/css/boostrap.min.css" rel="stylesheet">
	<link href = "/static/css/specified_template_used.css" rel="stylesheet">
	
	<script src="/static/js/jquery.min.js"></script>
	<script src="/static/js/bootstrap.min.js"></script>
		
Now go into your project's ``urls.py`` file and do the following::
	
	url(r'^index/', 'exampleapp_name.views.index', name = 'index')
	
Then finally do a ``python manage.py collectstatic`` and type yes to the prompt
and then run ``python manage.py runserver``. 

Ready Made Example (used css and js files from django-admin-bootstrapped)
----------------------------------------------------------------------------------
	
A ready made example for you is contained in the directory
``management/django/templates1``. Please cd into the directory.

In this directory you will also find a Makefile that you can use to
execute the above steps. To start the server, you can say::

  make start

To view the web pages, say::

  make view

.. note:: After clicking on http://127.0.0.1.8000/, go to http://127.0.0.1.8000/admin
   then type ../index in the URL

In case you need to recreate the server please say::

  make create

To cleanup you say::

  make clean

To stop the server please say::

  make stop

The steps are implicitly included in the makefile

.. include:: ../../../django/templates/Makefile
   :literal:
  
.. error::
   BUG THE MAGEFILE DOES NOT SHOW
  
Tips
----------------------------------------------------------------
.. note::
	Because this is not a django template, the steps are a bit different
	in the description but do not differ much. Instead of adding static 
	to the ``link ref`` you just take it away so that it's ``css`` or ``js``.

