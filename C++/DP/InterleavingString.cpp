# include <iostream>
# include <string>
# include <vector>

using namespace std;


class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		/**
		* @brief 
		* 设已知字符串s3前t个字符可能由字符串s1的前t1个字符与字符串s2的前t2个字符交错排列而成,
		* 且有 t1 + t2 = t， 则考虑当前问题——匹配s3中第t+1个字符串，其共有两种情况：
		* - 由 s1 的第 t1 + 1 个字符匹配 s3 的第 t + 1 个字符
		* - 由 s2 的第 t2 + 1 个字符匹配 s3 的第 t + 1 个字符
		* 构建二维数组 bool_array 描述这一情况：
		* 则 bool_array[t1][t2] 为求解 bool_array[t1 + 1][t2] 与 bool_array[t1][t2 + 1] 的子问题。
		* 考虑到在 bool_array 数组构建时，从左至右按列构建，每次只需用到上一列的结果，所以可将内存空间简化至一维数组。
		* 当 bool_array[m + 1][n + 1]为true时，表示存在由s1与s2转换至s3的交错排列
		*/
		int m = s1.length();
		int n = s2.length();

		// 创建 m + 1 维数组以包含空字符来讨论字符串s1或字符串s2分别为s3起始字符串的情形
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
}