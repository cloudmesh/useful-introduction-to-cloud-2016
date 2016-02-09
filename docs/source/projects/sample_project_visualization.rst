.. _ref-class-project-visualization:

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

.. figure:: ../images/projects/viz_demo.gif

   Figure 2. Interactive Data Visualization for donorschoose.org**

Source
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   - http://adilmoujahid.com/posts/2015/01/interactive-data-visualization-d3-dc-python-mongodb/

Dataset
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Project dataset from DonorsChoose.org <https://s3.amazonaws.com/open_data/csv/opendata_projects.zip>`_

Technologies
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   - D3.js
   - DC.js
   - Python
   - MongoDB



