====================================================
How to write good Python codes for Cloudmesh
====================================================

****************************************************
Code in Python
****************************************************
We use Python to develop Cloudmesh and we follow the Python coding style. In order to contribute to  Cloudmesh project, you need to have basic understanding of Python coding style. If you are new to Python, the following article will be a good start point:

* http://docs.python-guide.org/en/latest/writing/style/

PEP8 gives coding conventions for the Python code comprising the standard library in the main Python distribution, it is a Style Guide for Python Code and suggested to read:

* http://legacy.python.org/dev/peps/pep-0008/


Introduction to Python code quality checkers
====================================================
There are some very good tools to help you check your Python code quality, such as pep8, Pylint and autopep8

pep8
----------------------------------------------------
pep8 is a tool to check your Python code against some of the style conventions in PEP 8 (refer to: https://pypi.python.org/pypi/pep8).

install::

        pip install pep8

have a try::

        pep8 your_file.py

Pylint
-----------------------------------------------------
Pylint is a source code bug and quality checker for the Python programming language. It follows the style recommended by PEP 8 (refer ro: http://www.pylint.org/).

install::

        sudo apt-get install pylint

have a try::
  
        pylint your_file.py

autopep8
-----------------------------------------------------
autopep8 automatically formats Python code to conform to the PEP 8 style guide. It uses the pep8 utility to determine what parts of the code needs to be formatted. autopep8 is capable of fixing most of the formatting issues that can be reported by pep8 (refer to: https://pypi.python.org/pypi/autopep8/).

install::
  
        pip install --upgrade autopep8

have a try::
  
        autopep8 your_file.py

Using Python code quality checkers in editors
=====================================================
TBD...
