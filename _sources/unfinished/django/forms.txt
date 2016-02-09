Example: Forms
=====================================================================

Description
---------------------------------------------------------------------
This example demonstrates how to make a simple form in a bootstrapped theme template django application. 

Create an Django application first by doing a::
	
	django-admin.py startproject projectname
	cd projectname
	python manage.py startapp appname 
	
.. note::
	This example can be seen http://www.pythoncentral.io/how-to-use-python-django-forms/
	
In your application, create a ``forms.py`` file in your appname directory. In your forms file, do the following::
	
	from django import forms
	
	class PostForm(forms.Form):
	    content  = forms.CharField(max_length=256)
	    created_at = forms.DateTimeField()
	    
Now in your ``views.py`` file, do the following::
	
	from myblog.forms import PostForm
	
	def post_form_upload(request):
	    if request.method == 'GET':
	        form = PostForm()
	    else:
	        # A POST request: Handle Form Upload
	        form = PostForm(request.POST) # Bind data from request.POST into a PostForm
	        
	        # If data is valid, proceeds to create a new post and redirect the user if form.is_valid():
	            content = form.cleaned_data['content']
	            created_at = form.cleaned_data['created_at']
	            post = m.Post.objects.create(content = content, 
	            				 created_at = created_at)
	            return HttpResponseRedirect(reverse('post_detail',
	            					kwargs = {'post_id': post.id}))
	      
	       return render(request, 'post/post_form_upload.html', {'form': form,})
	
Now in your templates directory, create a template for the form to posted on the server::
	
	{% extends "base.html" %}
	
	{% block content %}
	<form action='/post/form_upload.html' method='post'>{% csrf_token %}
	{{ form.as_p }}
	<input type='submit' value='Submit' />
	</form>
	{% endblock %}
	
Then in your project directory, access the ``urls.py`` file, and attached this url pattern to it::
	
	urlpatterns = patterns('',
	    ...
	    url(r'^post/form_upload.html$', 'appname.views.post_form_upload', name= 'post_form_upload'),
	    ...
	)
	
Now, when starting up your server, type after the server number ``/post/form_upload.html`` and you should then see your form up and running


Ready Made Example
----------------------------------------------------------------------
A ready made example for you is contained in the directory ``management/django/forms1``. Please cd into the directory.

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
