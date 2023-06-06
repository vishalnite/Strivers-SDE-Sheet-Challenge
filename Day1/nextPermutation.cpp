/*
Generate next largest permutation

T.C - O(N) + O(N) + O(N) = O(3N)
S.C - O(1)
*/

vector<int> nextPermutation(vector<int> nums, int n) {
    
    int idx = -1; //Index of breakpoint

    for(int i = n - 2; i >= 0; i--) { //loop from back to find the breakpoint
        if(nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }

    if(idx == -1) { //If there are no breakpoints, return reverse of the array
        reverse(nums.begin(), nums.end());
        return nums;
    }

    for(int i = n - 1; i > idx; i--) { //To find a number just greater than the breakpoint number
        if(nums[i] > nums[idx]) {
            swap(nums[i], nums[idx]);
            break;
        }
    }

    reverse(nums.begin() + idx + 1, nums.end());
    return nums;
}