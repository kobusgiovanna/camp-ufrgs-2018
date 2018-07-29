/*
    Exemplo de Merge Sort Tree
    Resolve o problema K-th Number
    https://www.spoj.com/problems/MKTHNUM/
    Victor Colombo - 2018
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 100010;
 
vector<int> seg[4*MAX];
int v[MAX];
 
void update(int node, int l, int r) {
    if(l != r) {
        int mid = (l + r)/2;
        update(2*v + 1, l, mid);
        update(2*v + 2, mid + 1, r);
        int ptrL = 0, ptrR = 0, ptr = 0;
        while(ptrL < seg[2*v + 1].size() && ptrR < seg[2*v + 2].size())
            if(seg[2*v + 1][ptrL] < seg[2*v + 2][ptrR]) seg[node].push_back(seg[2*v + 1][ptrL++]);
            else seg[node].push_back(seg[2*v + 2][ptrR++]);
        while(ptrL < seg[2*v + 1].size())
            seg[node].push_back(seg[2*v + 1][ptrL++]);
        while(ptrR < seg[2*v + 2].size())
            seg[node].push_back(seg[2*v + 2][ptrR++]);
    }
    else {
        seg[node].push_back(v[l]);
    }
}
 
int query(int node, int l, int r, int a, int b, int val) {
    if(a > r || b < l || l > r) {
        return 0;
    }
    else if(l >= a && r <= b) {
        return int(upper_bound(seg[node].begin(), seg[node].end(), val) - seg[node].begin());
    } else {
        int mid = (l + r) / 2;
        return query(2*v + 1, l, mid, a, b, val) + query(2*v + 2, mid + 1, r, a, b, val);
    }
}
 
int main() {
    int n, m, maxi = 0, mini;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        maxi = max(maxi, v[i]);
        mini = min(mini, v[i]);
    }
    update(0, 1, n);
    while(m--) {
        int l, r, k, ans;
        scanf("%d%d%d", &l, &r, &k);
        int lo = mini, hi = maxi;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int aux = query(0, 1, n, l, r, mid);
            if(aux == k) {
                ans = mid;
                hi = mid - 1;
            } else if(aux < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
} 