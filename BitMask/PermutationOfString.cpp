 int maxProduct(string s) {
        int n=s.length();
        for(int i=0;i<(1<<n);i++)
        {
            string a="",b="";
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j)))
                    a+=s[j];
                else
                    b+=s[j];
            }
            cout<<" a : "<<a<<" b : "<<b<<"\n";
        }
        return 0;
    }

//  a :       b : abc
//  a : a     b : bc
//  a : b     b : ac
//  a : ab    b : c
//  a : c     b : ab
//  a : ac    b : b
//  a : bc    b : a
//  a : abc   b : 

 int generateCombinations(string s) {
        int n=s.length();
        int mask = 1<<n;
        for(int i = 1; i<mask; i++) {
            string a;
            int num = i, j = 0;
           while(num) {
               if(num & 1) {
                   a+=s[j];
               }
               num = num>>1;
               j++;
           }
           cout<<a<<endl;
        }
        return 0;
}
// a
// b
// ab
// c
// ac
// bc
// abc
