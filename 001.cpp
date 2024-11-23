#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

template <class DataType>
struct BiNode
{
	BiNode(DataType data = DataType())
		:data_(data)
		,left_(nullptr)
		,right_(nullptr)
	{}
	DataType data_;
	BiNode<DataType>* left_;
	BiNode<DataType>* right_;
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
	char max_change()
	{
		return _max_change(root_);
	}
	void preOrder()
	{
		pre_Order(root_);
		cout << endl;
	}
private:
	BiNode<DataType>* root_;
	BiNode<DataType>* _pre_insert(vector<char> num, int n, int& k)
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
				BiNode<DataType>* tree = new BiNode<char>(num[k]);
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
	char _max_change(BiNode<DataType>* node)
	{
		if (node == nullptr)
		{
			return '\0';
		}

		char leftmax = _max_change(node->left_);
		char rightmax = _max_change(node->right_);

		char maxz = max(leftmax, rightmax);

		if (maxz - '0' > node->data_ - '0')
		{
			node->data_ = maxz;
		}
		return node->data_;
	}
	void pre_Order(BiNode<DataType>* node)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			cout << node->data_ << " ";
			pre_Order(node->left_);
			pre_Order(node->right_);
		}
	}
};

int main()
{
	string str;
	getline(cin, str);
	stringstream sstr(str);
	char tmp;
	vector<char> num;
	while (sstr >> tmp)
	{
		num.push_back(tmp);
	}
	int n = num.size();
	BiTree<char> bi;
	bi.pre_insert(num, n);
	char res;
	res=bi.max_change();
	bi.preOrder();

}