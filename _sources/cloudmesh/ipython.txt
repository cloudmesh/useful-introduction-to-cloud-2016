.. _cloudmesh-ipython-ref:

IPython on Cloudmesh
======================================================================

IPython is an interactive shell of Python programming language with additional
features such as tab completion, rich history, introspection, magic functions,
and a web-based interface Notebook. bpython and DreamPie also provide enhanched
Python shell compared to the default Python console. IPython Notebook offers
web-based code development toolkit with plotting and media streaming libraries.

Cloudmesh includes IPython shell and Notebook to offer interactive Python shell
capabilities on a command-line and a web browser. Running IPython on Cloudmesh
gives you a chance to try Python code development with convenient toolkits. The
open-source scientific software SciPy runs with IPython for data processing and
plotting analysis results. Additional modules are also included such as
matplotlib and numpy to support scientific computing with Python.

Start IPython Console
-------------------------------------------------------------------------------

IPython console is installed with Cloudmesh. Try IPython console::

  $ ipython
  Python 2.7.6 (default, Mar 22 2014, 22:59:56) 
  Type "copyright", "credits" or "license" for more information.

  IPython 2.2.0 -- An enhanced Interactive Python.
  ?         -> Introduction and overview of IPython's features.
  %quickref -> Quick reference.
  help      -> Python's own help system.
  object?   -> Details about 'object', use 'object??' for extra details.

  In [1]: 

Hello Albert!
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Try a simple example of Python::

  In [1]: name="Albert"

  In [2]: print ("Hello "+name+"!")
  Hello Albert!

System command
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Add `!` to your system command to run it on IPython console::

  In [3]: !echo $name
  Albert


You can mix with other system command, for example::

  In [4]: !echo $name on `hostname`
  Albert on cloudmesh-dev1

Import Cloudmesh API
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Like a standard Python shell, importing Cloudmesh is simple in IPython Console.

::

  In [5]: import cloudmesh

  In [6]: cloudmesh.shell("help")
  Documented commands (type help <topic>):
  ========================================
  EOF      dot2      info       loglevel  py              stack    version
  admin    edit      init       man       q               status   vm     
  banner   exec      inventory  metric    quit            storm    volume 
  clear    exp       key        notebook  quota           timer    web    
  cloud    flavor    label      nova      rain            usage    yaml   
  cluster  graphviz  launcher   open      register        use    
  color    group     limits     pause     script          user   
  debug    help      list       plugins   security_group  var    
  default  image     load       project   ssh             verbose

  Ipython Commands
  ================
  notebook

  Gui Commands
  ============
  web

  Ssh Commands
  ============
  ssh

  Cloud Commands
  ==============
  admin    default  init       list      quota           stack   user    project
  cloud    flavor   inventory  loglevel  rain            status  vm    
  cluster  group    launcher   metric    register        storm   volume
  debug    image    usage      nova      security_group  usage   keys  


Try listing clouds using the Cloudmesh module::

  In [7]: cloudmesh.shell("cloud list")
  +-----------+--------+
  | cloud     | active |
  +-----------+--------+
  | aws       |        |
  | azure     |        |
  | devstack  |        |
  | dreamhost |        |
  | hp        |        |
  | hp_east   |        |
  | india     | True   |
  +-----------+--------+

Starting IPython Notebook
-------------------------------------------------------------------------------

We use a `cm` command to start IPython Notebook.

On a Linux shell::

  $ cm notebook start

On a IPython console::

  In [1]: import cloudmesh

  In [2]: cloudmesh.shell("notebook start")

Reference
----------------------------------------------------------------------

* IPython: http://ipython.org/
* bpython: http://www.bpython-interpreter.org/
* DreamPie: http://www.dreampie.org/
* SciPy: http://www.scipy.org/
* NumPy: http://www.numpy.org/
* matplotlib: http://matplotlib.org/
