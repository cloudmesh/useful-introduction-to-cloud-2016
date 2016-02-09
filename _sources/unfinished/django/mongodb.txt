Example: Mongodb
==================================================================

Description
-----------------------------------------------------------------
This is an example of out to setup a succesfully mongodb server


* This same information and more can be obtained at
  http://django-mongodb-engine.readthedocs.org/en/latest/index.html

Make sure you are in virtualenv, if not do the following::
	
	pip install virtualenv
	virtualenv myproject
	source myproject/bin/activate
	
Now install ``Django-nonrel``, ``djangotoolbox``,
and ``Django MongoDB Engine`` to your system::
	
	pip install git+https://github.com/django-nonrel/django@nonrel-1.5
	pip install git+https://github.com/django-nonrel/djangotoolbox
	pip install git+https://github.com/django-nonrel/mongodb-engine
	
In order to get you ``SITE_ID``	in your project do a::
	
	python ./manage.py shell
	>>> from django.contrib.sites.models import Site
	>>> Site().save()
	
Then do a::
	
	Site.objects.all()[0].id
	u'your_number_here'
	
Now go into your project's ``settings.py`` file and go to the
``DATABASES ()`` and ``SITE_ID`` function and add the following::
	
	DATABASES = {
		'default' : {
			'ENGINE' : 'django_mongodb_engine',
			'NAME' : 'my_database'
		}
	}
	............
	SITE_ID = 'your_number_here'
	
Then run a ``python manage.py syncdb`` and a ``python manage.py
runserver`` and then you should be connected.

* If you want the bootstrapped theme, do a ``pip install
  django-admin-bootstrapped`` and add ``'django_admin_bootstrapped',``
  before the ``django.contrib.admin`` app in the ``INSTALLED _APPS``
  list.



Ready Made Example
---------------------------------------------------------------------------

A ready made example for you is contained in the directory
``management/django/mongo1``. Please cd into the directory.

In this directory you will also find a Makefile that you can use to
execute the above steps. To start the server, you can say::

  make start

To view the web pages, say::

  make view

.. note:: After clicking on http://127.0.0.1.8000/, go to
          http://127.0.0.1.8000/admin

In case you need to recreate the server please say::

  make create

To cleanup you say::

  make clean

To stop the server please say::

  make stop

The steps are implicitly included in the makefile

.. include:: ../../../django/mongodb/Makefile
   :literal:

.. error::
   BUG THE MAGEFILE DOES NOT SHOW
  
