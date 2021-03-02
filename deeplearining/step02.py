## Function 클래스

import numpy as np


class Variable:
    def __init__(self, data):
        self.data = data


class Function:
    def __call__(self, input):  # f = Function() 형태로 함수의 인스턴스를 변수 f에 대입해두고, f() 형태로 __call__ 메서드 호출 가능.
        x = input.data
        y = self.forward(x)
        output = Variable(y)
        return output

    def forward(self, in_data):
        raise NotImplementedError()


class Square(Function):     # Function 클래스를 상속받음. https://wikidocs.net/16073
    def forward(self, x):
        return x ** 2



x = Variable(np.array(10))
f = Square()
y = f(x)
print(type(y))
print(y.data)

