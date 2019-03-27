# include<iostream>
# include <map>
# include <vector>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		/**
		设 index 为数组 A 的索引，interval_array[i] 对应的 map 包含了索引 i 处的不同长度间隔 d 的序列数目
		则原问题：位置 i 处的各个不同长度间隔的序列数目
		可利用子问题： 各个位置 j (0 < j < i) 处长度 d = A[i] - A[j] 的序列数目之和求出 (不同的 A[i] - A[j] 分别求和用于计算位置 i 处不同的 d 序列数目)
		*/
		int length = A.size();
		vector<map<int, int>> interval_array(length);

		for (int i = 0; i < length; i++) 
		{
			map<int, int> single_interval;

		}
	}
};