/*
    Dinic (Max Flow)
    Complexidade O(V^2E)
    -> Nós vão de 1 a V
    -> Setar número de nós V, source S e sink T
    -> Setar limite de nós MAXV
    -> Adicionar adjacencias usando add_adj()
    -> Chamar clear() antes de cada teste
*/

const int MAXV = 100, INF = 0x7FFFFFFF;

struct edge {
    int dest, rev, cap, f;
    edge(int dest, int rev, int cap) : dest(dest), rev(rev), cap(cap) {
        f = 0;
    }
};

int dist[MAXV + 1], ptr[MAXV + 1];
vector<edge> adj[MAXV + 1];
int V, S, T;

void add_edge(int a, int b, int cap) {
    adj[a].push_back(edge(b, adj[b].size(), cap));
    adj[b].push_back(edge(a, adj[a].size() - 1, 0));
}

bool bfs() {
    for(int i = 1; i <= V; i++)
        dist[i] = -1;
    dist[S] = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i = 0; i < adj[v].size(); i++) {
            edge e = adj[v][i];
            if(dist[e.dest] == -1 && e.cap > e.f) {
                dist[e.dest] = dist[v] + 1;
                q.push(e.dest);
            }
        }
    }
    return dist[T] != -1;
}

int dfs(int v, int f) {
    if(v == T) return f;
    for(; ptr[v] < adj[v].size(); ++ptr[v]) {
        edge &e = adj[v][ptr[v]];
        if(dist[e.dest] == dist[v] + 1 && e.cap > e.f) {
            int df = dfs(e.dest, min(f, e.cap - e.f));
            if(df > 0) {
                e.f += df;
                adj[e.dest][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int max_flow() {
    int flow = 0;
    while(bfs()) {
        for(int i = 1; i <= V; i++)
            ptr[i] = 0;
        while(true) {
            int df = dfs(S, INF);
            if(df == 0) break;
            flow += df;
        }
    }
    return flow;
}

void clear() {
    for(int i = 1; i <= V; i++)
        adj[i].clear();
}
