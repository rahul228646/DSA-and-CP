
// find the number of pair such that  l<= a[i]+a[j] <=r
// lower bound function returns the index of the next smallest number just greater than or equal to that number
// upper bound function returns the index of the next largest number just smaller than or equal to that number

void solve () {
    int t, n, l, r;
    cin>>t;
    while(t--) {
        cin>>n>>l>>r;
        vector<int> v(n, 0);
        ll sum = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }
        srtInc(v);
        for (int i = 0; i < n; ++i) {
            int newLb = abs(l-v[i]);
            int newUb = abs(r-v[i]);
            int id1 = upper_bound(v.begin()+i+1, v.end(), newUb)-v.begin();
            int id2 = lower_bound(v.begin()+i+1, v.end(), newLb)-v.begin();
            cout<<id2<<" "<<id1<<endl;
            count += id1-id2;
        }
        prt(count);
    }
}
