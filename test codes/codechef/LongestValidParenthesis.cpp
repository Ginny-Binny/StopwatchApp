class Solution {
public:
    int longestValidParentheses(string s) {
        
        int maxL=0;
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch=='(')open++;
            else close++;
            if(close==open)maxL=max(maxL,(open+close));
            else if(close>open){open=0;close=0;}
        }
        open=close=0;
         for(int i=s.length()-1;i>=0;i--){
            char ch = s[i];
            if(ch=='(')open++;
            else close++;
            if(close==open)maxL=max(maxL,(open+close));
            else if(close<open){open=0;close=0;}
        }
        return maxL;
    }
};
