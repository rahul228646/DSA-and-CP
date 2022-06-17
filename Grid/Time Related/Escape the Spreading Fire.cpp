https://leetcode.com/contest/biweekly-contest-77/problems/escape-the-spreading-fire/

class Solution {
public:
    
    //max waiting time
    #define MAX_T 1e9
        
    struct triplet{  // for storing tripet in queue
        long r,c,t;
    };
    
    //for checking if we wait maxT min at initial pos then, 
    //is it possible to reach to home or not?
    bool isPossible(long maxT,  vector<vector<int>> &fire, vector<vector<int>> &directions){
        int m=fire.size();
        int n=fire[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        visited[0][0]=true; // mark start idx as visited
        
        queue<triplet> q;
        q.push({0,0,maxT}); 
        
        while(!q.empty()){
            auto [r,c,t]=q.front();
            q.pop();

            if(r==m-1 && c==n-1)
                return true; // reached home
            
            if(fire[r][c]<=t)  //fire reached to person at same time or before he reached 
                continue;
            
            for(int i=0;i<directions.size(); i++){
                int nR=r+directions[i][0]; // new row
                int nC=c+directions[i][1]; // new Col
                
               if(min(nR, nC)>=0 && nR<m && nC<n && fire[nR][nC]!=-1 && t+1 <= fire[nR][nC]){
                   if(!visited[nR][nC]){
                       visited[nR][nC]=true; //make it visited
                       q.push({nR, nC, t+1}); // push in queue to check adj
                   }
               }
            }
        }
        
        //Spiderman: No way Home :(
        
        return false; //cannot reach if waited maxT min at initial pos/no way possibe
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> fire(m,vector<int>(n, INT_MAX));
        //store the time to reach fire at a pos, intially infinite Time
        
        queue<pair<int,int>> q; 
      
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ //if fire cell
                    fire[i][j]=0;  // the cells which are on fire in the start
                    q.push({i,j});
                }    
                else if(grid[i][j]==2) // fire cannot reach the wall cells
                {
                    fire[i][j]=-1;  // so store -1 if wall is there 
                }
            }
        }

        //for going in all 4 directions
        vector<vector<int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
        
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
                
            for(int j=0;j<directions.size();j++){
                int newRow=row + directions[j][0];
                int newCol=col + directions[j][1];
                
                // fire[newRow][newCOl]=-1 -> wall cell 
                if(min(newRow,newCol)>=0 && newRow<m && newCol<n && fire[newRow][newCol]!=-1){ // is valid coord.
                    if(fire[newRow][newCol] > fire[row][col] + 1){ // if previously stored time was greater 
                   
                      fire[newRow][newCol]= fire[row][col] +1 ; 
                      q.push({newRow,newCol});
                   }
                }
            } 
        }
        
        //Use Binary seach to find the maxWaiting Time
        //Our search space will be from 0 to 10^9 min
        
        long l=0, h=MAX_T, maxWaitingTime=-1;
        
        while(l<=h){
            long mid=l+(h-l)/2;
            if(isPossible(mid, fire, directions))
            {
                //store the max time till now which is possible
                maxWaitingTime=max(maxWaitingTime,mid);
                // if we can wait this longer then try to wait longer
                l=mid+1;
            }else{
                //check for waitaing for shorter period instead
                h=mid-1;
            }
        }
        
        return maxWaitingTime;
    }
};





