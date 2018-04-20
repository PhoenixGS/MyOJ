q=int(raw_input())
qs=[map(int,raw_input().split(' ')) for a in range(q)]
mn=1
for t in qs:
    mn=max(mn,t[0]+1)
f=[0]*(mn+1)
f[0]=0
f[1]=1
for t in range(2,mn+1):
    f[t]=f[t-1]+f[t-2]
ans=0
def gcd(a,b):
    while b:
        a,b=b,a%b
    return a
for t in qs:
    n=t[0]
    print gcd(t[1]*f[n]+t[2]*f[n+1],t[3]*f[n]+t[4]*f[n+1])%998244353