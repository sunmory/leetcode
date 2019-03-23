# include<iostream>
# include<vector>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode operator=(TreeNode & temp_node) 
	{
		cout << "copy" << endl;
		val = temp_node.val;
		return *this;
	}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) 
	{
		vector<TreeNode*> result;

		for (int i = 1; i < n + 1; i++) 
		{
			if (result.empty())
			{
				TreeNode temp_node(i);
				result.push_back(&temp_node);
			}
			else
			{
				TreeNode temp_node(i);
				result.push_back(&temp_node);
			}
		}

		for (TreeNode * temp_node : result)
			cout << "result: " << temp_node->val << endl;

		return result;
	}
};

int main()
{
	vector <TreeNode *> result;
	Solution s;
	result = s.generateTrees(5);

	for (TreeNode * temp_node : result)
		cout << "result: " << temp_node->val << endl;
}