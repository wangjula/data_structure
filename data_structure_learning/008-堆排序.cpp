//堆排序
//算法思想：堆是完全二叉树，通过插入元素时调整次序，形成最大堆或最小堆，最大堆父亲大，子女小。关键操作是用shiftDown，shiftUp调整堆。
//        堆排序的思想是先建立最大堆。最大堆中，交换堆顶和最后一个编号的元素，在新的堆局部调整重新形成最大堆。经过n-1轮交换删除并调整后
//        排序完成
//时间复杂度：O(nlog2n)
//不稳定
sturct Element {
	int key;
	char info;
};

class MaxHeap {
public:
	MaxHeap();
	~MaxHeap();
private:
	Element * heap;
	int size;
	int maxSize;
	void siftDown(int start, int m);        //从start到m自顶向下调整
	void siftUp(int start);                 //自底向上调整
};

//简化版，不实际构造堆，只使用堆的思想
//一次向下调整，左右子女最大元素浮到堆顶，原堆顶元素下降到最低
void siftDown(int R[], int low, int high) {
    int i = low;
    int j = 2 * i + 1;                      //j为i的左子女
    int temp = R[i];
    while (j <= high) {
        if (j < high && R[j] < R[j + 1]) {  //j指向i的左右子女中的较大子女
            ++ j;
        }
        if (temp < R[j]) {
            R[i] = R[j];
            i = j;                          //继续向下调整
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    R[i] = temp;
}

void HeapSort(int R[], int n) {
    int i;
    int temp;
    for (i = (n - 2) / 2; i >= 0; -- i) {   //建立初始最大堆，从一半元素处自底向上依次调用siftDown()调整
        siftDown(R, i, n - 1);
    }
    for (i = n - 1; i >= 0; -- i) {         //此时R[0]为最大元素，和最后一个元素交换，继续调整R[0]-R[n-2]形成的新堆
        temp = R[0];                        //经n-1轮调整，使R[]完全有序
        R[0] = R[i];
        R[i] = temp;
        siftDown(R, 0, i - 1);
    }
}