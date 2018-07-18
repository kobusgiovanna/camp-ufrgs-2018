#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define SQRT_MAXN 1123
#define INF INT_MAX

int n;
int bnum;//numero de baldes
int bsize;//tamanho maximo do balde
int v[MAXN];
int mini[SQRT_MAXN];//minimo por balde

//primeiro elemento do balde
int fbucket(int a){
    return a*bsize;
}
//ultimo elemento do balde
int lbucket(int a){
    return min((a+1)*bsize,n)-1;
}
//em que balde esta dado elemento
int bucket(int i){
    return i/bsize;
}

void prep(){
    bsize=1;
    while(bsize*bsize<n)bsize++;
    bnum=(n+bsize-1)/bsize;
    for(int i=0;i<bnum;i++)
        mini[i]=INF;
    for(int i=0;i<n;i++)
        mini[bucket(i)]=min(mini[bucket(i)],v[i]);
}

int query(int i, int j){
    int resp=INF;    
    int firstb=bucket(i);
    int lastb =bucket(j);
    for(int k=i;k<=min(lbucket(firstb),j);k++)
        resp=min(resp,v[k]);
    for(int k=max(fbucket(lastb),i);k<=j;k++)
        resp=min(resp,v[k]);
    for(int k=firstb+1;k<lastb;k++)
        resp=min(resp,mini[k]);

    return resp;
}

void change(int i, int x){
    v[i]=x;
    int currb=bucket(i);
    mini[currb]=INF;
    for(int k=fbucket(currb);k<=lbucket(currb);k++)
        mini[currb]=min(mini[currb],v[k]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
     
    int testes=1;

    while(testes--){

        cin>>n;

        for(int i=0;i<n;i++)cin>>v[i];

        prep();

        int q;
        cin>>q;

        for(int t=0;t<q;t++){
            char c=;
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


