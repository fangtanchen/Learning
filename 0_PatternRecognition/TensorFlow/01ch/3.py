import tensorflow as tf

with tf.device('/gpu:0'):
    a=tf.constant([1.0,2.0,3.0,4.0,5.0,6.0],name="a")
    b=tf.constant([1.0,2.0,3.0,4.0,5.0,6.0],name="b")
    c=tf.matmul(a,b)


