#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int read(){
	int Res=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') f=(ch=='-'?-f:f),ch=getchar();
	while (ch>='0'&&ch<='9') Res=Res*10+ch-'0',ch=getchar();
	return Res*f;
}
int N,ML,MD,tot,lnk[1005],son[22005],nxt[22005],w[22005];
ll dis[1005],Min;
bool vis[1005],boo[1005],use;
void add(int x,int y,int z){son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;}
queue<int>Que;
void spfa(int x){
	if (vis[x]) return (void)(use=1);
	vis[x]=boo[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (dis[son[i]]>dis[x]+w[i]){
			dis[son[i]]=dis[x]+w[i];
			spfa(son[i]);
			if (use) return (void)(vis[x]=0);
		}
	}
	vis[x]=0;
}
void spfa(){
	memset(dis,192,sizeof dis);
	Que.push(1);vis[1]=1;dis[1]=0;
	while (Que.size()){
		int Now=Que.front();Que.pop();vis[Now]=0;
		for (int i=lnk[Now];i;i=nxt[i]){
			if (dis[son[i]]<dis[Now]+w[i]){
				dis[son[i]]=dis[Now]+w[i];
				if (!vis[son[i]]){
					vis[son[i]]=1;Que.push(son[i]);
					if (dis[Que.front()]>dis[Que.back()]) swap(Que.front(),Que.back());
				}
			}
		}
	}
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	N=read();ML=read();MD=read();
	for (int i=1;i<=ML;i++){
		int x=read(),y=read(),D=read();
		add(x,y,D);
	}
	for (int i=1;i<=MD;i++){
		int x=read(),y=read(),D=read();
		add(y,x,-D);
	}
	for (int i=1;i<=N;i++) {if (!boo[i]) spfa(i);if (use) return puts("-1"),0;}
	for (int i=1;i<=N;i++) add(i,i+1,0),add(i+1,i,0);
	memset(vis,0,sizeof vis);
	spfa();
	if (dis[N]==dis[0]) return puts("-2"),0;
	printf("%lld\n",dis[N]);
	return 0;
}
