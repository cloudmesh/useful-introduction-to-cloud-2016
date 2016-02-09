.. _ref-class-project-live-twitter:

Live Twitter Analysis
===============================================================================
   
Introduction
-------------------------------------------------------------------------------

   Social media for many people has become integral part of their daily life.
   Social media metrics are now considered parts of altmetrics, which are
   non-traditional metrics proposed as an alternative to more traditional
   metrics.

Twitter is an online social networking service that enables users to send and
read short 140-character messages called "tweets". Registered users can post
and read tweets, but general public can also read them. This is unlike
Facebook, where social interactions are often private. Users access Twitter
through the website interface, SMS, or mobile device app.  

We will develop a program(s) for live Twitter Analysis based on using Twitter's
Search and Streaming APIs for sentiment analysis and visualization of results
(Figure 1).  We will also analyze and visualize NIST Twitter network.  We can
track and statistically analysis the NIST mentions, followers, retweets,
compare it to other National labs, and many more things. The analysis could
help NIST, measure and improve our effectiveness in engaging public about our
work and our outreach effort on Twitter.


.. figure:: ../images/projects/nist_project_twitter.png

   Figure 1. Show different Twitter visualizations

We could develop the application based on Apache Storm, a distributed
computation framework, which adds reliable real-time data processing
capabilities to Apache Hadoop. It is fast, scalable, reliable and can be
programmed using a variety of programming languages (Python, Java, Scala). Its
architecture consists of three primary node sets: Nimbus nodes, Zookeeper
nodes, and Supervisor nodes.  

Algorithms
-------------------------------------------------------------------------------

* Sentiment Analysis:
Sentiment analysis or opinion mining refers to the use of natural language
processing and text analysis to identify and extract subjective information in
source materials. Normally speaking, sentiment analysis aims to determine the
attitude of a speaker or a writer with respect to some topic or the overall
contextual of a document(s). 

Examples of words used for Sentiment analysis:
        Positive: nice, awesome, cool, superb, etc.
        Negative: bad, uninspired, expensive, disappointed, recommend others to
        avoid, etc.

Datasets
-------------------------------------------------------------------------------

Live Twitter feed

Possible Tools
-------------------------------------------------------------------------------

* Big Data: Apache Strom, Apache HBase, Twitter's Search and Streaming APIs, 
  
* Visualization tools: D3 Visualization, Tableau visualization.
 
* Development tools:  Java, Python, Scala and JavaScript, JQuery

* Natural Language Processing Algorithms: Python Natural Language Toolkit
  (NLTK) and AlchemyAPI Service.

.. include:: nist_footer.rst
