// Two Sum Problem:
/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // bool duplicate = false;
        // int n = nums.size();

        // for(int i = 0; i < n; i++){ // TLE --> O(n^2) time complexity
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] == nums[j]) duplicate = true;
        //     }
        // }
        // return duplicate;
        // not the optimal, as it will count the freq of all the elements
        // present int n = nums.size();

        // unordered_map<int,int>freq;

        // for(int i : nums){
        //     freq[i]++;
        // }

        // for(auto i : freq){
        //     if(i.second >= 2) return true;
        // }

        // return false;

        // OPTIMAL APPROACH --------------  usinf hash set
        unordered_set<int> st;

        for (int x : nums) {
            if (st.count(x)) // this will return 1 or 0, if duplicate exist return 1 else return 0
                return true;
            st.insert(x);
        }
        return false;
    }
};

int main()
{
    Solution s;
    int n; // use for the size of the array
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

   cout<<s.containsDuplicate(arr);
    return 0;
}