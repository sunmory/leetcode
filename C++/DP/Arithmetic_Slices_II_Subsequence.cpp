# include<iostream>
# include <map>
# include <vector>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		/**
		�� index Ϊ���� A ��������interval_array[i] ��Ӧ�� map ���������� i ���Ĳ�ͬ���ȼ�� d ��������Ŀ
		��ԭ���⣺λ�� i ���ĸ�����ͬ���ȼ����������Ŀ
		�����������⣺ ����λ�� j (0 < j < i) ������ d = A[i] - A[j] ��������Ŀ֮����� (��ͬ�� A[i] - A[j] �ֱ�������ڼ���λ�� i ����ͬ�� d ������Ŀ)
		*/
		int length = A.size();
		vector<map<int, int>> interval_array(length);

		for (int i = 0; i < length; i++) 
		{
			map<int, int> single_interval;

		}
	}
};