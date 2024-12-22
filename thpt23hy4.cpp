struct smt {
    vector<int> tree, lazy;

    void build(int n) {
        tree.resize(8*n);
        lazy.resize(8*n);
    }
    int mex(int a, int b) {
        return a + b;
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;
        tree[node] = (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
        return;
    }
    int query(int node, int l, int r, int u, int v) {
        push(node, l, r);
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r) >> 1;
        int q_1 = query(node*2, l, mid, u, v);
        int q_2 = query(node*2 + 1, mid + 1, r, u, v);
        return mex(q_1, q_2);
    }
    void update(int node, int l, int r, int u, int v, int x) {
        push(node, l, r);
        if (u > r || v < l) return;
        if (u <= l && r <= v) {
            lazy[node] = x;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * node, l, mid, u, v, x);
        update(2 * node + 1, mid + 1, r, u, v, x);
        tree[node] = mex(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
};
struct HLD {
    smt tree;
    vector<vector<int>> adj;
    vector<int> depth, parent, head, heavy, tin, sz;
    int timer = 1;
    HLD(int n) {
        adj.resize(n+5);
        depth.resize(n+5);
        parent.resize(n+5);
        head.resize(n+5);
        heavy.resize(n+5);
        tin.resize(n+5);
        sz.resize(n+5);
        tree.build(n);
    }
    int query(int u, int v) {
        int ans = 0;
        int dist = abs(depth[u] - depth[v]);
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            ans += tree.query(1, 1, timer, tin[head[v]], tin[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        ans += tree.query(1, 1, timer, tin[u], tin[v]);
        return dist + 1 - ans;
    }
    void update(int u, int v, int x) {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            tree.update(1, 1, timer, tin[head[v]], tin[v], x); 
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        tree.update(1, 1, timer, tin[u], tin[v], x);
        return;
    }
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            u = parent[head[u]];
        }
        return (depth[u] < depth[v] ? u : v);
    }
    void add(int n) {
        fto(i, 1, n-1) {
            int u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
        return;
    }

    void dfs_sz(int u, int p) {
        sz[u] = 1;
        depth[u] = depth[p] + 1;
        parent[u] = p;
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (!heavy[u]) heavy[u] = v;
            else if (sz[heavy[u]] < sz[v]) heavy[u] = v;
        }
    }
    void dfs_hld(int u, int p) {
        tin[u] = timer++;
        head[u] = p;
        if (heavy[u]) dfs_hld(heavy[u], p);
        for (auto v : adj[u]) {
            if (v == parent[u] || heavy[u] == v) continue;
            dfs_hld(v, v);
        }
        return;
    }
    
    void build() {
        dfs_sz(1, 1);
        dfs_hld(1, 1);
    }
};