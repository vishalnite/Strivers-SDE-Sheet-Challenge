/*
Given a sorted array. Each element appears twice except one number. FInd that number.

T.C - O(logN)
S.C - O(1)
*/

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	int low = 0, high = n - 2;

	while(low <= high) {
		int mid = (low + high) >> 1;

		if(mid % 2 == 0) {
			if(arr[mid] == arr[mid + 1]) 
				low = mid + 1;
			else
				high = mid - 1;
		}
		else {
			if(arr[mid] == arr[mid + 1])
				high = mid - 1;
			else 
				low = mid + 1;
		}
	}

	return arr[low];
}