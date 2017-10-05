import tensorflow as tf
import numpy as np

a=tf.Variable(2,name="scalar")
b=tf.Variable([1.0,2.0],name="vector")
c=tf.Variable([[1,2],[3,4]],name="matrix")
W=tf.Variable(tf.zeros([784,10]))


init=tf.global_variables_initializer()
init_ab=tf.variables_initializer([a,b],name="init_ab")
with tf.Session() as sess:
    sess.run(init_ab)
    print sess.run(W.initializer)
    print a
    print b
    print W
    print a.eval()
    print W.eval()
