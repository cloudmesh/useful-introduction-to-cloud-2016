.. _ref-class-lesson-project-examples:

Sample Projects
===============================================================================

.. sidebar:: Page Contents
   :maxdepth: 1

   .. contents::
      :local:

Notice
-------------------------------------------------------------------------------

These sample projects are only for your reference to give you some idea of a
final project.  We do not intend to limit your idea of projects. Instead, we
recommend that you define a problem and find topics and technologies from your
area of interest.  If you have other topics or concepts from the outside of the
class, please contact us to discuss your project. It may help find project
scope in practical.

Predicting Airline Delays with Hadoop
-------------------------------------------------------------------------------

Project Idea
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

One of the main goals is using machine learning algorithms to build predictive
models with Python packages and data analysis programs. Training the original
datasets is important to build models with its performance.  Finding a good
combination of technologies and programming languages would be cruicial to make
a successful project.

Project Overview
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Description: Every year approximately 20% of airline flights are delayed or
  cancelled, resulting in significant costs to both travellers and airlines.
  This project builds a supervised learning model that predicts airline delay
  from historial flight data and weather information.

* Dataset: `Airline delay dataset 2007, 2008 <http://stat-computing.org/dataexpo/2009/the-data.html>`_
* Technologies:
   - Hadoop
   - Apache Pig
   - Python
   - Pandas
   - HDFS
   - scikit-learn

.. figure:: ../../images/projects/ml1.png

   Average delays by month

.. figure:: ../../images/projects/ml2.png
   
   Average delays during a day

.. figure:: ../../images/projects/ml3.png

   Top 15 airlines for flight delay (Chicago O'Hare airport)

* Source: 
    - http://nbviewer.ipython.org/github/ofermend/IPython-notebooks/blob/master/blog-part-1.ipynb

Daily Variation of Barometric Pressure
-------------------------------------------------------------------------------

Project Idea
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This type of projects gives you some experience of data processing.
Rich Python modules i.e. Pandas, NumPy or Matplotlib allow you to import and
manipulate dataset in order to provide results in a graphical format.

Project Overview
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Description: Daily variation of barometric pressure (maximum minus minimum
  for each day) in inches, for the past 12 months. For each of the hand-picked
  major cities, the 365 daily ranges for that city are histogrammed.
* Dataset: `Quality Controlled Local Climatological Data <http://cdo.ncdc.noaa.gov/qclcd/QCLCD?prior=N>`_
* Technologies: 
   - IPython Notebook 2.0 (Pandas, Numpy, matplotlib)
   - d3.js

.. figure:: ../../images/projects/GeoSparkGrams.png

   Figure 1. GeoSparkGrams of Daily Barometric Volatility*


* \*Source: 
   - http://nbviewer.ipython.org/urls/gist.githubusercontent.com/michaelmalak/dd5495a605a8b951da43/raw/472b180b46d50726326eda2a4704f7ee0e94f539/GeoSparkGram.ipynb
   - http://technicaltidbit.blogspot.com/2014/05/geosparkgrams-tiny-histograms-on-map.html

Data Visualization
-------------------------------------------------------------------------------

Project Idea
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The main goal of this type of projects is visulaizing datasets stored in a
database.  You may like to use relational databases (SQL based) but this
example uses document based (JSON like, BSON) structure to store information
and you gain some experience with document-oriented databases.

You have open data based on CSV files. The tasks include
creating a database and automating the loading of the latest open data CSV
extracts from Amazon Storage (S3) into a database. With D3.js and DC.js
visualization toolkits, you understand how to provide results in an interactive
mode.

Project Overview
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Description: DonorsChoose.org is a US based nonprofit organization that
  allows individuals to donate money directly to public school classroom
  projects. Public school teachers post classroom project requests on the
  platform, and individuals have the option to donate money directly to fund
  these projects. The classroom projects range from pencils and books to
  computers and other expensive equipments for classrooms. In more than 10
  years of existence, this platform helped teachers in all US states to post
  more than 7700,000 classroom project requests and raise more than
  $280,000,000. DonorsChoose.org is making the platform data open and available
  for making discoveries and building applications. In this tutorial we will be
  using one of the available datasets for building an interactive data
  visualization that represents school donations broken down by different
  attributes.

* Dataset: `Project dataset from DonorsChoose.org <https://s3.amazonaws.com/open_data/csv/opendata_projects.zip>`_
* Technologies:
   - D3.js
   - DC.js
   - Python
   - MongoDB

.. figure:: ../../images/projects/viz_demo.gif

   Figure 2. Interactive Data Visualization for donorschoose.org**

* \**Source:
   - http://adilmoujahid.com/posts/2015/01/interactive-data-visualization-d3-dc-python-mongodb/

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

* Dataset: `Escherichia coli K-12 <http://www.genome.wisc.edu/pub/sequence/U00096.2.fas>`_
* Technologies:
    - Python
    - Amazon

* Source:
   - http://wordaligned.org/articles/longest-common-subsequence
   - http://donniedemuth.s3.amazonaws.com/bioinf_with_python_and_hadoop.pdf

* Tips: You can use Python MapReduce frameworks such as:
   - `Disco <http://discoproject.org/>`_
   - `octo.py <https://code.google.com/p/octopy/>`_
   - `mincemeat.py <https://github.com/michaelfairley/mincemeatpy>`_
   - `mrjob <https://pythonhosted.org/mrjob/>`_

MapReduce Implementation for GFF Parsing
-------------------------------------------------------------------------------

Project Idea
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is similar to the example of the Longest Common Substring Problem. The
main goals of this project are to define a problem and to implement solutions
in Python with known frameworks and tools.

Project Overview
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Description: Generic feature format (GFF) is a nice plain text file format
  for storing annotations on biological sequences, and would be very useful
  tied in with the BioSQL relational database. GFF parsing is a little tricker
  to fit into the Biopython SeqIO system than other sequence file formats.
  Formats like GenBank or UniProt contain a sequence and its features combined
  into a single record. This allows parsers to iterate over files one at a
  time, returning generic sequence objects from each record. This scales with
  large files so your memory and processor worries are bounded by the most
  complicated record in the file.

* Map Function::

  def _gff_line_map(line, params):
    strand_map = {'+' : 1, '-' : -1, '?' : None, None: None}
    line = line.strip()
    if line[0] != "#":
            parts = line.split('\t')
            should_do = True
            if params.limit_info:
                    for limit_name, limit_values in params.limit_info.items():
                            cur_id = tuple([parts[i] for i in
                                    params.filter_info[limit_name]])
                            if cur_id not in limit_values:
                                    should_do = False
                                    break       

* Reduce Function::

  def _gff_line_reduce(map_results, out, params):
      final_items = dict()
      for gff_type, final_val in map_results:
        send_val = (simplejson.loads(final_val) if params.jsonify else
        final_val)
        try:
               final_items[gff_type].append(send_val)
        except KeyError:
              final_items[gff_type] = [send_val]
      for key, vals in final_items.items():
        out.add(key, (simplejson.dumps(vals) if params.jsonify else vals))

* Dataset: N/A
* Techonologies:
    - Python
    - Disco
    - Amazon EC2
* Source: http://bcb.io/2009/03/22/mapreduce-implementation-of-gff-parsing-for-biopython/
