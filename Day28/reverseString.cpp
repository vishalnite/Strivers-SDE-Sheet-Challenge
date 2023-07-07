/*
Reverse a string. The string may contain multiple spaces at the start, end and in between.
E.g - "   the sky    is  blue   "
O/p - "blue is sky the"

[Brute force -- using stack]

T.C - O(N)
S.C - O(1)
*/

string reverseString(string &str){
	int left = 0;
	int right = str.length() - 1;

	string ans = "";
	string word = "";

	while(str[left] == ' ') {
		left++;
	}

	while(str[right] == ' ') {
		right--;
	}

	while(left <= right) {
		if(str[left] != ' ') {
			word += str[left];
		}
		else {

			if(str[left - 1] == ' ') {
				left++;
				continue;
			}

			if(ans.length() == 0)
				ans = word;
			else 
				ans = word + " " + ans;
			word = "";		
		}
		left++;
	}

	if(ans.length() == 0) {
		ans = word;
	}
	else {
		ans = word + " " + ans;
	}
	
	return ans;
}



