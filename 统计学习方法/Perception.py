import random

class perception:
    def __init__(self, x, y, learn_rate=1.0):
        self.learn_rate = learn_rate
        self.x = x
        self.y = y
        self.getWB()
       
    def getWB(self):
        if len(self.x) == 0:
            print('There is no sample!')
            return
        self.n = len(self.x[0])
        for p in self.x:
            if len(p) != self.n:
                print('The dimension in samples is not consistent!')
                return
        self.w = [0.0 for p in range(self.n)]
        self.b = 0.0

    def multipy(self, i):
        ans = [self.x[i][j]*self.w[j] for j in range(self.n)]
        return sum(ans)

    def judge(self, i):
        return (self.b+self.multipy(i))*self.y[i]

    def checker(self):
        for i in range(len(self.x)):
            if self.judge(i) <= 0:
                print(self.judge(i))
                return True, i
        return False, None

    def update(self, i):
        self.w = [self.w[j]+self.learn_rate * self.x[i][j]*self.y[i] for j in range(self.n)]
        self.b = self.b+self.learn_rate*self.y[i]

    def fit(self):
        ans = self.checker()
        while ans[0]:
            self.update(ans[1])
            print('Sample x%d:'%(ans[1]+1), self.x[ans[1]], self.y[ans[1]])
            print('\tModel:', self.w, self.b)
            ans = self.checker()


x = [[1, 1], [5,2], [6,9], [4,3]]
y = [-1, -1, +1, +1]
#x = [[3,3], [4,3], [1,1]]
#y = [1, 1, -1]
tmp = perception(x, y)
tmp.fit()