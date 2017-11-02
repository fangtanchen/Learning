import tensorflow as tf

my_var=tf.Variable(2,name="my_var")
op_time2=my_var.assign(2*my_var)

with tf.Session() as sess:
    sess.run(my_var.initializer)
    print my_var.eval()
    sess.run(op_time2)
    print my_var.eval()
    sess.run(op_time2)
    print my_var.eval()
    sess.run(op_time2)
    print my_var.eval()
