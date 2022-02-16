# Notes on Graph

- when we traverse using BFS to find a path from a path from source to destination, the fist time we encounter the destination "Node" in the queue is the shortest path
<img width="500" alt="Screenshot 2022-02-10 at 3 21 34 PM" src="https://user-images.githubusercontent.com/56363090/153381975-d5d618e5-d4ad-4ba4-958c-17d0ab5d0687.png">
" A B F " is the shortest path from source to destination

- DFS can't be used to find shortest path (https://leetcode.com/problems/shortest-path-in-binary-matrix/) -- in this question DFS doesn't work

- Kruskals and Prims algo are used to create minimum spanning tree (connected graph with min cost/weight)

- Dijkstra’s is used to find the shortest paths from the source to all vertices in the given graph.

- Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph. It is slower than Dijkstra's algorithm for the same problem, but more versatile, as it is capable of handling graphs in which some of the edge weights are negative numbers.
