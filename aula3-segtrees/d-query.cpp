/*
    Exemplo de Persistent Segment Tree
    Resolve o problema D-query
    https://www.spoj.com/problems/DQUERY/
    Victor Colombo - 2018
*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1000010;
 
struct node {
    node *l, *r;
    int val;
    node() : l(NULL), r(NULL) {}
} nodes[4*MAX];
 
int n, v[MAX], ptr = 0;
 
node* newnode() {
    return &nodes[ptr++];
}
 
node* head[MAX];
 
int query(node* v, int l, int r, int a, int b) {
    if(v == NULL || a > r || b < l || l > r) {
        return 0;
    }
    else if(l >= a && r <= b) {
        return v->val;
    }
    else {
        int mid = (l + r) / 2;
        return query(v->l, l, mid, a, b) + query(v->r, mid + 1, r, a, b);
    }
}
 
node* build(int l, int r) {
    if(l > r) {
        return NULL;
    }
    node *v = newnode();
    int mid = (l + r)/2;
    if(l != r) {
        v->l = build(l, mid);
        v->r = build(mid + 1, r);
    }   
    v->val = 0;
    return v;
}
 
node* update(node *v, int l, int r, int idx, int val) {
    node *u = newnode();
    *u = *v;
    u->val += val;
    if(l != r) {
        int mid = (l + r) / 2;
        if(idx <= mid) {
            u->l = update(v->l, l, mid, idx, val);
        } else {
            u->r = update(v->r, mid + 1, r, idx, val);
        }
    }
    return u;
}
 
int main() {
    scanf("%d", &n);
    head[0] = build(1, n);
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        node* aux = head[i - 1];
        if(v[val]) aux = update(aux, 1, n,v[val], -1);
        head[i] = update(aux, 1, n, v[val] = i, 1);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(head[r], 1, n, l, r));
    }
    return 0;
} 