import tensorflow as tf

# parsing tfrecords manually
record_iterator = tf.python_io.tf_record_iterator(path=tfrecords_filename)
for string_record in record_iterator:
    example = tf.train.Example()
    example.ParseFromString(string_record) # NB: IN-PLACE
