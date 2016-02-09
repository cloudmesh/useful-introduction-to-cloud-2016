Shell
======================================================================

Basic Shell Commands
----------------------------------------------------------------------

A part of cloud computing experiences you may come across the use of
basic Linux commands from a command shell. These commands are simple
abbreviations for tasks related to managing directories and files, but
also let you gain access to remote computers.

A simple list of those commands include::

  ls         # List the files in a directory.
  cp         # Copy files.
  mv         # Move or rename files.
  rm         # Remove files.  
  rm -r      # Remove entire directory subtree.
  cd         # Change directories.
  pwd        # Print working directory.
  cat        # Lists a file or files sequentially.
  more       # Displays a file a screen at a time.
  less       # Variant on "more".
  mkdir      # Make a directory.
  rmdir      # Remove a directory.
  echo $HOME # prints the home directory path
  uname      # prints information about the operating system
  hostname   # prints the name of the host
  whoami     # prints the username that you are logged in at

To access a remote machine you can use the command::

  ssh

In case you like and are able to forward X11 features back to you yo
may want to log into the remote machine with the -Y or -X flags. Thus,
to login into the machine india@futuresystems.org (on which you must have
an account, lets assume your account name is albert), you can say::

  ssh -X albert@india.futuresystems.org

The detailed manual pages to such commands can be found for example in
the command shell when you type in `man` followed by the command
name.  Thus::

  man ls

will provide you with the manual page about the ls command. You can
also look up such commands via google while typing man and the command
name into google search. You can also directly go to 

* https://www.kernel.org/doc/man-pages/

and type in the name of the command in the search form. Very popular
are also reference cards from the various Linux variants. You can find
them at

* `Debian Linux reference card
  <https://www.debian.org/doc/manuals/refcard/refcard>`_
* `Another Linux reference card
  <http://files.fosswire.com/2007/08/fwunixref.pdf>`_


Editors that Work in a Terminal
----------------------------------------------------------------------

At time you may come across the situation where the only access you
have to a remote computer is through a terminal that does not allow
you to run any fancy graphics. However, how do you edit now files if
the normal editors you have access to are not installed? In many cases
you will find the editors `vi` and `emacs` on your systems. If they
are not, you may have to install them. If you have not yet learned an
editor and you need to learn one, we recommend that you learn
emacs. It is possible to learn it just by studying the Emacs reference
cards that you can find on the internet. Just remember the CTRL-g that
allows you to cancel things in case something goes wrong.

* `Emacs reference card <http://www.gnu.org/software/emacs/refcards/pdf/refcard.pdf>`_

If you like to find out more about these editors. Please search for
more tutorials and documentations online.

For vi such a reference card is available at

* http://www.ks.uiuc.edu/Training/Tutorials/Reference/virefcard.pdf

Exercises
----------------------------------------------------------------------

#. Get an account on the machine india.futuresystems.org
#. Log into futuresystems.org
#. Try out some of the commands listed above
#. Become aware of the disastrous consequences that you can do with
   the rm command
#. Try out one of the editors
