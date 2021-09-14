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
