#include <bits/stdc++.h>
using namespace std;
#define SZ 666666
int n;
#define pb push_back
typedef long long ll;
struct trie
{
int ch[500023][26],an;
trie() {an=1;}
int go(int x,int c)
{
    if(!ch[x][c]) ch[x][c]=++an;
    return ch[x][c];
}
int C,fs[500023],ls[500023],rv[500023];
void dfs(int x)
{
    if(!x) return;
    fs[x]=++C; rv[C]=x;
    for(int s=0;s<26;++s)
        dfs(ch[x][s]);
    ls[x]=C;
}
}t[3];
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
typedef pair<int,int> pii;
vector<pii> rs[500023];
vector<pair<pii,int> > qry[500023];
char str[500023];
int anss[500023];
#define fi first
#define mp make_pair
#define se second
vector<int> ps[3];
int su[SZ];
inline void edt(int x,int y)
{
	for(;x<=t[2].C;x+=x&-x) su[x]+=y;
}
inline int gs(int x)
{
	int ss=0;
	for(;x>=1;x-=x&-x) ss+=su[x];
	return ss;
}
int gs(int l,int r) {return gs(r)-gs(l-1);}
int main()
{
    scanf("%d",&n);
    int tl=0;
    for(int i=1;i<=n;++i)
    {
        int x[3];
        vector<int> vs; vs.pb(1);
        for(int j=0;j<3;++j)
        {
            scanf("%s",str);
            int g=1;
            for(int d=0;str[d];++d)
            {
                g=t[j].go(g,str[d]-'a');
				if(j==0) vs.pb(g); ++tl;
			}
            x[j]=g;
        }
#define forauto_(t,v) \
for(__typeof__(v.begin()) _=v.begin();_!=v.end();++_){__typeof__(*_) t=*_;
    	forauto_(t,vs)
	        rs[t].push_back(pii(x[1],x[2]));
	    }
    }
    cerr<<clock()<<"ms\n";
    cerr<<tl<<"!\n";
    if(tl>500000) throw "invalid data";
    for(int i=0;i<3;++i)
		t[i].dfs(1),ps[i].push_back(1);
    int q; scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        int s; char o[3],c[3];
        scanf("%s%d",o,&s); --s;
        if(o[0]=='+')
        {
            scanf("%s",c); int x=ps[s].back();
            ps[s].push_back(t[s].ch[x][c[0]-'a']);
        }
        else ps[s].pop_back();
        int x[3];
        for(int j=0;j<3;++j) x[j]=ps[j].back();
        if(x[0]&&x[1]&&x[2]);else continue;
        qry[x[0]].pb(mp(pii(x[1],x[2]),i));
    }
    for(int i=1;i<=t[0].C;++i)
    {
    	vector<pair<pii,pii> > vx;
    	forauto_(g,rs[i])
    		vx.pb(mp(pii(t[1].fs[g.fi],-2),pii(t[2].fs[g.se],0)));
    	}
    	forauto_(g,qry[i])
    		vx.pb(mp(pii(t[1].ls[g.fi.fi],1),pii(g.fi.se,g.se))),
			vx.pb(mp(pii(t[1].fs[g.fi.fi]-1,-1),pii(g.fi.se,g.se)));
		}
		sort(vx.begin(),vx.end());
    	forauto_(t,vx)
			if(t.fi.se==-2) edt(t.se.fi,1);
			else
				anss[t.se.se]+=t.fi.se*gs(
				::t[2].fs[t.se.fi],::t[2].ls[t.se.fi]);
		}
    	forauto_(t,vx)
			if(t.fi.se==-2) edt(t.se.fi,-1);
		}
    }
    cerr<<clock()<<"ms\n";
    for(int i=1;i<=q;++i)
    	pint(anss[i]),pc(10);
    cerr<<clock()<<"ms\n";
}
