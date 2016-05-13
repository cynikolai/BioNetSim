#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


// Very basic node structure. A node is seen as a single real value measuring some quantity in an organism (e.g. the amount of some chemical in some location)
struct Node
{
	double value;
	Node()
	{
		value = 0;
	}
	Node(double nvalue)
	{
		value = nvalue;
	}
	void update_node(double nupdate)
	{
		value += nupdate;
	}
};



