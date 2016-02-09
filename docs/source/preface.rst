Preface
======================================================================

Conventions
----------------------------------------------------------------------

.. role:: pink

.. highlight:: bash

:pink:`$`
    When showing examples of commands, the :pink:`$` symbol precedes the
    actual command. So, the other lines are the output obtained after
    executing the command. An example invoking the ls command
    follows::

       $ ls

:pink:`PORTALNAME`
    In some examples we refer to your portal name as the :pink:`PORTALNAME`
    you have on FutureSystems.

:pink:`USERNAME`
    In some examples we refer to your local computers name as
    :pink:`USERNAME`. Your portal name and your local name may be
    different.

Menu selections:
    :menuselection:`Start --> Programs`

Man page:
    :manpage:`ls(1)`

Blocks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. hint:: This is an important hint.

	   |info-image| Hints are represented in simple blocks that are
	   distinguished from the main text


.. |info-image| image:: images/glyphicons_195_circle_info.png 

Using the Notebooks
----------------------------------------------------------------------

The material provided in this documentation contains a number of
IPython notebooks. Naturally, you do not have to do that, but it may
provide you with an easy way to try and run the examples. These
notebooks can be executed or accessed through the IPython notebook. We
recommend that you set up the cloudmesh server software on the machine
where you run the iPython notebooks on. If it is your desktop or
Laptop, you can follow the instructions given in the quickstart setup
guide.

However, before you can use them you also have to download and install
cloudmesh on the machine where you will be running the notebooks
from. The installation of cloudmesh is documented elsewhere in this document.

In addition you will need to install the notebook documents locally.
You need to run the notebook server from the directory that contains this
material. This can be easily checked out from git hub in the following
way::

  $ git clone git@github.com:cloudmesh/introduction_to_cloud_computing.git

One you have downloaded the learning documentation form github, you
need to cd into the directory with::

  $ cd introduction_to_cloud_computing 

Install additional requirements with requirements::

    $ pip install -r requirements.txt

Next you have to compile the information with::

   $ fab doc.html

Now you can start the notebook server with::

  $ fab doc.notebook

You can now visit them and execute them. To view the information
locally you can say::

  $ fab doc.html

A link to the list of notebooks will be provided in the sidebar menu.
