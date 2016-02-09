Adding new Commands via a Python Package        
===============================================================================

Exercise I
-------------------------------------------------------------------------------

(cm.1) This assignment will teach you how to add new commands to
cloudmesh while using the `cm-generate-command`. First read the
documentation and watch the video for an example to add a simple
command. After you successfully installed it, find a python package
that you like and can be installed with pip. Develop a new command
that has the following options (additional parameters may be used if
necessary). We use here the name your_command as a placeholder find a
better name for it::

  cm your_command deploy ...

      deploys the python package

  cm your_command start ...

      if the package has some services start them now

   cm your_command stop ...

       if the package has some services stop them  
   
   cm your_command run ...

       runs some useful command against the services

Alternatively, if you can not locate a good package, you can use 
shelve, while implementing the commands::

  cm shelve deploy
  cm shelve start --file=FILENAME     # filename of the shelve file
  cm shelve clear                                # removes the shelve file
  cm shelve set index data       # adds the data to the given index
  cm shelve delete index          # removes the data at the index
  cm shelve list                        # list the contents

Provide an extensive documentation while using docopts.

In a future task we will use what you have learned here to provide a
cm command that deploys and manages an advanced PaaS onto a virtual
cluster. For now we just do a simple version so you get familiar with
the concepts. Examples for such a bigger deployments are:

* pig
* zookeeper
* hadoop (already provided by cm)
* harp
* apache
* drupal
* others

You will sudo for many of them, thus india is not sufficient for the
more advanced PaaS. These are supposed to be done on a virtual cluster
while leveraging the `cm cluster` command.

