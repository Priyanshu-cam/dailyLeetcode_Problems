#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size(); 
        // vector<int>ans(n, 1); 

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i == j) continue; // if we have same index then skip that element 

        //         ans[i] *= nums[j]; // multiplying the array element with the ans
        //     }
        // }
        // return ans; 

        // // SECOND APPROACH: 

        // int n = nums.size(); 
        // vector<int>prefix(n, 1); 
        // prefix[0] = 1; 
        // vector<int>suffix(n, 1); 
        // suffix[n - 1] = 1; 
        // vector<int>ans(n, 1); 

        // for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] * nums[i - 1]; 
        // for(int j = n - 2; j >= 0; j--) suffix[j] = suffix[j + 1] * nums[j + 1];

        // for(int k = 0; k < n; k++) ans[k] = prefix[k] * suffix[k];

        // return ans; 

        // Follow Up Approach: 
        int n = nums.size();
        int prefix = 1, suffix = 1; 
        vector<int>ans(n,1); 

        for(int i = 0; i < n; i++){
            ans[i] = prefix; 
            prefix *= nums[i];
        }

        for(int j = n - 1; j >= 0; j--){
            ans[j] *= suffix; 
            suffix *= nums[j];
        }
        
        return ans;
    }
};

int main(){
    Solution s; 

    int n; // arr size; 
    cin>>n; // taking array size 

    vector<int>arr(n); // declaring a vector of size n 
    for(int i = 0; i < n; i++) cin>>arr[i]; // storing elements into the vector

    vector<int>ans = s.productExceptSelf(arr); // storing the modified array into answer as answer array

    for(int i : ans) cout<<i<<" ";

    return 0; 
}


// Approach 1: 
/* Here i have used the concept of nested loop: 
iterating over the loop where ith element is the current and jth will help me to get the product of the remaining element except ith
so: 
if at any moment index i == j, skip that element and calculate the product of remaining elements of the given array; 
this will take O(n^2) time complexity and auxiliary space will be O(2N) --> O(n) time complexity 
*/

// Second Approach using prefix and suffix 
/*
in this approach i am using the concept of prefix and suffix sum which means the product of elements present on my left and product of elements present on my right
that way we will get two array with product of current element's left and right elements present 
and it will take O(n) time and auxiliary space as O(3N) --> O(n) space complexity
*/

// Follow Up approach:
// Here i am directly updating suffix and prefix, so No need to store them in seperate vector, Just update and use it 