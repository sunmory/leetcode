# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> pre_path_num(n, 1);
		int max_num = 0;
		for (int raw_num = 1; raw_num < m; raw_num++) 
		{
			vector<int> current_path_num(n, 0);
			for (int col_num = 0; col_num < n; col_num++) 
			{
				if (col_num == 0)
					current_path_num[col_num] = 1;
				else
					current_path_num[col_num] = current_path_num[col_num - 1] + pre_path_num[col_num];
			}
			pre_path_num = current_path_num;
			max_num = current_path_num[n - 1];
		}
		
		return max_num;
	}
};


void main() 
{
	Solution s;
	int num = s.uniquePaths(3, 3);
	cout << "max path: " << num << endl;
}
