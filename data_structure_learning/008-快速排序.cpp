//快速排序
//算法思想；每趟选择一个元素，作为划分的枢轴，使小于枢轴的元素全在左侧，大于枢轴的元素排列在右侧。		
//		   选择不同的枢轴重复多次使序列全部有序
//时间复杂度：乱序时最好O(nlog2n)，有序时最差O(n2)，平均O(nlog2n)
void QuickSort(int R[], int low, int high) {
	int i, j;
	int temp;
	if (low < high) {
		i = low;                                 //i, j为两个扫描指针，i之前的元素全部小于枢轴，j之后的元素全部大于枢轴
		j = high;                                //i，j初始时指向两端，向中间扫描，相遇时扫描结束，一趟子序列排序完成
		temp = R[low];                           //每趟排序，选择R[low]作为枢轴
		while (i < j) {
			while (j > i && R[j] >= temp) {
				-- j;
			}
			if (i < j) {
				R[i] = R[j];
				++ i;
			}

			while (i < j && R[i] < temp) {
				++ i;
			}
			if (i < j) {
				R[j] = R[i];
				-- j;
			}
		}
		R[i] = temp;
		QuickSort(R, low, i - 1);
		QuickSort(R, i + 1, high);
	}
}
