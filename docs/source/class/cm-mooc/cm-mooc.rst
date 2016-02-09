Big Data Applications and Analytics Shell Overview
======================================================================

`cm-mooc` provides an easy way to start a Cloudmesh VM on OpenStack India. 
You can start a virtual machine for Cloudmesh with a single command in `cm-mooc`.
You can also enable IPython Notebook on the virtual machine with `cm notebook`
commands.  You may read the following instructions to enable this program on
your terminal.

Tutorial Video Clip: http://youtu.be/kFWGPqHrBCA

.. |video-cm-mooc| replace:: |video-image| :youtube:`kFWGPqHrBCA`


Create a FutureSystems Account
----------------------------------------------------------------------
------------

First you need to have an account on the FutureSystems portal at 

* http://portal.futuresystems.org

We have discussed this in a previous session and you can find out more
information in Sthe Section :ref:`s-accounts`.

.. note:: FutureSystems Portalname and Project ID
          For this example we assume you have set the shell variable
	  PORTALNAME to your FutureSystems portal username. This can
	  be done as follwows. Let us assume your portal name is
	  `albert`. Than you can set it with::

              export PORTALNAME=albert

Next you need to login to the india login node
with::

    localhost$ ssh $PORTALNAME@india.futuresystems.org

If you need more information about  ssh  see :ref:`s-using-ssh`.

After you log into india you must activate openstack with the
following command::

  india$ module load fg455

This setp has to be executed every time yo log into india. 

.. note:: You can also place the lines into your ~/.bash_profile in
	  case you do not want to add the lines by hand every time.

Managing you Key on india
----------------------------------------------------------------------

If you have not registered your ssh key to the cloud, you will need to
generate one ::

  india$ ssh-keygen -t rsa -C $USER-india-key

This will generate a key in the default location. You must also
specify a passphrase for the key to make the use more secure. Thus you
will have a key in `~/.ssh/id_rsa.pub`. This key can now be added to
the cloud::

  india$ nova keypair-add --pub-key ~/.ssh/id_rsa.pub $USER-india-key

In case you want to use some more advanced features of cloudmesh you
may also want to upload the public key to the FutureSystems portal. 

Initializing `cm-mooc`
----------------------------------------------------------------------

.. note:: Do not forget to activate openstack if you have logied in
	  new to india::

	     india$ module load fg455

First we initialize `cm-mooc` and open up some ports as part of the
openstack default security group. Cloudmesh, IPython Notebook requires
to use 5000, 8888 port numbers. We need to add rules for these port
numbers.

.. note:: If you already have `cloudmesh` in your security group, you
       can skip this step.

::

	  india$ source ~/.futuregrid/openstack_havana/novarc
	  india$ nova secgroup-create cloudmesh "cloudmesh ports 5000, 8888"
	  india$ nova secgroup-add-rule cloudmesh tcp 8888 8888 0.0.0.0/0
	  india$ nova secgroup-add-rule cloudmesh tcp 5000 5000 0.0.0.0/0
	  india$ nova secgroup-list-rules cloudmesh


Next you simply  execute the following commands::

       india$ cm-mooc start      

.. warning:: Please wait approximately 5 minutes after this command.
       when you log into early the next command will fail.

List the VM Information
----------------------------------------------------------------------

You can check the status of the VM by the following command::

  cm-mooc list

The status may report to you active, but that does not mean that all
the software is installed yet. So please be patient and wait for some minutes.

Loggin in to the VM
----------------------------------------------------------------------

After you have waited for 5 minutes you can execute::

       india$ cm-mooc login       # SSH to VM

This command will start a virtual machine for you that has the
software for the class installed. Now that you are logged into the VM
you will need to start the ipython notebook server. This is done with
the command::

       vm$ cm notebook create # provide your password to IPython Notebook on the

This command will need some input from you and asks you to setup your
ipython notebook password as well as information for a self signed certificate

After this step is completed you can exit the virtual machine with the
command::

      vm$ exit

Now that you are back on india, you can simply start the notebook with::

       india$ cm-mooc notebook start

This will start the notebook server on your vm while using your
password and the certificate you created. 


Accessing the notebook
----------------------------------------------------------------------

Now you can access the IPython Notebook via a web browser is
simple. Just type in the following into your browser url::
      
  https://[ip address]:8888

If you forgot the ip address you can use the command::

	india$ cm-mooc info


Using the class materials
----------------------------------------------------------------------
JavaFiles, please see `the tutorial </introduction_to_cloud_computing/class/javafiles.html>`_.
You can find the class materials in the following directories. 
Upon your choice of programming language, you can try python or 
Java examples:

* **IPythonFiles**: directory containing IPython Notebooks for the class fg455
* **JavaFiles**: directory containing cloudmesh Java code
* **cloudmesh**: directory containing cloudmesh IPython Notebooks

The source for these directories is maintained at 

* https://github.com/cglmoocs/IPythonFiles
* https://github.com/cglmoocs/JavaFiles
* https://github.com/cloudmesh/introduction_to_cloud_computing

The directory:: 

   /home/ubuntu/JavaFiles

has the course programs in Java.  To view the IPython Notebook
programs navigate to the directory with::

  vm$ cd /home/ubuntu/IPythonFiles

Below are the steps to execute the java programs on ~/JavaFiles::

    vm$ javac -classpath <path to the jar file directory> <ClassName>.java
    vm$ java  -classpath <path to the jar file directory> <ClassName> 

A sample Make file is included in the directory::

    ~/JavaFiles/Section-4_Physics-Units-9-10-11/Unit-11_A-Calculated-Dice-Roll/Makefile

For dependencies, please try set your CLASSPATH on ~/Dependencies::

    vm$ export CLASSPATH=~/Dependencies:$CLASSPATH

Similarly for python navigate to home/ubuntu/IPythonFiles directory first cd into the directory::

    vm$ cd /home/ubuntu/IPythonFiles

and than execute the desired program with::

    vm$ python  <FileName>.py

Help
----------------------------------------------------------------------

You can see available commands to `cm-mooc` program::

   india$ cm-mooc -h


Deleting the VM
----------------------------------------------------------------------

In case you do not need the VM anymore, you can delete the VM with::

       india$ cm-mooc delete

.. warning:: This is a real delete of your VM with all its contents
	     and data. You want to think twice about if you like to
	     execute the command.



.. note:: Try Cloudmesh Web Site at http://[ip address]:5000 Your
   default password is: *cloudmesh* To change the password, try the
   following commands::



Optional: Starting the cloudmesh server
----------------------------------------------------------------------

.. warning:: If you are not needing the cloudmash server (e.g. you are
	  part of the FG452 project) this part is not needed. You will
	  only use the ipython notebook server

If you laos like to try the cloudmesh server you can srat it on
the VM. First make sure you are logged into the vm::
  
     india$ cm-mooc login

     vm$ cd ~/cloudmesh
     vm$ fab user.mongo # set your password
     vm$ fab server.start # restart the Cloudmesh server
