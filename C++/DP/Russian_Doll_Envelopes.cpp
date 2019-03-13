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
	@brief ��Ժ����Ľ���˼·Ϊ��
	���Ƚ� pair vector ��������е�һ�������Գ�Ϊ����
	�Ƚ� pair �����������У� ������ pair �ĳ�����ͬʱ����Ƚϴ������ǰ�棨��Ƚ��򣩣���Ϊ����ͬ�������ŷ��޷�Ƕ�ף����Ҳ�ǽ������У�
	�����ɳ�����ͬ����ϢǶ�׵��ж�
	֮����ݿ���  longest increasing subsequence 
	����� DP ���������� o(n^2)�ĸ��Ӷ������
	ʹ�ö������������ɴﵽ o(nlog(n))���Ӷ�
	�����������Ϊ��
	���ȴ���һ�� vector ��ŵ�ǰ���ܵ�������Ӵ�����Ϣ����(�Ӵ����λ���ϵ���ֵ�� �Ӵ��ĳ���)���� vector ��Ϊ active_vector
	���ڸ��������� a���������е�����Ԫ�أ���������λ�� i ʱ������ a[i] ��������Ӵ������ÿɷ�����������ۣ�
	(1) a[i] �� active_vector �д�ŵ������Ӵ������λ���ϵ���ֵ����Сֵʱ����Ϊ���� a[i] ��ʼ�п��ܲ������Ӵ��������մﵽ���ֵ����˽�a[i] 
	���� active_vector ����Ϊ 1
	(2) a[i] ��  active_vector �д�ŵ������Ӵ������λ���ϵ���ֵ��һ���м�ֵ���� a[i] ���ӵ����Է�����Ӵ��е���Ӵ��ĺ��棬������ֵ + 1��
	�������ɵ��Ӵ������λ�ú�����Ӵ����ȱȽϣ��������ɾ��������Ӵ�(��Ϊ��ǰ�Ӵ������λ���ϵ���ֵҪ��С����ζ�Ÿý������)
	(3) a[i] �� active_vector �д�ŵ������Ӵ������λ���ϵ���ֵ�����ֵʱ��ֱ��ѡ�������Ӵ��г��������Ӵ��������

	��������������֪��active_vector �в����ڳ�����ͬ���Ӵ�����Ϊ ���λ���ϵ���ֵ�Ľ�С����ʵ��С�ڵ��ڣ����Ӵ��Ĳ���
	�ᵼ�� ���λ���ϵ���ֵ�Ľϴ� ���Ӵ���ɾ��

	���⣬ ���λ���ϵ���ֵ�Ľϴ� ���Ӵ��ĳ��� һ������ ���λ���ϵ���ֵ�Ľ�С ���Ӵ� ��ͬ��������� (2) ��֤�����ʣ�

	��ˣ�a[i] �����λ�á������Ƚϵ�λ�ö��� a[i] �ڵ�ǰ�����Ӵ������λ���ϵ���ֵ��������������ɲ��ö��ֲ���ȷ����
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