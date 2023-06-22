/*
Find the kth permutation sequence of numbers from 1 to N

[Brute force -- Recursion -- Takes a lot of time -- O(N! * N) * O(N!*log(N!))]

T.C - O(N) * O(N) = O(N^2)
S.C - O(N)
*/

string kthPermutation(int n, int k) {
    vector<int> numbers;
    int fact = 1;
    for(int i = 1; i < n; i++) {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k - 1;
    string ans = "";
    while(true) {
        int pos = k / fact;
        ans = ans + to_string(numbers[pos]);
        numbers.erase(numbers.begin() + pos);
        if(numbers.size() == 0)
            break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
