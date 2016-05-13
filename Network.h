#include "Link.h"

//An inhibitor is a structure that acts on an organism to modify it's growth rate. When an element of the inhibitor matrix data is set to true, the value of that link function is maintained, while if it is set to false it is instead changed to the zero function. This encapsulates the mechanism by which real biological inhibitors work.

struct Inhibitor
{
	int size;
	vector<vector<bool>> data;
    
    //Constructor for an initial null inhibitor
	Inhibitor(int nsize)
	{
		size = nsize;
		data.resize(nsize);
		for(int i = 0; i < nsize; i++)
		{
			data[i].resize(nsize);
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				data[i][j] = true;
			}
		}
	}
};

//Returns an inhibitor with the combined effects of two inhibitors.
Inhibitor inhibitor_union(Inhibitor a, Inhibitor b)
{
	Inhibitor c(a.size);
	for (int i = 0; i < a.size; i++)
	{
		for (int j = 0; j < a.size; j++)
		{
			if (a.data[i][j] == true && b.data[i][j] == true)
			{
				c.data[i][j] = true;
			}
			else
			{
				c.data[i][j] = false;
			}
		}
	}
	return c;
}

// Simulates an abstract organism, consisting of nodes and links.
struct Network
{
	int size;
	vector<Node> nodes;
	vector<vector<Link>> links;
	vector<Node> organism;
	double mtime;

    // Generates nodes and links of organism.
	Network(int nsize, vector<Node> norganism, vector<vector<Link>> nlinks)
	{
		size = nsize;
		nodes = norganism;
		organism = norganism;
		links = nlinks;
		mtime = 0; 
	}
    
	void Network_update(double dt, Inhibitor drug)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (drug.data[i][j])
				{
					double update_amount = dt * links[i][j].linkderiv(nodes[j].value);
					nodes[i].update_node(update_amount);
				}
			}
		}
		this->Homeostasis();
	}

	double mass()
	{
		double mas = 0;
		for (int i = 0; i < size; i++)
		{
			mas += nodes[i].value;
		}
		return mas;
	}
    
    //Hypothesised homeostatic processes, which modify the way the link functions are expected to behave for the growth of the organism to be stable. This was in later models discarded as an unnecessary assumption.
	void Homeostasis()
	{
		double ratio = (nodes[0].value)/(organism[0].value);
		for(int i = 0; i < size; i++)
		{
			double nratio = (nodes[i].value)/(organism[i].value);
			if (ratio > nratio)
			{
				ratio = nratio;
			}
		}
		for (int i = 0; i < size; i++)
		{
			nodes[i].value = organism[i].value * ratio;
		}
	}

};


