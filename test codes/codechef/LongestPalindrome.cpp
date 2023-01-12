int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for(const string& s: words)
            cnt[s]++;
        int len{0};
        bool appeared{false}; 
        for(const auto &[s,occ]: cnt)
        {
            if(s[1] == s[0])
            {
                if(not appeared and occ % 2 == 1)
                {
                    appeared = true; 
                    len += occ;
                    continue;
                }
                len += occ / 2 * 2;
            }
            else{
                auto it = cnt.find({s[1],s[0]});
                if(it != cnt.end())
                    len+= min(it->second, occ);
        }
        return 2 * len;
    }
