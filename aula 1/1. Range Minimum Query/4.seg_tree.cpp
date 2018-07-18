#include <bits/stdc++.h>
using namespace std;

#define MAXN 112345
#define INF INT_MAX

int n;
int v[MAXN];
int seg[4*MAXN];
int com[4*MAXN];
int fim[4*MAXN];

int prep(int node, int ncom, int nend){
    if(seg[node]!=INF)return seg[node];
    com[node]=ncom;
    fim[node]=nend;
    if(ncom==nend){
        seg[node]=v[ncom];
        return seg[node];
    }
    int nmid=(ncom+nend)/2;
    seg[node]=min(prep(2*node,ncom,nmid),prep(2*node+1,nmid+1,nend));
    return seg[node];
}

void prep(){
    for(int i=0;i<=4*n;i++)seg[i]=INF;
    prep(1,0,n-1);
}

int query(int node, int i, int j){
    if(j<com[node]||i>fim[node])return INF;
    if(i<=com[node]&&j>=fim[node])return seg[node];
    return min(query(2*node,i,j),query(2*node+1,i,j));
}

int query(int i, int j){
    return query(1,i,j);
}

void change(int node, int index,int x){
    if(index<com[node]||index>fim[node])return;
    if(com[node]==fim[node])seg[node]=x;
    change(2*node,index,x);change(2*node+1,index,x);
    seg[node]=min(seg[2*node],seg[2*node+1]);
}

void change(int i, int x){
    v[i]=x;
    return change(1,i,x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
     
    int testes;
    cin>>testes;

    while(testes--){

        cin>>n;

        for(int i=0;i<n;i++)cin>>v[i];

        prep();

        int q;
        cin>>q;

        for(int t=0;t<q;t++){
            char c;
            cin>>c;
            if(c=='q'){
                int i,j;
                cin>>i>>j;
                cout<<query(i,j)<<endl;
            }
            if(c=='c'){
                int i, x;
                cin>>i>>x;
                change(i,x);
            }
        }
    }    
    return 0;
}