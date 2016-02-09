Local PBS Queuing System
======================================================================

Overview
----------------------------------------------------------------------

Sometimes users may want to emulate the behavior of PBS on a local machine. This is useful to develop sophisticated job specifications or to emulate a queuing system as available on supercomputers. Often the installation of a full version of torque or other batch systems may be too much effort.

A solution is to install LPBS available at

https://github.com/goerz/LPBS

Duration: 1 hour

Installation
----------------------------------------------------------------------

LPBS is written in python and therefore can be installed easily with::

   pip install LPBS 

After you install it you need to configure it and make sure you have a directory in which you place the temporary files and the configuration file. We assume that we use the directory `~/qsub'. Make sure you are not already using the qsub directory. To complete the setup do the following:

   mkdir -p ~/qsub/scratch

Edit the .bashrc file and add the line::

  export LPBS_HOME=~/qsub

Now place the following file in ~/qsub/lpbs.cfg::

    [Server]

    # Full hostname of submission server (hostname.domain). Will be made available
    # to running job through the environment variable PBS_SERVER. Job IDs will end
    # in the server hostname

    hostname: localhost
    domain: local


    [Node]

    # Full hostname of the execution node (hostname.domain). Will be made available
    # to running job through the environment variable PBS_O_HOST. Since LPBS is
    # designed to execute jobs locally, the settings here should in general be
    # identical to those in the [Server] section

    hostname: localhost
    domain: local


    [LPBS]

    # Setting for job execution.
    # If 'username_in_jobid' is enabled, the job IDs will have the form
    # 'seqnr.user.hostname.domain' where 'user' is the username of the user
    # submitting the job.
    # The file given in 'sequence_file' is used for keeping track of the 'seqnr'
    # appearing in the job ID.
    # The file given in 'logfile' is used for logging all LPBS events. Both
    # 'sequence_file' and 'logfile' are relative to $LPBS_HOME.

    username_in_jobid: 0
    sequence_file: sequence
    logfile: lpbs.log


    [Scratch]

    # Settings for the scratch space provided to jobs. 'scratch_root' defines a
    # location where jobs should write temporary data. If given as a relative path,
    # it is relative to $LPBS_HOME. Environment variables will be expanded at the
    # time of the job submission.
    # If the value of # 'create_jobid_folder' is set to 1, a folder with the name of
    # the full job ID is created inside scratch_root. This folder is automatically
    # deleted when the job ends, unless 'keep_scratch' is set to 1. If the job
    # failed, the scratch will not be deleted, unless 'delete_failed_scratch' is set
    # to 1.

    scratch_root: $HOME/qsub/scratch
    create_jobid_folder: 1
    keep_scratch: 0
    delete_failed_scratch: 0


    [Notification]

    # Settings on how the user should be be notified about events such as the start
    # and end of a job. If sent_mail is set to 1, emails will be sent for
    # notifications depending on the value of the '-m' option to lqsub. If
    # 'send_growl' is set to 1, Growl (http://growl.info) is used for notification
    # on MacOS X. Notifications via Growl do not take into account the '-m' options
    # during job submission.

    send_mail: 0
    send_growl: 0


    [Mail]

    # SMTP settings for email notifications. Notification emails will be sent from
    # the address given by the 'from' option. The SMTP server given in 'smtp' is
    # used for sending the emails, if 'authenticate' is set to 1, authentication is
    # done with the given 'username' and 'password'. If 'tls' is 1, TLS encryption
    # will be used.

    from: nobody@example.org
    smtp: smtp.example.com:587
    username: user
    password: secret
    authenticate: 0
    tls: 1


    [Growl]

    # Settings for Growl notifications. Notifications are sent to either localhost
    # or a remote host via the GNTP protocol. The 'hostname' setting gives the
    # address and port of the Growl server, the given 'password' is used for
    # authentication (note that if sending to localhost, no authentication is
    # necessary). If 'sticky' is set to 1, the Growl notifications will be sticky.
    # It is possible to send notifications to more than one host. In this case, both
    # 'hostname' and 'password' should be a comma-separated list of values, with
    # each item corresponding to one host.

    hostname: localhost:23053
    password:
    sticky: 0


    [Log]

    # 'logfile' gives the name of the central log file, relative to $LPBS_HOME.

    logfile: lpbs.log


.. note:: To avoid a little bug in the program you need to set in the cfg file `create_jobid_folder: 1`

Usage
----------------------------------------------------------------------

Now you can use the commands lqsub, lqstat, and lqdel.

Thus this is now a different kind of virtual cluster ;-)

A simple script is::

    #PBS -N pbstest
    #PBS -j oe
    #PBS -l nodes=1:ppn=1
    #PBS -l walltime=00:00:10
    #PBS -l mem=10mb
    #PBS -o pbstest.out

    echo "####################################################"
    echo "User: $PBS_O_LOGNAME"
    echo "Batch job started on $PBS_O_HOST"
    echo "PBS job id: $PBS_JOBID"
    echo "PBS job name: $PBS_JOBNAME"
    echo "PBS working directory: $PBS_O_WORKDIR"
    echo "Job started on" `hostname` `date`
    echo "Current directory:" `pwd`
    echo "PBS environment: $PBS_ENVIRONMENT"
    echo "####################################################"

    echo "####################################################"
    echo "Full Environment:"
    printenv
    echo "####################################################"

    echo "The Job is being executed on the following node:"
    cat ${PBS_NODEFILE}
    echo "##########################################################"

    echo "PUT YOUR COMMANDS TO BE EXECUTED HERE"

    echo "##########################################################"
    echo "Job Finished: " `date`
    exit 0



Prerequisites
----------------------------------------------------------------------

We recommend that you use python 2.7.9, with virtualenv. 

Exercises
----------------------------------------------------------------------

Exercise 1
----------------------------------------------------------------------

Install LPBS on a virtual machine on India

Exercise 2
----------------------------------------------------------------------

Install LPBS on multiple virtual machines on India. Develop a program that lists all jobs on the VMs

Exercise 3
----------------------------------------------------------------------

Develop a python script that modifies the .bashrc file if $LPBS_HOME is not set in the environment.

Exercise 4
----------------------------------------------------------------------

Develop a python that conducts a full deployment of LPBS while using a single command-line. Use python docopts to pass the parameters. We expect the following to work::

  lpbs_install [--dir=LPBS_HOME]

if the --dir option is ommitted use ~/qsub as default. Install the configuration file that you find in this example. To uninstall we have a command::

   lpbs_install --uninstall

This will delete the installation and the directory, as well as trying to remove the LPBS_HOME variable in .bashrc. If the later can not be found through an exception.

Exercise 5
----------------------------------------------------------------------

Use chef for deployment.

Exercise 6
----------------------------------------------------------------------

Use puppet for deployment.

Exercise 7
----------------------------------------------------------------------

Use ansible for deployment.











Acknowledgment
----------------------------------------------------------------------

The configuration files and job script are modifications of the once found at https://github.com/goerz/LPBS
