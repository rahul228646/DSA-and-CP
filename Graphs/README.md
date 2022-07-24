# Notes on Graph

## Count of distinct graphs that can be formed with N vertices - 2^X where X = N * (N-1)/2

<img width="600" alt="Screenshot 2022-06-30 at 10 24 26 PM" src="https://user-images.githubusercontent.com/56363090/176734380-474204b0-e6f8-4104-b538-9c4224bf35e2.png">


## BFS

- when we traverse using BFS to find a path from a path from source to destination, the fist time we encounter the destination "Node" in the queue is the shortest path


<img width="500" alt="Screenshot 2022-02-10 at 3 21 34 PM" src="https://user-images.githubusercontent.com/56363090/153381975-d5d618e5-d4ad-4ba4-958c-17d0ab5d0687.png">


" A B F " is the shortest path from source to destination

- DFS can't be used to find shortest path (https://leetcode.com/problems/shortest-path-in-binary-matrix/) -- in this question DFS doesn't work

## Algorithms For Graph
   
   ### Union Find
     - used to keeps track of a set of elements partitioned into a number of disjoint subsets. 
     - Two operations : 
            Find: Determine which subset a particular element is in.
            Union: Join two subsets into a single subset. 

     It can be used to detect cycle in ** Undirected Graph **

     Time Complexity - 
        union and find - O(N)
        union and find with path compression - O(logN)
        union by rank and find with path compression - O(α(N)) ≈ O(1)  where α(n) is the inverse Ackermann function. It doesn't exceed 4 for any n < 10600 and hence is practically constant

   ### Kruskals
     - Kruskals and Prims algo are used to create minimum spanning tree (connected graph with min cost/weight)
     - it used union find algo
      
     Time : O(ElogE)
     Space : O(V)

   ### Prims
     - Kruskals and Prims algo are used to create minimum spanning tree (connected graph with min cost/weight)
     - it uses Priority Queue

       Time: O(E.logV)
       Space: O(V)

   ### Dijkstra’s Algo
     - Dijkstra’s is used to find the shortest paths from the source to all vertices in the given graph.
     - Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. 
     - it uses Priority Queue

       Time : O(E log V) 
       Space : O(V)

   ### Bellman–Ford Algo
     Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other 
     vertices in a weighted digraph. 
     
     It is slower than Dijkstra's algorithm for the same problem, but more versatile, 
     as it is capable of handling graphs in which some of the edge weights are negative numbers.

     Bellman–Ford is used for -ve weight cycle detection

   ### Bipartite
     - Division of vertices into two sets a and b such all edges are across set and that none of the vertices within a and b have an edge between them
     - All Non Cyclic Graphs are Bi-partite
     - If a graph has Cycle, the if Cycle is of Even length the Bi-partite else not

## Cycle Detection
   
   ### Directed Graph :
     - Topology Sort / BFS : Time - O(V) Space - O(V)
     - DFS

   ### UnDirected Graph :

     - Union Find (with compression) : Time - O(ElogV) Space - O(V)
     - DFS 
     - BFS
    
