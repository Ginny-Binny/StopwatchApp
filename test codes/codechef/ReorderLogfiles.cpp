class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            if (isdigit(a.back()))  
                return false;
            if (isdigit(b.back())) 
                return true;
            const auto aa = a.substr(a.find(' '));
            const auto bb = b.substr(b.find(' '));
            if (aa == bb)
                return a < b;
            return aa < bb; 
        });
       
        return logs;
    }
};
