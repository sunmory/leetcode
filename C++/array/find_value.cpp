# include<iostream>
# include<vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row_num = array.size();
		int column_num = array[0].size();
		
		int i = row_num - 1;
		int j = 0;
		while (i >= 0 and j <= column_num - 1) 
		{
			if (target == array[i][j])
				return true;

			if (target < array[i][j])
				i--;
			else
				j++;
		}
		return false;
	}
};

int main() 
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
	cout << result << endl;
	return 0;
}