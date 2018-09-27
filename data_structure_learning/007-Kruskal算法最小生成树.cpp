//图使用邻接表表示
//使用最小堆，并查集
void Kruskal(LGraph & G, MinSpanTree & mst) {
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();
	MinHeap heap(m);
	UFSets F(n);

	int u, v, count;
	MSTEdgeNode ed;
	for (u = 0; u < n; ++ u) {
		for (v = u + 1; v < n; ++ v) {
			if (G.getWeight(u, v) < maxValue) {
				ed.head = v;
				ed.tail = u;
				ed.weight = G.getWeight(u, v);
				heap.Insert(ed);
			}
		}
	}

	count = 0;                 //加入边计数
	while (count < n - 1) {
		heap.RemoveMin(ed);
		u = F.Find(ed.tail);   //取边两端顶点的根结点
		v = F.Find(ed.head);
		if (u != v) {          //两个端结点的根结点不同，说明不再同一棵树中，则加入MST，并合并到同一棵树下
			F.Union(u, v);
			mst.Insert(ed);    //如果要计算权值，直接在此处累加权值即可
			++ count;
		}
	}
}