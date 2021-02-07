import cv2
import tensorflow.compat.v1 as tf

print(cv2.__version__)
print(tf.__version__)
print("hi 안녕")

x = [[1, 2, 3]]
y = [[1, 2, 3]]

W = tf.placeholder(tf.float32)