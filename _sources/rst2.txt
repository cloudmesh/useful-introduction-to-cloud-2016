.. _howto-sphinx-ref:


Sphinx Quick Reference Guide
============================

This is a brief overview of Sphinx formatting that is easy to mixup,
and it is provided here as a reminder. The official Sphinx website has
an extensive guide on the uses and nuances of reStructured Text.

`Sphinx Official Webpage  <http://sphinx.pocoo.org/contents.html>`_

Section Headings
****************

Headings in order of specificity such that each heading level may not
contain a heading preceding it::

        %%%%%%%%%%%%%%%%%%%%%%
	Master Doc Top Heading
	%%%%%%%%%%%%%%%%%%%%%%
	
	  -The percent signs should only be used in the contents.rst root document.

	###############
	Section Heading
	###############

        ***************
        Chapter Heading
        ***************

	Major Heading
	=============
	
	Minor Heading
	*************
	
	Major Subsection
	----------------

	Minor Subsection
	^^^^^^^^^^^^^^^^

	Paragraph
	"""""""""

Labels and References
*********************

You can use labels to cross-reference arbitrary locations in any document 
through :ref: and :doc: roles. For this to work, label names must be unique 
throughout the entire documentation. You can label a section with .. _label-name: 
(two periods, one space, one underscore, followed by the label name and a colon). 
If you place a label directly before a section title, you can reference to it 
with :ref:. The :ref: role would then generate a link to the section, the link 
title being the section title.

There is also a way to directly link to documents, using the :doc: role; the 
document name can be specified in absolute or relative fashion.::

    .. _label-name:
    
    #############
    Section Title
    #############

    Here is a reference to label-name: :ref:`label-name`
    Here is a direct document link: :doc:`file-name`

Text Formatting
***************

*Italic Text Here*::

    *Italic Text Here*

**Bold Text Here**::
    
    **Bold Text Here**

`Italic Text Here, too.`::
 
    `Italic Text Here, too.`

``Highlighted Text Here``::

    ``Highlighted Text Here``

- Bullet List Item0
- Bullet List Item1

    - Child Bullet0 (notice the extra lines + indent)
    - Child Bullet1 

- Bullet List Item2::

    - Bullet List Item0
    - Bullet List Item1
        
        - Child Bullet0 (notice the extra lines + indent)
   	- Child Bullet1 

    - Bullet List Item2

Bullet lists may use one of three bullet characters: '*', '+', or '-'.
This documentation will use the '-' character for bullet lists.

#. Numbered Item 0
#. Numbered Item 1
#. Numbered Item 2::
    
    #. Numbered Item 0
    #. Numbered Item 1
    #. Numbered Item 2

Figures and Images
******************

An image may be placed into a page using::

    .. image:: image-name.jpeg

Similarly, a figure (a graphic with a caption) may be added::

    .. figure:: fig1.png

       Caption goes here.

Codeblocks and Samples
**********************

When you have example code that you want to display, simply precede the
code lines with two colons and indent the code::

    Review the following script::

        Line 1
	Line 2
	Line 3

Sphinx provides syntax highlighting through Pygments if it is installed. 
The default environment for sphinx is Python, so if you want to provide example
code in another language, you can do so as follows::

    .. code-block:: c

       Some C code

A piece of literal text, such as code can be displayed inline, as opposed to
the codeblock style, using :samp: as shown below::

    Use :samp:`print 1+{variable}` to ...

The curly braces indicate a "variable part" of the text, and will be displayed
differently than the other text.

Notes and Warnings
******************

When there is important information that needs to be displayed to a user,
you can use a note or a warning. A warning is recommended for information
regarding security. Here is an example usage::

    .. note::

       This is a note for the user.

    .. warning::
       
       If you don't warn the user about security information, bad stuff can happen.

Downloads and Files
*******************

To link to a file within your source tree for downloading you can use 
the :download: role. All downloadable files are put into the _downloads
subdirectory of the output directory. An example::

    Please download :download:`this example script <../example.py>`.

The example.py file will be copied to your output directory upon building.

When you want to refer to a file or directory that is being discussed, 
use the :file: role. In the case of a variable file name 
(such as a version number), curly braces should surround the variable section::

    The file is installed in :file:`/usr/lib/python2.{x}/site-packages` ...

TODO items
**********

You can compile a list of todo items throughout all documentation using the
todo directive::

    .. todo::
       This directive is useful to remember what needs to be done.

When you want to display a list of all todo items, use the todolist directive::

    .. todolist::
       This directive is replaced by a list of all todo directives in the
       whole documentation.

Autodoc
*******

The sphinx extension ``autodoc`` provides a simple way to extract python 
docstrings from your objects and output them in a combined documentation.

This is accomplished through the use of directives such as the following::

    .. automodule::
    .. autoclass::
    .. autoexception::

All three of those directives will by default only insert the docstring of the object itself::

    .. autoclass:: Noodle

will produce source like this::

    .. class:: Noodle

       Noodle's docstring

You can mix automatic and non-automatic member documentation like so::

    .. autoclass:: Noodle
       :members: eat, slurp

       .. method:: boil(time=10)

          Boil the noodle *time* minutes.

Also supported are the following directives::

    .. autofunction::
    .. autodata::
    .. automethod::
    .. autoattribute::

For module data members and class attributes, documentation can be done in two
different styles. Either a special-formatted comment *before* the attribute
definition, or in a docstring *after* the definition. This is shown below::

    class Foo:
        """Docstring for class Foo."""

	#: Doc comment for attribute Foo.bar.
	bar = 1

	baz = 2
	"""Docstring for attribute Foo.baz.""" 

For more information on autodoc usage, see the `Sphinx autodoc page
<http://sphinx.pocoo.org/ext/autodoc.html?highlight=autodoc#sphinx.ext.autodoc>`_
