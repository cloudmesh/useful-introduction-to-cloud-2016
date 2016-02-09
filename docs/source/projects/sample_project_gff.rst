.. _ref-class-project-gff:

MapReduce Implementation for GFF Parsing
-------------------------------------------------------------------------------

Project Idea
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is similar to the example of the Longest Common Substring Problem. The
main goals of this project are to define a problem and to implement solutions
in Python with known frameworks and tools.

Project Overview
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Description: Generic feature format (GFF) is a nice plain text file format
  for storing annotations on biological sequences, and would be very useful
  tied in with the BioSQL relational database. GFF parsing is a little tricker
  to fit into the Biopython SeqIO system than other sequence file formats.
  Formats like GenBank or UniProt contain a sequence and its features combined
  into a single record. This allows parsers to iterate over files one at a
  time, returning generic sequence objects from each record. This scales with
  large files so your memory and processor worries are bounded by the most
  complicated record in the file.

* Map Function::

  def _gff_line_map(line, params):
    strand_map = {'+' : 1, '-' : -1, '?' : None, None: None}
    line = line.strip()
    if line[0] != "#":
            parts = line.split('\t')
            should_do = True
            if params.limit_info:
                    for limit_name, limit_values in params.limit_info.items():
                            cur_id = tuple([parts[i] for i in
                                    params.filter_info[limit_name]])
                            if cur_id not in limit_values:
                                    should_do = False
                                    break       

* Reduce Function::

  def _gff_line_reduce(map_results, out, params):
      final_items = dict()
      for gff_type, final_val in map_results:
        send_val = (simplejson.loads(final_val) if params.jsonify else
        final_val)
        try:
               final_items[gff_type].append(send_val)
        except KeyError:
              final_items[gff_type] = [send_val]
      for key, vals in final_items.items():
        out.add(key, (simplejson.dumps(vals) if params.jsonify else vals))

Dataset
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

N/A

Techonologies
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - Python
    - Disco
    - Amazon EC2

Source
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

http://bcb.io/2009/03/22/mapreduce-implementation-of-gff-parsing-for-biopython/


