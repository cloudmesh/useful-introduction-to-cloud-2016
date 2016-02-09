Title: Unsupervised Name Disambiguation Based on Clustering
======================================================================


**Technologies:**


**Description:**

Name ambiguity is a common problem exists in scientific literature due to two facts. One of them is that so often the author full name information is not available, e.g., Joan Smith and John Smith will both appear as J. Smith in author list of some paper. Another less common reason is that multiple authors share totally identical name.

There are plenty of related research in this area trying to attacking this problem. One quite common one is based on clustering technique. E.g., based on other available information such as co-authorship, research interests/fields, etc.

We now have a database with about 140K publications involving about 20k authors (author names) we are interested in. Currently the data is in MySQL database. Each publication has a title, and possible authors associated with it. Most of publications also have publication venue information. Co-authorship mapping is also available.

Your desired task is to grab the data, and put it into some NoSQL format such as MongoDB, or some other graph based database, e.g., neo4j. Then construct social networking alike graphs based on the data for the visualization. And then conduct clustering based approach to attack the name ambiguity problem, based on the co-authorship data, as well as other semantic information derived e.g. from the title and publication venue.

The desired development tool/framework is Python + Flask/Django + Ajax. Statistics and machine learning background would be necessary as well.

**Deliverables:**


**Extensions:**
