
class Solution {
  public:
  int hammingDistance(int x, int y){
    int count = 0;
    int h;
    h = x ^ y;
    while(h){
      if(h & 1) count++;
      h = h>>1;
    }
    return count;
  }
};

or
  
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += (x >> i & 1) != (y >> i & 1);
        return ans;
    }
};
