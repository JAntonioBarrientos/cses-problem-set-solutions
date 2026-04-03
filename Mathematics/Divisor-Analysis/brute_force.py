import sys

def myf(x):
    l = 1
    r = x
    ans = 1
    while l <= r:
        m = l+(r-l)//2
        if m*m <= x:
            ans = m
            l = m+1
        else:
            r = m-1
    return ans

def solve():
    input = sys.stdin.readline()
    n = int(input)
    fact = []
    num = 1
    for i in range(n):
        input = sys.stdin.readline().split()
        l = list(map(int, input))
        fact.append(l)
        num *= l[0] ** l[1]
    print(num)
    div = []
    mult = 1
    for i in range(1, num+1):
        if num % i == 0 :
            div.append(i)
            mult *= i
    
    print(div)
    print(mult)

    fact= []
    print(myf(mult))
    for i in range(2, 10):
       if mult% i == 0 :
           base = i
           con = 0
           while mult% i == 0:
               con+=1
               mult/= i
           fact.append([base, con])
    print(fact)



            






if __name__ == '__main__':
    solve()



