.. _s-cloudmesh-quickstart:

Quickstart on your desktop
============================

A video bout the quickstart instalation is available on |video-cm-install| 

.. sidebar::


.. highlight:: bash

.. role:: red

.. role:: pink

.. important::

   This quickstart will guide you on installing Cloudmesh on your
   local workstation running Ubuntu 14.04 or OSX


.. note:: FutureSystems Portalname and Project ID
          For this example we assume you have set the shell variable
	  PORTALNAME to your FutureSystems portal username. This can
	  be done as follows. Let us assume your portal name is
	  `albert`. Than you can set it with::

              export PORTALNAME=albert

         We also assume that you have a project id that you set to::

              export PROJECTID=fg101
 
         if it is the number 101.


We recommend that you use virtualenv to provide an isolated environment 
for cloudmesh. We assume you create one called ENV and activate it::


  $ virtualenv ~/ENV
  $ source ~/ENV/bin/activate

 .. comment::
 
  The easiset way for users is install cloudmesh from pip with::

  pip install cloudmesh

  (This is not yet fully supported, so you do need the source code installation)
  
If you like to extend cloudmesh we recommend that you
download the following repository into your local copy of github
source code directories. We assume you have git installed::

  $ mkdir github
  $ cd github

  $ git clone https://github.com/cloudmesh/cloudmesh.git

In some cases you may also want to download some other repositories
that are either used by cloudmesh, or are extensions to
cloudmesh. This includes::

  $ git clone https://github.com/cloudmesh/cloudmesh_base.git
  $ git clone https://github.com/cloudmesh/cloudmesh_pbs.git  
  
Next, you need to install a number of required packages with the
following commands::

  $ cd cloudmesh
  $ sudo ./install system
  $ ./install requirements

.. note:: on OSX you can omit the sudo. 

.. note:: OSX installation of python-LDAP may be an issue. You can use
	  the following woraround::

	    pip install python-ldap \
	         --global-option=build_ext \
                 --global-option="-I$(xcrun --show-sdk-path)/usr/include/sasl"
	  
To get access to IaaS cloud platforms, you need to create locally a
new user that has access to various clouds. This can be done with::

  $ ./install new

The next steps will deploy the cloudmesh code into the virtualenv
library path::

  $ ./install cloudmesh


.. note:: This step is optional but highly recommended for users.

   In case you have accounts on the IU machines you can also obtain
   pre-configured cloud rc files from them. To test if you have an account
   and have set it up correctly, please login to the machine india::

     $ ssh $PORTALNAME@india.futuresystems.org

   If this does not work, you may not have uploaded your public key to
   FutureSystems portal at

   * https://portal.futuresystems.org/my/ssh-keys

   Once this step is completed, you can
   create the configuration files as follows::

     $ cm-iu user fetch
     $ cm-iu user create

At this time we like you to edit some information about yourself in
the cloudmesh.yaml file. Choose your favorite editor::

  $ emacs ~/.cloudmesh/cloudmesh.yaml

Change the values marked with TBD that you find here with values that describe
you. 

.. .. todo:: Hyungro: cm "default username=username $PORTALNAME"

.. .. todo:: Hyungro: cm "project fg101"  101 is just a placeholder use your real
	  project id
	  
As you will need at one point to login into virtual machines you will
need a key that cloudmesh can use do to so. We assume you have a
public key generated in your .ssh directory in the file::

  $ ~/.ssh/id_rsa.pub

If you do not have such a key, you can generate it with::

  $ ssh-keygen -t rsa -C $PORTALNAME-key

The next steps will deploy the cloudmesh database::

  $ fab mongo.reset

We add the key to the database with::

   $ cm key add --keyname=$PORTALNAME-key ~/.ssh/id_rsa.pub

where :pink:`PORTALNAME` is your name for the FutuerSystems portal.

You may next need to specify your default project if you have not yet
done so::
   
     $ cm project default $PROJECTID
     
where :pink:`PROJECTID` is your default project id from FutureSystems
e.g. fg456 as an example.
   
To start cloudmesh use::

  $ fab server.start

Now you can test the service by visiting the web interface at
http://127.0.0.1:5000. We have a convenient shortcut for this by
typing:: 

  $ fab server.view

Alternatively you can use the cloudmesh shell by invoking the cm
command via a terminal::

  $ cm
  
  ======================================================
  / ___| | ___  _   _  __| |_ __ ___   ___  ___| |__
  | |   | |/ _ \| | | |/ _` | '_ ` _ \ / _ \/ __| '_ \
  | |___| | (_) | |_| | (_| | | | | | |  __/\__ \ | | |
  \____|_|\___/ \__,_|\__,_|_| |_| |_|\___||___/_| |_|
  ======================================================
  Cloudmesh Shell
  
  cm> cloud
  +--------------------------+----------+
  | cloud                    | active   |
  +==========================+==========+
  | alamo                    |          |
  +--------------------------+----------+
  | aws                      |          |
  +--------------------------+----------+
  | azure                    |          |
  +--------------------------+----------+
  | dreamhost                |          |
  +--------------------------+----------+
  | hp                       |          |
  +--------------------------+----------+
  | hp_east                  |          |
  +--------------------------+----------+
  | india_eucalyptus         |          |
  +--------------------------+----------+
  | india                    |          |
  +--------------------------+----------+
  | sierra_eucalyptus        |          |
  +--------------------------+----------+
  | sierra                   |          |
  +--------------------------+----------+

  cm> cloud on india
  ...
  cloud 'india' activated.

  cm> flavor india --refresh
  ...
  Refresh time: 0.190665006638
  Store time: 0.0578060150146
  +--------+------+--------------+---------+-------+--------+----------------------+
  | CLOUD  |   id | name         |   vcpus |   ram |   disk | cm_refresh           |
  |--------+------+--------------+---------+-------+--------+----------------------|
  | india |    1 | m1.tiny      |       1 |   512 |      0 | 2014-08-26T01-15-20Z |
  | india |    3 | m1.medium    |       2 |  4096 |     40 | 2014-08-26T01-15-20Z |
  | india |    2 | m1.small     |       1 |  2048 |     20 | 2014-08-26T01-15-20Z |
  | india |    4 | m1.large     |       4 |  8192 |     40 | 2014-08-26T01-15-20Z |
  | india |    7 | m1.memmedium |       1 |  4096 |     20 | 2014-08-26T01-15-20Z |
  | india |    6 | m1.memlarge  |       1 |  8192 |     20 | 2014-08-26T01-15-20Z |
  +--------+------+--------------+---------+-------+--------+----------------------+


Commands without description
----------------------------------------------------------------------


This script assumes that you have a key in::

  $ ~/.ssh/id_rsa.pub

Which will be used to log into the VMs and the machines. This key must
be uploaded to the FutureSystems portal.


For ubuntu use
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

  $ git clone https://github.com/cloudmesh/cloudmesh.git
  $ virtualenv ~/ENV
  $ source ~/ENV/bin/activate
  $ cd cloudmesh
  $ sudo ./install system
  #
  # The command requires input
  #
  $ ./install requirements
  $ ./install new
  $ ./install cloudmesh
  $ cm-iu user fetch --username=$PORTALNAME
  $ cm-iu user create
  $ fab mongo.reset
  #
  # The command requires input
  #
  $ fab server.start
  $ cm project default $PROJECTID  
  $ cm cloud list
  $ cm cloud on india
  $ cm flavor india --refresh


For OSX use
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

  #
  # make sure you installed xcode and do xcode-select --install
  #
  $ git clone https://github.com/cloudmesh/cloudmesh.git
  $ virtualenv ~/ENV
  $ source ~/ENV/bin/activate
  $ cd cloudmesh
  $ ./install system
  #
  # The command requires input
  #  
  $ ./install requirements
  $ ./install new
  $ ./install cloudmesh
  $ cm-iu user fetch --username=$PORTALNAME
  $ cm-iu user create
  $ fab mongo.reset
  #
  # The command requires input
  #
  $ fab server.start
  $ cm project default $PROJECTID
  $ cm cloud list
  $ cm cloud on india
  $ cm flavor india --refresh


.. _ref-cloudmesh-quickstart-system-install-curl:

One line install with curl
----------------------------------------------------------------------

.. warning:: This method is experimental, please give us feedback. 
 
This script can also be executed while getting it from our convenient
installation script repository. For ubuntu you can use::

  $ curl https://raw.githubusercontent.com/cloudmesh/get/master/cloudmesh/ubuntu/14.04.sh | bash 

This will do the following:

- update package listing
- install `systems dependencies <https://github.com/cloudmesh/get/blob/master/cloudmesh/system-dependencies.csv>`_
- create a virtual env in ``$HOME/ENV`` (specify ``venv`` to override
  default)
- installs cloudmesh and python dependencies via ``pip``
- clones the cloudmesh repository into a ``./cloudmesh`` directory
  (specify ``cloudmeshdir`` to override)
- populates ``~/.cloudmesh``


One line configure with curl
----------------------------------------------------------------------

After cloudmesh and dependencies have been installed, use the
following to do the initial configuration.

.. note:: This only needs to be run once on each system

::
   
   $ curl https://raw.githubusercontent.com/cloudmesh/get/master/cloudmesh/configure.sh | portalname=albert projectid=fg101 bash

This will:

- call ``cm-iu user fetch``
- call ``cm-iu user create``
- generate the database (``fab {mongo.boot,user.mongo,mongo.simple}``)
- set the default project id to ``$projectid``.


One line start with curl
----------------------------------------------------------------------

At this point you will want to start the cloudmesh services::

  $ curl https://raw.githubusercontent.com/cloudmesh/get/dev/cloudmesh/start.sh | bash

This:

- assumes that cloudmesh repo is located in ``./cloudmesh`` (specify
  ``cloudmeshdir=path/to/local/repo`` to override)
- starts the cloudmesh server (``fab server.start``)
- updates the clouds from ``india`` (``cm {cloud,flavor}``)



Tips
----------------------------------------------------------------------

If you lost the cursor on your terminal, you can use the command::

   $ reset 

to bring the terminal in its default settings.

.. |video-image| image:: /images/glyphicons_402_youtube.png 
.. |video-cm-install| replace:: |video-image| :youtube:`lGiJifD0VgU`
