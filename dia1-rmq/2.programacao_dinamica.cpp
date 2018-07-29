#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123
#define INF INT_MAX

int n;
int v[MAXN];
int memo[MAXN][MAXN];

int pd(int i,int j){
    if(v[i]==v[j])return v[i];
    int &resp=memo[i][j];
    if(resp==-1){
        resp=min(pd(i+1,j),pd(i,j-1));
    }
    return resp;
}

void prep(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            memo[i][j]=-1;
        }
    }
    pd(0,n-1);
}

int query(int i, int j){
    int resp=INF;    
    for(int k=i;k<= j; k++)
        resp=min(resp,v[k]);
    return resp;
}

void change(int i, int x){
    v[i]=x;
    prep();
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
























 