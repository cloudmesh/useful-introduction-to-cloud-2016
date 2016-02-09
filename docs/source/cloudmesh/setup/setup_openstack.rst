.. _s-cloudmesh-vm-quickstart:

Quickstart for an Openstack VM 
======================================================================

A video about the contents of this page is available on
|video-cm-openstack-setup|.

.. |video-image| image:: /images/glyphicons_402_youtube.png 
.. |video-cm-openstack-setup| replace:: |video-image| :youtube:`rcecpgm-47g`


.. highlight:: bash

.. role:: pink

.. note:: This setup is primarily used for testing, but it can also be
	  useful for classes using OpenStack, when the call
	  participants have access to an OpenStack cloud. 

Setting up Cloudmesh on a VM is an especially convenient way during
development and testing. To do so, you can follow the steps to run
Cloudmesh in a VM running Ubuntu 14.04 on FutureSystems `India`
OpenStack. The instructions have been tested on a small instance 
and the whole process could take about half an hour before you 
can access the running server.

Requirements
----------------------------------------------------------------------

* FutureSystems Account
* SSH Access to india.futuresystems.org

We assume that you have set up an account on FutureSystems and are
able to log into the machine with the name india.

If you use a different cloud, you can adapt the instructions
accordingly.

Navigator
-------------------------------------------------------------------------------

This tutorial uses different labels to distinguish SSH Terminals.

* ``india$``: SSH terminal for india.futuresystems.org
* ``vm$``: SSH terminal for a vm

``india$``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``india$`` stands for a SSH terminal of india.futuresystems.org. If you see the
``india$`` label, you are logged on ``india (i136)`` to run your command.  It
is like so::

  [$PORTALNAME@i136 ~]$ 

``vm$``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``vm$`` stands for a SSH terminal of your VM instance. If you see the
``vm$`` label, you run a command on your VM instance.  It is like so::

  ubuntu@$USER-001:~$ 

If you have a different name instead of ``$USER-001``, you see the name in the
label.


Starting the VM
----------------------------------------------------------------------

First, you have to start a VM on the cloud and assign it a public IP. 

This can be done in multiple ways, using the command line, vagrant, or
the horizon GUI. Let us assume you have set it up via the horizon GUI
or the nova command line. 

To set up a machine you could use either of the following methods:

* **Horizon**: see `our manual page
  <../../iaas/openstack.html#horizon-gui>`_.

* **Nova**: see the :ref:`s-openstack`

* **Cloudmsh**: see :ref:`s-cloudmesh-quickstart` and the Cloudmesh
  shell found elsewhere.


.. note:: FutureSystems Portal Name and Project ID
          For this example we assume you have set the shell variable
	  PORTALNAME to your FutureSystems portal username. This can
	  be done as follows. Let us assume your portal name is
	  `albert`. Than you can set it with::

              export PORTALNAME=albert

         We also assume that you have a project id that you set to::

              export PROJECTID=fg101
 
         if it is the number 101.

.. note:: Please note that in the following document we use the
	  :pink:`$USER` and :pink:`$PORTALNAME` are the same values
	  and the portalname needs to be replaced with the portal name
	  you obtained for FutureSystems. As the subsequent steps are
	  all executed on india we can simply use the default
	  :pink:`$USER` shell variable.

However, we use here a commandline approach and use the tools already
installed on india. Thus you do not have to install anything on your
machine. We assume however that you have uploaded the public key of
your machine to the FutureSystems portal so you can log into india.

We summarize the following steps::

  $ ssh $PORTALNAME@india.futuresystems.org
  india$ module load openstack
  india$ source ~/.cloudmesh/clouds/india/juno/openrc.sh

In order to log into the machine (once we start it up later),
OpenStack needs to have an ssh keypair associated.  You can either
have OpenStack create a key for you or import your current key.

Create a new SSH Key
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

OpenStack Nova creates a new key with the following command::

  india$ nova keypair-add $USER-india-key >~/.ssh/$USER-india-key
  india$ chmod 600 ~/.ssh/$USER-india-key

This will generate the key, import it into OpenStack, and ``chmod``
updates a permission (600 - owner read, write only) of the file.

.. warning:: Remember to set a passphrase once prompted to secure your private
             key.

             You must not use a passphrase less key! Please specify a
	     strong passphrase.


Import Existing SSH Key
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To **import** a pre-existing key, such as ``~/.ssh/id_rsa.pub``, do the
following::

  india$ nova keypair-add --pub-key ~/.ssh/id_rsa.pub $USER-india-key

This will associate your ``~/.ssh/id_rsa.pub`` key with the name
``$USER-india-key``.

Update Security Groups 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Next step is to open the necessary ports of the VM to be started::

  india$ nova secgroup-add-rule default icmp -1 -1 0.0.0.0/0
  india$ nova secgroup-add-rule default tcp 22 22 0.0.0.0/0
  india$ nova secgroup-add-rule default tcp 8888 8888 0.0.0.0/0
  india$ nova secgroup-add-rule default tcp 5000 5000 0.0.0.0/0
  india$ nova secgroup-list-rules default

Boot a VM
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now you can boot a VM and set public ip for external access::

  india$ nova boot --flavor m1.small --image "futuresystems/ubuntu-14.04" --key_name $USER-india-key $USER-001

  india$ nova floating-ip-create ext-net

  india$ export MYIP=`nova floating-ip-list | grep "| -" | cut -d '|' -f3 | head -1`
  india$ nova add-floating-ip $USER-001 $MYIP
  india$ nova show $USER-001

You should see a table similar to this::

    +--------------------------------------+-------------------------------------------------------------------+
    | Property                             | Value                                                             |
    +--------------------------------------+-------------------------------------------------------------------+
    | OS-DCF:diskConfig                    | MANUAL                                                            |
    | OS-EXT-AZ:availability_zone          | nova                                                              |
    | OS-EXT-STS:power_state               | 1                                                                 |
    | OS-EXT-STS:task_state                | -                                                                 |
    | OS-EXT-STS:vm_state                  | active                                                            |
    | OS-SRV-USG:launched_at               | 2015-03-26T18:17:45.000000                                        |
    | OS-SRV-USG:terminated_at             | -                                                                 |
    | accessIPv4                           |                                                                   |
    | accessIPv6                           |                                                                   |
    | config_drive                         |                                                                   |
    | created                              | 2015-03-26T18:17:39Z                                              |
    | flavor                               | m1.small (2)                                                      |
    | hostId                               | 1094ef059b959406822d0a0517873b8cb03363d700019913ebd9f636          |
    | id                                   | ad81e08f-9827-4a37-b029-xxxxxxxx                                  |
    | image                                | futuresystems/ubuntu-14.04 (6a6a3474-8194-44ac-9f56-70cb93207f21) |
    | int-net network                      | 10.23.1.xxx, 149.165.xxx.xxx                                      |
    | key_name                             | xxx-india-key                                                     |
    | metadata                             | {}                                                                |
    | name                                 | xxx-001                                                           |
    | os-extended-volumes:volumes_attached | []                                                                |
    | progress                             | 0                                                                 |
    | security_groups                      | default                                                           |
    | status                               | ACTIVE                                                            |
    | tenant_id                            | c7e8f17828fb48309e38axxxxxxxxxxxx                                 |
    | updated                              | 2015-03-26T18:17:45Z                                              |
    | user_id                              | 433181ac60be4115a51axxxxxxxxxxxx                                  |
    +--------------------------------------+-------------------------------------------------------------------+

Looking at the status you will see if the VM is in ACTIVE
state. Repeat the command::

    india$ nova show $USER-001

if necessary. 

Login to VM
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Once this is the case you can login to it with::

  india$ ssh -i ~/.ssh/id_rsa -l ubuntu $MYIP

.. note:: Alternative login: ``nova ssh $USER-001 --login ubuntu``, if a floating ip address is linked. 

Cloudmesh Installation
----------------------------------------------------------------------

One-liner by ``curl``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Installation of Cloudmesh can be complicated. We provide a one-liner
script to install::

  vm$ curl https://raw.githubusercontent.com/cloudmesh/get/master/cloudmesh/ubuntu/14.04.sh | venv=$HOME/ENV bash

.. note:: This may take several minutes. (approximate 15 minutes)

Please see :ref:`ref-cloudmesh-quickstart-system-install-curl` for
details on what this does.

You may see outputs like so::

    %  Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                      Dload  Upload   Total   Spent    Left  Speed
    100  1314  100  1314    0     0   3428      0 --:--:-- --:--:-- --:--:--  3439

    ... (skip) ...

    copy etc/user_info.yaml -> /home/ubuntu/.cloudmesh/user_info.yaml
    copy etc/cloudmesh_country.yaml -> /home/ubuntu/.cloudmesh/cloudmesh_country.yaml
    copy /home/ubuntu/.cloudmesh/me-none.yaml -> /home/ubuntu/.cloudmesh/me.yaml
    # Created: /home/ubuntu/.cloudmesh/me.yaml

    # ----------------------------------------------------------------------

Virtualenv Activation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You now need to activate the virtualenv created::

  vm$ source $HOME/ENV/bin/activate

After this command, you see the ``(ENV)`` label in your prompt like so::

  (ENV)ubuntu@$USER-001:~$


Cloudmesh Setup
----------------------------------------------------------------------

As part of its installation, Cloudmesh creates a ``~/.cloudmesh`` directory
with configuration files in YAML format. Now we need to populate the
``cloudmesh.yaml`` file with your actual cloud credentials.  Cloudmesh provides
tools for you to retrieve your futuresystems cloud credential and configure the
``cloudmesh.yaml`` file properly. Before we can use it however we have to
create a key that we upload to the FutureSystems portal.

New SSH Key for VM
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is a **new** SSH key for your VM instance. Be sure that you create a new
key on your instance. If you terminate your instance, you may loose your ssh
key.

SSH Key Generation for VM instance::

 vm$ export PORTALNAME=<put your portal name here>
 vm$ ssh-keygen -t rsa -C $PORTALNAME-ubuntu-vm-key

Cache the key by a session based command ``ssh-agent``::

  vm$ eval `ssh-agent -s`
  vm$ ssh-add
 
Register to FutureSystems Portal
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Then you need to add the key to your FutureSystems portal account. 
Please visit the portal and paste the content of the public
key in the appropriate field. You can get the content of the key by ::

  vm$ cat ~/.ssh/id_rsa.pub

The key string is similar to::

  ssh-rsa
  AAAAB3NzaC1yc2EAAAADAQAB.... ubuntu@albert-001

You will register this key string to the portal with the following steps:

* Open a web browser: https://portal.futuresystems.org/manage-my-portal-account
* Find ``SSH Keys`` > ``Add a public key``
* Paste your key string to ``Key`` text box
* Add a title and submit

At this point you should be able to connect to india from your VM instance. Try
a ssh command on VM and find ``i136`` hostname::

  vm$ ssh $PORTALNAME@india.futuresystems.org hostname
  Python version 2.7.9 loaded
  OpenStack Clients loaded
  i136

If you see ``i136`` hostname, your VM has access to india.

Credential Setup
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now you can fetch the information you need to acces openstack form india::

  vm$ cm-iu user fetch
  vm$ cm-iu user create
  
It's also recommended you manually edit the file `~/.cloudmesh/cloudmesh.yaml` 
either with emacs or vim::

  vm$ emacs ~/.cloudmesh/cloudmesh.yaml

or::

  vm$ vi ~/.cloudmesh/cloudmesh.yaml

Update your profile such as name, email, or address. Find ``profile:`` section
and update ``TBD`` value to real value.

India Configuration by Fabric ``fab`` Command Tool 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Move into ``cloudmesh`` source directory.::

  vm$ cd ~/cloudmesh

In order to start the cloudmesh web server that is accessible to outside,
we also need to undertake some changes for the india OpenStack cloud 
configuration with ::
 
  (ENV)vm$ fab india.configure

You may see outputs like so::

  modify -> /home/ubuntu/.cloudmesh/cloudmesh_server.yaml
  modify -> /home/ubuntu/.cloudmesh/cloudmesh.yaml
  Configuration changes have been made successfully

Virtualenv ``ENV``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``(ENV)$`` means that ``ENV`` virtual environment is enabled on your terminal.
This tutorial uses the ``ENV`` virtualenv to install Python packages relevant
to Cloudmesh.  When you run any Cloudmesh-related commands, you must enable
``ENV`` virtualenv by::

  vm$ source ~/ENV/bin/activate

MongoDB Initialization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To run cloudmesh you will need to start a number of services. The first
is to create and initialize the cloudmesh database. Here we will use the
command::

  (ENV)vm$ fab mongo.reset

Please note that this command will erase the previous database and you
should be carefully considering its use. When you initialize the
cloudmesh server first this is the best method.  

.. note:: Also note that this command will take a long time on
	  machines that do not have SSD's due to the way mongo sets up
	  the database. Be patient and do not interrupt the program
	  although it may run multiple minutes.


Cloudmesh Start
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Now you are ready to start all services for cloudmesh with::

  (ENV)vm$ fab server.start

.. tip:: Press ``Enter`` or ``Return`` key after seeing the ... **Loading
   module pie_chart_fg380** message on your screen. ``fab server.start``
   launches ``Flask`` web service by using a linux background command '&'. This
   makes that your screen looks frozen but your shell is available to you.

.. figure:: ../../images/hanging_after_fab_server_start.png

   Success Message of ``fab server.start`` 

Then the cloudmesh service should be available via::

   http://MYIP:5000

If you forgot your IP, use Nova command on India::

   india$ nova list --name $USER-001
   +--------------------------------------+-----------------------------------------------+---------+------------+-------------+--------------------------------------+
   | ID                                   | Name                                          | Status  | Task State | Power State | Networks                             |
   +--------------------------------------+-----------------------------------------------+---------+------------+-------------+--------------------------------------+
   | 5f62f7f6-1bdc-406e-bb4b-1eecccd133fe | albert-001                                    | ACTIVE  | -          | Running     | int-net=10.23.1.xxx, 149.165.xxx.xxx |
   +--------------------------------------+-----------------------------------------------+---------+------------+-------------+--------------------------------------+

The address starts with ``149.165`` is your public IP address.


NOTE:

#. As you might be copying your yaml files into the cloud please
   secure the VM (following good security practice, including but 
   not limited to proper ssh settings disallowing password authentication, 
   securing the location of your private key as well as setting a 
   passphrase, etc.). As this method targets the scenario for rapid 
   dev and testing, it will be a good idea that shutting the vm down 
   after using.

#. As the server is not secured by HTTPS, remember not to use your
   favorite password when you are asked to set a password for portal login.

#. This method is only intended for development and testing, and not
   recommended for real production use. If you have that intention,
   you can configure the system to use nginx+uwsgi to put cloudmesh
   user secure SSL channel.
