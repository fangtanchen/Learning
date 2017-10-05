import tensorflow as tf

W=tf.Variable(tf.truncated_normal([700,10]))
U=tf.Variable(2*W.initialized_value())

with tf.Session() as sess:
    sess.run(U.initializer)
    print W
    print U.eval()
