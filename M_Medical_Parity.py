import sys

def x_should(x,y):
    n = len(y)
    diff = 0
    ones = 1
    xx = [0] * n
    xx[0] = 1
    if y[0] == 0:
        ones = 0
        xx[0] = 0
        
    for c in range(1, n):
        if y[c] == 1:
            ones += 1
            if ones % 2 == 0:
                xx[c] = 0
            else:
                xx[c] = 1
    for c in range(n):
        if x[0] != xx[0]:
            diff += 1
            
            
def y_should(x, y):
    n = len(x )