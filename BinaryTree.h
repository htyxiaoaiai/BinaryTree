# BinaryTree
#pragma once

#include<iostream>
#include<assert.h>
#include<queue>
#include<stack>

using namespace std;

//节点结构
template<class T>
struct BinaryTreeNode
{
	//构造函数 
	BinaryTreeNode(const T& data)
		:_data(data)
		,_leftChild(NULL)
		,_rightChild(NULL)
	{}
public:
	T _data;//数据域
	BinaryTreeNode* _leftChild;//左孩子指针
	BinaryTreeNode* _rightChild;//右孩子指针
};


//二叉树类
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}
	//构造函数
	BinaryTree(const T* a, size_t size, const T& invalid)
	{
		assert(a);
		size_t index = 0;
		_root = _CreateTree(a, size, invalid,index);
	}
	//拷贝构造
	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}
	//赋值运算符的重载
	BinaryTree<T>& operator=(BinaryTree<T> t)
	{
		swap(_root, t._root);
		return *this;
	}
	//析构函数
	~BinaryTree()
	{
		_Destory(_root);
	}

public:
	//前序遍历
	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}
	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	//后序遍历
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}
	//层次遍历
	void LevelOrder()
	{
		_LevelOrder(_root);
		cout << endl;
	}
	//求二叉树的节点个数
	size_t Size()
	{
		return _Size(_root);
	}
	//求二叉树的深度
	size_t Depth()
	{
		return _Depth(_root);
	}
	//求二叉树的叶子节点的个数
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}

	void PrevOrderNoRec();
	void InOrderNoRec();
	void PosOrderNoRec();
	Node* Find(const T& x)
	{
		return _Find(_root, x);
	}

	//求取第k层节点的个数
	//1、第k层节点的个数等于其左右子树第k-1层节点个数之和
	/*size_t GetKLevelSize(size_t k)
	{
		return _GetKSize(_root,k);
	}*/

	//2、遍历时求size
	size_t GetKLevelSize(size_t k)
	{
		size_t size = 0;//记录个数
		size_t level = 1;
		_GetKSize(_root, k, level, size);
		//size必须传引用，level不能传引用
		return size;
	}
protected:
	Node* _CreateTree(const T* a, size_t size, const T& invalid,  size_t&  index)
		//index要传引用，需要更改index的值
	{
		Node* root = NULL;
		//判断数组是否越界和输入的值是否合法
		if (index < size&&a[index] != invalid)
		{
			root = new Node(a[index]);//创建根节点
			root->_leftChild = _CreateTree(a, size, invalid, ++index);//递归创建左子树
			root->_rightChild = _CreateTree(a, size, invalid, ++index);//递归创建右子树
		}
		return root;//返回根节点
	}

	void _PrevOrder(Node* root)
	{
		//如果节点为空则直接返回
		if (root == NULL)
		{
			return;
		}

		cout << root->_data << " ";//访问根节点
		_PrevOrder(root->_leftChild);//递归访问左子树
		_PrevOrder(root->_rightChild);//递归访问右子树
	}

	void _InOrder(Node* root)
	{
		//如果节点为空则直接返回
		if (root == NULL)
		{
			return;
		}

		_InOrder(root->_leftChild);//访问左子树
		cout << root->_data << " ";//递归访问根节点
		_InOrder(root->_rightChild);//递归访问右子树
	}

	void _PostOrder(Node* root)
	{
		//如果节点为空则直接返回
		if (root == NULL)
		{
			return;
		}

		_PostOrder(root->_leftChild);//访问左子树
		_PostOrder(root->_rightChild);//递归访问右子树
		cout << root->_data << " ";//递归访问根节点
	}

	//层次遍历
	void _LevelOrder(Node* root)
	{
		if (root == NULL)
		{

			return;
		}
		queue<Node*> q;
		q.push(root);//根节点入队
		while (!q.empty())//当队列不为空
		{
			if (q.front()->_leftChild)
			{
				q.push(q.front()->_leftChild);
			}
			if (q.front()->_rightChild)
			{
				q.push(q.front()->_rightChild);
			}
			cout << q.front()->_data << " ";
			q.pop();
		}
	}

	//size_t _Size(Node* root)
	//{
	//	size_t count = 0;
	//	if (root == NULL)
	//	{
	//		return count;//树为空
	//	}

	//	count++;//根节点
	//	count += _Size(root->_leftChild);//计算左子树大小
	//	count += _Size(root->_rightChild);//计算右子树大小
	//	return count;
	//}


	size_t _Size(Node* root)
	{
		if (root == NULL)
		{
			return 0;//树为空
		}

		return _Size(root->_leftChild) + _Size(root->_rightChild) + 1;
	}

	//返回左右子树深度较大的
	size_t _Depth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		size_t LeftDepth = _Depth(root->_leftChild);
		size_t RightDepth= _Depth(root->_rightChild);
		if (LeftDepth > RightDepth)
		{
			return ++LeftDepth;
		}
		else
		{
			return ++RightDepth;
		}
	}

	size_t _LeafSize(Node*root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->_leftChild == NULL && root->_rightChild == NULL)
		{
			return 1;
		}

		return _LeafSize(root->_leftChild)+ _LeafSize(root->_rightChild);
	}

	Node* _Copy(Node* root)
	{
		
		if (root == NULL)
		{

			return NULL;
		}

		Node* newRoot = new Node(root->_data);
		newRoot->_leftChild = _Copy(root->_leftChild);
		newRoot->_rightChild = _Copy(root->_rightChild);
		return newRoot;
	}

	void _Destory(Node* root)
	{
		if (root == NULL)
		{
			return;
		}

		//删除叶结点
		if (root->_leftChild == NULL&&root->_rightChild == NULL)
		{
			delete root;
			root = NULL;
			return;
		}

		_Destory(root->_leftChild);//递归删除左子树
		_Destory(root->_rightChild);//递归删除右子树
		delete root;
	}

	//查找数据
	Node* _Find(Node*root, const T&x)
	{
		if (root == NULL)
		{
			return NULL;
		}

		//查找根节点
		if (root->_data == x)
		{
			return root;
		}

		//查找左子树
		Node* ret = _Find(root->_leftChild, x);
		if (ret)
		{
			return ret;
		}

		//查找右子树
		return _Find(root->_rightChild, x);
	}

	//查找第K层的节点个数
	//方法1
	size_t _GetKSize(Node*root, size_t k)
	{
		if (root == NULL)
		{
			return 0;
		}

		if (k == 1)
		{
			return 1;
		}

		return _GetKSize(root->_leftChild, k - 1) + _GetKSize(root->_rightChild, k - 1);
	}
	
	//方法2遍历时求size
	void _GetKSize(Node*root, size_t k, size_t level, size_t &size)
	{
		if (root == NULL)
		{
			return;
		}
		
		if (level == k)
		{
			++size;
			return;
		}

		_GetKSize(root->_leftChild, k, level + 1, size);
		_GetKSize(root->_rightChild, k, level + 1, size);
	}
private:
	BinaryTreeNode<T>* _root;//根节点
};

template<class T>
void BinaryTree<T>:: PrevOrderNoRec()
{
	if (_root == NULL)
	{
		return;
	}
	stack<Node*> s;
	s.push(_root);

	while (!s.empty())
	{
		Node* top = s.top();//获取栈顶
		cout << top->_data << " ";
		s.pop();

		//右孩子入栈
		if (top->_rightChild)
		{
			s.push(top->_rightChild);
		}
		
		//左孩子入栈
		if (top->_leftChild)
		{
			s.push(top->_leftChild);
		}
	}
	cout << endl;
}


template<class T>
void BinaryTree<T>::InOrderNoRec()
{
	if (_root == NULL)
	{
		return;
	}
	Node* cur = _root;
	stack<Node*> s;
	while (cur||!s.empty())//如果栈为空并且cur==NULL跳出循环
	{
		//找到最左下方的节点访问
		while (cur)
		{
			s.push(cur);
			cur = cur->_leftChild;
		}
		
		Node* top = s.top();
		cout << top->_data << " ";
		s.pop();

		//如果右子树不为空则按照中序遍历，重新找到最最下角的继续访问
		if (top->_rightChild)
		{
			cur = top->_rightChild;
		}

		//如果右子树为空，则cur==NULL,不会再次进入循环，直接出栈访问
	}
	cout << endl;
}


template<class T>
void BinaryTree<T>::PosOrderNoRec()
{
	if (_root == NULL)
	{
		return;
	}

	Node* cur = _root;//当前指针
	Node* prev = NULL;//栈内的前驱指针
	stack<Node*> s;
	while (cur || !s.empty())
	{
		//找到最左下角节点
		while (cur)
		{
			s.push(cur);
			cur = cur->_leftChild;
		}

		Node* top = s.top();
		
		//如果右子树为空，或者之前访问过则输出
		if (top->_rightChild == NULL || prev == top->_rightChild)
		{
			cout << top->_data << " ";
			prev = top;//出栈之前更新prev
			s.pop();
		}
		else
		{
			cur = top->_rightChild;
		}
	}
	cout << endl;
}
