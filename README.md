# 1579.-Remove-Max-Number-of-Edges-to-Keep-Graph-Fully-Traversable
# 🔗 Remove Max Number of Edges to Keep Graph Fully Traversable

This project contains an optimized **C++ solution** using **Disjoint Set Union (Union-Find)** to solve the problem of removing the **maximum number of edges** while ensuring that both **Alice and Bob** can fully traverse a graph.

🔗 [LeetCode Problem Link](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/)

---

## 🧩 Problem Description

You are given a graph with `n` nodes and edges of 3 types:
- **Type 1:** Usable by Alice only.
- **Type 2:** Usable by Bob only.
- **Type 3:** Usable by both Alice and Bob.

Your task is to return the **maximum number of edges you can remove** while still allowing both Alice and Bob to traverse the entire graph.

If it's **impossible** to achieve full traversal, return `-1`.

---

## 🚀 Approach

This solution uses **Union-Find (DSU)** with path compression and union by rank. The idea is:

1. **Sort edges**, giving priority to type 3 (shared) edges.
2. Use separate DSUs for Alice and Bob.
3. Use type 3 edges for both Alice and Bob first.
4. Then use type 1 edges for Alice and type 2 for Bob.
5. After all edges are processed, **verify** that both graphs are fully connected.
6. Return the total number of edges - used edges = **removable edges**.

---

## 🧠 Algorithm Steps

1. Initialize `parent` and `rank` arrays for Alice and Bob.
2. Sort edges by type in descending order so type 3 edges are processed first.
3. Traverse the edges:
   - Apply type 3 edges to both Alice and Bob’s DSU.
   - Apply type 1 edges to Alice.
   - Apply type 2 edges to Bob.
4. Check if both Alice and Bob’s graphs are fully connected using DSU.
5. Return total edges - edges used, or `-1` if not fully connected.

---

## 🧾 Example

### Input:
n = 4 edges = [ [3,1,2], [3,2,3], [1,1,3], [1,2,4], [1,1,2], [2,3,4] ]
### Output:
2
