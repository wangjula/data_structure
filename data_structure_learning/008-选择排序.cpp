//选择排序
//算法思想：第一趟查找最小元素和第一个元素交换，第二趟查找次小的元素与第二个元素交换。。。至所有元素交换完成，序列有序
//时间复杂度：O(n2)
void SelectSort(int R[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n; ++ i) {
		k = i;
		for (j = i + 1; j < n; ++ j) {
			if (R[k] > R[j]) {
				k = j;
			}
		}

		if (k != i) {
			temp = R[0];
			R[i] = R[k];
			R[k] = temp;
		}
	}
}