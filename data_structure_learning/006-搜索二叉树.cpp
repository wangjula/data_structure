//遍历所有结点，找到符合key值的结点，直接将该结点地址赋值个p，否则继续遍历子树
//注意修改的p为同一个，所以应该使用引用型BTNode *& p
void search(BTNode * root, BTNode *& p, char key) {
	if (root != NULL) {
		if (root -> data == key) {
			p = root;
		} else {
			search(root -> lchild, p, key);
			if (p == NULL) {                             //"剪枝"，若左子树没有搜索到，才去搜索右子树
				search(root -> rchild, p, key);
			}
		}
	}
}