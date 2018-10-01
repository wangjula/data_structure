//折半插入排序
//算法思想：同直接插入排序，区别查找插入位置时，使用折半查找
//时间复杂度：最好O(nlog2(n))，平均和最差是O(n2)
void HalfInsertSort(int R[], int n) {
    int i, j, l, h, mid;
    int temp;
    mid = 0;
    for (i = 1; i < n; ++ i) {
        temp = R[i];
        l = 0;
        h = i - 1;
        
        while (l <= h) {                     //折半查找插入点
            mid = (l + h) / 2;
            if (temp < R[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        for (j = i - 1; j > h; -- j) {      //插入点（h + i）及以后的元素后移
            R[j + 1] = R[j];
        }
        R[h + 1] = temp;                    //插入R[i]
    }
}