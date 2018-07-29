/*
    Exemplo de Segment Tree
    Resolve o problema Potentiometers
    https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192
    Victor Colombo - 2018
*/

#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)
#define ff first
#define ss second
#define pb push_back

using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

const int MAXN = 200100;

int seg[4*MAXN];

void update(int node, int l, int r, int idx, int val) {
    if(idx < l || idx > r) return;
    if(l == r) {
        seg[node] = val;
    } else {
        int m = (l + r) / 2;
        update(2*node, l, m, idx, val);
        update(2*node + 1, m + 1, r, idx, val);
        seg[node] = seg[2*node] + seg[2*node + 1];
    }
}

int query(int node, int l, int r, int a, int b) {
    if(l >= a && r <= b) return seg[node];
    if(l > b || r < a) return 0;
    int m = (l + r) / 2;
    return query(2*node, l, m, a, b) + query(2*node + 1, m + 1, r, a, b);
}

int main() {
    int n, t = 1;
    while(scanf("%d", &n) && n) {
        if(t != 1) printf("\n");
        printf("Case %d:\n", t++);
        for(int i = 1; i <= n; i++) {
            int aux;
            scanf("%d", &aux);
            update(1, 1, n, i, aux);
        }
        char str[10];
        while(scanf(" %s", str) && str[0] != 'E') {
            int a, b;
            scanf("%d%d", &a, &b);
            if(str[0] == 'S') update(1, 1, n, a, b);
            else printf("%d\n", query(1, 1, n, a, b));
        }
    }
    return 0;
}
