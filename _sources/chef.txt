DevOps
======================================================================

* combinaition of terms *Development* and *Operation*


Vagrant
======================================================================



Chef
======================================================================

* go to http://learn.getchef.com/rhel/get-a-virtual-machine/ and do the tutorial

* install http://docs.getchef.com/install_dk.html

* chef verify

echo 'eval "$(chef shell-init bash)"' >> ~/.bash_profile


just client

* curl -L https://www.getchef.com/chef/install.sh | sudo bash

Berkshelf
======================================================================

Berkshelf manages an applications cookbooks and its dependencies.  It
allows to use chef recipies from others and reduce replication of the
recipies while avoiding to duplicate them in your own repository or
recipies. Berkshelf uses berkfiles to manage the recipies. If you have
an existing cookbook, you can create a bersksfile in an existing
directory containing the recipe with::

  berks init .

In case you like to start a new a new cookbook (lets assume the name
is <mycookbook> can create on with::

   berks create <mycookbook>

Than you can specify the dependencies in the Berksfile such as::

  source "https://supermarket.getchef.com"
  metadata
  cookbook "git"

To install the cookbooks just say::

  berks install

The cookbooks will tahn be located in::

  ~/.berkshelf






vagrant plugin install vagrant-berkshelf --plugin-version 2.0.1


Example
======================================================================

::

    mkdir cookbooks
    cd cookbooks
    chef generate cookbook cm_test
    tree

::

  .
  └── cm_test
      ├── Berksfile
      ├── README.md
      ├── chefignore
      ├── metadata.rb
      └── recipes
	  └── default.rb

  2 directories, 5 files

renerate a template::

   chef generate template cm_test index.html

update default.rb



chef-client --local-mode --runlist cm_test


running scripts 

https://docs.getchef.com/resource_script.html

running python ;-)

https://docs.getchef.com/resource_python.html
