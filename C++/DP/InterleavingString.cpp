# include <iostream>
# include <string>
# include <vector>

using namespace std;


class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		/**
		* @brief 函数简要说明-测试函数
		* @param index    参数1
		* @param t        参数2 @see CTest
		*
		* @return 返回说明
		*     -<em>false</em> fail
		*     -<em>true</em> succeed
		*/
		int m = s1.length();
		int n = s2.length();

		// 创建 m + 1 维数组以讨论字符串s1或字符串s2分别为s3起始字符串的情形
		vector<bool> bool_array(m + 1, false);
		bool_array[0] = true;

		// 如果长度限制不满足，直接false
		if (m + n != s3.length())
			return false;

		for (int row = 1; row < m + 1; row++) 
		{
			if (bool_array[row - 1] and s1[row - 1] == s3[row - 1])
				bool_array[row] = true;
			else
				break;
		}

		for (int column = 1; column < n + 1; column++) 
		{
			for (int row = 0; row < m + 1; row++) 
			{
				if (row == 0)
					bool_array[row] = (bool_array[row] and (s2[column - 1] == s3[column - 1]));
				else
					bool_array[row] = (bool_array[row] and s2[column - 1] == s3[row + column - 1]) or (bool_array[row - 1] and s1[row - 1] == s3[row + column - 1]);
			}
		}

		return bool_array[m];
	}
};

int main(){
	Solution s;
	string s1 = "dbbca";
	string s2 = "";
	string s3 = "dbbca";
	bool result = s.isInterleave(s1, s2, s3);
	cout << "Interleaving: " << result << endl;
	//cout << s1.length() << endl;
}