import tensorflow as tf

a=tf.constant([3,6])
b=tf.constant([2,2])

op_add=tf.add(a,b)
op_addn=tf.add_n([a,a,b])
op_mul=tf.multiply(a,b)
op_matmul=tf.matmul(tf.reshape(a,[1,2]),tf.reshape(b,[2,1]))
op_div=tf.div(a,b)
op_mod=tf.mod(a,b)

with tf.Session() as sess:
    u,v,w,x,y,z=sess.run([op_add,op_addn,op_mul,
                          op_matmul,op_div,op_mod])
    print u
    print v
    print w
    print x
    print y
    print z
