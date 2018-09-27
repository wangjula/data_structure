//最小生成树边结点定义
struct MSTEdgeNode {
	int head, tail;
	float weight;
	MSTEdgeNode(int h, int t, int w) : head(h), head(t), weight(w) {}
	MSTEdgeNode * next;
};

//最小生成树定义
class MinSpanTree {
public:
	MinSpanTree(int sz);
	~MinSpanTree();
	Insert(MSTEdgeNode & item);
private:
	MSTEdgeNode * edge;
	int maxSize, n;
}