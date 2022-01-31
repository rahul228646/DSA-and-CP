

// Time : O(n) Space : O(1)

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
 
// Time : O(k) where k is bits that are different Space : O(1)
  
class Solution {
public:
    int hammingDistance(int x, int y) {
        int Xor = x ^ y, ans = 0;
        while(Xor) {
            ans++;
            Xor = (Xor & Xor-1); // this step unsets the right most digit
        }
        return ans;
    }
};


or
  
// Time : O(n)  Space : O(1)
  
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += (x >> i & 1) != (y >> i & 1);
        return ans;
    }
};

or
 
  
// Time : O(n)  Space : O(n)
  
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xb(x), yb(y);
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += xb[i] != yb[i];
        return ans;
    }
};
