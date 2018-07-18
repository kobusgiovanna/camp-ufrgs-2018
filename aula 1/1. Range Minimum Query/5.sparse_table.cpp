#include <bits/stdc++.h>
using namespace std;

#define MAXN 112345
#define LOGMAXN 20
#define INF INT_MAX

int n;
int v[MAXN];
int st[MAXN][LOGMAXN];

void prep(){
    for(int i=n-1;i>=0;i--){
        st[i][0]=v[i];
        for(int j=1;j<=LOGMAXN;j++)
            st[i][j]=min(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);       
    }
}

int query(int i, int j){
    int m=j-i+1;
    if(m==1)return v[i];
    m=(31-__builtin_clz(m));
    return min(st[i][m],st[j-(1<<m)+1][m]);
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