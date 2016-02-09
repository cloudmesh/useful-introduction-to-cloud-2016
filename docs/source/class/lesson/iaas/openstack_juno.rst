OpenStack Juno
======================================================================

Overview
----------------------------------------------------------------------

This lesson will introduce you to a very important topic to OpenStack Juno
release.  The latest release Juno is the 10th release of OpenStack platform
which includes new features e.g. Sahara, updates and bug fixes.  We will
explore a few changes and updates in OpenStack Juno release.

.. tip:: Duration: 10 minutes

Prerequisite
----------------------------------------------------------------------

In order to conduct this lesson you should have knowledge of

* `Overview OpenStack <overview_openstack.html>`_

Description
----------------------------------------------------------------------

Rule of OpenStack Release
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table 1. OpenStack Release

======= ======  ======  ===================
Series  Name    Date    Major changes
======= ======  ======  ===================
1st     Austin  2010    Object Storage
...     ...     ...     ...
10th    Juno    2014    OpenStack Sahara

                        OpenStack Trove
11th    Kilo    2015    OpenStack Docker
                        Plugin

                        OpenStack Ironic
======= ======  ======  ===================

OpenStack Sahara
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

OpenStack Sahara (previously Savanna) project provides Apache Hadoop clusters
on OpenStack to offer agile access to a big data platform. Sahara focuses on
deploying a Hadoop cluster with easy and fast steps and configuring cluster
topology from the user's perspective. MapReduce, MapReduce.Streaming, Hive,
Pig, Java, Spark, and Shell are supported for data processing on the cluster.

A summary of OpenStack Sahara is:

* OpenStack Data Processing software
* Hadoop cluster provisioning and task operation
* Management in OpenStack Horizon (GUI) Dashboard
* OpenStack integrated project 
* Available from Juno release
* Elastic Data Processing (EDP) for executing MapReduce tasks
* Similar to Amazon Elastic MapReduce (EMR)

.. figure:: /images/lesson_openstack_sahara.png

   Figure 1. Architecture of OpenStack Sahara

References
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

* Github: https://github.com/openstack/sahara
* Developer Guide: http://docs.openstack.org/developer/sahara/

Sahara vs Cloudmesh
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

Table 2. Comparison between OpenStack Sahara and Cloudmesh Virtual Cluster

==============          =========       ==============================================
Feature                 Sahara          Cloudmesh
==============          =========       ==============================================
IaaS platform           OpenStack       OpenStack, Eucalyptus, Amazon, Azure, HP Cloud
...                     ...             ...
==============          =========       ==============================================

Next Step
-----------

In the next page, starting a web server on Amazon EC2 will be addressed.

`Amazon Web Services (AWS) <aws_tutorial.html>`_

