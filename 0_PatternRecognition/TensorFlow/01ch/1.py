import tensorflow as tf
a=tf.add(3,5)

with tf.Session() as sess:
    print sess.run(a)
    print a

print a
