/*
Find all the permutations of the string.

T.C - O(N! * N)
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
