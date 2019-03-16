# include <iostream>
# include <string>
# include <vector>

using namespace std;

//class Solution {
//public:
//	int longestValidParentheses(string s) 
//	{
//		int n = s.size();
//		int max_length = 0;
//		vector<vector<bool>> match_array(n / 2);
//
//		for (int i = 0; i < n / 2; i++) 
//		{
//			// 2 * (i + 1)
//			match_array[i].resize(n - 2 * (i + 1) + 1, false);
//		}
//
//		for (int i = 0; i < n - 1; i++) 
//		{
//			if (s[i] == '(' and s[i + 1] == ')') 
//			{
//				match_array[0][i] = true;
//				max_length = 2;
//			}
//				
//		}
//
//		bool match = false;
//		bool temp_match = false;
//		int length;
//		int temp_length;
//
//		for (int i = 1; i < n / 2; i++) 
//		{
//			cout << "index: " << i << endl;
//			for (int j = 0; j < n - 2 * (i + 1) + 1; j++) 
//			{	
//				match = false;
//				length = (i + 1) * 2;
//				for (int len = 2; len < length; len = len + 2) 
//				{
//				//	temp_length = 2 * (len + 1);
//					temp_match = match_array[len / 2 - 1][j] and match_array[(length - len) / 2 - 1][j + len];
//					match = match or temp_match;
//					if (match == true)
//						break;
//				}
//				match = match or (s[j] == '(' and match_array[i - 1][j + 1] and s[j + length - 1] == ')');
//				match_array[i][j] = match;
//				if (match and max_length < 2 * (i + 1))
//					max_length = 2 * (i + 1);
//			}
//		}
//		return max_length;
//	}
//};

class Solution {
public:
	int longestValidParentheses(string s) 
	{
		int n = s.size();
		int max_length = 0;
		int temp_index;
		vector<int> match_index(n, 0);
		for (int i = 1; i < n; i++) 
		{
			if (s[i] == ')') 
			{
				if (s[i - 1] == '(')
					match_index[i] = (i > 2 ? match_index[i - 2] : 0) + 2;
				else {
					temp_index = i - (match_index[i - 1] + 1);
					match_index[i] = (i > 2 and match_index[i - 1] > 0 and temp_index >= 0 and s[temp_index] == '(') 
						? match_index[temp_index - 1] + match_index[i - 1] + 2 : 0;
				}
					
			}
			max_length = max_length > match_index[i] ? max_length : match_index[i];
		}
		return max_length;
	}
};


void main() {
	Solution s;
	string str = ")(()())(";
	cout << s.longestValidParentheses(str) << endl;
}