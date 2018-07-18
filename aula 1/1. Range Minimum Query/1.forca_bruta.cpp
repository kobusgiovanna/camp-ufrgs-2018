#include <bits/stdc++.h>
using namespace std;

#define MAXN 112345
#define INF INT_MAX

int n;
int v[MAXN];

void prep(){}

int query(int i, int j){
    int resp=INF;    
    for(int k=i;k<= j; k++)
        resp=min(resp,v[k]);
    return resp;
}

void change(int i, int x){
    v[i]=x;
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