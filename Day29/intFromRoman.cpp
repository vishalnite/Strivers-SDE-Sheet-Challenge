/*
Convert from roman numeral to integer.

T.C - O(N)
S.C - O(1)
*/

int intFromRoman(char roman) {
    switch(roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int n = s.length();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i < n && intFromRoman(s[i + 1]) > intFromRoman(s[i])) {
            ans -= intFromRoman(s[i]);
        }
        else {
            ans += intFromRoman(s[i]);
        }
    }

    return ans;
}