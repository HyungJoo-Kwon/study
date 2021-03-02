## Variable 클래스

import numpy as np


class Variable:
    def __init__(self, data):
        self.data = data


data = np.array(1.0)
x = Variable(data)
print(x.data)

x.data = np.array(2.0)
print(x.data)


# x = np.array(1)  // 0차원 배열, 스칼라
# x.ndim  >>  0  

# x = np.array([1, 2, 3]) // 1차원 배열, 벡터
# x.ndim  >>  1

# x = np.array([[1, 2, 3],[4, 5, 6]]) // 2차원 배열, 행렬, 3차원 벡터
# x.ndim  >>  2

C:\Users\w\Desktop\deeplearining\밑바닥3 그림과 수식\그림 1-2.png