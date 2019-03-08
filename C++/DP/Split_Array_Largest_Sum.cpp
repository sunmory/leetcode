# include<iostream>
# include<vector>
# include<algorithm>

using namespace std;

class Solution 
{
public:
	int splitArray(vector<int>& nums, int m) 
	{
		int nums_size = nums.size();
		vector<long> min_max_array(nums_size, 0);

		m = m - 1;

		//min_max_array[0] = nums[0];
		long sum = 0;
		long max_value = 0;
		long min_max = 0;

		for (int num_index = 0; num_index < nums_size; num_index++) 
		{
			sum = sum + nums[num_index];
			min_max_array[num_index] = sum;
		}

		for (int _m = 1; _m <= m; _m++) 
		{
			//for (int num_index = _m; num_index < nums_size; num_index++)
			for (int num_index = nums_size - 1; num_index >= _m; num_index--)
			{
				sum = 0;
				min_max = INT_MAX;
				//for (int split_index = nums_size - 1; split_index >= num_index; split_index--) 
				//{
				//	sum = sum + nums[split_index];
				//	max_value = max(min_max_array[split_index - 1], sum);
				//	if (max_value < min_max)
				//		min_max = max_value;
				//}

				for (int split_index = num_index; split_index > _m - 1; split_index--)
				{
					sum = sum + nums[split_index];
					max_value = max(min_max_array[split_index - 1], sum);
					if (max_value < min_max)
						min_max = max_value;
				}
				min_max_array[num_index] = min_max;
			}
		}

		return min_max_array[nums_size - 1];
	}

	int splitArray2(vector<int>& nums, int m)
	{	
		int nums_size = nums.size();
		vector<int> min_max_array(nums_size, 0);

		m = m - 1;

		//min_max_array[0] = nums[0];
		int sum = 0;
		int min_max_value = INT_MAX;
		int min_max = INT_MAX;
		int temp_max_value = 0;
		int temp_min_max = 0;

		for (int num_index = 0; num_index < nums_size; num_index++)
		{
			sum = sum + nums[num_index];
			min_max_array[num_index] = sum;
		}

		for (int _m = 1; _m <= m; _m++)
		{
			sum = 0;
			//min_max = INT_MAX;
			min_max_value = INT_MAX - nums[_m] - 10;
			temp_min_max = min_max_array[_m - 1];
			for (int num_index = _m; num_index < nums_size; num_index++)
			{
				//sum = sum + nums[num_index];7 2 5 10 8
				//temp_max_value = max(min_max_array[num_index - 1], sum);
				temp_max_value = max(temp_min_max, nums[num_index]);
				min_max_value = min(min_max_value, temp_max_value);
				temp_min_max = min_max_array[num_index];
				min_max_array[num_index] = min_max_value;
			}
		}

		return min_max_array[nums_size - 1];
	}
};

int main() 
{
	int a[5] = { 7, 2, 5, 10, 8 };
	vector<int> nums(a, a + 5);
	int result;
	Solution s;
	result = s.splitArray2(nums, 2);
	cout << "min_max: " << result << endl;

}