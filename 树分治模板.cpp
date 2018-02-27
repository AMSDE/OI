#include<cstdio>
#include<algorithm>
#define maxn 100005
#define maxe 200005
using namespace std;
int N;
int tot,lnk[maxn],nxt[maxe],son[maxe];
int Sum,Root,F[maxn],Size[maxn];
bool vis[maxn];
inline int read(){
	int Res=0;char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') Res=Res*10+ch-'0',ch=getchar();
	return Res;
}
inline void getrt(int x,int fa){
	F[x]=0;Size[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]||son[i]==fa) continue;
		getrt(son[i],x);
		Size[x]+=Size[son[i]];
		F[x]=max(F[x],Size[son[i]]);
	}
	F[x]=max(F[x],Sum-Size[x]);
	if (F[x]<F[Root]) Root=x;
}
inline void Solve(int x){
	vis[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]) continue;
		Root=0;Sum=Size[son[i]];
		getrt(son[i],0);
		Solve(Root);
	}
}
inline void add(int x,int y){son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;}
int main()
{
	N=read();
	for (int i=1;i<N;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	Sum=N;F[0]=2e9;
	getrt(1,0);
	Solve(Root);
	return 0;
}
