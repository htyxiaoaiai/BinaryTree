# BinaryTree
#include"BinaryTree.h"

void TestBinary()
{
	//int a1[10] = { 1,2,3,'#','#',4,'#','#',5,6 };
	//BinaryTree<int> t1(a1, 10, '#');
	//cout << "先序遍历：";
	////t1.PrevOrder();
	//t1.PrevOrderNoRec();
	//cout << "中序遍历：";
	//t1.InOrder();
	//t1.InOrderNoRec();
	//cout << "后序遍历：";
	//t1.PostOrder();
	//t1.PosOrderNoRec();
	//cout << "层次遍历：";
	//t1.LevelOrder();
	//cout << "size:" << t1.Size() << endl;
	//cout << "depth:" << t1.Depth() << endl;
	//cout << "leafSize:" << t1.LeafSize() << endl;

	//int a2[15] = { 1,2,'#',3,'#','#',4,5,'#',6 ,'#' ,7,'#' ,'#' ,8 };
	int a1[10] = { 1,2,3,'#','#',4,'#','#',5,6 };
	//int a[] = { 1,2,'#','#',3 };
	//BinaryTree<int> t(a2, 15, '#');
	BinaryTree<int> t(a1, 10, '#');
	BinaryTree<int> t2;
	t2 = t;
	cout << "先序遍历："; 
	t2.PrevOrderNoRec();
	//t2.PrevOrder();
	cout << "中序遍历：";
	t2.InOrder();
	t2.InOrderNoRec();
	cout << "后序遍历：";
	t2.PostOrder();
	t2.PosOrderNoRec();
	cout << "层次遍历：";
	t2.LevelOrder();
	cout << "size:" << t2.Size() << endl;
	cout << "depth:" << t2.Depth() << endl;
	cout << "leafSize:" << t2.LeafSize() << endl;
	cout << "查找1:" << t2.Find(1) << endl;
	cout << "查找10：" << t2.Find(10) << endl;
	cout << "Level 1:" << t2.GetKLevelSize(1) << endl;
	cout << "Level 2:" << t2.GetKLevelSize(2) << endl;
	cout << "Level 3:" << t2.GetKLevelSize(3) << endl;
	cout << "Level 4:" << t2.GetKLevelSize(4) << endl;
	cout << "Level 5:" << t2.GetKLevelSize(5) << endl;
	cout << "Level 6:" << t2.GetKLevelSize(6) << endl;
}
int main()
{
	TestBinary();
	getchar();
	return 0;
}
