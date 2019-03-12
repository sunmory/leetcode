# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <functional>

using namespace std;

class Solution 
{
	vector<string> add_word(vector<string> last_array, string new_word)
	{
		vector<string> new_array;
		for (string temp : last_array)
			new_array.push_back(temp + " " + new_word);
		return new_array;
	}

public:
	vector<string> wordBreak(string s, vector<string>& wordDict) 
	{
		int length = s.size();
		int word_num = wordDict.size();
		vector<string>::iterator index;
		//vector<vector<int>> match_array(length, vector<int>(2, -1));
		vector<vector<int>> match_array(2);
		vector<string> temp_string_array;
		vector<string> temp_macth_string;
		vector<string> result;
		vector<unordered_map<string, vector<string>>> m(2);
		int current_index = 0;
		int last_index = 1;

		for (int char_index = 0; char_index < length; char_index++)
		{
			string substr = s.substr(0, char_index + 1);
			index = find(wordDict.begin(), wordDict.end(), substr);
			if ((index - wordDict.begin()) < word_num) 
			{
				match_array[current_index].push_back(char_index);
				m[current_index][substr] = (vector<string>(1, substr));
				if (char_index == length - 1)
					result.push_back(s);
			}		
	 	}

		for (int cut_num = 1; cut_num < length; cut_num++) 
		{
			current_index = (current_index + 1) % 2;
			last_index = (last_index + 1) % 2;
			match_array[current_index].clear();
			m[current_index].clear();
			for (int char_index = cut_num; char_index < length; char_index++) 
			{
				int first = 0;
				string push_key = s.substr(0, char_index + 1);
				for (int position : match_array[last_index]) 
				{
					if (position >= char_index)
						break;
					string sub_str = s.substr(position + 1, char_index - position);
					index = find(wordDict.begin(), wordDict.end(), sub_str);
					if (index - wordDict.begin() < word_num) 
					{	
						string get_key = s.substr(0, position + 1);
						
						temp_string_array = m[last_index][get_key];
						temp_string_array = add_word(temp_string_array, sub_str);
						if (first == 0)
						{
							match_array[current_index].push_back(char_index);
							first = 1;
						}
						for (string _s : temp_string_array)
							m[current_index][push_key].push_back(_s);
						if (char_index == length - 1) 
						{
							for (string _s : temp_string_array)
								result.push_back(_s);
						}
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	string b[10] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	vector<string> a(b, b + 10);
	string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Solution s;
	vector<string> result = s.wordBreak(s1, a);
	for (string _s : result)
		cout << _s << endl;
}