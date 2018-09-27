struct VertexType {
	int no;
	char info;
};

class MGraph {
public:
	MGraph();
	~MGraph();
private:
	int n, e;
	int edges[maxSize][maxSize];
	VertexType vexs[maxSize];
};