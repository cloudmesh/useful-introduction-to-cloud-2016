Examples: Models
=========================================================================

Description
---------------------------------------------------------------------------
.. note::

	This example demonstrates how to setup a model using the Django 
	bootstrapped theme. 

First, cd into your project in the terminal and type the following::
	
	$ python manage.py startapp exampleapp
	$ cd exampleapp
	$ texteditor models.py
	
Here's an example of a modified models.py file in exampleapp::
	
	from django.db import models
	from django.utils.encoding import smart_unicode

	# Create your models here.

	class SignUp(models.Model):
	first_name = models.CharField(max_length=120, 
				      null =True, 
                                      blank=True)
	last_name = models.CharField(max_length=120, 
                                     null =True, 
                                     blank=True)
	email = models.EmailField()
	timestamp = models.DateTimeField(auto_now_add=True, auto_now=False)
	
	def __unicode__(self):
		return smart_unicode(self.email)
		
After modifying go to ``$ texteditor admin.py`` and modify the file. 
Here's an example::
	
	from django.contrib import admin

	# Register your models here.
	from .models import SignUp

	class SignUpAdmin(admin.ModelAdmin):
		class Meta:
			model =SignUp
		
	admin.site.register(SignUp, SignUpAdmin)
	
Now go into your django project and do the following::
	
	$ texteditor settings.py 
	.. Add newly created app to INSTALLED_APPS
	INSTALLED_APPS = (
	'django_admin_bootstrapped',
	.....
	.....
	'exampleapp',
	)
	
	
	
Now do a ``python manage.py syncdb`` and ``python manage.py runserver`` and you 
should see your django-bootstrapped theme with model working!


Ready made example
-----------------------------------------------------------------------------

A ready made example for you is contained in the directory
``management/django/models``. Please cd into the directory.

In this directory you will find a Makefile that you can use to execute the 
above steps. To start the server you can say:: 

	make start

To view the web pages, say::

	make view
.. note::
	After clicking on http://127.0.0.1.8000/, go to http://127.0.0.1.8000/admin
	then type ../index in the URL. 

In case you need to recreate the server please say::

	make create

To cleanup you say::

	make clean

To stop the server please say::

	make stop

The steps are implicitly included in the makefile

.. include:: ../../../django/models/Makefile
  :literal:



	

