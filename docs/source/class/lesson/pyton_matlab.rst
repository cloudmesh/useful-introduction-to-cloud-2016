Calling Python from matlab
======================================================================

In some cases it may be needed that you call python from within
matlab. To test it we use s simple python function.  Let us assume you
have cloudmesh_base installed previously in a terminal via::

  $ pip install cloudmesh_base

Next let us start matlabfrom the terminal with the command::

  $matlab

Once the matlab IDE comes up, let us find out which version of python
is callable. To do so please type::

   >> pyversion

You will get a response such as::
 
    version: '2.7'
    executable: '$HOME/ENV/bin/python'
    library: '/usr/lib/libpython2.7.dylib'
    home: '$HOME/ENV'
    isloaded: 1

Make sure the version of python is as you expect.

Now we can call the banner function included in cloudmesh_base as
follows. First e need to import the module, than we need to just call
the function::

  >> import py.cloudmesh_base.util.banner
  >> banner('hallo')

The output will be::

# ####################################################
# hallo
# ####################################################

For more information of python matlab integration see:

* http://www.mathworks.com/help/matlab/getting-started_buik_wp-3.html
