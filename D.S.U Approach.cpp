// Problem: Remove Maximum Number of Edges to Keep Graph Fully Traversable
// LeetCode: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

class Solution {
public:

    // Function to find the root of a node with path compression
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);  // Path compression
        return parent[x];
    }

    // Function to unite two sets by rank; returns true if union is successful
    bool unite(int x, int y, vector<int>& parent, vector<int>& rank) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px == py) return false;  // Already connected

        // Union by rank
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Initialize disjoint sets for Alice and Bob
        vector<int> parentAlice(n), rankAlice(n, 0), parentBob(n), rankBob(n, 0);
        for (int i = 0; i < n; i++) {
            parentAlice[i] = parentBob[i] = i;
        }

        int used = 0;

        // Sort edges so type 3 edges (usable by both) come first
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[0] > b[0];
        });

        // Process each edge
        for (auto& edge : edges) {
            int type = edge[0], u = edge[1] - 1, v = edge[2] - 1;
            if (type == 3) {
                // Try to add edge for both Alice and Bob
                bool a = unite(u, v, parentAlice, rankAlice);
                bool b = unite(u, v, parentBob, rankBob);
                if (a || b) used++;
            } else if (type == 1) {
                // Alice-only edge
                if (unite(u, v, parentAlice, rankAlice)) used++;
            } else {
                // Bob-only edge
                if (unite(u, v, parentBob, rankBob)) used++;
            }
        }

        // Ensure both Alice and Bob can reach all nodes
        int rootAlice = find(0, parentAlice);
        int rootBob = find(0, parentBob);
        for (int i = 1; i < n; i++) {
            if (find(i, parentAlice) != rootAlice || find(i, parentBob) != rootBob)
                return -1;  // Graph is not fully traversable for both
        }

        // Return the maximum number of removable edges
        return edges.size() - used;
    }
};
