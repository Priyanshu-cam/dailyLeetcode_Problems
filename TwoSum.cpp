// Two Sum Problem:
/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Brute:
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(nums[i] + nums[j] == target) return {i, j};

        //     }
        // }  uses O(n^2) time and no space
        // return {-1,-1};

        // Optimal:
        unordered_map<int, int> pair;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];

            auto it = pair.find(diff);

            if (it != pair.end())
                return {it->second, i};

            pair[nums[i]] = i;
        }
        return {};
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
    int target;
    cin >> target;

    vector<int> ans = s.twoSum(arr, target);
    if (ans.empty())
        cout << "No solution";
    else
        for (int i : ans)
            cout << i << " ";


    return 0;
}