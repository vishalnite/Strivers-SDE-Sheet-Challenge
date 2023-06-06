/*
Maximize the profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit that can be achieved from this transaction.

T.C - O(N)
S.C = O(1)
*/

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    
    int n = prices.size();
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;

}