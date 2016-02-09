Ecosystem
===================================================================

virtualenv
----------------------------------------------------------------------

Often you have your own computer and you do not like to change its
environment to keep it in prestine condition. Python comes with mnay
libraries that could for example conflict with libraries that you have
installed. To avoid this it is bets to work in an isolated python
environment while using virtualenv,. Documentation about it can be
found at::

* http://virtualenv.readthedocs.org/

The installation is simple once you have pip installed. If it is not
installed you can say::

  $ easy_install pip

After that you can install the virtual env with::

  $ pip install virtualenv

To setup an isolated environment for example in the directory ~/ENV
please use::

  $ virtualenv ~/ENV

To activate it you can use the command::

  $ source ~/ENV/bin/activate

you can put this command n your bashrc or bash_profile command so you
do not forget to activate it.



pypi
----------------------------------------------------------------------
The Python Package Index is a large repository of software for the
Python programming language containing a large number of packages
[link]. The nice think about pipy is that many packages can be
installed with the program 'pip'.

To do so you have to locate the <package_name> for example with the
search function in pypi and say on the commandline::

    pip install <package_name>

where pagage_name is the string name of the package. an example would
be the package called fabric which you can install with::

   pip install fabric
 
If all goes well the package will be installed.

github
----------------------------------------------------------------------


Github is a code repository that allows the development of code in a
distributed fashion. There are many good tutorials about github.

Some of them can be found on the github Web page. An interactive
tutorial is for example available at

* https://try.github.io/

A more extensive list of tutorials can be found at 

*
https://help.github.com/articles/what-are-other-good-resources-for-learning-git-and-github

Important is that you always want to make sure that you want to use
the git init command and add your Name and e-mail. Do it consistent in
the machines you use, or your checkins in git (if you do them) do not
show up in a consistant fashion as a single user. This is done with
the following commands::

  $ git config --global user.name "John Doe"
  $ git config --global user.email johndoe@example.com

You can set also the editor with::

  $ git config --global core.editor emacs

More information about a first time setup is documented at::

  $ http://git-scm.com/book/en/Getting-Started-First-Time-Git-Setup

To check your setup you can say::

  $ git config --list

Python resources
======================================================================

There is a rich set of resources related to python programming on the
internet. Some resources that we found useful include:

* http://ivory.idyll.org/articles/advanced-swc/

* http://python.net/~goodger/projects/pycon/2007/idiomatic/handout.html

* http://www.youtube.com/watch?v=0vJJlVBVTFg

The following have been found useful by previous students. However
there may be much better resources out there.

* http://www.korokithakis.net/tutorials/python/

and here is one that you can do on a web browser in case you have not
installed python on your computer

* http://www.afterhoursprogramming.com/tutorial/Python/Introduction/

