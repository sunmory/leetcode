# include<iostream>
# include<vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row_num = array.size();
		int column_num = array[0].size();

		int left = 0;
		int right = column_num - 1;
		int up = 0;
		int down = row_num - 1;

		int middle_row;
		int middle_column;

		while (left <= right and up <= down) 
		{
			middle_row = (up + down) / 2;
			middle_column = (left + right) / 2;

			if (target == array[middle_row][middle_column])
				return true;
			if (target > array[middle_row][middle_column])
			{
				left = middle_column + 1;
				up = middle_row + 1;
			}
			else 
			{
				right = middle_column - 1;
				down = middle_row - 1;
			}
		}
		if (left > right) 
		{
			while (up <= down) 
			{
				int middle = (up + down) / 2;
				if (target == array[middle][middle_column])
					return true;
				if (target > array[middle][middle_column])
					up = middle + 1;
				else
					down = middle - 1;
			}
		}
		if (up > down) 
		{
			while (left <= right) 
			{
				int middle = (left = right) / 2;
				if (target == array[middle_row][middle])
					return true;
				if (target > array[middle_row][middle])
					left = middle + 1;
				else
					right = middle - 1;
			}
		}
		return false;
	}
};

void main() 
{
	int a[5][2] = { { 2, 5 },{ 6, 13 },{ 8, 16 },{ 10, 18 },{ 20, 21 } };
	vector<vector<int>> positions(5, vector<int>(2));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			positions[i][j] = a[i][j];
		}
	}

	Solution s;
	bool result = s.Find(8, positions);
}