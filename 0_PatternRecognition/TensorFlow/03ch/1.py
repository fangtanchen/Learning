import tensorflow as tf

a=2
b=3

x=tf.add(a,b)
y=tf.multiply(a,b)
useless=tf.multiply(a,x)
z=tf.pow(y,x)

with tf.Session() as sess:
    z=sess.run(z)
    writer=tf.summary.FileWriter('./my_graphs/11',sess.graph)
    print z
    writer.close()
