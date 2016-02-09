.. _ref-class-lesson-deploying-hadoop-cluster-manual:


Deploying Hadoop Cluster on India OpenStack
===============================================================================

.. tip:: Approximate time: 45 minutes

Introduction
-------------------------------------------------------------------------------

Hadoop Cluster is specialized computational cluster especially for
MapReduce data analysis applications.  On FutureSystems OpenStack,
Hadoop Cluster is offered to deal with distributed software on the
cloud.  The size of Hadoop Cluster can be easily adjustable to provide
efficient throughput for the computation.

Prerequisite
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This tutorial assumes you already have used OpenStack and know how to
create multiple virtual machine images. To build a distributed Hadoop
cluster, you will need at least two VMs for nodes, though more than
two are welcome. Much of the functionality described here will be
available via Cloudmesh, but this document explains how to perform
these tasks manually, to help you better understand the requirements
and process of building a cluster.

Important Fact
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are certain things to remember when Hadoop Cluster is started.

 - The number of nodes
 - The size of a flavor
 - The limit of your account (quota)

Please ensure that you create a Hadoop Cluster with a proper number of nodes, a
size of a flavor and your quota.  Large flavor provides powerful a single node
but consumes your quota quickly.  Additional cluster nodes may be needed if
speed-up is possible to your data processing.

Cluster Preparation
-------------------------------------------------------------------------------

Prior to deploying Hadoop, your nodes must be able to communicate.
This will require changes to the `/etc/hosts` configuration file, and
creation and sharing of SSH keys among the nodes of the cluster.

Add lines to the end of your `/etc/hosts` file, one line for each node
in the cluster, listing the IP address, fully qualified host name, and
an alias for the host to be used by Hadoop. Here is an example of an
`/etc/host` file with six nodes added. Of course you will use the
proper IP addresses and host names for your VMs. You can use the same
hosts file for every node in your cluster::

    127.0.0.1 localhost

    # The following lines are desirable for IPv6 capable hosts
    ::1 ip6-localhost ip6-loopback
    fe00::0 ip6-localnet
    ff00::0 ip6-mcastprefix
    ff02::1 ip6-allnodes
    ff02::2 ip6-allrouters
    ff02::3 ip6-allhosts

    # lines added for Hadoop cluster
    10.39.1.46 smccaula-101.novalocal hadoop1
    10.39.1.47 smccaula-102.novalocal hadoop2
    10.39.1.55 smccaula-103.novalocal hadoop3
    10.39.1.56 smccaula-104.novalocal hadoop4
    10.39.1.57 smccaula-105.novalocal hadoop5
    10.39.1.45 smccaula-106.novalocal hadoop6

Your nodes will also SSH authentication to communicate. For each node,
you will need to create a pair of SSH keys (as root). The following
command will create a key pair in `/root/.ssh`::

    ssh-keygen -t rsa -P ""

You will need to append the public key created (default will be
id_rsa.pub) to the authorized_keys file of each node. You can do this
by downloading the keys from one host and uploading them to another,
or by copying and pasting them from an editor program in your
terminal. If copying and pasting, be sure all characters are copied.
Given you have moved a public key to another host, you can append it
to authorized_key as follows (again, this is as root and the files are
in `/root/.ssh`)::

  cat hadoop2.pub >> /root/.ssh/authorized_keys

Test this by verifying that you can SSH from node to node in either
direction. From this point, implementing a multi-node cluster is very
similar to building a single node pseudo-cluster. The main difference
is that we will establish some division of labor among the nodes.
There are three functions we need to fill:

NameNode for the HDFS file system:

-	Keeps track of all files and on which nodes they are stored

ResourceManager for the YARN resource negotiator:

-	Manages cluster resources and applications

DataNode(s) for the HDFS file system

-	Stores data files and makes them available to client applications

cm cluster create: a convenient way to create a cluster of VMs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cloudmesh provides a convenient way to create such a cluster of VMs 
(each of them can log into all others). Please follow the following 
steps:

.. important::
    Make sure you update your Cloudmesh and the Cloudmesh server is running.
    Open a terminal, execute the following commands, modify the values of the
    options according to your own environment and needs. Also you may execute
    these in Cloudmesh CLI 'cm'.

1 select cloud to work on, e.g.::

    cm cloud select india

2 activate the cloud, e.g.::

    cm cloud on india

3 set the default key to start VMs, e.g.::

    cm key default test-key

4 set the start name of VMs, which is prefix and index, e.g.::

    cm label --prefix=test --id=1

5 set image of VMs, e.g.::

    cm default image --name=futuregrid/ubuntu-14.04

6 set flavor of VMs, e.g.::

    cm default flavor --name=m1.small

Then you may start the cluster with command 'cluster create' by providing the
following values:

--count: specify amount of VMs in the cluster

--group: specify a group name of the cluster, make sure it's UNIQUE

--ln: login name for VMs, e.g. ubuntu 
e.g.::

    cm cluster create --count=3 --group=test --ln=ubuntu

You may also provide cloud name, flavor or image in the command if you don't
want to pre-set them. e.g.::
    
    cm cluster create --count=3 --group=test0 --ln=ubuntu --cloud=india --flavor=m1.small --image=futuregrid/ubuntu-14.04

to list the VMs you just created::

    cm vm list --refresh --group=test

Deploying Hadoop
----------------------------------------------------------------------

We will have to decide on the architecture of our cluster before
proceeding. In practice, clusters can be tens of thousands of nodes,
but our cluster will be a handful of nodes. For our example, we will
combine all the management functions on one node, and make the rest
datanodes.

Chef Installation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

We will use Chef to install the Hadoop software, and configure our
nodes, calling different recipes for the manager and worker nodes. In
addition to Hadoop, we will install Oracle Java, as that is Hadoop’s
preferred version of Java. The Apt and Yum cookbooks are also
downloaded as they are required by the Hadoop recipe. First we need to
install Chef and download the required cookbooks from the Chef
repository. As root, and in the /home/ubuntu directory, these commands
will do that::

    sudo su -
    apt-get update
    cd /home/ubuntu
    curl -L https://www.opscode.com/chef/install.sh | bash

Chef Configuration and Cookbooks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Install required cookbooks and setup configuration (.chef).

::

    wget http://github.com/opscode/chef-repo/tarball/master
    tar -zxf master
    mv *-chef-repo* chef-repo
    rm master
    cd chef-repo/
    mkdir .chef
    echo "cookbook_path [ '/home/ubuntu/chef-repo/cookbooks' ]" > .chef/knife.rb
    cd cookbooks
    knife cookbook site download java
    knife cookbook site download apt
    knife cookbook site download yum
    knife cookbook site download hadoop
    knife cookbook site download ohai
    knife cookbook site download sysctl
    tar -zxf java*
    tar -zxf apt*
    tar -zxf yum*
    tar -zxf hadoop*
    tar -zxf sysctl*
    tar -zxf ohai*
    rm *.tar.gz

java.rb
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are four files we will need to create to store our preferences.
These will need slight customization based on your host names and your
desired configuration. In ``/home/ubuntu/chef-repo/roles`` create
``java.rb`` for our Java preferences. We request Oracle Java version 6,
and ask to have the ``$JAVA_HOME`` environment variable set
automatically::

    name "java"
    description "Install Oracle Java"
    default_attributes(
      "java" => {
	"install_flavor" => "oracle",
	"jdk_version" => "6",
	"set_etc_environment" => true,
	"oracle" => {
	  "accept_oracle_download_terms" => true
	}
      }
    )
    run_list(
      "recipe[java]"
    )

hadoop.rb
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In ``/home/ubuntu/chef-repo/roles`` create ``hadoop.rb`` for our Hadoop
preferences. These preferences will actually be the same whether we
are installing a namenode or a datanode, we will just call a different
recipe. Here we will pass the names of our HDFS and YARN manager
nodes. In this example the manager node has an alias of hadoop1. If
you named yours differently, change it here to match::

    name "hadoop"
    description "set Hadoop attributes"
    default_attributes(
      "hadoop" => {
	"distribution" => "bigtop",
	"core_site" => {
	  "fs.defaultFS" => "hdfs://hadoop1"
	},
	"yarn_site" => {
	  "yarn.resourcemanager.hostname" => "hadoop1"
	}
      }
    )
    run_list(
      "recipe[hadoop]"
    )  


solo.rb
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In ``/home/ubuntu/chef-repo`` create ``solo.rb`` to store locations and
instructions for Chef to use::

    file_cache_path "/home/ubuntu/chef-solo"
    cookbook_path "/home/ubuntu/chef-repo/cookbooks"
    role_path "/home/ubuntu/chef-repo/roles"
    verify_api_cert true

solo.json
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Finally, in ``/home/ubuntu/chef-repo`` create ``solo.json`` for the specific
instructions to Chef on what to install. This is the only file that
will change between a manager and worker node installation. Both
versions are shown below. Remember that you could configure
differently, the HDFS namenode and YARN resourcemanager could be on
different nodes, and the namenode and resourcemanager nodes could also
be datanodes if desired. You may want to install and initialize your
manager node prior to creating your worker node.

For the manager node::

    {
      "run_list": [ "role[java]", "recipe[java]", "role[hadoop]", "recipe[hadoop::hadoop_hdfs_namenode]",
       "recipe[hadoop::hadoop_yarn_nodemanager]", "recipe[hadoop::hadoop_yarn_resourcemanager]" ]
    }

For the worker node::

    {
      "run_list": [ "role[java]", "recipe[java]", "role[hadoop]",  "recipe[hadoop::hadoop_hdfs_datanode]" ]
    }

Repeat the worker installation for as many nodes as are available. At
this point your cluster is deployed and awaiting initialization.

Installation using ``chef-solo`` (``chef-client -z``)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You must run this command on a master(namenode) and a worker(datanode). If you
have hadoop1, hadoop2, ... ,and hadoopX, SSH into all and run this command.

::

  chef-solo -j /home/ubuntu/chef-repo/solo.json -c /home/ubuntu/chef-repo/solo.rb

In a newer version of Chef ::

  chef-client -z -j /home/ubuntu/chef-repo/solo.json -c /home/ubuntu/chef-repo/solo.rb

Initializing and Testing
-------------------------------------------------------------------------------

On the namenode only, we will have to initialize the file system.
First check the status of all services and stop any that are running.
Don’t worry about services not installed on this node::

    service hadoop-hdfs-namenode status
    service hadoop-hdfs-datanode status
    service hadoop-yarn-resourcemanager status
    service hadoop-yarn-nodemanager status

To initialize the namenode, run::

    /etc/init.d/hadoop-hdfs-namenode init

Namenode Initialization and Start
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Restart any services installed on the node. There is one more
initialization step required on the namenode, to create a default
directory structure::

    service hadoop-hdfs-namenode start
    /usr/lib/hadoop/libexec/init-hdfs.sh

The expected output looks liks so::

  + su -s /bin/bash hdfs -c '/usr/bin/hadoop fs -mkdir /tmp'
  + su -s /bin/bash hdfs -c '/usr/bin/hadoop fs -chmod -R 1777 /tmp'

  ... (skip) ...

  + su -s /bin/bash hdfs -c '/usr/bin/hadoop fs -put /usr/lib/hadoop-mapreduce/hadoop-distcp*.jar /user/oozie/share/lib/distcp'
  + ls '/usr/lib/pig/lib/*.jar' '/usr/lib/pig/*.jar'
  + '[' '' = -u ']'

Datanode(s) Service Start
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Go to your datanode(s) and start::

   service hadoop-hdfs-datanode start

You may see the message like this::

 * Started Hadoop datanode (hadoop-hdfs-datanode): 

When these initialization steps are complete, and all the appropriate
services are running on each node, the Hadoop cluster will be
operational and ready to run jobs.


``jps`` Java Virtual Machine Process Status Tool
-------------------------------------------------------------------------------

Once you installed namenode and datanode(s), check process using ``jps``
command.

On **Namenode**, you may see::

  20937 ResourceManager
  15854 NodeManager
  22874 Jps
  20609 NameNode

On **Datanode**, you may see::

 4137 Jps
 4061 DataNode

MapReduce Example: Word Count
-------------------------------------------------------------------------------

Once you installed a Hadoop cluster, you may want to run a program using the
cluster.  One of the popular examples of Hadoop is a Word Count MapReduce
program which counts how often words occur from the input text file. We have a
separate page for this program here.

:ref:`Word Count Program <ref-class-lesson-hadoop-word-count>`

.. _ref-class-lesson-deploying-hadoop-cluster-manual-exercise:

Exercise
-------------------------------------------------------------------------------

- Try to run a simple job on your hadoop cluster (wordcount)
.. - Create a hadoop cluster with a different number of nodes

FAQ
-------------------------------------------------------------------------------

- Q. How do I delete a Hadoop Cluster on Cloudmesh?
- A. ``cluster delete --group=[name]``

Other resource
-------------------------------------------------------------------------------

- `MyHadoop <http://cloudmesh.github.io/introduction_to_cloud_computing/paas/hadoop.html>`_

Questions?
-------------------------------------------------------------------------------

.. - Forum via Git Issues: `Git Issues
  <https://github.com/CourseMaterial/introduction_to_cloud_computing/issues>`_

- Email: `Contact Us <contact.html>`_

.. Deploying Hadoop Cluster with Chef (Experimental)
.. -------------------------------------------------------------------------------

.. We are currently developing a new method to deploy Virtual Cluster with Chef
.. recipes and OpenStack Heat.  As a first tryout, we have developed a deployment
.. of Hadoop Cluster. For detail, see the next page:

.. toctree::
   :maxdepth: 1

   hadoop_cluster_chef

.. *Note that this is experimental, some features may not work properly.*

Next Step
-------------------------------------------------------------------------------

In the next page, we deploy a Sharded MongoDB cluster on FutureSystems using
Cloudmesh.

`Next Tutorial>> Deploying MongoDB Sharded Cluster <mongodb_cluster.html>`_

.. .. toctree::
..   :maxdepth: 1

..   mongodb_cluster
