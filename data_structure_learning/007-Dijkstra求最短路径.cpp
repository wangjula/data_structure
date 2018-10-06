//非负权值单源最短路径算法
//打印最短路径
void printPath(int path[], int start) {
	int stack[maxSize];
	int top = -1;

	while (path[start] != -1) {               //反向路径入栈
		stack[++ top] = path[start];
		start = path[start];
	}
	stack[top ++] = start;                    //起点path[]值为-1，也需要加入栈

	while (top != -1) {                       //输出正向路径
		cout << stack[top --] << " ";
	}
	cout << endl;
}

void Dijkstra(LGraph & G, int v, int dist[], int path[]) {
	int n = G.NumberOfVertices();
	bool * S = new bool[n];
	int i, j, k, u, w, min;

	for (i = 0; i < n; ++ i) {                   //初始化S[], dist[], path[]
		dist[i] = G.getWeight(v, i);             //S[]表示已经找到最短路径的顶点集合
		S[i] = false;                            //dist[]表示对应顶点到v的最短距离
		if (i != v && dist[i] < maxValue) {      //path[]表示对应顶点最短路径的前一个顶点
			path[i] = v;
		} else {
			path[i] = -1;
		}
	}

	S[v] = true;                           //顶点v加入集合S
	dist[v] = 0;
	for (i = 0; i < n - 1; ++ i) {
		min = maxValue;
		u = v;
		for (j = 0; j < n; ++ j) {         //查找不在S中，具有最短路径的顶点u
			if (S[j] = false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;                       //将顶点u加入集合
		for (k = 0; k < n; ++ k) {         //更新路径，如果新加入顶点使路径缩短，则更新dist[]
			w = G.getWeight(u, k);
			if (S[k] == false && w < maxValue && dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}