.. _ref-class-notice:

Notice
===============================================================================

.. sidebar:: Page Contents

   .. contents::
         :local:

Change of OpenStack Group
-------------------------------------------------------------------------------

* Subject: Change of fg465 tenant to fg465a, fg465b, fg465c
* Date affected by: April, 30th 2015
* Affected Group: Entire BDOSSP Class Spring 2015
* Reason: To avoid a system issue (probably OpenStack bug) on a single large tenant
* Actions to be taken: Nothing but cautions on your account

Description
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``fg465`` tenant (group) will be replaced with multi-groups in India OpenStack
Juno. The accounts to the class will be split up into three groups: ``fg465a``,
``fg465b`` and ``fg465c``. After this change, you unfortunately experience
with:

* No access to VM instances on fg465
* No access to VM images on fg465
* Re-configuration of Cloudmesh (or re-installation)
* Multi groups in Horizon (OpenStack GUI)

*This change will be made transparent to you so you may not notice.*

We have assigned each student to a group, to see your group, run::

  source ~/.cloudmesh/clouds/india/juno/openrc.sh
  echo $OS_TENANT_NAME

Possible Issues
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
If you can't use ``nova`` commands, please report your issue with the output
message of executing the following commands:

::

  source ~/.cloudmesh/clouds/india/juno/openrc.sh
  module load openstack
  echo $OS_TENANT_NAME
  nova list

For the other issues, you may find answers in the FAQs below.

Details of the Change
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``~/.cloudmesh/clouds/india/openrc.sh``

* ``OS_TENANT_NAME=fg465`` will be replaced with either ``fg465a``, ``fg465b``
  or ``fg465c``

* 1/3 students will go into fg465a
* 1/3 students will go into fg465b
* Rest students will go into fg465c

Termination of ``fg465`` **IMPORTANT**
   - All VM instances will be terminated and cleaned.
   - Any work left on the instances will be deleted.

Contact
-------------------------------------------------------------------------------

We will try to make this change transparent to you but if you have any issues,
please inform us.

* TA Email : coursehelp@futuresystems.org
* Discussion Email: DiscussionBDOSSP37186@futuresystems.org

FAQs
-------------------------------------------------------------------------------

* Q. Can't find my VM instances in OpenStack Horizon.
* A. Try to change your group to ``fg465[a|b|c]``.

.. figure:: ../images/faqs/horizon_changing_groups.png

   Changing Group in Horizon

|  

* Q. I have data to be saved on fg465. How can I make a backup?
* A. If you can get access to your VM instance, try to make a copy of your
  data.  And move to a new instance.

| 


* Q. Can I use my keypairs?
* A. You will continue use the keypairs registered on fg465 in your new group.

|  

* Q. How do I know which group I am in?
* A. ``echo $OS_TENANT_NAME`` in a ssh terminal.

|  


* Q. I see ``ERROR (Unauthorized): The request you have made requires
  authentication. (HTTP 401)`` message.
* A. You have either a broken credential or in a wrong project group. Please
  contact us.

|  

* Q. I see ``ERROR (CommandError): You must provide an auth url via either
  --os-auth-url or env[OS_AUTH_URL] or specify an auth_system which defines a
  default url with --os-auth-system or env[OS_AUTH_SYSTEM]`` message.
* A. You have not enabled your credential. Run ``source
  ~/.cloudmesh/clouds/india/openrc.sh``

|  

* Q. I see ``Permission denied (publickey).`` message on my ssh command.
* A. It is related to your ssh keypair, not related to this change of
  ``fg465``. Please confirm you have a right key pair with your VM instance.

| 

* Q. I see ``ssh: connect to host xx.xx.xx.xx port 22: No route to host``
  message.
* A. It is because that your VM is not ready or you're trying to connect a
  wrong address. This message is not related to the change of ``fg465``.

