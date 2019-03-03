# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) 
	{
		long int m = s.length();
		long int n = t.length();

		long int temp_value_1 = 1;
		long int temp_value_2 = 0;

		vector<int> subseq_num(m + 1, 1);
		//subseq_num[0] = 0;

		for (long int j = 1; j < n + 1; j++) 
		{
			temp_value_1 = subseq_num[0];
			for (long int i = 0; i < m + 1; i++) 
			{	
				if (i < j) 
				{	
					temp_value_1 = subseq_num[i];
					subseq_num[i] = 0;
					continue;
				}
				if (s[i - 1] != t[j - 1]) 
				{	
					temp_value_1 = subseq_num[i];
					subseq_num[i] = subseq_num[i - 1];
				}
					
				else if (s[i - 1] == t[j - 1]) 
				{
					temp_value_2 = subseq_num[i];
					subseq_num[i] = subseq_num[i - 1] + temp_value_1;
					temp_value_1 = temp_value_2;
				}
			}
			//subseq_num[0] = 0;
		}

		return subseq_num[m];
	}
};

int main() 
{
	string s = "";
	string t = "";
	Solution solution;
	int result;

	result = solution.numDistinct(s, t);
	cout << "the number of distinct subsequences is: " << result << endl;
	
}