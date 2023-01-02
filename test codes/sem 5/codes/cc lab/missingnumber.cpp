#include <bits/stdc++.h>
using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr)
{
    map<int, int> arr_1;
    map<int, int> brr_1;
    for (int i = 0; i < arr.size(); i++)
    {
        arr_1[arr[i]]++;
    }
    for (int i = 0; i < brr.size(); i++)
    {
        brr_1[brr[i]]++;
    }
    vector<int> ans;
    map<int, int>::iterator j = arr_1.begin();
    for (auto i : brr_1)
    {
        if (i.first == j->first)
        {
            // if (j != arr_1.end())
            // {
                if (i.second == j->second)
                {
                    j++;
                }
                else
                {
                    ans.push_back(i.first);
                    j++;
                }
            }
        // } 
        else
        {
            ans.push_back(i.first);
        }
    }
    return ans;
}

int main(){

    vector<int> arr1 = {1,2,3,4,6,7};
    vector<int> arr2 = {1,2,3,4,5,6,7};
    vector<int> res;

    res = missingNumbers(arr1, arr2);

    for(int i = 0; i<res.size(); i++){
        cout<<res[i];
    }
}