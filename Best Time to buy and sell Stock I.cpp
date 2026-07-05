// Two Sum Problem:
/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); // to get the size of the given array; 
        int buyDay = prices[0];// setting first element as buying day 
        int profit = 0; // to store maxProfit;

        for(int i = 1; i < n; i++){ // iterate over the loop 
           if(prices[i] > buyDay){ // if the current price is greater than the buyDay, means the stock prices increased then
            profit = max(profit, (prices[i] - buyDay)); // calculate the profit (to sell the stock )
           }

           buyDay = min(buyDay, prices[i]); // else find out the min element from the array and make it as a buying day to get the maximum profit.
        }
        return profit;
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

   cout<<s.maxProfit(arr);
    return 0;
}