#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
#include <sstream>
using namespace std;

template <class DataType>
struct BiNode
{
	BiNode(DataType data=DataType())
		:data_(data)
		,left_(nullptr)
		,right_(nullptr)
	{}
	DataType data_;
	BiNode* left_;
	BiNode* right_;
};

template <class DataType>
class BiTree
{
public:
	BiTree()
		:root_(nullptr)
	{}
	~BiTree(){}
	void pre_insert(vector<char> num, int n)
	{
		int k = -1;
		root_ = _pre_insert(num, n, k);
	}
	void countNode()
	{
		int degree2 = 0;
		count_Node(root_, degree2);
		cout << degree2 << endl;
	}
private:
	BiNode <DataType>* root_;
	BiNode<DataType>* _pre_insert(vector<char> num, int n,int& k)
	{
		k++;
		if (k >= n)
		{
			return nullptr;
		}
		else
		{
			if (num[k] != '#')
			{
				BiNode<DataType>* tree = new BiNode<int>(num[k]-'0');
				tree->left_ = _pre_insert(num, n, k);
				tree->right_ = _pre_insert(num, n, k);
				return tree;
			}
			else
			{
				return nullptr;
			}
		}
	}
	void count_Node(BiNode<DataType>*node, int& degree2)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			int degree = (node->left_ != nullptr) + (node->right_ != nullptr);
			if (degree == 2)
			{
				degree2++;
			}
		}
		count_Node(node->left_, degree2);
		count_Node(node->right_,degree2);
	}
};

int main()
{
	string str;
	getline(cin, str);
	vector<char> num;
	for (char c : str)
	{
		num.push_back(c);
	}
	BiTree<int> bi;
	int n = num.size();
	bi.pre_insert(num, n);
	bi.countNode();
}
