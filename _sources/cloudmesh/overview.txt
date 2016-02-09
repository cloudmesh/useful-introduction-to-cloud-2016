.. _cloudmesh-overview-ref:


Cloudmesh Overview
======================================================================

We have provided some documentation about cloudmesh at
http://cloudmesh.github.io/index.html.

Cloudmesh is an important component to deliver a software-defined
system – encompassing virtualized and bare-metal infrastructure,
networks, application, systems and platform software – with a unifying
goal of providing Cloud Testbeds as a Service (CTaaS). Cloudmesh
federates a number of resources from academia and industry. This
includes existing FutureSystems, Amazon Web Services, Azure, HP Cloud,
Karlsruhe using various technologies.

An high level architectural image is provided at 

.. figure:: /images/cloudmesh-arch-2013.png
   :scale: 50%

   **Figure:** *High level architecture of Cloudmesh*

The three layers of the Cloudmesh architecture include a Cloudmesh
Management Framework for monitoring and operations, user and project
management, experiment planning and deployment of services needed by
an experiment, provisioning and execution environments to be deployed
on resources to (or interfaced with) enable experiment management, and
resources.

Before continuing we recommend that you look at the following sections
on the cloudmesh web page:

* http://cloudmesh.github.io/cloudmesh.html
* http://cloudmesh.github.io/cloud.html
* http://cloudmesh.github.io/rain.html
* http://cloudmesh.github.io/hpc.html

In this document we like to focus on the actual implementation of
cloudmesh and how the various components are structured. For this
purpose we have redrawn the Figure we pointed out earlier while
focusing on a number of subcomponents that we will be looking more
closely into.


.. figure:: /images/cm-arch-layers.pdf
   :scale: 50%

   **Figure:** *High level architecture of Cloudmesh*

Typo: there are two baremetal boxes in cloudmesh cor. one should be HPC 

This diagram highlights some important information which we describe next

Cloudmesh Main Components
----------------------------------------------------------------------

The main cloudmesh component include:

* Cloudmesh Install Management: which allows to easily
  install cloudmesh on a given operating system. This can also
  include a virtual machine. 
* Cloudmesh Baremetal Management (currently part of core): which
  allows the deployment of an os via bare metal through cloudmesh.
  The important differentiation to other systems is that users can
  be authorized to conduct bare metal provision based on service
  policy descriptions. The user may not be the administrator of the
  machine.
* Cloudmesh Core: which contains the major components to interface
  with external subsystems to conduct bare matel provisioning,
  interact with IaaS such as virtual machines, HPC queues, or the
  bare metal provisioning services. 

Cloudmesh Install Management
----------------------------------------------------------------------

* Conducted in three phases
* **Phase 1:** prepare the system. Te OS may have missing packages. the
  program will install all missing packages for cloudmesh. This step
  requires typically sudo permissions.
* **Phase 2:** Install the python requirements. As cloudmesh is mostly
  developed in python, this step installs all necessary python
  libraries. 
* **Phase 3:** Install the cloudmesh programs. This Step installs the
  cloudmesh program in the python library. (We use virtual env for
  our development)

Cloudmesh Service Management
----------------------------------------------------------------------

After all the software is installed, we can start up the various
cloudmesh services. This includes

* **Cloudmesh Database**: A NOSQL database in which we record which
  virtual machines run on which IaaS. This allows us to have a
  federated view of the heterogeneous clouds.  
* **Cloudmesh Web Service**: Provides a Graphical user interface to
  manage virtual machines and HPC tasks
* **Cloudmesh Task Service**: As cloudmesh is a multi user systems
  many tasks need to be handles in parallel. To achieve this we are
  using an AMPQ queue and coordinate the execution of managing
  multiple virtual machines for multiple users.

Cloudmesh Use Mode
----------------------------------------------------------------------

Base on the rich service model in Cloudmesh we are able to start
cloudmesh either in a

* standalone mode or in a
* hosted mode for multiple users.

For development purposes most users will want to run the cloudmesh
services in standalone mode. This enables you to test out cloudmesh
without interfering with other users. It also allows you to be
completely responsible for your credentials without relaying them
through a third party.



Cloudmesh Baremetal
----------------------------------------------------------------------

Cloudmesh contains an interface to cobbler for its bare metal
services. However the important feature is that it also contains a very
small abstraction interface to bare metal provisioning. This will allow
us to integrate with other bare metal provisioners and enable for
example the use of OpenStack Ironic once it is deployed for example on
FutureSystems.

Cloudmesh HPC
----------------------------------------------------------------------

Cloudmesh provides an easy tou use API and GUI to HPC queues. It
allows simple display of queues. As FutureSystems shares on some systems
the queue manager it also seperates the queues appropriately and
displays them accordingly. The API returns the job and queue
information as python dicts.

Cloudmesh IaaS
----------------------------------------------------------------------

Cloudmesh contains an abstration to interface with arbitrary IaaS
farmeworks this includes

* Azure
* AWS
* OpenStack
* Eucalyptus
* clouds that can be accessed through libcloud

The important differentiation to other frameworks is that it is not
just capable of interfacing with libcloud to a remote cloud but it is
possible to provide interfaces while using the native protocol. This
has greatly helped in debugging real clouds as for example some
features are not properly exposed through libcloud or EC2 compatible
mechanisms. It also protected us from several changes that took place
during the various versions of OpenStack. Our OpenSTack library
interfaces directly with the OpenStack REST services

Cloudmesh Web
----------------------------------------------------------------------

While other clouds focus on their own infrastructure, Cloudmesh
provides a user interface with federation capabilities to display and
interact with heterogeneous clouds. In addition information between
these clouds is not hidden behind a compatibility library such as
libcloud or a cloud standard, but uses instead the natively available
information. This allows developers to interact and inspect information
on a different level than just being able to start and stop virtual
machines. Interfaces to HPC queues are also available. The Web
services interfaces with the Task and Database Services.

.. figure:: /images/cm-splash.png
   :scale: 50%

   **Figure:** *The Cloudmesh Web Interface*


Cloudmesh Shell
----------------------------------------------------------------------

For experiment management it os often not sufficient to just provide a
GUI interface but to be able to script how virtual machines are
coordinated. This can be done with our cloudmesh shell that similar to
matlab has its own shell environment, but can also be simply be
called as a command on a regular Linux terminal. The Cloudmesh Shell 
services interfaces with the Task and Database Services.

::

   cm cloud list

::

    +-------------------+--------+
    | cloud             | active |
    +-------------------+--------+
    | alamo             | True   |
    | aws               |        |
    | azure             |        |
    | dreamhost         |        |
    | hp                |        |
    | hp_east           |        |
    | india             | True   |
    | india_eucalyptus  |        |
    | sierra            | True   |
    | sierra_eucalyptus |        |
    +-------------------+--------+

Cloudmesh API
----------------------------------------------------------------------

A convenient API is presented to interface to cloudmesh in python
(shown here how to select an image on the cloud india)::
  #
  # IMPORTS
  #
  import cloudmesh
  
  #
  # INITIALIZATION
  #
  mesh = cloudmesh.mesh("mongo")
  username = cloudmesh.load().username()
  mesh.activate(username)

  #
  # GETTING INFORMATION ABOUT THE IMAGE
  #
  image=mesh.image('india','futuregrid/ubuntu-14.04')

  print image

Cloudmesh State
----------------------------------------------------------------------

As the Shell and the Web Service interact with the Database and the
Task Services, the status after a refresh is synchronized between
them. This means if I start a virtual machine with the command shell I
can see it in the Web after a refresh and vice versa. Default values
are shared and the interaction between Web and Shell is seamless.

The emphasize is here on managing multiple machines and the start of a
VM can be done with a single click in the Web or with a single command
without parameters in the shell. This is in contrast to other
frameworks that do not make use of extensive default management for
repetitive interactive experiments.

Tutorials
----------------------------------------------------------------------

We have provided a number of tutorials through IPython notebooks that
you can follow. A setup guide is available that documents the
installation of cloudmesh through a single curl call. The tutorials
will show you each of the three different interfaces including:

* the Python API
* the Web GUI via the Web browser
* the command shell

The examples focus on displaying information and managing virtual
machines.

A list of all `notebooks <../_index_notebooks.html>`_ is available. The list
will be expanded, and we would be happy if you contribute to them with
your own suggestions. If you think we need to show a particular
feature, please let us know. We wil try to add it.


Development and Transition to FutureSystems
----------------------------------------------------------------------

* Due to the transition of FutureGrid to FutureSystems, we have
  limited our tutorial activities in regards to baremetal provisioning

* We are focusing our current efforts on the development of our PaaS
  launcher that interfaces with chef and ssh to deploy platforms on
  other resources. 





