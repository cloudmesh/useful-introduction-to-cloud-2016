.. _ref-class-project-fingerprint-matching:

Fingerprint Matching
===============================================================================

Introduction
-------------------------------------------------------------------------------

Fingerprint recognition refers to the automated method for verifying a match
between two fingerprints and that is used to identify individuals and verify
their identity. Fingerprints (Figure 1.) are the most widely used form of
biometric used to identify individuals.

.. figure:: ../images/projects/nist_project_fingerprint_loop.jpg
   
.. figure:: ../images/projects/nist_project_fingerprint_whorl.jpg

   Figure 1. Shows two sample fingerprints.

The automated fingerprint matching generally required the detection of
different fingerprint features (aggregate characteristics of ridges, and
minutia points) and then the use of fingerprint matching algorithm, which can
do both one-to-one and one-to-many matching operations. Based on the number of
matches a proximity score (distance or similarity) can be calculated.

Algorithms
-------------------------------------------------------------------------------
For this work we will use the following algorithms:

* MINDTCT: The NIST minutiae detector, which automatically locates and records
  ridge ending and bifurcations in a fingerprint image.
  (http://www.nist.gov/itl/iad/ig/nbis.cfm)

* BOZORTH3: A NIST fingerprint matching algorithm, which is a minutiae based
  fingerprint-matching algorithm. It can do both one-to-one and one-to-many
  matching operations. (http://www.nist.gov/itl/iad/ig/nbis.cfm)

Datasets
-------------------------------------------------------------------------------
We start with one of the following datasets for the study:

* Special Database 27a (Free Sample Data) http://www.nist.gov/itl/iad/ig/sd27a.cfm
* Special Database 14 - NIST Mated Fingerprint Card Pairs 2.
* Special Database 29 - Plain and Rolled Images from Paired Fingerprint Cards. 
* Special Database 30 - Dual Resolution Images from Paired Fingerprint Cards.
(http://www.nist.gov/itl/iad/ig/special_dbases.cfm)

Possible Tools
-------------------------------------------------------------------------------
* Big Data:
  Apache Hadoop or Apache Spark, Apache HBase, 
* Development:  
  Java, Python, Scala.

.. include:: nist_footer.rst
