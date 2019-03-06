# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		/**
		ԭ������ total_tra_num �ν����л�ȡ��������������Ϊ�� total_tra_num - 1 �ʲ����л�ȡ�������
		������ά�����б�ʾ���׵Ĵ������б�ʾ��Ʊ����������õ����µݹ鹫ʽ��
		best_solution[tra_num][sell_day] = max(prices[sell_day - 1] - prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1]);
		buy_day �� [1, sell_day] ����
		��ʾ�� tra_num �ν����ڵ� sell_day ������ʱ�����۸ù�Ʊ���ڵڼ��칺��ĲŻ����������
		best_solution[tra_num - 1][buy_day - 1] �������⣬��ʾ�����µ� buy_day - 1 �н��� tra_num - 1 �ν�������ȡ���������
		*/
		int total_tra_num = 2;
		int day_num = prices.size();
		//vector<int> best_solution(total_tra_num, 0);
		vector<vector<int>> best_solution(total_tra_num + 1, vector<int> (day_num + 1, 0));

		int max_value = 0;

		for (int tra_num = 1; tra_num <= total_tra_num; tra_num++) 
		{
			max_value = 0;
			for (int sell_day = 1; sell_day <= day_num; sell_day++) 
			{
				for (int buy_day = 1; buy_day <= sell_day; buy_day++) 
				{
					max_value = max(max_value, prices[sell_day - 1] - prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1]);
				}
				best_solution[tra_num][sell_day] = max_value;
			}
		}
		return best_solution[total_tra_num][day_num];
	}

	int maxProfit2(vector<int>& prices) {
		/**
		@ brief ʱ���Ż�
		*/
		int total_tra_num = 2;
		int day_num = prices.size();
		//vector<int> best_solution(total_tra_num, 0);
		vector<vector<int>> best_solution(total_tra_num + 1, vector<int>(day_num + 1, 0));

		int max_value = 0;
		int min_value = INT_MAX;

		for (int tra_num = 1; tra_num <= total_tra_num; tra_num++)
		{
			max_value = 0;
			min_value = INT_MAX;
			for (int sell_day = 1; sell_day <= day_num; sell_day++)
			{
				//max_value = 0;
				// ������ͬһ tra_num �¶� buy_day ѭ��ʱ�� prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1] ���ظ������
				// ���Խ���һ����������������������� buy_day ��ѭ��������
				//for (int buy_day = 1; buy_day <= sell_day; buy_day++)
				//{
				//	max_value = max(max_value, prices[sell_day - 1] - prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1]);
				//}
				// ��Ϊ�����ظ����ֵ���Сֵ����ʱʱ���Ż�Ϊ total_tra_num * day_num��
				min_value = min(prices[sell_day - 1] - best_solution[tra_num - 1][sell_day - 1], min_value);
				max_value = max(max_value, prices[sell_day - 1] - min_value);
				best_solution[tra_num][sell_day] = max_value;
			}
		}
		return best_solution[total_tra_num][day_num];
	}

	int maxProfit3(vector<int>& prices) {
		/**
		@ brief �ռ��Ż�
		*/
		int total_tra_num = 2;
		int day_num = prices.size();
		vector<int> best_solution(day_num + 1, 0);
		// ������ʱ�洢���� temp_profit
		int temp_profit;
		//vector<vector<int>> best_solution(total_tra_num + 1, vector<int>(day_num + 1, 0));

		int max_value = 0;
		int min_value = INT_MAX;

		for (int tra_num = 1; tra_num <= total_tra_num; tra_num++)
		{
			max_value = 0;
			min_value = INT_MAX;
			temp_profit = best_solution[0];

			for (int sell_day = 1; sell_day <= day_num; sell_day++)
			{
				// �����ڳ�������ʱ��
				// min_value = min(prices[sell_day - 1] - best_solution[tra_num - 1][sell_day - 1], min_value)
				// ֻ�漰��ǰһ�� tra_num - 1 ������������ݵķ��ʣ���˽��ռ��Ż�Ϊ day_num
				min_value = min(prices[sell_day - 1] - temp_profit, min_value);
				temp_profit = best_solution[sell_day];
				max_value = max(max_value, prices[sell_day - 1] - min_value);
				best_solution[sell_day] = max_value;
			}
		}
		return best_solution[day_num];
	}
};

int main() 
{
	int p[6] = {3,2,6,5,0,3};
	vector<int> prices(p, p + 6);
	Solution s;
	int profit = s.maxProfit(prices);

	cout << "The max profit is: " << profit << endl;
}