Installing Django
======================================================================

..
	????? Install SQLite on Ubuntu Machine (if you haven't already) Go to
	www.sqlite.org/download.html and download the sqlite-shell-linux
	Extract download to your respective directory

.. warning::

To install django you simply call::       

   $ pip install django
   
Starting Up Django
=========================================================================

To stat a new django web site you can use the following commands::
       
	$ django-admin.py startproject example_site 
        $ cd example_site
        $ python manage.py syncdb
        
This will give you an ask you for some user information similar to::

  python manage.py syncdb
  Creating tables ...
  Creating table django_admin_log
  Creating table auth_permission
  Creating table auth_group_permissions
  Creating table auth_group
  Creating table auth_user_groups
  Creating table auth_user_user_permissions
  Creating table auth_user
  Creating table django_content_type
  Creating table django_session

  You just installed Django's auth system, which means you don't have any superusers defined.
  Would you like to create one now? (yes/no): yes
  Username (leave blank to use 'albert'): 
  Email address: albert@example.com
  Password: 
  Password (again): 
  Superuser created successfully.
  Installing custom SQL ...
  Installing indexes ...
  Installed 0 object(s) from 0 fixture(s)


.. note::

  The user albert is just our example user, please replace it with the
  username you like. Please chose a responsible password


Next you will need to run the server::    
        
        
        $ python manage.py runserver

in browser do 

http://127.0.0.1:8000/

If you get the following prompt::
	
	It worked! Congratulations on your first Django-powered page.

	Of course, you haven't actually done any work yet. Next, start your first app by running python manage.py startapp [appname].
	You're seeing this message because you have DEBUG = True in your Django settings file and you haven't configured any URLs. Get to work!

Then you have successfully accessed the database. 

To browse if the server is running on your web browser, enter this url and then login::

  http://127.0.0.1:8000/admin

	
	

