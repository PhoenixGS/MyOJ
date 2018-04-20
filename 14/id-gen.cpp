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
struct trie
{
int ch[500223][26],an,ml[500223],ls;
trie() {an=ls=1;}
void xjbb()
{
	int s=1;
	while(s<=an&&rand()%2) s*=2;
	int l=max(ls-s,1),r=min(ls+s*3,an);
	int x=l+rand()%(r-l+1),c=rand()%26;
	ls=x; if(!ch[x][c]) ch[x][c]=++an;
}
int go(int x,int c)
{
    if(!ch[x][c]) ch[x][c]=++an;
    return ch[x][c];
}
void xjb()
{
	while(an<400000) xjbb();
	{
		int l=80000,x=1;
		while(l--) x=go(x,rand()%26);
	}
	{
		int l=20000,x=1;
		while(l--) x=go(x,rand()%26);
	}
	cerr<<an<<"=\n";
	for(int i=an;i>=1;--i)
	{
		for(int j=0;j<26;++j)
			ml[i]=max(ml[i],ml[ch[i][j]]);
		++ml[i];
	}
}
string gen(int l)
{
	int x=1; string s;
	while(l)
	{
		vector<int> ss;
		for(int j=0;j<26;++j)
			if(ml[ch[x][j]]>=l) ss.pb(j);
		int j=ss[rand()%ss.size()];
		x=ch[x][j]; s.pb(j+'a'); --l;
	}
	return s;
}
}t[3];
int S=150000,q=150000;
vector<int> gen(int l)
{
	int s=l/3;
	vector<int> w;
	while(l>s)
	{
		int ww=2;
		if(rand()%5==0)
		for(int j=1;j<=10&&
		rand()%2==1;++j)
			ww<<=1;
		if(rand()%3) ww=1;
		int x=rand()%min(ww,l-s)+1;
		w.pb(x); l-=x;
	}
	int sb=2*sqrt(s)+1;
	while(l)
	{
		int x=min(rand()%sb+1,l);
		w.pb(x); l-=x;
	}
	reverse(w.begin(),w.end());
	return w;
}
vector<int> v[3];
string st[533333][3];
vector<int> ct[3][533333];
#include <windows.h>
int main()
{
	srand(time(0)^GetTickCount()); 
	int aa; cin>>aa; S=q=aa;
	for(int i=0;i<3;++i) t[i].xjb();
	cerr<<"generated trie\n";
	int n;
	while(1)
	{
	v[0]=gen(S/3);
	v[1]=gen(S/3);
	v[2]=gen(S/3);
	n=min(min(v[0].size(),v[1].size()),v[2].size());
	v[0].resize(n); v[1].resize(n); v[2].resize(n);
	int su=0;
	for(auto r:v[0]) su+=r;
	for(auto r:v[1]) su+=r;
	for(auto r:v[2]) su+=r;
	if(su<S/20.0*19) continue;
	su=(S-su)/3;
	cerr<<su<<"=\n";
	while(su--)
		++n, v[0].pb(1), v[1].pb(1), v[2].pb(1);
	break;
	}
	cerr<<"n="<<n<<"\n";
	cerr<<"generated ABC\n";
	printf("%d\n",n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
			st[i][j]=t[j].gen(v[j][i]);
		printf("%s %s %s\n",st[i][0].c_str(),
		st[i][1].c_str(),st[i][2].c_str());
		for(int j=0;j<3;++j)
		{
			int x=1;
			for(auto r:st[i][j])
			{
				ct[j][x].pb(i);
				x=t[j].ch[x][r-'a'];
			}
			ct[j][x].pb(i);
		}
	}
	cerr<<"written strings\n";
	string s[3];
	vector<int> ps[3];
	for(int i=0;i<3;++i)
		ps[i].pb(1);
	int mx=0;
	printf("%d\n",q);
	char*cur=0,*ed; int kk,cl=0,mxx=0;
	for(int i=1;i<=q;++i)
	{
		//if(i%5000==1&&i>mxx) mxx=i,cerr<<i<<"\n";
		if(cl)
		{
			bool clr=1;
			for(int j=0;j<3;++j)
				clr&=s[j].size()<=2;
			if(clr) cl=0;
		}
		if(cur&&cur==ed) cur=0,kk=-1,cl=1;
		int k,c;
		if(!cur&&!cl)
		{
		k=rand()%3;
		vector<int>&v=ct[k][ps[k].back()];
		int mat=v.size()?v[rand()%v.size()]:(-1);
		if(mat==-1||s[k].size()==st[mat][k].size())
		{
			if(rand()%5==0)
				c=rand()%26;
			else c=-1;
		}
		else
		{
			if(rand()%2==0)
				c=-1;
			else
			{
				if(rand()%30==0)
				{
				cur=&st[mat][k][s[k].size()];
				ed=&st[mat][k][st[mat][k].size()];
				int rs=100;
				while(rs<200&&rand()%2) rs<<=1;
				ed=min(ed,cur+rs);
				kk=k;
				}
				else c=st[mat][k][s[k].size()]-'a';
			}
		}
		}
		if(cur!=0)
		{
			k=kk; c=*(cur++)-'a';
		}
		if(cl) k=rand()%3,c=-1;
		if(!s[k].size()&&c==-1) {--i; continue;}
	//	if(i%max(q/200,400)==0) cl=1,cur=0;
		if(c==-1) printf("- %d\n",k+1),
		s[k].pop_back(),ps[k].pop_back();
		else printf("+ %d %c\n",k+1,c+'a'),
		s[k].pb(c),ps[k].push_back(t[k].ch[ps[k].back()][c]);
		mx=max(mx,(int)s[k].size());
	}
	cerr<<mx<<"\n";
}

