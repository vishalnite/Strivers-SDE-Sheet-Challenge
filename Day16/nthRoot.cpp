/*
FInd the nth root of the given number.

T.C - O(N * log(M))
S.C - O(1)
*/

int nthRoot(int mid, int n, int m) {
  long long prod = 1;
  for(int i = 0; i < n; i++) {
    prod *= mid;
    if(prod > m)
      return -1;
  }

  if(prod < m)
    return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int low = 0, high = m;
  while (low <= high) {
    int mid = (low + (high - low) / 2);

    if (nthRoot(mid, n, m) == 0)
      return mid;
    else if (nthRoot(mid, n, m) == 1)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}