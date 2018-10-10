//折半查找；假设已经序列已经有序
//使用判定树分别计算查找成功和查找失败的平均查找长度ASL
int BiSearch(int R[], int low, int high, int key) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == R[mid]) {
			return mid;
		} else if (key > R[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}