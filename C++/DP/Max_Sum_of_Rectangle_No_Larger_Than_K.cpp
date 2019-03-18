# include <iostream>
# include <vector>
# include <set>
# include <algorithm>

using namespace std;

class Solution 
{
	//struct result 
	//{
	//	int start_index;
	//	int end_index;
	//	int max_value;
	//};
	int maximum_subsequence(const vector<int> & a, int k) 
	{
		//result r;
		int length = a.size();
		int sum_to_index = a[0];
		int max_value;


		for (int index = 1; index < length; index++) 
		{
			int temp_sum = sum_to_index + a[index];
			if (temp_sum < k and temp_sum) 
			{
				sum_to_index = (sum_to_index + a[index]);
			}
			else
			{
				sum_to_index = a[index];
			}

			if (max_value >= sum_to_index) 
			{
				max_value = max_value;
			}
			else 
			{
				max_value = sum_to_index;
			}
		}

		return max_value;
	}


public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
	{
		if (matrix.empty())
			return 0;
		int row_num = matrix.size();
		int column_num = matrix[0].size();
		int current_value = INT_MIN;
		int current_sum = 0;

		set<int>::iterator ite;

		

		for (int left_index = 0; left_index < column_num; left_index++)
		{
			vector<int> add_by_row(row_num, 0);
			for (int right_index = left_index; right_index < column_num; right_index++) 
			{
				set<int> sum_set;
				sum_set.insert(0);
				for (int i = 0; i < row_num; i++)
					add_by_row[i] = add_by_row[i] + matrix[i][right_index];
				current_sum = 0;
				for (int temp_value : add_by_row) 
				{
					current_sum = current_sum + temp_value;
					ite = sum_set.lower_bound(current_sum - k);
					if (ite != sum_set.end())
						current_value = max(current_value, current_sum - *ite);
					sum_set.insert(current_sum);
				}
			}
		}
		return current_value;
	}
};

int main() 
{
	int a1[5] = { 7, 7, 4, -6, -10 };
	int a2[5] = { -7, -3, -9, -1, -7 };
	int a3[5] = { 9, 6, -3, -7, 7 };
	int a4[5] = { -4, 1, 4, -3, -8 };
	int a5[5] = { -7, -4, -4, 6, -10 };
	int a6[5] = { 1, 3, -2, 3, -10 };
	int a7[5] = { 8, -2, 1, 1, -8 };

	int result;

	vector<vector<int>> matrix(1, vector<int>(3));

	int a[7][5] = { { 7, 7, 4, -6, -10 },{ -7, -3, -9, -1, -7 } ,{ 9, 6, -3, -7, 7 },{ -4, 1, 4, -3, -8 },{ -7, -4, -4, 6, -10 },{ 1, 3, -2, 3, -10 },{ 8, -2, 1, 1, -8 } };
	int b[1][3] = { {2, 2, -1} };
	for (int i = 0; i < 1; i++) 
		for (int j = 0; j < 3; j++)
			matrix[i][j] = b[i][j];

	Solution s;
	result = s.maxSumSubmatrix(matrix, 0);
	cout << result << endl;
}