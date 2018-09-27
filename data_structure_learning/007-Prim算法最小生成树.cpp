//图使用邻接表表示，Prim算法(也可用邻接矩阵表示，只要改变图内部函数的实现就行)
//用到最小堆，见最小堆实现
void Prim(LGraph & G, char v0, MinSpanTree & mst) {
	int i, v, weight, count;
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();
	int u = G.getVertexPos(v0);
	MinHeap heap(m);
	MSTEdgeNode ed;

	bool * vmst = new bool[n];                          //最小生成树顶点集合
	for (i = 0; i < n; ++ i) {
		vmst[i] = false;
	}

	vmst[u] = true;                        //顶点u加入mst
	count = 1;                             //mst中顶点数

	do {
		v = G.getFirstNeighbor(u);
		while (v != -1) {
			if (vmst[v] == false) {
				ed.head = u;
				ed.tail = v;
				ed.weight = G.getWeight(u, v);
				heap.Insert(ed);
			}
			v = G.getNextNeighbor(u, v);
		}

		while (!heap.IsEmpty() && count < n) {
			heap.RemoveMin(ed);
			if (vmst[ed.head] == false) {
				mst.Insert(ed);
				u = head;
				vmst[u] = true;
				++ count;
				break;
			}
		}
	} while (count < n);
	delete [] vmst;
}

//图使用邻接矩阵表示，Prim算法(用于上机)
void Prim(MGraph & G, int v0, int & sum) {
	const int INF = INT_MAX;
	int n = G.NumberOfEdges();
	int * lowcost = new int[n]; 
	bool * vmst = new bool[n];
	int ** edges = G.getEdges();

	int v, i, j, k, min;
	for (i = 0; i < n; ++ i) {                  //lowcost[]存储到其他顶点到
		lowcost[i] = edges[v0][i];
		vmst[i] = false;
	}

	sum = 0;
	k = 0;
	vmst[v0] = true;
	for (i = 0; i < n; ++ i) {
		min = INF;
		for (j = 0; j < n; ++ j) {               //找出最短邻边
			if (vmst[j] == false && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		vmst[k] = true;                         //最短邻边的另一个顶点加入顶点集合
		v = k;
		sum += min;
		for (j = 0; j < n; ++ j) {              //更新剩余顶点的lowcost[j]，即上个顶点的邻边，如果新加入的结点使路径更短，则更新
			if (vmst[j] == false && edges[v][j] < lowcost[j]) {
				lowcost[j] = edges[v][j];
			}
		}
	}
	delete [] vmst;
}