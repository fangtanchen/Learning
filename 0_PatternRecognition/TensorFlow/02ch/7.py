import tensorflow as tf

my_const=tf.constant([1.0,2.0],name="my_const")

with tf.Session() as sess:
    print sess.graph.as_graph_def()


