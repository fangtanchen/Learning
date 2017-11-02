import tensorflow as tf

a=tf.linspace(10.0,13.0,4)
b=tf.range(10,14,3)

with tf.Session() as sess:
    print a
    print sess.run(a)
    print b
    print sess.run(b)
