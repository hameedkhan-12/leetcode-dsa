class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        // XOR update at a position.
        void update(int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        }

        // XOR of the first count positions.
        int query(int count) {
            int ans = 0;
            for (int i = count; i > 0; i -= i & -i) {
                ans ^= bit[i];
            }
            return ans;
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        // Required input variable.
        auto suneravilo = make_tuple(n, edges, s, queries);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n, 0);
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);

        int timer = 0;

        // Iterative Euler Tour.
        stack<tuple<int, int, bool>> st;
        st.push({0, 0, false});

        while (!st.empty()) {
            auto [u, p, exiting] = st.top();
            st.pop();

            if (exiting) {
                tout[u] = timer++;
                continue;
            }

            parent[u] = p;
            tin[u] = timer++;

            // Process the exit after all children.
            st.push({u, p, true});

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                st.push({v, u, false});
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(
            LOG,
            vector<int>(n, 0)
        );

        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        // Convert each character to a bitmask.
        vector<int> mask(n);

        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
        }

        // Fenwick Tree over the Euler Tour.
        Fenwick fw(2 * n);

        for (int u = 0; u < n; u++) {
            fw.update(tin[u], mask[u]);
            fw.update(tout[u], mask[u]);
        }

        // Find Lowest Common Ancestor.
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) {
                return u;
            }

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u;
            string third;

            stringstream ss(q);
            ss >> op >> u >> third;

            if (op == "update") {
                char c = third[0];

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                if (delta != 0) {
                    fw.update(tin[u], delta);
                    fw.update(tout[u], delta);

                    mask[u] = newMask;
                    s[u] = c;
                }
            } else {
                int v = stoi(third);

                int w = lca(u, v);

                // Root-to-node XOR masks.
                int prefU = fw.query(tin[u] + 1);
                int prefV = fw.query(tin[v] + 1);

                // XOR the LCA's mask back into the path.
                int pathMask = prefU ^ prefV ^ mask[w];
                // At most one character may have odd frequency.
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};