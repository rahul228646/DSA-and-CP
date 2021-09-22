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

