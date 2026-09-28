#include<bits/stdc++.h>
class Solution {
public:
    typedef long long int ll;
    bool canTransform(vector<int>& source, vector<int>& target) {

        ll s1=accumulate(source.begin(),source.end(),0LL);
        ll s2=accumulate(target.begin(),target.end(),0LL);
        return s1==s2;
        
    }
};