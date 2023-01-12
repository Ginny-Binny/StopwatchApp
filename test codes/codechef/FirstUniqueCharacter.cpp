class Solution {
public:

    int firstUniqChar(string s) 
    {  
        vector<int> freq(200, 0);
        
        for(char ch:s)
            freq[(int)ch]++;
        
        for(int i=0; i<s.size(); i++)
            if (freq[(int)s[i]] == 1)
                return i;
        
        return -1;
    }
};

