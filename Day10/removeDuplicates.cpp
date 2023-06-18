/*
Remove duplicates from the array. Do it in-place and return the new length of the array.

T.C - O(N)
S.C - O(1)
*/

int removeDuplicates(vector<int> &arr, int n) {
	int i = 0;
	for(int j = 1; j < n; j++) {
		if(arr[i] != arr[j]) {
			i++;
			arr[i] = arr[j];
		}
	}
	return i + 1;
}