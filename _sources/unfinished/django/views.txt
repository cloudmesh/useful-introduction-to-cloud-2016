Example: Views
=========================================================================

Description
-----------------------------------------------------------------

This example demonstrates how to setup a View in django with the bootstrapped 
theme.

In order to write a view in Django do the following::
	
	cd exampleapp
	texteditor views.py
	
In views.py in your app, write your view::
	
	from django.http import HttpResponse
	def index(request):
		return HttpResponse("You got it!")
		
Now go to your individual project and configure your urls.py file::
	
	url(r'^exampleapp/$', 'exampleapp.views.index', name = 'index'),
	
Now do a ``python manage.py syncdb`` and then do a ``python manage.py runserver``
and you should be able to type in ``/exampleapp`` behind the local Host address and 
receive the message above. 


Ready Made Example
-----------------------------------------------------------------------

A ready made example for you is contained in the directory
``management/django/views``. Please cd into the directory.

In this directory you will also find a Makefile that you can use to
execute the above steps. To start the server, you can say::

  make start

To view the web pages, say::

  make view
.. note::
	After clicking on http://127.0.0.1.8000/, go to http://127.0.0.1.8000/admin
	then type ../index in the URL

In case you need to recreate the server please say::

  make create

To cleanup you say::

  make clean

To stop the server please say::

  make stop

The steps are implicitly included in the makefile

.. include:: ../../../django/views/Makefile
   :literal:
  
  
  
Tips:
---------------------------------------------------------------------

If you don't want to display the plain view and 
want the bootstrapped theme (further explained in Templates example), uncomment 
``return render(request, 'views_html',)`` and comment out 
``return HttpResponse ("You got it!")`` in the ``views.py`` file. In the 
``views_app``, uncomment ``STATIC_ROOT`` in the ``settings.py`` file
in ``../views/views``. Then run::
	
	make start
	make static
	make view
