.. _project_namedisambugiuty:

Author Name Disambiguation for Bibliometric Data
======================================================================

Motivation
----------------------------------------------------------------------

It is common to evaluate authorsship with common metrics such as
h-index, g-index, i-index and other similar metrics. However, these
metrics assume that an author can be identified without
ambiguity. Hence, it is importamt that bibliometric databases contain
correct information and distinguish between various authors. However,
this may be a difficult problem in practice as different databases use
different auther identifieres. Furthermore authors may even have same
names and same institutions. In other cases we find that authors have
changed their lastnames. Even if the databases are currated by
authors, those that do not participate in the curration step will
presenta challange in leading to an accurate database. All this
contributes to a situation in which it is challanging to gurantee
accuracy.

Task
----------------------------------------------------------------------

Develop a framework that addresses issues in the author disambiguity
problem. First start with a brief literature review and identify
various solutions conducted for example by IEEE, Google, Microsoft,
Research Gate, cite seer, and others. Find a literature review that
may even use full text analysis.

Identify a solution that you chose whch could be a combination of
approaches. Demonstarte your solution and identify the issue based on
data you obtain from the XSEDE database (provided under limitetd
distribution rights to you) and other data sources that are freely
available such as from IEEE, and others.

Develop a statistical method that provides a confidence interval
showing the likelyhood of papers written by an outhor with the same
name (note the name could be incomplete or even misspelled) are the
same. Do the same if you find an author that has actually changed its
name.  Test your algorithm on a large database of users and provide a
histogram about how good your algorithm performs. Identify potential
categories of good and bad performing entries and discuss the result.

Prior work:

* https://github.com/scienceimpact/bibliometric.git

Screenshots:

 .. image:: images/Relationship_Authors_Publications.png
 
* https://github.com/scienceimpact/bibliometric/blob/master/Project%20Screenshots/Relationship_Authors_Publications.PNG?raw=true

* https://github.com/scienceimpact/bibliometric/blob/master/Project%20Screenshots/Relationship_Authors_Publications2_Clusters.PNG?raw=true

Example of possible useful Technologies for this Project
----------------------------------------------------------------------

* graphdb
* neo4j
* Apache Giraph
* mongodb
* d3.js
* sql
* REST


Artifacts
----------------------------------------------------------------------

* Working program
* Detailed instalation instructions
* Easy to use install program using DevOps 
* Integration of the instalation into a cloudmesh command
* Report written in IEEE format in LaTeX or Word
* Original images used in the report 
* To make citation of scholarly work easier we recommend that you use
  a bibliography management tool such as endnote for word or bibtex
  for LaTex. In case of MS Word, if you do not have access to endnote,
  please use the build in citation manager from Word.
  


Note that the reference of previous work is neither a statement for
good or bad work of that project. There is always something one can
improve.

Optional Artifacts
----------------------------------------------------------------------

Develop a rest service that given two publications and an authorname,
that returns if the authors are identical. Return also the likelyhood.

This is a minor modification to the above and provides just a rest
interface to your work.
