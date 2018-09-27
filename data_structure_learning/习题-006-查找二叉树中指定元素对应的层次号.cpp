//算法1：可以使用层次遍历解决，在二叉树结点中添加lno作为层次号，遍历的同时设置子女的层次号，若匹配元素，则输出结点层次号即可

//算法2：使用一个全局变量L作为层次号，先序遍历二叉树，转向子女时L—-，返回上一层时L++，当结点匹配时，L即为层次号

int L = 1;
void leno(BTNode * root, char key) {
	if (root != NULL) {
		if (root -> data == key) {
			cout << L << endl;
		}

		-- L;                 //转向处理子树，层次号减1
		leno(root -> lchild, key);
		leno(root -> rchild, key);
		++ L;
	} 
}