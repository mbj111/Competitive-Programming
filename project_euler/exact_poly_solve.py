import numpy as np

def fun(n):
    return 1 - n + n**2 - n**3 + n**4 - n**5 + n**6 - n**7 + n**8 - n**9 + n**10

ans = np.zeros(shape = (300, 1), dtype = np.float64)
def generate_ten():
    for i in range(300):
        ans[i] = fun(i)

generate_ten()

def solve():
    sum_ = 0
    for i in range(12):
        A = np.zeros(shape = (i+1, i+1), dtype = np.int64)
        for j in range(i+1):
            for k in range(i+1):
                A[j][k] = j**k
        #print A
        b = np.array( ans[0:i+1], dtype = np.int64)
        #print b
        sol = np.linalg.solve(A, b)
        print sol
        
        for j in range(300):
            temp = 0
            for k in range(i+1):
                temp += sol[k]*(j**k)
            print i, temp, ans[j]
            if not np.isclose(temp,ans[j]):
                sum_ += temp
                break
        print "\n"
    print np.int64(sum_)


solve()
