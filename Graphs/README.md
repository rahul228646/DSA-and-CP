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
     - A graph wiht Negative weight cycle doesn't have a shortest path
     - it uses Priority Queue

       Time : O(E log V) 
       Space : O(V)

   ### Bellman–Ford Algo
     Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other 
     vertices in a weighted digraph. 
     
     It is slower than Dijkstra's algorithm for the same problem, but more versatile, 
     as it is capable of handling graphs in which some of the edge weights are negative numbers.

     Bellman–Ford is used for -ve weight cycle detection
     
     A graph wiht Negative weight cycle doesn't have a shortest path
     
     Shortest path with i length is calculated in <= ith iteration

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
    
## Connected Components / Strongly Connected Components
   
   largest group of node in which if we start from any node, we can visit every other node.
   
   ### UnDirected Graph :
   
      - just do a Dfs on every unvisited vertex and count the components just like no. of provinces
   
   ### Directed Graph :
   
      https://www.youtube.com/watch?v=QtdE7QPsWiU&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=21
      
      Kosaraju Algo :
         We need to figure out the problematic edge do dfs on each side of problmatic edge first on ending side then on 
         starting side
         steps involev to do the above
         1. do a dfs on any node and add nodes in a stack before backtracking (top of the stack will give a node 
         from the staring side portion of the problematic edge in the  connected graph)
         2. reverse all edges (starting side will become ending side)
         3. do a dfs int the order arranged in tthe stack
      

## Mother Vertex

   https://www.youtube.com/watch?v=gNn0L18DUvg&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=22
   
   a node from which we can visit every other node directly or indirectly
   - apply random order dfs and store nodes into a stack before backtracking
   - node on top of the stack is the only possible mother vertex
   - check if the vertex can visit every other node and return answer accordingly
    
