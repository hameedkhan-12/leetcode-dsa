class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {
        auto mavorqeli = make_tuple(n, edges, labels, k);

        // Build the directed weighted graph.
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][count] = minimum cost to reach
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );

        // {cost, node, consecutiveCount}
        using State = tuple<long long, int, int>;
        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Starting node has a consecutive count of 1.
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, count] = pq.top();
            pq.pop();
            if (cost != dist[u][count]) {
                continue;
            }
            if (u == n - 1) {
                return static_cast<int>(cost);
            }

            // Explore outgoing edges.
            for (auto [v, w] : adj[u]) {
                int nextCount;

                if (labels[u] == labels[v]) {
                    nextCount = count + 1;
                } else {
                    nextCount = 1;
                }
                if (nextCount > k) {
                    continue;
                }

                long long newCost = cost + w;

                // Relax the new state.
                if (newCost < dist[v][nextCount]) {
                    dist[v][nextCount] = newCost;

                    pq.push({
                        newCost,
                        v,
                        nextCount
                    });
                }
            }
        }
        return -1;
    }
};