
https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// time - o(nlogn) space - 1
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int res = 1, platformNeeded = 1, i = 1, j = 0;
    	while (i<n && j<n) {
    	    if(arr[i] <= dep[j]) {
    	        platformNeeded++;
    	        i++;
    	    }
    	    else if (arr[i] > dep[j]) {
    	        platformNeeded--;
                j++;
    	    }
    	    
    	    res = max(res, platformNeeded);
    	}
    	return res;
    }


// arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
// dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

// All events are sorted by time.
// Total platforms at any time can be obtained by
// subtracting total departures from total arrivals
// by that time.

//  Time      Event Type     Total Platforms Needed 
//                                at this Time                               
//  9:00       Arrival                  1
//  9:10       Departure                0
//  9:40       Arrival                  1
//  9:50       Arrival                  2
//  11:00      Arrival                  3 
//  11:20      Departure                2
//  11:30      Departure                1
//  12:00      Departure                0
//  15:00      Arrival                  1
//  18:00      Arrival                  2 
//  19:00      Departure                1
//  20:00      Departure                0

// Minimum Platforms needed on railway station 
// = Maximum platforms needed at any time 
// = 3
