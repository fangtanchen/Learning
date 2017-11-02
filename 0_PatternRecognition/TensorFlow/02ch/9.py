import tensorflow as tf

a=tf.constant(2)
W=tf.Variable(10)
op_assign=W.assign(100)

with tf.Session() as sess:
    print sess.run(W.initializer)
    print W
    print W.eval()
    print sess.run(op_assign)
    print W
    print W.eval()
    print a.eval()
