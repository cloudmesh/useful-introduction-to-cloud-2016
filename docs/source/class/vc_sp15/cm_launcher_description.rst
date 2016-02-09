Using Cluster on Cloud IaaS Platform
------------------------------------

Many cloud platforms such as OpenStack, Eucalyptus, AWS, etc. support a
compute cluster on their virtualized environments with orchestration
tools like Docker, Puppet or Chef. It typically, however, requires
additional tasks to configure networks and support large number of
clusters manually. Cloudmesh offers ``launcher`` command with OpenStack
Heat and Chef recipes to provide automated and scalable clusters.

Provisioning Virtual Machines for Cluster
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To create a virtual machine(s) for a cluster, we use OpenStack Heat.
Heat is the OpenStack Orchestration tool which creates compute
environments with its template on OpenStack platform. The template
contains information about cloud resources such as virtual machines,
floating IP addresses, security groups, key-pairs, volumes, etc. With the
OpenStack Heat Template, a master node and a worker node(s) can be
configured differently with its settings for the cloud resources.

Communication (SSH) across multiple nodes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In a cluster environment, every node needs to communicate with each
other. Cloudmesh Cluster automatically sets up for you by utilizing
OpenStack Heat Template. We have added a ssh-copy-id like script inside
of Cloudmesh cluster command and the newly generated ssh keypair is
propagated through OpenStack Heat Template. get\_param or get\_file in
the template allows to inject the keypair to each node of the cluster.
We also update the system hosts files in each cluster node so that they
can login each other with its own hostname i.e. hadoop1 or master. This
is also done by OpenStack Heat Template. We placed an injection script
in the last node of cluster so when the user\_data is being executed,
the last node propagates all the hostnames with their private IP
addresses to /etc/hosts on the rest of nodes. This completes configuring
ssh password-less connection across the cluster node(s).

Configuration for master and worker node
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To setup a cluster with master and worker node(s), configuration and
installation are different in the master and the worker node. Cloudmesh
cluster allows you to provide a separated installation script with stdin
or a file as a user script to run on the node. With this isolated user
space for installing and configuring packages, you can easily setup a
master and a worker node in Cloudmesh. If you need to install program a
on a master node, for example, you can simply call
``cluster write [cluster name] master`` with
``apt-get install program a`` on a ubuntu image. We treat that there is
a single master and all worker node(s) are same.

Confirmation of the cluster installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

To ensure everything is properly installed and configured, Cloudmesh
tries to check the installation with a few options. A Cloudmesh user can
define what to expect as a result so ``cm launcher`` can
understand whether it is successfully installed or not. Also, testing
command or script can be executed to verify the installation with
``cm launcher``. If there was error occurred, rollback would be
performed.
