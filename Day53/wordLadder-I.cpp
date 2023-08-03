/*
Given a dictionary of words, a start word and a target word. All are of same size. Find the number of sequences it takes to transform start word
to end word. Each trasfromation should exist in the dictionary.
[Use BFS traversal and change each character of word from 'a' to 'z, if found put it into queue and erase from dictionary]

T.C - O(N  * word length * 26)
S.C - O(N)
*/

#include<unordered_set>
#include<queue>

int wordLadder(string begin, string end, vector<string> &dict) 
{
	int len = begin.size();
	unordered_set<string> st(dict.begin(), dict.end());
	queue<pair<string, int>> q;
	q.push({begin, 1});
	st.erase(begin);

	while(!q.empty()) {
		string word = q.front().first;
		int steps = q.front().second;
		q.pop();

		if(word == end)
			return steps;

		for(int i = 0; i < len; i++) {
			char original = word[i];
			for(char ch = 'a'; ch <= 'z'; ch++) {
				word[i] = ch;
				if(st.find(word) != st.end()) {
					q.push({word, steps + 1});
					st.erase(word);
				}
			}
			word[i] = original;
		}
	}

	return -1;
}