#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,Res,A[400005],F[400005];
inline int read(){
	int Res=0;char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') Res=Res*10+ch-'0',ch=getchar();
	return Res;
}
int Nxt[32*400000+5][2],p;
#define W(k) bool((1<<k)&x)
inline void insert(int x){
	int rt=0;
	for (int i=31;i>=0;i--){
		if (!Nxt[rt][W(i)]) Nxt[rt][W(i)]=++p;
		rt=Nxt[rt][W(i)];
	}
}
inline int find(int x){
	int rt=0,Ans=0;
	for (int i=31;i>=0;i--){
		if (Nxt[rt][W(i)^1]) Ans+=1<<i,rt=Nxt[rt][W(i)^1];
		else rt=Nxt[rt][W(i)];
	}
	return Ans;
}
int main()
{
	N=read();
	for (int i=1,Now=0;i<=N;i++){
		A[i]=read();Now^=A[i];
		F[i]=max(F[i-1],find(Now));insert(Now);
	}
	memset(Nxt,0,sizeof Nxt);p=0;
	for (int i=N,Now=0;i;i--){
		Now^=A[i];
		Res=max(Res,F[i-1]+find(Now));insert(Now);
	}
	printf("%d\n",Res);
	return 0;
}
