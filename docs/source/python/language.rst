
Lanaguage Features
==================================================================

Print
-----------------------------------------------------------------
.. runblock:: pycon

   >>> print "Hello Cloud"

Comments
-----------------------------------------------------------------

Simple comment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. runblock:: pycon

   >>> # this is a comment

Multiline Comment with "
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
::

   """ 
   this is a multiline comment 
   """

Multiline Comment with '
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
::

   '''
   this is a multiline comment
   '''

Variables
-----------------------------------------------------------------
.. runblock:: pycon

   >>> flavor = "tiny"
   ... print flavor

Changing the variable Value
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. runblock:: pycon

   >>> flavor = "large"
   ... print flavor

List
-----------------------------------------------------------------
.. runblock:: pycon

    >>> list = [1, 2, 3, 4, 5, 6]
    ... print list[0]
    ... print list[len(list)-1]
    ... print list[2:5]



For Loop 
-----------------------------------------------------------------
.. runblock:: pycon

    >>> list = [1, 2, 3, 4, 5, 6]
    ... for element in list:
    ...   print element


.. runblock:: pycon

   >>> flavors = ['tiny', 'medium', 'large']
   ... for flavor in flavors:
   ...   print flavor

If Condition
-----------------------------------------------------------------
.. runblock:: pycon

   >>> flavor = "tiny"
   ... if flavor == "tiny":
   ...    print("vanilla has a tiny flavor")
   ... elif flavor == "large":
   ...    print("large flavor")
   ... else:
   ...    print("this flavor I do not like")


Arithmetic Operators
-----------------------------------------------------------------
.. runblock:: pycon

    >>> list = [1, 2, 3, 4, 5, 6]
    ... print sum(list)
    ... print min(list)
    ... print max(list)
    ... print sum(list)/len(list)
    ... print sum(list)/float(len(list))

Functions
----------------------------------------------------------------------

Function to do calculations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. runblock:: pycon

    >>> def f(x,y):
    ...   return x+y+ y*y + x*x
    ...
    ... print f(1,2)
    ... print f(4,6)


Functions for String Manipulation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. runblock:: pycon

    >>> def name(firstname, lastname):
    ...   return "%s %s" % (firstname, lastname)
    ...
    ... def reversename(firstname, lastname):
    ...   return "%s, %s" % (lastname, firstname)
    ...
    ... print name('Gregor', 'von Laszewski')
    ... print reversename('Gregor', 'von Laszewski')


   



Excersises
==================

her is the task i like you to do to reinforce the learning experience once you are done with the tutorial.

#. Write a program that uses loops over both x and y coordinates while x is in 1,2,3,4,5 and y is in 5,4,3,2,1 and prints the x and y coordinate
#. Write a program that sums up all values in x and y
#. Write a program just like the first task but does not print values where x is equal to 2 and y is equal to 4
#. Write a function that takes in a word and returns  it in reverse order
#. Provide a program that uses dicts
#. Read up on classes and write a program that uses classes.
#. We will create an icecream machine that produces icecream in with tiny flavor, medium flavor and large flavor. 
#. In addition the icecream cone will be wrapped into some paper  that has an image on it. Images will be Penguin, Apple, Emperor, King

