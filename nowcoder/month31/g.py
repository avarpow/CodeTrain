a = int(input())
for i in range(0, a):
    s = input().split(' ')
    q = int(s[0])
    w = int(s[1])
    if(q <= 1):
        print(-1)
    else:
        k = 0
        while(q**k <= w):
            k = k+1
        print(k-1)
