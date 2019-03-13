# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

bool compare1(const pair<int, int> & p1, const pair<int, int> & p2)
{
	if (p1.first < p2.first)
		return true;
	else if (p1.first == p2.first)
		return p1.second > p2.second;
	else
		return false;
}

class Solution 
{
	/**
	@brief 该院问题的解题思路为：
	首先将 pair vector 按长或宽中的一个排序，以长为例，
	先将 pair 按长升序排列， 当两个 pair 的长度相同时，宽度较大的排在前面（宽度降序），因为长相同的两个信封无法嵌套，如宽也是降序排列，
	则会造成长度相同的信息嵌套的判断
	之后根据宽找  longest increasing subsequence 
	常规的 DP 方法可以在 o(n^2)的复杂度下求出
	使用二叉搜索辅助可达到 o(nlog(n))复杂度
	其子问题分析为：
	首先创建一个 vector 存放当前可能的最长增长子串的信息——(子串最后位置上的数值， 子串的长度)，该 vector 称为 active_vector
	对于给定的数组 a，遍历其中的数字元素，当遍历到位置 i 时，数字 a[i] 对最长增长子串的作用可分三种情况讨论：
	(1) a[i] 是 active_vector 中存放的所有子串的最后位置上的数值的最小值时，以为这以 a[i] 开始有可能产生的子串长度最终达到最大值，因此将a[i] 
	加入 active_vector 长度为 1
	(2) a[i] 是  active_vector 中存放的所有子串中最后位置上的数值的一个中间值，则将 a[i] 增加到可以放入的子串中的最长子串的后面，将长度值 + 1，
	将新生成的子串与插入位置后面的子串长度比较，如相等则删除后面的子串(因为当前子串的最后位置上的数值要更小，意味着该结果更优)
	(3) a[i] 是 active_vector 中存放的所有子串的最后位置上的数值的最大值时，直接选出所有子串中长度最大的子串放入其后

	而由上述分析可知，active_vector 中不存在长度相同的子串，因为 最后位置上的数值的较小（其实是小于等于）的子串的插入
	会导致 最后位置上的数值的较大 的子串的删除

	此外， 最后位置上的数值的较大 的子串的长度 一定大于 最后位置上的数值的较小 的子串 （同样是由情况 (2) 保证的性质）

	因此，a[i] 插入的位置、插入后比较的位置都有 a[i] 在当前所有子串的最后位置上的数值的排序决定，即可采用二分查找确定。
	*/
	int binary_search(vector<pair<int, int>> activate_envelops, int end_num) 
	{
		int left = 0;
		int right = activate_envelops.size() - 1;
		int middle = 0;

		if (right == -1)
			return 0;

		while (left <= right) 
		{
			middle = left + (right - left) / 2;
			if (activate_envelops[middle].first < end_num)
				left = middle + 1;
			else if (activate_envelops[middle].first > end_num)
				right = middle - 1;
			else
				return middle;
		}

		if (activate_envelops[middle].first > end_num)
			return - middle;
		if (activate_envelops[middle].first < end_num)
			return - (middle + 1);
	}
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes)
	{
		int num = envelopes.size();
		int index = 0;
		vector<pair<int, int>> activate_vector;
		pair<int, int> temp_pair;

		if (num == 0)
			return 0;

		sort(envelopes.begin(), envelopes.end(), compare1);

		for (vector<pair<int, int>>::iterator envelopes_index = envelopes.begin(); envelopes_index != envelopes.end(); envelopes_index++) 
		{
			index = binary_search(activate_vector, (*envelopes_index).second);
			if (index == 0) 
			{
				temp_pair.first = (*envelopes_index).second;
				temp_pair.second = 1;
				activate_vector.insert(activate_vector.begin() + index, temp_pair); 
				if (activate_vector.size() > 1)
					if (activate_vector[1].second == 1)
						activate_vector.erase(activate_vector.begin() + 1, activate_vector.begin() + 2);
					
			}
			else
			{
				index = abs(index);
				temp_pair.first = (*envelopes_index).second;
				temp_pair.second = activate_vector[index - 1].second + 1;
				//activate_vector[index - 1].first = (*envelopes_index).second;
				activate_vector.insert(activate_vector.begin() + index, temp_pair);
				if (index + 1 <= activate_vector.size() - 1)
					if (activate_vector[index].second == activate_vector[index + 1].second)
						activate_vector.erase(activate_vector.begin() + index + 1, activate_vector.begin() + index + 2);
			}
				
		}
		temp_pair = activate_vector.back();
		return temp_pair.second;
	}
};

int main() 
{
	pair<int, int>p1(1, 2);
	pair<int, int>p2(2, 3);
	pair<int, int>p3(3, 4);
	pair<int, int>p4(3, 5);
	pair<int, int>p5(4, 5);
	pair<int, int>p6(5, 5);
	pair<int, int>p7(5, 6);
	pair<int, int>p8(6, 7);
	pair<int, int>p9(7, 8);
	//pair<int, int>p5(1, 1);

	vector<pair<int, int>> envelops;
	envelops.push_back(p1);
	envelops.push_back(p2);
	envelops.push_back(p3);
	envelops.push_back(p4);
	envelops.push_back(p5);
	envelops.push_back(p6);
	envelops.push_back(p7);
	envelops.push_back(p8);
	envelops.push_back(p9);
	//envelops.push_back(p5);

	Solution s;
	int max_num = s.maxEnvelopes(envelops);
	cout << "max_num: " << max_num << endl;

}