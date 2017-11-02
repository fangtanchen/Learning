import tensorflow as tf

x=2
y=3
add_op=tf.add(x,y)
mul_op=tf.multiply(x,y)
useless=tf.multiply(x,add_op)
pow_op=tf.pow(add_op,mul_op)

with tf.Session() as sess:
    z,notuseless=sess.run([pow_op, useless])
    print notuseless
    writer=tf.summary.FileWriter('./graphs/1',sess.graph)
    print z
    writer.close()
