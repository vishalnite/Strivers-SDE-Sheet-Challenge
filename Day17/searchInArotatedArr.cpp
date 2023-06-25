/*
Given a sorted array which is rotated by k elements. Check whether an element is present in the array.

T.C - O(logN)
S.C - O(1)
*/

int search(int* arr, int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(arr[mid] == key)
            return mid;

        if(arr[low] <= arr[mid]) {
            if(arr[low] <= key && key <= arr[mid])
                high = mid - 1;
            else    
                low = mid + 1;
        }
        else {
            if(arr[mid] <= key && key <= arr[high]) 
                low = mid + 1;
            else    
                high = mid - 1;
        }
    }

    return -1;
}