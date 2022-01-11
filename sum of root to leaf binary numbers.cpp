#include<iostream> 
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class solution {
public:
	vector<int> v;
	int sum = 0;
	int sumRootToLeaf(TreeNode* root) {
		if (root == nullptr) {
			v.push_back(0);
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr) {
			v.push_back(root->val);
			sum += binaryToDecimal(v);
			return sum;
		}
		v.push_back(root->val);
		int i = sumRootToLeaf(root->left);
		v.pop_back();
		int j = sumRootToLeaf(root->right);
		v.pop_back();
		return sum; 
	}

	int binaryToDecimal(vector<int>& v) {
		int num = 0;
		int l = v.size();
		for (int i = 0; i < l; i++) {
			int temp = pow(2, l - 1 - i);
			num = num + temp * v[i];
		}
		return num;
	}
};

int main() {
	struct TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(0);
	root->right = new TreeNode(0);
	/*root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(1);*/
	solution obj;
	cout << obj.sumRootToLeaf(root) << endl;
	return 0;
}