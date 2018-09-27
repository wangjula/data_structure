
void Floyd(LGraph & G, int a[][], int path[][]) {
	int n = G.NumberOfVertices();
	int i, j, k;

	for (i = 0; i < n; ++ i) {                       //初始化a[][], path[][]
		for (j = 0; j < n; ++ j) {                   //a[i][j]表示顶点i与顶点j之间最短路径长度
			a[i][j] = G.getWeight(i, j);             //path[i][j]表示顶点j的前一顶点号
			if (i != j && a[i][j] < maxValue) {
				path[i][j] = i;
			} else {
				path[i][j] = -1;
			}
		}
	}

	for (k = 0; k < n; ++ k) {
		for (i = 0; i < n; ++ i) {
			for (j = 0; j < n; ++ j) {
				if (a[i][k] + a[k][j] < a[i][j]) {  //若顶点i经过k到j能缩短路径，则更新a[i][j]和path[i][j]
					a[i][j] = a[i][k] + a[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

void printPath(int u, int v, int path[][]) {
	if (path[u][v] == -1) {
		cout << path[u][v] << " ";
	} else {
		int mid = path[u][v];
		printPath(u, mid, path);                   //处理mid的前半段路径
		printPath(mid, v, path);                   //处理mid的后半段路径
	}
}