# include<iostream>
# include<vector>
# include "file.h"


using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void output(TreeNode * head) {
	vector<TreeNode *> node_vector;
	vector<TreeNode *>::iterator node_iter;
	node_vector.push_back(head);
	node_iter = node_vector.begin();

	while (node_iter != node_vector.end()) 
	{
		if ((*node_iter) == NULL) 
		{
			cout << "NULL ";
			node_iter = node_vector.erase(node_iter);
			continue;
		}
			
		cout << (*node_iter)->val << " ";
		
		if ((*node_iter)->left != NULL or (*node_iter)->right != NULL )
		{
			node_vector.push_back((*node_iter)->left);
			node_iter = node_vector.begin();
			node_vector.push_back((*node_iter)->right);
			node_iter = node_vector.begin();
		}
			
		node_iter = node_vector.erase(node_iter);
	}
	cout << endl;
}

TreeNode * copy_tree(TreeNode * root) 
{
	if (root == NULL) {
		return NULL;
	}

	TreeNode * left_tree = copy_tree(root->left);
	TreeNode * right_tree = copy_tree(root->right);
	TreeNode * new_root = new TreeNode(root->val);
	new_root->left = left_tree;
	new_root->right = right_tree;
	return new_root;
}

class Solution {
public:
	vector<TreeNode *> generateTrees(int n) 
	{
		vector<TreeNode *> result;

		for (int i = 1; i < n + 1; i++) 
		{
			if (result.empty())
			{
				 TreeNode * temp_node = new TreeNode(i);
				 result.push_back(temp_node);
			}
			else
			{
				
				int size = result.size();
				for (int j = 0; j < size; j++)
				{
					vector<TreeNode *>::iterator node_iter = result.begin();
					TreeNode * temp_old_node = * node_iter;
					TreeNode * old_head = temp_old_node;
					node_iter = result.erase(node_iter);
					TreeNode * temp_new_node = new TreeNode(i);
					temp_new_node->left = temp_old_node;
					result.push_back(copy_tree(temp_new_node));
					temp_new_node->left = NULL;
					while (temp_old_node->right != NULL) 
					{
						temp_new_node->left = temp_old_node->right;
						temp_old_node->right = temp_new_node;
						result.push_back(copy_tree(old_head));
						temp_old_node->right = temp_new_node->left;
						temp_new_node->left = NULL;
						temp_old_node = temp_old_node->right;
					}
					temp_old_node->right = temp_new_node;
					result.push_back(old_head);
				}
			}
		}



		return result;
	}
};

int main()
{
	vector <TreeNode* > result;
	Solution s;
	result = s.generateTrees(3);
	for (TreeNode * node : result)
		output(node);
}