/*
Fractional Knapsack problem.

T.C - O(NlogN) + O(N)
S.C - O(1)
*/

#include <bits/stdc++.h>

bool static comparator(pair<int, int> p1, pair<int, int> p2) {
    double r1 = (double)p1.second / p1.first;
    double r2 = (double)p2.second / p2.first;
    return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);
    double maxProfit = 0.0;

    int i = 0;
    int capacity = w;

    while(i < n && capacity > 0) {
        int weight = items[i].first;
        int value = items[i].second;

        if(weight <= capacity) {
            capacity -= weight;
            maxProfit += value;
        }
        else {
            maxProfit += (((double)capacity / weight) * value);
            capacity = 0;
        }
        i++;
    }

    return maxProfit;
}