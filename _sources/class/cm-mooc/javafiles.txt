JavaFiles
==========

The course provides some examples to run the course Programs in Java. You can run the programs locally or on the cloud with the cm-mooc virtual machine.
In this documentation, we focus on how to run the Java programs on the virtual machine.

`cm-mooc` virtual machine on India
-----------------------------------

If you don't know the running `cm-mooc` on India Futuresystems, please refer `cm-mooc </introduction_to_cloud_computing/class/cm-mooc.html>`_.
We assume that you have launched the virtual machine and you are staying in $HOME directory on the virtual machine.

.. note:: To remind you how to use the virtual machine, please see the
  following commands::

    localhost$ ssh -X $PORTALNAME@india.futuresystems.org
    india$ module load fg455
    india$ cm-mooc login
    vm$ cd JavaFiles

Run Programs
-------------

X Window System (X11) should be enabled on your desktop to view plotting data. Java and other libraries are pre-installed on the VM.


Programs Location
^^^^^^^^^^^^^^^^^^

On the VM, `JavaFiles` directory contains course programs::

  vm$ cd ~/JavaFiles

Run Each Program
^^^^^^^^^^^^^^^^^^
Makefile allows you to compile java programs easily, and to run.

In each directory, please execute::
  
  vm$ make      # compile
  vm$ make run  # run Java Program

The Elusive Mr. Higgs
^^^^^^^^^^^^^^^^^^^^^^

This course program is for the unit 9 in the section 4.::
  
  vm$ cd ~/JavaFiles/Section-4_Physica-Units-9-10-11/Unit-9_The-Elusive-Mr.Higgs/
  vm$ make
  vm$ make run

Example of the plotting data is:

.. image:: /images/javafiles/higgs1.png

.. note::

  Other programs have same templates to compile and run.

Run Programs on a local machine
--------------------------------

Download programs and dependencies.:

- Programs::
 
       $ git clone https://github.com/cglmoocs/JavaFiles.git

- Dependencies::

       $ git clone https://github.com/cglmoocs/Dependencies.git
    
.. note::

  Make sure that the dependencies are included in CLASSPATH for your Java.


List of Programs
-----------------
There are 5 programs under ~/JavaFiles directory on the virtual machine.

- In Section 4, Unit 9, `The Elusive Mr. Higgs <https://github.com/cglmoocs/JavaFiles/tree/master/Section-4_Physics-Units-9-10-11/Unit-9_The-Elusive-Mr.Higgs>`_
- In Section 4, Unit 11, A Calculated Dice Roll.
- In Section 7, Unit 19, K'th Nearest Neighbor Algorithms.
- In Unit 27, PageRank.
- In Unit 28, K Means Clustering.

