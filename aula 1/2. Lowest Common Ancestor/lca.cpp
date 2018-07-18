#include <bits/stdc++.h>
using namespace std;

#define MAXN 112345
#define LOG_MAXN 20
#define INF INT_MAX

//define k as ceiling of log of MAXN
 
int n;
vector<int> are[MAXN];
int h[MAXN];
int lc[LOG_MAXN][MAXN];
 
//node, parent, height
void lca_dfs(int u, int p, int ha){
	h[u]=ha;
	lc[u][0]=p;
	for(int i=1;i<LOG_MAXN;i++)
		lc[i][u]=lc[i-1][lc[i-1][u]];
	for(int v:are[u]){
		if(v!=p)lca_dfs(v,u,ha+1);
	}
}
 
int lca(int u, int v){
	if(h[u]>h[v])swap(u,v);
	for(int i=LOG_MAXN-1;i>=0;i--){
		if(h[lc[i][v]]>=h[u])v=lc[i][v];
	}
	if(u==v)return u;
	for(int i=LOG_MAXN-1;i>=0;i--){
		if(lc[i][u]!=lc[i][v]){
			u=lc[i][u];
			v=lc[i][v];
		}
	}
	return lc[0][u];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int t;
	cin>>t;
	int num=1;
 
	while(t--){
		int n,f,inf,q,a,b;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f;
			for(int j=0;j<f;j++){
				cin>>inf;
				are[i].push_back(inf);
				are[inf].push_back(i);
			}
		}
		lca_dfs(1,1,0);
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>a>>b;
			cout<<lca(a,b)<<endl;
		}
		for(int i=1;i<=n;i++)are[i].clear();
	}
 
	return 0;
} 
 