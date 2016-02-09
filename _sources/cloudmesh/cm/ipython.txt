Install IPython Server
----------------------------------------------------------------------

Cloudmesh contains a convenient mechanism to set up an IPython web server.
The server will run on port 8888 of your vm. It will install in your
environment a notebook directory in ~/notebook. Here you can place
your ipython notebooks. initially this directory will be empty.

You create the notebook server with::

   cm notebook create

You start the notebook server with ::

   cm notebook start

You can terminate the notebook server with::

   cm notebook kill

When terminating, make sure you saved your notebooks. You can restart
the server in case you need to run it again.
