import tensorflow as tf
import numpy as np

print np.float32==tf.float32

a=11
op1=tf.ones_like(a)
op2=tf.zeros_like(a)

with tf.Session() as sess:
    print sess.run([op1,op2])

a=['apple','peach','banana']
#op1=tf.ones_like(a)
op2=tf.zeros_like(a)

with tf.Session() as sess:
    print sess.run([op1,op2])

a=[[True,False,True],
   [False,True,False],
   [True,False,False]]
op1=tf.ones_like(a)
op2=tf.zeros_like(a)

with tf.Session() as sess:
    print sess.run([op1,op2])
