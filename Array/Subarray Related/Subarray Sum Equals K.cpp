https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> map;

		map[0] = 1;
		int sum = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			if (map.find(sum - k) != map.end()) {
				count += map[sum-k];  
			}
			map[sum]++;
		}

		return count;
	}
};

[ 1, 7, 6, 2, 3, 3, 2 ]
     Initially, m[0] = 1;

     i    s     m          check map                 r
     =================================================
     0    1     m[1 ] = 1; m[1 - 8  ] doesn't exist  0
     1    8     m[8 ] = 1; m[8 - 8  ] exists         1
     2    14    m[14] = 1; m[14 - 8 ] doesn't exist  1
     3    16    m[16] = 1; m[16 - 8 ] exists         2
     4    19    m[19] = 1; m[19 - 8 ] doesn't exist  2
     5    22    m[22] = 1; m[22 - 8 ] exists         3
     6    24    m[24] = 1; m[24 - 8 ] exists         4

     [ 1, 7, 6, 2, 3, 3, 2 ]
       |  |  |  |  |  |  |
       ====  |  |  |  |  |
          x  ====  |  |  |
                |  |  |  |
                =======  |
                y  |     |
                   =======
               
