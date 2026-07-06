#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        
        int current_sum = 0; 
        int max_sum = INT_MIN;

        for(int i = 0; i < n; i++){
            current_sum += nums[i]; 
            max_sum = max(max_sum, current_sum); 

            if(current_sum < 0) current_sum = 0; 
        }
        return max_sum;
    }
};

int main(){
    Solution s; 
    int n; 
    cin>>n; 
    vector<int>arr(n); 

    for(int i = 0; i < n; i++)cin>>arr[i]; 

    cout<<s.maxSubArray(arr); 

    return 0; 
}