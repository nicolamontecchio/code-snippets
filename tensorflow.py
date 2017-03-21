import tensorflow as tf

# parsing tfrecords manually
record_iterator = tf.python_io.tf_record_iterator(path=tfrecords_filename)
for string_record in record_iterator:
    example = tf.train.Example()
    example.ParseFromString(string_record) # NB: IN-PLACE

# more complete example
def read_from_tfrecords_file(fpath, n_samples):
  record_iterator = tf.python_io.tf_record_iterator(path=fpath)
  labels = []
  words = []
  for string_record in islice(record_iterator, n_samples):
    example = tf.train.Example()
    example.ParseFromString(string_record)
    _l = example.features.feature['label'].int64_list.value[0]
    _w = example.features.feature['words'].int64_list.value[:]
    labels.append(_l)
    words.append(_w)
  return np.array(labels), np.array(words)
