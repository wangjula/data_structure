//普通结点
struct OLNode {
	int row, col;                  //行号，列号
	OLNode * right, * down;        //右指针，下指针
	float val;                     //数据
};

//头结点
struct HeadNode {
	int m, n, k;                   //行数，列数，非零结点个数
	OLNode * rhead, * chead;         //每行的头结点，每列的头结点
};

//十字链表：申请两个数组，分别存储所有行头结点，列头结点。头结点rhead指向行头结点，chead指向列头结点
