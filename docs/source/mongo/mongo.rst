MongoDB
======================================================================


authenticated login
----------------------------------------------------------------------

::

  mongo
  use auth
  db.auth("admin", "password")

Show
----------------------------------------------------------------------

::

   show dbs

Use
----------------------------------------------------------------------

::

  use cloudmesh


Status via mongoengine
----------------------------------------------------------------------

db = Document._get_db()
client_count = db.command("serverStatus")["connections"]['current'] - 1  



javascripts

db.collection.count({username: "my_username"});

ObjectId("505bd76785ebb509fc183733").getTimestamp();

// Will profile all queries that take 100 ms
db.setProfilingLevel(1, 100);

// Will profile all queries
db.setProfilingLevel(2);

// Will disable the profiler
db.setProfilingLevel(0);

db.currentOp() - shows you all currently running operations
db.killOp(opid) - lets you kill long running queries
db.serverStatus() - shows you stats for the entire server, very useful for monitoring
db.stats() - shows you stats for the selected db
db.collection.stats() - stats for the specified collection


mongotop - shows how much time was spend reading or writing each collection over the last second
mongostat - brilliant live debug tool, gives a view on all your connected MongoDB instances
