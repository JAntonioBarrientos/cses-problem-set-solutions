import sys


def solve():
    input = sys.stdin.readline().split()
    n, k = map(int, input)
    input = sys.stdin.readline().split()
    primes = list(map(int, input))
    cnt = 0
    for i in range(1, n+1):
        for p in primes:
            if i % p == 0:
                cnt+=1
                break
    print(cnt)

if __name__ == '__main__':
    solve()
