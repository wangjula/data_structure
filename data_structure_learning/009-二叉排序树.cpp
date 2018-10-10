//搜索
BTNode * BSTSearch(BTNode * bt, int key) {
	if (bt != NULL) {
		if (bt -> key == key) {
			return bt;
		} else if (key < bt -> key) {
			return BSTSearch(bt -> lchild, key);
		} else {
			return BSTSearch(bt -> rchild, key);
		}
	}
	return NULL;
}

//插入元素：即插入搜索失败的位置
bool BSTInsert(BTNode *& bt, int key) {
	if (bt == NULL) {                            //插入空树，即新建结点
		bt = new BTNode(key);
		return true;
	} else if (key == bt-> key) {                //搜索到该元素，无需插入
		return false;
	} else if (key < bt -> key) {
		return BSTInsert(bt -> lchild, key);
	} else {
		return BSTInsert(bt -> rchild, key);
	}
}

//删除结点：删除后需要维持二叉排序树的关系
//分三种结点处理：
//      1、叶子结点，将父结点指针清空，并删除该结点
//      2、若结点只有左子树，则使用左子树代替结点位置，并删除该结点；若结点只有右子树，使用右子树代替结点位置，并删除该的结点
//      3、若既有左子树又有右子树，则使用中序下右子树第一个元素交换该结点，交换后中序下右子树第一个结点按照步骤1，2递归处理
bool BSTRemove(BTNode *& bt, int key) {
	if (bt != NULL) {
		if (key == bt -> key) {                                    //找到目标结点开始删除
			if (bt -> lchild != NULL && bt -> rchild != NULL) {          //结点同时有左子女和右子女的情况，对应步骤3
				BTNode * p = bt -> rchild;
				while (p -> lchild != NULL) {
					p = p -> lchild;
				}
				bt -> key = p -> key;
				BSTRemove(p, key);
			} else {                                                     //结点左子女或右子女或左右子女都为空，对应步骤1，2
				p = bt;
				if (p -> lchild == NULL) {                               //引用类型，直接修改父结点指向目标结点的指针
					bt = bt -> rchild;
				} else {
					bt = bt -> lchild;
				}
				delete p;
				return true;
			}
		} else if (key < bt -> key) {                             //向左查找目标结点并处理
			return BSTRemove(bt -> lchild, key);
		} else {                                                  //向右查找目标结点并处理
			return BSTRemove(bt -> rchild, key);
		}
	}
	return false;
}