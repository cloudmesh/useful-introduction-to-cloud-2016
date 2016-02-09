Setup Cloudmesh in an VirtualBox VM with Vagrant for Testing
==============================================================

.. highlight:: bash

This tutorial provides as how to deploy Cloudmesh with Vagrant and VirtualBox.
Official Ubuntu 14.04 Server LTS 64 bit and 32 bit are supported as base images
of Vagrant.

Download cloudmesh
--------------------------

::

  $ git clone https://github.com/cloudmesh/cloudmesh.git
  $ cd cloudmesh

Install Vagrant and VirtualBox
--------------------------------

This instructions are tested on Ubuntu 14.04.

::

  $ sudo apt-get install vagrant
  $ sudo add-apt-repository multiverse 
  $ sudo apt-get update
  $ sudo apt-get install virtualbox


Install Vagrant on OSX
-------------------

Download and install vagrant from https://www.vagrantup.com/downloads.html

::
   
  curl -L https://dl.bintray.com/mitchellh/vagrant/vagrant_1.7.2.dmg > vagrant_1.7.2.dmg
  open vagrant_1.7.2.dmg

Click on the vagrant.pkg and follow the install instructions

Verify that vagrant is installed with::

  vagrant -h


which should give you the vagrant help message

Install virtualbox from

https://www.virtualbox.org/wiki/Downloads

once downloaded and you clock on the dmg, follow the instalation instructions.
  
Install Veewee (Optional)
-------------------------

There are `requirements <veewee-requirement.html>`_ prior installing Veewee.

::
  
   $ gem install veewee

* On OS X Yosemite::

   
   $ sudo ARCHFLAGS=-Wno-error=unused-command-line-argument-hard-error-in-future gem install veewee


Vagrant up
----------

.. important:: 

   In order to configure a virtual machine to use cloudmesh on you will
   need to specify some environmental variables:

   - PORTALNAME
   - PROJECTID

   ::

      $ export PORTALNAME=albert
      $ export PROJECTID=fg101


.. important::

   In order for the virtual machine to access the resources on ``india`` using your credentials, you will need to have ``ssh-agent`` running with your ssh key added. For instance::

     $ eval `ssh-agent`
     $ ssh-add ~/.ssh/id_rsa

You can now start a virtual machine with cloudmesh installed, configured, and running:

::

  $ cd ~/cloudmesh/vagrant
  $ vagrant up


.. note:: If you have trouble with the above instructions and `this
          Vagrantfile
          <https://github.com/cloudmesh/cloudmesh/blob/dev2.0/vagrant/Vagrantfile>`_
          does not work, please contact us.

Vagrant ssh
-----------

At this point the virtual machine is up and running with cloudmesh
installed, configured, and running. To use it, just log in:

::
 
   $ vagrant ssh

Use cloudmesh
-----------------

The virtualenv will be loaded by default, allowing you to use cloudmesh immediately

::

   $ cm
