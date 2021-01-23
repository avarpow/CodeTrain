a = int(input())
ans = 1
mod = 998244353
# print("a", a % 2)
if(a % 2):
    ans = ans * 4
    ans = ans % mod
b = a >> 1
# print("b", b)
now = 6
k = 0
while(b > 0):
    #print(k, "  ", ans)
    k = k+1
    if(b % 2):
        # print(now, "add  ", ans)
        ans = ans * now
        ans = ans % mod
    now = now * now
    now = now % mod
    b = b >> 1
print(ans)
