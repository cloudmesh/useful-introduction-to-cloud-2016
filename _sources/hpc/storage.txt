
.. _s-storage:

Storage Services
======================================================================

Using Indiana University's Storage Services from FutureSystems
----------------------------------------------------------------------

FutureSystems does not provide an HPSS server. However, if you have an IU
account (available only for IU faculty, staff, affilates, and
students), you can use the following services from india:

* `SDA <http://rc.uits.iu.edu/storage/sda>`__ service
* `HSI <http://rc.uits.iu.edu/storage/hsi>`__, the Hierarchical Storage
Interface client is available in india. 

To use the HSI client on india:

-  First, activate your SDA account as descreibed in the `MDSS Service Starter
   Kit <http://rc.uits.iu.edu/storage/mdss-starter-kit>`__ documentation.
-  Then, from india, load the HSI module as follows::

    $ module load hsi
    hsi version 3.5.3 loaded

-  Connect to the SDA::

    $ hsi -A combo
    Principal: your_iu_userid                                
    [youriuid]Password:                                
    Username: your_iu_userid  UID: 1122636  Acct: 1122636(1122636) Copies: 1 Firewall: off [hsi.3.5.3 Fri Nov 20 10:01:25 EST 2009]
    ?

Your principal is your IU Network ID, and your password is
the IU passphrase.

-  Enable firewall mode; otherwise, you will receive this error::

    put: Error -5 on transfer

    ? firewall -on
    A: firewall mode set ON, I/O mode s<et to extended (parallel=off), autoscheduling currently set to OFF

-  List local folder::

     ? lls
     testfile.txt

-  List the current directory in HPSS::

    ? pwd
    pwd0: /hpss/pathtoyouriuusername

-  For transferring files (*put* and *get*), search the `IU Knowledge
   Base <http://kb.iu.edu/?search=hsi>`__.

-  To exit HSI::

   ? exit

-  For a summary of available HSI commands::

    ? help
    
    You can also type "hsi -?" to get just a command line summary

    HPSS File and Directory Commands
    --------------------------------
    get, cget, mget, recv            - Copy HPSS file to local directory
    put, cput, mput, replace, save, store, send - Copy a local file to HPSS
    cp, copy                         - Copy a file within HPSS
    delete, mdelete, erase, rm       - Remove a file from HPSS
    ls, list                         - List directory
    pwd                              - Print current directory
    find                             - Traverse a directory tree looking for a file
    ln                               - Create symbolic link in HPSS
    mv, move, rename                 - Rename an HPSS file
    mkdir, md, add                   - Create an HPSS directory
    rmdir, rd, remove                - Delete an HPSS directory
    cd, cdls                         - Change current directory
    touch                            - Update last access time

    Local File and Directory Commands
    ---------------------------------
    lcd, lcdls  - Change local directory
    lls         - List local directory
    lpwd        - Print current local directory
    !<command>  - Issue shell command

    File Administrative Information
    -------------------------------
    chgrp  - Change group id of file or directory
    chmod  - Change permissions of file or directory
    chown  - Change owner of file or directory
    umask  - Set file creation permission mask

    Storage Hiearacy Commands
    -------------------------
    lscos   - List available Classes of Service

    Keywords
    --------
    set, default - Change keyword value
    COSLIST      - COS list name to use for subsequently created files
    DIRn         - Set working directory
    TALK         - Turns on/off verbose mode
    BACKUP       - Keep a copy of overwritten files

    Saved Keysets
    -------------
    adopt  - Load a keyset
    free   - Delete a keyset
    keep   - Save a keyset
    show   - Display a keyset

    HSI commands
    -----------
    help             - Display help file
    quit, exit, end  - Terminate HSI
    glob             - Toggle wildcard expansion
    hash             - Toggle file transfer hashmarks
    in               - Read commands from a local file
    out              - Write HSI output to a local file
    log              - Write all HSI commands and responses to a local log file
    bell             - Toggles terminal bell
    prompt           - Toggles HSI prompting for mget, mput, and mdelete


    HSI is a command driven interface to the HPSS Mass Storage System.

    HSI can accept input several different ways:
      From a command line.     Example: hsi
      Single line execution.   Example: hsi "mkdir foo; cd foo; put data_file"
      From a command file.     Example: hsi "in command_file"

    HSI can read from standard input and write to standard output.  
    Command line example:
      tar cvf - . | hsi put - : data.tar
      hsi get - : data.tar | tar xvf -
    Interactive example:
      put "|tar cvf - *.c"  : data.tar
      get "|tar xvf -" : data.tar

    WARNING: For 'get' and 'put' operations, HSI uses a different syntax
     than FTP to identify the local file name.  The syntax uses a ':' to
     identify the local file name.  See section 5.8 of the online documentation
     for details.  Example:  put local_file : hpss_file

    Recursive operations are allowed for the following commands:
     cget, chgrp, chmod, chown, cput, delete, get, ls, mdelete, mget,
     migrate, mput, purge, put, rm, stage, touch

    Wildcards are supported.  See section 5.9 of the online documentation.

    The complete HSI manual is online at http://www.sdsc.edu/Storage/hsi

