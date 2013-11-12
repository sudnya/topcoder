// SRM 144 DIV2 1100 points
#include <set>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>


class Edge
{
	public:
		Edge(int f, int t, int cost) : from(f), to(t), cost(cost)
		{
		}
	public:
		int from, to, cost;
};

class Node;

typedef std::vector<Node*> NodeList;

class Node
{
	public:
		Node(int i)
		: parent(nullptr), id(i), costFromParent(0), costFromRoot(0)
		{
		
		}

	public:
		Node* parent;
		int id;
		NodeList children;

	public:
		int costFromParent;
		int costFromRoot;

};

static void computeDistanceFromRoot(Node* node)
{
	int currentCost = node->costFromParent;

	if(node->parent != nullptr)
	{
		currentCost += node->parent->costFromRoot;
	}

	node->costFromRoot = currentCost;

	for(auto child : node->children)
	{
		computeDistanceFromRoot(child);
	}
}

static int findMaxPath(Node* node)
{
	int maxSoFar = node->costFromRoot;

	for(auto child : node->children)
	{
		maxSoFar = std::max(maxSoFar, findMaxPath(child));
	}

	return maxSoFar;
}

class Tree
{
	public:
		void addEdge(Edge e)
		{
			auto head = getOrAddNode(e.from);
			auto tail = getOrAddNode(e.to);

			assert(tail->parent == nullptr);
			tail->parent = head;
			head->children.push_back(tail);

			tail->costFromParent = e.cost;
		}

		Node* getOrAddNode(int id)
		{
			auto node = nodes.find(id);

			if(node == nodes.end())
			{
				node = nodes.insert(std::make_pair(id, Node(id))).first;
			}

			return &node->second;
		}

		void computeDistanceFromRoot()
		{
			::computeDistanceFromRoot(root);
		}

		int findMaxPath()
		{
			return ::findMaxPath(root);
		}

	public:
		std::map<int, Node> nodes;
		Node* root;
};
class PowerOutage
{
	public:
int estimateTimeOut(const std::vector<int>& from, const std::vector<int>& to, const std::vector<int>& ducts)
{
	//will need distance worth all ducts
	int path = 0;
	for (auto& i : ducts)
		path += i;

	//create a tree
	std::vector<Edge> allEdges;
	//all edges
	for (auto i = from.begin(), j = to.begin(), k = ducts.begin(); i != from.end(); ++i, ++j, ++k)
	{
		Edge e(*i, *j, *k);
		allEdges.push_back(e);
	}

	Tree t;
	for (auto& e : allEdges)
	{
		t.addEdge(e);
	}

	t.root = t.getOrAddNode(0);

	t.computeDistanceFromRoot();

	int maxPathSoFar = t.findMaxPath();
	//find all leaf nodes - leafIdx, leafId
	//take all paths except farthest path twice
	//farthest path taken only once
	return (2*path) - maxPathSoFar;
}

};

int main()
{
	PowerOutage po;
	std::vector<int> from;
	std::vector<int> to;
	std::vector<int> ductL;

	from.push_back(0);
	from.push_back(0);
	from.push_back(0);
	from.push_back(1);
	from.push_back(4);
	from.push_back(4);
	from.push_back(6);
	from.push_back(7);
	from.push_back(7);
	from.push_back(7);
	from.push_back(20);

	to.push_back(1);
	to.push_back(3);
	to.push_back(4);
	to.push_back(2);
	to.push_back(5);
	to.push_back(6);
	to.push_back(7);
	to.push_back(20);
	to.push_back(9);
	to.push_back(10);
	to.push_back(31);


	ductL.push_back(10);
	ductL.push_back(10);
	ductL.push_back(100);
	ductL.push_back(10);
	ductL.push_back(5);
	ductL.push_back(1);
	ductL.push_back(1);
	ductL.push_back(100);
	ductL.push_back(1);
	ductL.push_back(1);
	ductL.push_back(5);
	int outageTime = po.estimateTimeOut(from, to, ductL);
	std::cout << "Timeout for : " << outageTime << "\n";
	return 0;
}
