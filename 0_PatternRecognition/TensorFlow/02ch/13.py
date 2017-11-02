import tensorflow as tf

a=tf.placeholder(tf.float32,shape=[3])
b=tf.constant([5,5,5],dtype=tf.float32)

add_op=a+b

with tf.Session() as sess:
    print sess.run(add_op,{a:[1,2,3]})

