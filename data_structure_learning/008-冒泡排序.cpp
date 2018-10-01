//冒泡排序
//算法思想：比较第n-1和第n-2个元素，发生逆序则交换，再比较第n-2, 第n-3个元素。。。至第0个元素完成一趟冒泡。
//         一轮排序后，最小元素在第0个位置，其他元素靠近最终排序的位置。n-1轮可以使序列全部有序
//时间复杂度：最好情况O(n)，最差和平均O(n2)
void BubbleSort(int R[], int n) {
	int i, j, temp;
	bool exchange;                             //若为false，标志一轮比较无逆序，无需继续排序
	for (i = 1; i < n; ++ i) {
		exchange = false;
		for (j = n - 1; j >= i; -- j) {
			if (R[j] < R[j - 1]) {
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				exchange = true;
			}
		}
		if (exchange == false) {
			return;
		}
	}
}