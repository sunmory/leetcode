# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		/**
		原问题在 total_tra_num 次交易中获取最大利润的子问题为在 total_tra_num - 1 词操作中获取最大利润
		构建二维矩阵行表示交易的次数，列表示股票的天数，则得到如下递归公式：
		best_solution[tra_num][sell_day] = max(prices[sell_day - 1] - prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1]);
		buy_day 在 [1, sell_day] 遍历
		表示第 tra_num 次交易在第 sell_day 天卖出时，讨论该股票是在第几天购入的才会有最大利润
		best_solution[tra_num - 1][buy_day - 1] 是子问题，表示在余下的 buy_day - 1 中进行 tra_num - 1 次交易所获取的最大利润
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
		@ brief 时间优化
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
				// 发现在同一 tra_num 下对 buy_day 循环时， prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1] 是重复计算的
				// 所以将这一部分提出单独计算以消除对 buy_day 的循环，即将
				//for (int buy_day = 1; buy_day <= sell_day; buy_day++)
				//{
				//	max_value = max(max_value, prices[sell_day - 1] - prices[buy_day - 1] + best_solution[tra_num - 1][buy_day - 1]);
				//}
				// 变为先找重复部分的最小值，此时时间优化为 total_tra_num * day_num：
				min_value = min(prices[sell_day - 1] - best_solution[tra_num - 1][sell_day - 1], min_value);
				max_value = max(max_value, prices[sell_day - 1] - min_value);
				best_solution[tra_num][sell_day] = max_value;
			}
		}
		return best_solution[total_tra_num][day_num];
	}

	int maxProfit3(vector<int>& prices) {
		/**
		@ brief 空间优化
		*/
		int total_tra_num = 2;
		int day_num = prices.size();
		vector<int> best_solution(day_num + 1, 0);
		// 声明临时存储变量 temp_profit
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
				// 发现在程序运行时：
				// min_value = min(prices[sell_day - 1] - best_solution[tra_num - 1][sell_day - 1], min_value)
				// 只涉及其前一列 tra_num - 1 的最高利润数据的访问，因此将空间优化为 day_num
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