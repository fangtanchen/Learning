import tensorflow as tf

a=tf.constant([2,3],name="a")
b=tf.constant([[0,1],[2,3]],name="b")

x=tf.add(a,b,name='add')
y=tf.multiply(a,b,name='mul')
z=tf.zeros([2,3],tf.int32)

with tf.Session() as sess:
    r,s,t=sess.run([x,y,z])
    print r
    print s
    print t

with tf.Session() as sess:
    r,s,t=sess.run([x,y,z])
    print r
    print s
    print t

input_tensor=tf.constant([[0,1],[2,3],[4,5]],name="input_tensor")
z=tf.zeros_like(input_tensor)
h=tf.fill([2,3],9)
with tf.Session() as sess:
    p,q=sess.run([z,h])
    print z
    print p
    print h
    print q
