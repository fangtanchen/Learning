import sys

def haha():
    def pp():
        #global x
        x[0]=2
        print(x[0])
    for i in range(10):
        pp()

if __name__=='__main__':
    x=[1];
    haha()

