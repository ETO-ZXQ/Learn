class Fushu:
    def __init__(self, a, ai, b, bi):
        self.a = a
        self.ai = ai
        self.b = b
        self.bi = bi
        self.shi = 0
        self.xu = 0

    def add(self):
        self.shi = self.a + self.b
        self.xu = self.ai + self.bi

    def minus(self):
        self.shi = self.a - self.b
        self.xu = self.ai - self.bi

    def multiply(self):
        self.shi = self.a * self.b - self.ai * self.bi  # ab - aibi
        self.xu = self.a * self.bi + self.b * self.ai

    def devide(self):
        di = self.ai * self.ai + self.bi * self.bi
        self.shi = (self.a * self.b + self.ai * self.bi)/di
        self.xu = (self.a * self.bi + self.b * self.ai)/di

    def p(self):
        strshi = str(self.shi)
        if self.xu == 0:
            strxu = ''
        elif self.xu > 0:
            strxu = '+' + str(self.xu) + 'i'
        else:
            strxu = str(self.xu) + 'i'
        print(strshi + strxu)


c = Fushu(27, 25, 23, -67)
c.add()
d = Fushu(27, 25, 23, -67)
d.multiply()
e = Fushu(27, 25, 27, 25)
e.multiply()

c.p()
d.p()
e.p()

print("---验证-16的四分之一次方的根---")

n = Fushu(-1.414, 1.414, 1.414, -1.414)
n.multiply()
a = Fushu(n.shi, n.xu, n.shi, n.xu)
a.multiply()
n.p()
a.p()