//归并排序
//算法思想：采用分而治之的策略，先将序列划分成子序列，对每个子序列排序，最后合并成一个完全有序的序列
//归并排序是稳定的。平均、最好和最坏时间复杂度都是O(nlog2n)。merge需要辅助空间，空间复杂度为O(n)

//将R[low]-R[mid], R[mid+1]-R[high]两个子序列合并
void merge(int R[], int low, int mid, int high, int temp[]) {
	int i, j, t;
	i = low;
	j = mid + 1;
	t = 0;

	while (i <= mid && j <= high) {    //i, j为两个扫描指针，依次扫描，将较小的元素加入辅助数组
		if (R[i] <= R[j]) {
			temp[t ++] = R[i ++];
		} else {
			temp[t ++] = R[j ++];
		}
	}

	while (i <= mid) {                 //将剩余元素加入辅助数组
		temp[t ++] = R[i ++];
	}

	while (j <= high) {
		temp[t ++] = R[j ++];
	}

	i = low;
	t = 0;
	while (i <= high) {                //从辅助数组复制回R[]
		R[i ++] = temp[t ++]; 
	}
}

void MergeSort(int R[], int low, int high, int temp[]) {         //temp[]用于避免递归时反复分配内存
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(R, low, mid, temp);
        MergeSort(R, mid + 1, high, temp);
        merge(R, low, mid, high, temp);
    }
}