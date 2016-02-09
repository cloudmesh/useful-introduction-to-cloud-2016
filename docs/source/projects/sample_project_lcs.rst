.. _ref-class-project-lcs:

MapReduce Implementation for Longest Common Substring Problem
-------------------------------------------------------------------------------

Project Idea
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This type of projects focus on implementing parallel programming for solving a
particular problem. One example here is using Python programming language to
use map() and reduce() functions to find the longest repeating string in the
E-coli K-12 Genome on Amazon Cloud. The main goals are 1) implementing Python
map() and reduce() functions to find LCS (longest common substring), and 2)
running hem on Amazon Cloud. The real challenges are 1) defining a problem, 2)
finding an algorithm to solve the problem, and 3) implementing your idea or
algorithm in Python. Using commercial cloud, e.g. Amazon, Azure or Google is to
have some experience with the cloud services to utilize computing resources
available.

Project Overview
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Description: This project aims to measure similarity of genome sequences.
  MapReduce has benefits for generic comparison compared to other algorithms in
  terms of computation speed.

  Quoted from the book Cormen, Leiserson, Rivest and Stein’s
  classic reference, “Introduction to Algorithms” (CLRS for short). The longest
  common subsequence problem as follows::

  In biological applications, we often want to compare the DNA of two (or more)
  different organisms. […] For example, the DNA of one organism may be S1 =
  ACCGGTCGAGTGCGCGGAAGCCGGCCGAA while the DNA of another organism may be S2 =
  GTCGTTCGGAATGCCGTTGCTCTGTAAA. One goal of comparing two strands of DNA is to
  determine how “similar” the two strands are, as some measure of how cosely
  related the two organisms are.

Dataset
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Escherichia coli K-12 <http://www.genome.wisc.edu/pub/sequence/U00096.2.fas>`_

Technologies
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - Python
    - Amazon

Source
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   - http://wordaligned.org/articles/longest-common-subsequence
   - http://donniedemuth.s3.amazonaws.com/bioinf_with_python_and_hadoop.pdf

Tips
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
You can use Python MapReduce frameworks such as:

   - `Disco <http://discoproject.org/>`_
   - `octo.py <https://code.google.com/p/octopy/>`_
   - `mincemeat.py <https://github.com/michaelfairley/mincemeatpy>`_
   - `mrjob <https://pythonhosted.org/mrjob/>`_


