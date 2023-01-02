#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int convertToInt(string s){
    int ans = 0;
    int multiplier = 1;
    for (int i = s.length()-1; i >=0 ; --i) {
        if(s[i]=='1') ans+= multiplier;
        multiplier*=2;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        vector<string> arr;

        for (int i = 0; i < n; ++i) {
            string s;
            cin>>s;
            arr.push_back(s);
        }

        vector<pair<int,int>> arr2;
        for (int i = 0; i < n; ++i) {
            arr2.push_back(make_pair(convertToInt(arr[i]),i));
        }
        sort(arr2.begin(),arr2.end());
        string ans = "";
        for(auto it:arr2){
            ans+=arr[it.second];
        }
        int count=0;
        for (int i = 0; i < ans.length(); ++i) {
            for (int j = i+1; j <ans.length(); ++j) {
                if(ans[i]=='1' && ans[j]=='0') count++;
            }
        }
        cout<<count<<endl;

    }


    return 0;
}