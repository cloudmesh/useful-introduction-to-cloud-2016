How to setup a Cloudmesh Image
======================================================================

.. note:: The documentation talks about the steps to be followed to create 
            a image with cloudmesh installed and boot a new VM from the 
            cloudmesh image. The steps to be followed are::

            - Boot a VM from an existing image using nova commands
            - Setup Cloudmesh on the new VM
            - Create an image from the new VM 
            - Test the image

Boot a VM from an existing image using nova commands
-------------------------------------------------------

The steps to boot a VM from an existing image is available in the link: 
`<http://cloudmesh.github.io/introduction_to_cloud_computing/iaas/openstack.html>`_.
Follow the steps until "List running images".

For the sake of convenience, the steps without description is listed below::

      $ ssh username@india.futuresystems.org
      $ module load novaclient
      $ source ~/.futuregrid/openstack_havana/novarc
      $ nova flavor-list
      $ nova image-list
      $ nova keypair-add $USER-key > ~/.ssh/$USER-key
      $ chmod 600 ~/.ssh/$USER-key
      $ nova keypair-list
      $ nova secgroup-add-rule default icmp -1 -1 0.0.0.0/0
      $ nova secgroup-add-rule default tcp 22 22 0.0.0.0/0
      $ nova secgroup-list-rules default
      $ nova boot --flavor m1.large \
                  --image "futuregrid/ubuntu-14.04" \
                  --key_name $USER-key $USER-001
      $ nova list

If everything worked fine, the output of the last command should be similar to::

      +----------------------------------------+------------+--------+------------+-------------+--------------------+
      | ID                                     | Name       | Status | Task State | Power State | Networks           |
      +----------------------------------------+------------+--------+------------+-------------+--------------------+
      | 0747fe47-f8b1-4fd9-8f51-ad694708e6b7   | <USER>-001 | ACTIVE | None       | Running     | private=10.39.1.16 |
      +----------------------------------------+------------+--------+------------+-------------+--------------------+


Setup Cloudmesh on the new VM
-------------------------------------------------------

Once the status becomes 'ACTIVE', log in to the VM using the IP address given in the 'Networks' column::

       $ ssh -l ubuntu -i ~/.ssh/$USER-key 10.39.1.16

.. note:: This IP address is a private IP address and can be reached only when you are logged in to the 
		'India' machine.

Preparation of the VM
^^^^^^^^^^^^^^^^^^^^^^

Update the operating system by executing the following command::

      $ sudo apt-get update

Install virtualenv and git by executing the following commands::

	$ sudo apt-get install python-virtualenv

.. note:: This might take a minute or two to install

Once you have installed virtualenv, execute the following command to create 
a virtual environment::

	$ virtualenv ~/ENV

Activate the virtual environment by executing the followoing command::

	$ source ~/ENV/bin/activate

Execute the following command to permenantly put the source step into the bashrc file::

	$ echo "source ~/ENV/bin/activate" >> ~/.bashrc

Install git by executing the following command::

	$ sudo apt-get install git

Download cloudmesh code from github by running the following commands::

	$ cd ~
	$ git clone https://github.com/cloudmesh/cloudmesh.git

The above steps would have created a directory called cloudmesh with the codeset. Execute the 
following commands to setup required packages::

	$ cd cloudmesh

The next step is to fix some IP addresses on India by execting the command::  

      $ ./bin/fix-india-routing.sh

Install Cloudmesh
^^^^^^^^^^^^^^^^^^^

Install the required packages by exectuing the following commands::

	$ sudo ./install system [Note: This step would take a while. So be patient]
	$ ./install requirements [Note: This will take a minute or two to complete]

Create the yaml configuration files by executing the following command::

	$ ./install new

Install the cloudmesh code into the virtual environment, by running the following command::

	$ ./install cloudmesh

This step will install the cloudmesh related executable in "~/ENV/bin/" directory.

Now we are at a point where we have the cloudmesh code installed successfully. After this there are 
certain steps which are specific to each user.

So we stop here and snapshot the VM instance.

Create an image from the new VM
-------------------------------

Exit from the VM, by typing "exit" at the command prompt.

To view the existing images, execute the following command::

	$ nova image-list

To snapshot the VM instance, execute the following command::

	$ nova image-create $USER-001 futuregrid/cloudmesh-ubuntu-14.04

When the image is being created, the Status will be set to "SAVING". To check the status of the image creation execute the following command::

	$ nova image-list

You would see an output similar to::

	+----------------------------------------+------------------------------------+--------+--------------------------------------+
	| ID                                     | Name                               | Status | Server                               |
	+----------------------------------------+------------------------------------+--------+--------------------------------------+
	| 18c437e5-d65e-418f-a739-9604cef8ab33   | futuregrid/fedora-18               | ACTIVE |                                      |
	| 1a5fd55e-79b9-4dd5-ae9b-ea10ef3156e9   | futuregrid/ubuntu-14.04            | ACTIVE |                                      |
	| 592e74c1-6d7f-4518-8a9e-c37e2145d92a   | futuregrid/cloudmesh-ubuntu-14.04  | SAVING | d917ac67-1aeb-42de-a72f-90151ed177ed | 
	+----------------------------------------+------------------------------------+--------+--------------------------------------+

Once the image has been created successfully, the status is changed to ACTIVE as shown below::

	+----------------------------------------+------------------------------------+--------+--------------------------------------+
	| ID                                     | Name                               | Status | Server                               |
	+----------------------------------------+------------------------------------+--------+--------------------------------------+
	| 18c437e5-d65e-418f-a739-9604cef8ab33   | futuregrid/fedora-18               | ACTIVE |                                      |
	| 1a5fd55e-79b9-4dd5-ae9b-ea10ef3156e9   | futuregrid/ubuntu-14.04            | ACTIVE |                                      |
	| 592e74c1-6d7f-4518-8a9e-c37e2145d92a   | futuregrid/cloudmesh-ubuntu-14.04  | ACTIVE | d917ac67-1aeb-42de-a72f-90151ed177ed | 
	+----------------------------------------+------------------------------------+--------+--------------------------------------+

This snapshot image has now cloudmesh codeset installed. 


Test the image
---------------

Once the cloudmesh image has been created, We will go ahead and create a new VM instance from this snapshot::

       $ nova boot --flavor m1.large \
                   --image "futuregrid/cloudmesh-ubuntu-14.04" \
                   --key_name $USER-key $USER-cloudmesh-001

Check the status of the vm creation by executing the command::

	$ nova list

You would see an output similar to::

	+----------------------------------------+-----------------------+--------+------------+-------------+----------------------------------+
	| ID                                     | Name                  | Status | Task State | Power State | Networks                         |
	+----------------------------------------+-----------------------+--------+------------+-------------+----------------------------------+
	| 0747fe47-f8b1-4fd9-8f51-ad694708e6b7   | <USER>-cloudmesh-001  | ACTIVE | None       | Running     | private=10.39.1.62               |
	+----------------------------------------+-----------------------+--------+------------+-------------+----------------------------------+

The IP generated by default would be a private IP and this IP is not accessible from external network. Follow the steps below to generate an 
external IP address which allows the VM to be accessible from external network::

      $ nova floating-ip-create
      $ export MYIP==`nova floating-ip-list | fgrep "None" | cut -d '|' -f2 | head -1`
      $ nova add-floating-ip $USER-cloudmesh-001 $MYIP

Login to the VM by running the following command::

      $ ssh -l ubuntu -i $USER-key  $MYIP

Once you are inside the VM, check if a cloudmesh directory is available by executing the command::

	$ ls ~/cloudmesh

Update the user profile, name and project data in the cloudmesh.yaml file::

      $ vi ~/.cloudmesh.yaml

An alternative way to do update the cloudmesh.yaml file is use the functionality provided by cloudmesh::

      $ export PORTALNAME=<put your portal name here>
      $ ssh-keygen -t rsa -C $PORTALNAME-ubuntu-vm-key

Now add the key to the ssh agent::

      $ eval `ssh-agent -s`
      $ ssh-add

The ssh key for the VM needs to be added to the FutureSystems portal account. Copy the ssh key from the file::

      $ cat ~/.ssh/id_rsa.pub

Now fetch the user information needed to access openstack from India by running the following commands::

	$ cm-iu user fetch
	$ cm-iu user create

.. note:: When this command is run, it would ask for a portal username. Enter your FutureSystems portal name.

Make some changes to the India OpenStack configuration by executing the following command::

      $ fab india.configure

Create the cloudmesh database by executing the following command::

      $ fab mongo.reset

Start the cloudmesh services by executing the following command::

      $ fab server.start

Access Cloudmesh using the http link::

      http://PUBLIC_IP_OF_THE_VM:5000

.. note:: You can get the public ip of the VM by running the command::
            
            $ echo $MYIP

.. attention:: Once you are done with your work and you no longer need the VMs, you can delete them with the commands::

       $ nova delete $USER-cloudmesh-001
       $ nova delete $USER-001

.. Indices and tables
.. ==================

.. * :ref:`genindex`
.. * :ref:`modindex`
.. * :ref:`search`

