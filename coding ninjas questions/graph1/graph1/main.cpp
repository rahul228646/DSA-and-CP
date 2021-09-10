#include <iostream>
#include <queue>
#include <vector>
#include<unordered_map>
#define MAXN 102
using namespace std;



// BFS Traversal
void print(int **edges, int n, bool * visited, int start = 0) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(q.size() != 0){
        int current = q.front();
        cout<<current<<" ";
        q.pop();
        for(int i=0; i<n; i++){
            if(i == current){
                continue;
            }
            if(edges[current][i] == 1 && visited[i] != true){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

//Code : Has Path
bool hasPath(bool *visited, int **edges, int n, int x, int y){
    if(edges[x][y] == 1 || edges[y][x] == 1){
        return true;
    }
    
    for(int i=0; i<n; i++){
        visited[x] = true;
        if(i == x){
            continue;
        }
        if(edges[x][i] == 1 && visited[i] != true){
           
           bool val = hasPath(visited, edges, n, i, y);
            if(val)
                return val;
            
        }
    }
    return false;
}

//Code : Get Path - DFS
vector<int> getPath(bool *visited, int **edges, int n, int start, int end){
    if(start == end){
        vector<int> v;
        v.push_back(start);
        return v;
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        visited[start] = true;
        if(start == i)
            continue;
        if(edges[start][i] == 1 && visited[i] == false){
            ans = getPath(visited, edges, n, i, end);
            if(ans.size()!=0){
                ans.push_back(start);
                return ans;
            }
        }
    }

    return ans;
    
}

//Code : Get Path - BFS
vector<int> getPathBFS(bool *visited, int **edges, int n, int start, int end){
    unordered_map<int, int> m;
    queue<int> q;
    q.push(start);
    bool flag = false;
    visited[start] = true;
    while(q.size() != 0){
        int current = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(i == current){
                continue;
            }
            if(edges[current][i] == 1 && visited[i] != true){
                m[i] = current;
                q.push(i);
                visited[i] = true;
                    if(i == end){
                        flag = true;
                        break;
                        
                    }
                    
                }
            }
           if(flag)
               break;
        }
    
    vector<int> v;
    
    if(q.empty()){
     
        return v;
    }
    
    else{
        v.push_back(end);
        int path=end;
        while(path != start){
            v.push_back(m[path]);
            path = m[path];
        }
    }
    return v;
}

void printGetPathBfs(int **edges, int n, bool * visited, int start = 0){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(q.size() != 0){
        int current = q.front();
        cout<<current<<" ";
        q.pop();
        for(int i=0; i<n; i++){
            if(i == current){
                continue;
            }
            if(edges[current][i] == 1 && visited[i] != true){
                q.push(i);
                visited[i] = true;
            }
           
        }
    }
}

//Code : Is Connected ?
void isConnected(int **edges, int n, bool * visited, int start = 0){
    //do BFS traversal then check if visited is true for all
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(i == front)
                continue;
            if(edges[front][i] == 1 && visited[i] != true){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for(int j = 0; j<n; j++){
        if(visited[j] == false){
            cout<<"false";
            return;
        }
                
    }
    cout<<"true";
    
}

//Code : All connected components
void print(int **edges, int n, bool * visited, int start, int *arr, int &k) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(q.size() != 0){
        int current = q.front();
        arr[k++] = current;
        q.pop();
        for(int i=0; i<n; i++){
            if(i == current){
                continue;
            }
            if(edges[current][i] == 1 && visited[i] != true){
                q.push(i);
                visited[i] = true;
            }
           
        }
    }
    
    // look at main part
}

//Islands
void dfs(int **adjList,int n,int sv,bool *visited){
    if(visited[sv])
        return;
    visited[sv]=true;
    for(int i=1;i<=n;i++){
        if(adjList[sv][i] && !visited[i])
            dfs(adjList,n,i,visited);
    }
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int ans = 0;
    int count = 0;
     int **adjList = new int* [(n+1)];
     for(int i = 1; i<=(n); i++){
         adjList[i] = new int [(n+1)];
         for(int j = 1; j<=(n); j++){
             adjList[i][j] = 0;
         }
     }
    for(int i = 0; i<m; i++){
        adjList[u[i]][v[i]] = 1;
        adjList[v[i]][u[i]] = 1;
    }
    
    bool *visited = new bool [n+1];
    for(int j = 1; j<=n; j++){
            visited[j] = false;
    }
    
    
    for(int i =1; i<=n; i++){
      if(!visited[i]){
          ans++;
          dfs(adjList,n,i,visited);
        }
    }
    
    return ans;
    
}

//3 Cycle
//Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
int cycle(int n,int m,vector<int>u,vector<int>v){
    
    int count = 0;
    int **adjList = new int* [(n+1)];
    for(int i = 0; i<(n+1); i++){
        adjList[i] = new int [(n+1)];
        for(int j = 0; j<(n+1); j++){
            adjList[i][j] = 0;
        }
    }
    
    for(int i = 0; i<m; i++){
        adjList[u[i]][v[i]] = 1;
        adjList[v[i]][u[i]] = 1;
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(adjList[i][j] != 1){
                continue;
            }
            for(int k = 1; k<=n; k++){
                if(adjList[i][k] == 1 && j!=k && adjList[j][k] == 1){
                    count++;
                }
                
            }
        }
    }
    
    return count/6;
}

//CODINGNINJA
int used[MAXN][MAXN];
int a[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
char pattern[11] = {'C','O','D','I','N','G','N','I','N','J','A'};
int validPoint(int x, int y, int N, int M){
    return (x >= 0 && x < N && y >= 0 && y < M);
}
int DFS(char Graph[][MAXN],int x, int y, int index, int N, int M){
    if(index == 11)
        return 1;
    used[x][y] = 1;
    int i, newX, newY;
    int found = 0;
    for(i = 0; i < 8; i++){
        newX = x + a[i][0]; // for moving in the matrix (8 directions)
        newY = y + a[i][1];
        
        if(validPoint(newX, newY, N, M) && Graph[newX][newY] == pattern[index] && !used[newX][newY]){
            found = found || DFS(Graph, newX, newY, index+1, N, M);
        }
    }
    
    used[x][y] = 0;
    return found;
}

int solveCode(char Graph[][MAXN], int N, int M){
    int i,j,found=0;
    
    for(i = 0; i < N; i++){
        for(j = 0, found = 0; j < M; j++){
            if(Graph[i][j] == 'C'){
                found = DFS(Graph,i,j,1,N,M);
                if(found)
                    break;
            }
        }
        if(found)
            break;
    }
    return found;
}

//Connecting Dots
//Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
//1. These k dots are different: if i ≠ j then di is different from dj.
//2. k is at least 4.
//3. All dots belong to the same colour.
//4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
//Return 1 if there is a cycle else return 0

int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};
//int visited[MAXN][MAXN]; using used istead

bool eligible(char board[][MAXN], int n, int m, int i, int j, char curr){
    if(i>=0 && j>=0 && i<n && j<m && board[i][j]==curr)
        return true;
    return false;
}

int path_helper(char board[][MAXN], int n, int m, int i, int j, int fromx, int fromy, char curr){
    if(i>n || j>m)
        return 0;
    if(used[i][j] == 1)
        return 1;
    if(board[i][j] != curr)
        return 0;

    used[i][j] = 1;
    for(int k = 0 ; k < 4 ; k++){
        int dx = i + xdir[k];
        int dy = j + ydir[k];
        if(eligible(board,n,m,dx,dy,curr) && (dx!=fromx || dy!=fromy)){ // fromx and from y is to avoid going backwards
            if(path_helper(board, n, m, dx, dy, i, j, curr) == 1)
                return 1;
        }
    }
    return 0;
}

int solveDots(char board[][MAXN],int n, int m)
{
    int ans = 0;
    memset(used,0,sizeof(used));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(used[i][j] != 1){
                char curr = board[i][j];
                ans = path_helper(board, n, m, i, j, -1, -1, curr);
                if(ans==1)
                    return 1;
            }
        }
    }
    return ans;
}

//Largest Piece
//Send Feedback
//Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
void initialize(bool **visited,int N,int M){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}

int solveHelperCake(int n, char cake[MAXN][MAXN], bool **visited, int si, int sj){
    
    visited[si][sj] = true;
    int count = 1;

    if(si >=0 && sj+1 >=0  && cake[si][sj+1] == '1' && visited[si][sj+1] != true ){
        count += solveHelperCake(n, cake, visited,si, sj+1);
    }
    if(si >=0 && sj-1 >=0  && cake[si][sj-1] == '1' && visited[si][sj-1] != true ){
        count += solveHelperCake(n, cake, visited,si, sj-1);
    }
    
    if(si-1 >=0 && sj >=0  && cake[si-1][sj] == '1' && visited[si-1][sj] != true ){
        count += solveHelperCake(n, cake, visited,si-1, sj);
    }
    
    if(si+1 >=0 && sj >=0  && cake[si+1][sj] == '1' && visited[si+1][sj] != true ){
        count += solveHelperCake(n, cake, visited,si+1, sj);
    }
    
 
  
    return count;
}

int solve(int n, char cake[MAXN][MAXN]){
    int max = 0;
    bool ** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[n];
    }
    
    initialize(visited,n,n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(cake[i][j] == '1' && !visited[i][j]){
                int s = solveHelperCake(n, cake, visited, i, j);
                if(s > max){
                    max = s;
                }

            }
        }
    }
    return max;
}


int main() {
    int V, E;
    cin >> V >> E;
    int **edges = new int *[V];
    for(int i = 0; i<V; i++){
        edges[i] = new int [V];
        for(int j = 0; j<V; j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i<E; i++){
        int a,b;
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
    bool *visited = new bool [V];

    for(int j = 0; j<V; j++){
            visited[j] = false;
    }
    
 /*   int *arr = new int [V];
    int k=0;
    
 for Code : All connected components
 
    for(int i =0; i<V; i++){
        if(!visited[i]){
            k = 0;
            print(edges, V, visited,i,arr, k);
            sort(arr,arr+k);
            cout<<endl;
            for(int j = 0; j<k; j++){
                cout<<arr[j]<<" ";
                arr[j] = 0;
            }

        }
    } */
}
