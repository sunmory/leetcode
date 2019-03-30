#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

float distance(float x1, float y1, float x2, float y2) 
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int split_users(float d, int users_num, vector<vector<float>> positions) 
{
	vector<vector<vector<float>>> results;

	for (int i = 0; i < users_num; i++) 
	{
		vector<vector<float>> temp_areas;
		vector<float> temp_user(3);
		int insert_position = -1;
		temp_user[0] = i;
		temp_user[1] = positions[i][0];
		temp_user[2] = positions[i][1];
		if (results.empty()) 
		{
			temp_areas.push_back(temp_user);
			results.push_back(temp_areas);
		}
		else
		{
			//for (int j = 0; j < results.size(); j++) 

			//for (vector<vector<vector<float>>>::iterator areas_ite = results.begin(); areas_ite < results.end(); areas_ite++)
			vector<vector<vector<float>>>::iterator areas_ite = results.begin();
			while(areas_ite < results.end())
			{
				bool is_find = false;
				for (vector<float> single_position : *areas_ite) 
				{
					
					float _d = distance(positions[i][0], positions[i][1], single_position[1], single_position[2]);
					if (_d <= d) 
					{
						temp_areas.insert(temp_areas.end(), (*areas_ite).begin(), (*areas_ite).end());
						if(insert_position == -1)
							insert_position = areas_ite - results.begin();
						areas_ite = results.erase(areas_ite);
						is_find = true;
						break;
					}
				}
				if (not is_find)
					areas_ite++;
			}
			temp_areas.push_back(temp_user);
			if (insert_position == -1)
				results.push_back(temp_areas);
			else
				results.insert(results.begin() + insert_position, temp_areas);
		}
	}
	for (vector<vector<vector<float>>>::iterator result_ite = results.begin(); result_ite < results.end(); result_ite++)
	{
		cout << endl;
		for (vector<float> temp_user : *result_ite)
			cout << temp_user[0] << " ";

	}

	return 0;
}

int q1() {
	int n = 10;
	int m = 5;
	int temp_m = 1;

	vector<int> students(n, 0);

	for (int i = 0; i < n; i++) {
		students[i] = i + 1;
	}

	vector<int>::iterator point = students.begin();

	while (students.size() > 1)
	{
		temp_m = temp_m * m;;
		for (int i = 0; i < temp_m; i++)
		{
			if (point == students.end())
				point = students.begin();
			if (i == m - 1) {
				cout << "out: " << *point << endl;
				point = students.erase(point);
			}
			else
				point++;

		}
	}
	cout << "result: " << students[0] << endl;
	return students[0];

}

int main() 
{
	float d = 2;
	int n = 5;
	float a[5][2] = { {3, 5}, {6, 13}, {2, 6}, {7, 12}, {0, 2} };
	vector<vector<float>> positions(n, vector<float>(2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			positions[i][j] = a[i][j];
		}
	}

	split_users(d, n, positions);
}
