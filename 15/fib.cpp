#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
int MOD;
struct mat{ll x[2][2];}c;
inline void operator *=(mat& a,const mat& b)
{
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			c.x[i][j]=(a.x[i][0]*b.x[0][j]
			+a.x[i][1]*b.x[1][j])%MOD; a=c;
}
mat qp(mat a,ll n)
{
	mat x;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			x.x[i][j]=(i==j);
	while(n)
	{
		if(n&1) x*=a;
		a*=a; n>>=1;
	}
	return x;
}
ll Fib(ll n,int p)
{
	MOD=p; mat r;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			r.x[i][j]=(i||j);
	return qp(r,n).x[1][0];
}
const int R=998244353;
inline ll gcd_(ll a,ll b) {return b?gcd_(b,a%b):a;}
inline ll gcd(ll a,ll b)
{ll g=gcd_(a,b); return (g<0)?(-g):g;}
char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
ll aa,bb;ll F(){
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
#define gll F()
#define BUFSIZE 5000000
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pint(int x)
{
    if(x==0) {pc(48); return;}
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
int main()
{
	int q=gll;
	while(q--)
	{
		ll n=gll; int a=gll,b=gll,c=gll,d=gll;
		if(a+b<=0||c+d<=0||a<0||b<0||c<0||d<0
		||a>1000||b>1000||c>1000||d>1000
		||n>1000000000000000000LL) throw "invalid data";
		while(1)
		{
			if(c<a) swap(c,a),swap(b,d);
			if(!a) break;
			int k=c/a; c-=k*a; d-=k*b;
		}
		swap(c,a),swap(b,d);
		if(c) throw "GG"; c=d;
		//gcd(a*F[n]+b*F[n+1],c*F[n+1])
		ll ans;
		if(a==0) ans=gcd(b,c)*Fib(n+1,R);
		else if(c==0) ans=a*Fib(n,R)+b*Fib(n+1,R);
		else
		{
			ll g=gcd(a,Fib(n+1,a));
			ll t=Fib(n,g*c)*a+Fib(n+1,g*c)*b;
			t%=g*c; if(t%g) throw "GG";
			ans=g*gcd(t/g,c);
		}
		pint(int(ans%R+R)%R); pc(10);
	}
	cerr<<clock()<<"ms\n";
}

