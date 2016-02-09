Account Information of Cloudmesh
===============================================================================

Cloudmesh manages account information which is stored in a file named
``cloudmesh.yaml``. In OpenStack, for example, access information such as
OS_USERNAME, OS_PASSWORD, OS_TENANT_NAME, OS_AUTH_URL, and OS_CACERT is
required to interact with a OpenStack service. Cloudmesh stores the access
information in the ``cloudmesh.yaml`` file under a user home directory and
MongoDB open-source document database. If you'd like to add more cloud
platforms, you may need to update this YAML data file. Windows Azure, Amazon
EC2, HP Cloud, Eucalyptus, and other OpenStack clouds are supported.

This page covers:
-------------------------------------------------------------------------------

* Basic structure of ``cloudmesh.yaml``
* Basic use of ``cloudmesh.yaml``
* An example of adding a new cloud account

Basic structure of ``cloudmesh.yaml``
-------------------------------------------------------------------------------

The ``cloudmesh.yaml`` configuration file mainly contains the following
information:

* profile (user profile data)
   - address
   - email
   - firstname
   - gid
   - uid
   - lastname
   - phone
   - username
* active (cloud activation)
   - [cloud name]
* clouds (cloud access information)
   - [cloud name]
* projects (project information)
   - active
   - completed
   - default
* security (security group information)
* keys (key pairs)

Cloud Access Information
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Each cloud has common key=value:

::

  cm_heading: [Description]
  cm_host: [Host address e.g. india.futuregrid.org]
  cm_label: [Unique label]
  cm_service_url_type: publicURL (OpenStack Onl)
  cm_type: [aws|openstack|ec2|eucalyptus|azure]
  cm_type_version: [Version e.g. juno or havana]
  default:
    flavor: [Instance type e.g. m1.small]
    image: [Virtual image name]
    location: [Region]

The following sections are credentials for clouds:

* OpenStack has:

::

  credentials:
    OS_AUTH_URL: [Address of OpenStack Authentication]
    OS_CACERT: [File path of CA Cert]
    OS_PASSWORD: [Password]
    OS_TENANT_NAME: [Project Name]
    OS_USERNAME: [User ID]
    OS_VERSION: juno

These credentials are adopted from OpenStack Credential variables. For more
details, see here: http://docs.openstack.org/developer/devstack/openrc.html

* Amazon Cloud (AWS) has:

:: 

  credentials:
    EC2_ACCESS_KEY: [ACCESS KEY string]
    EC2_SECRET_KEY: [SECRET KEY string]
    keyname: [SSH Key Pair name]
    userid: [AWS ID]
    EC2_PRIVATE_KEY: [File path of a private key]

* Microsoft Azure has:

::

   credentials:
     subscriptionid: [Subscription ID]
     managementcertfile: [File path of a management certificate e.g. *.pem]
     thumbprint: [File path of a fingerprint]
     servicecertfile: [File path of service certificate e.g. *.pfx]

* Eucalyptus has:

::

   credentials:
     EUCALYPTUS_CERT: [File path of a server certificate]
     EC2_CERT: [File path of a certificate]
     EC2_URL: [Address of Eucalyptus Authentication]
     EC2_ACCESS_KEY: [ACCESS KEY string]
     EC2_SECRET_KEY: [SECRET KEY string]
     EC2_PRIVATE_KEY: [File path of a private key]

File Location
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Once you've installed Cloudmesh, you can find the configuration
``cloudmesh.yaml`` file in the following location:

* $HOME/.cloudmesh/cloudmesh.yaml

Basic Template
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

We maintain a default template under:
https://github.com/cloudmesh/cloudmesh/blob/master/etc/cloudmesh.yaml

India OpenStack on FutureSystems
-------------------------------------------------------------------------------

If you've successfully installed Cloudmesh, you expect to have India OpenStack configured with your account.

An example of India account information in ``cloudmesh.yaml`` looks like this::

   clouds:
     india:
       cm_heading: India OpenStack, Juno
       cm_host: india.futuregrid.org
       cm_label: india_juno
       cm_service_url_type: publicURL
       cm_type: openstack
       cm_type_version: juno
       credentials:
         OS_AUTH_URL: https://i5r.idp.iu.futuregrid.org:5000/v2.0
         OS_CACERT: /home/albert/.cloudmesh/india-juno-cacert.pem
         OS_PASSWORD: 1234567890123
         OS_TENANT_NAME: fg999
         OS_USERNAME: albert
         OS_VERSION: juno
       default:
         flavor: m1.small
         image: futuresystems/ubuntu-14.04

You may find an identical information about credentials on india login node.
Try to compare with ``$HOME/.cloudmesh/clouds/india/juno/openrc.sh`` on india.

AWS example of ``cloudmesh.yaml``
-------------------------------------------------------------------------------

to use Amazon cloud, you may have AWS access information in ``cloudmesh.yaml``.

::

   clouds:
     aws:
       cm_host: aws.amazon.com
       cm_label: aws
       cm_type: aws
       credentials:
         EC2_ACCESS_KEY: 2UWLRAD5QABCDEFBC
         EC2_SECRET_KEY: jaHdMoasdv+Xk+k1dV8KI2/o/untirwqEzi/Fnl2
         EC2_PRIVATE_KEY: /home/albert/.cloudmesh/aws-pk.pem
       keyname: cloudmesh-aws
       userid: albert
       default:
         flavor: m1.small
         image: ami-fbb2fc92
         location: us-east-1


Cloud Activation on Cloudmesh
-------------------------------------------------------------------------------

If you added a new cloud access information in your ``cloudmesh.yaml``, you
need to activate your cloud on ``cm`` interactive shell or a web interface.

In ``cm`` shell, try to add it first. Example command looks like::

  cm> cloud add /home/albert/.cloudmesh/cloudmesh.yaml

And activate your new cloud::

  cm> cloud on [cloud name]

If you added AWS, try like this::

  cm> cloud on aws

You may have different name (label) for your cloud. Use your name, if it has a
different name.

.. note:: Find ``Profile`` page on the Cloudmesh web GUI. It supports cloud
          activation on the web.

Additional Information
-------------------------------------------------------------------------------

For more information of using a ``yaml`` file in Cloudmesh, please see here:

`YAML <yaml.html>`_
