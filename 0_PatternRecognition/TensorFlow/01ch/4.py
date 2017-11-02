import tensorflow as tf

g1=tf.get_default_graph()
g2=tf.Graph()

with g1.as_default():
    a=3
    b=5
    add_op=tf.add(a,b)
    with tf.Session() as sess:
        print sess.run(add_op)

with g2.as_default():
    a=5
    b=5
    mul_op=tf.multiply(a,b)
    with tf.Session() as sess:
        print sess.run(mul_op)
        c=sess.run(mul_op)
        print c
