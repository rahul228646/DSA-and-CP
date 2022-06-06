# Notes

## STL

### substr
	- str.substr(1)  : to remove a character from front of str
    - str.substr(x, length) : return str from index x to x+length

### find - O(n)
	- char x
      str.find(x)  : returns the index of char x in string str
    
### Insert - O(n)
	- string str, toBeInserted
      str.insert(str.begin()+i, toBeInserted.begin(), toBeInserted.end())   // https://www.geeksforgeeks.org/stdstringinsert-in-c/
      
### Resize - O(n)
	- string str
      str.resize(x) where x is size
         

### stringstream 
    - #include <sstream>

    - Time complexity: O(len(s)) by iterating through all the element in s
    - Space complexity: O(len(s)) as we pb all the space-separated substring in it

    - stringstream  ss (str)  // str is string

        1. Count words :
            string word; 
            while(str >> word) count++; // here spaces are used as delimiters
        2. Custom delimiters
            string word;
            char x; // delimiter
            while(getLine(ss, word, x)) cout<<word;  
	    
    - To Aplly precision in stringstream
    	
	    stringstream ss2;
        double discountPercentage = (100 - discount) / 100.0;
        ss2 << fixed << setprecision(2) << (discountPercentage * price);
        cout<<ss2.str();
  
