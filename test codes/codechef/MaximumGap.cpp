class Solution {
public:
    int maximumGap(vector<int>& n) {
        if(n.size()<2)
            return 0;
        int m=0;
        sort(n.begin(),n.end());
        for(int i=0;i<n.size()-1;i++)
            m=max(m,n[i+1]-n[i]);
        return m;
    }
};
