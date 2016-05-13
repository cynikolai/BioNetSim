#include "Network.h"
#include "P2random.h"
#include <iomanip>

int main()
{
    //Set parameters
	cout << std::setprecision(2);
	cout << std::fixed;
	int simsize;
	cin >> simsize;
	Inhibitor null_drug(simsize);
	int simseed;
	cin >> simseed;
	P2random::seed_mt(simseed);
	int simorganisms = 0;
	while(simorganisms < 100) // 100 random organisms
	{
		vector<Node> n_nodes;
		vector<vector<Link>> n_links;
		n_nodes.resize(simsize);
		n_links.resize(simsize);
		for(int i = 0; i < simsize; i++)
		{
			n_links[i].resize(simsize);
		}
		for(int i = 0; i < simsize; i++)
		{
			n_nodes[i].value = static_cast<double>(P2random::generate_tile(71) + 1);
		}
		for(int i = 0; i < simsize; i++)
		{
			for(int j = 0; j < simsize; j++)
			{
				n_links[i][j].first_deriv = P2random::generate_tile(71) + 1;
	 			n_links[i][j].second_deriv = P2random::generate_tile(71) + 1;
	 			n_links[i][j].third_deriv = P2random::generate_tile(71) + 1;
	 			n_links[i][j].fourth_deriv = P2random::generate_tile(71) + 1;		
	 			n_links[i][j].fifth_deriv = P2random::generate_tile(71) + 1;
			}
		}
		Network norganism(simsize,n_nodes,n_links);
		Network norganism_copy(simsize,n_nodes,n_links);
		norganism_copy = norganism;
		int simdrugs = 0;
		while (simdrugs < 100) // 100 random drugs
		{
			////////////////////////////////////////
			vector<vector<bool>> n_drugA;
			n_drugA.resize(simsize);
			for(int i = 0; i < simsize; i++)
			{
				n_drugA[i].resize(simsize);
			}
			for(int i = 0; i < simsize; i++)
			{
				for(int j = 0; j < simsize; j++)
				{
					int newnum = P2random::generate_tile(4);
					bool newbool = true;
					if (newnum % 5 == 0)
					{
						newbool = false;
					}
					n_drugA[i][j] = newbool;
				}
			}
			////////////////////////////////////////
			vector<vector<bool>> n_drugB;
			n_drugB.resize(simsize);
			for(int i = 0; i < simsize; i++)
			{
				n_drugB[i].resize(simsize);
			}
			for(int i = 0; i < simsize; i++)
			{
				for(int j = 0; j < simsize; j++)
				{
					int newnum = P2random::generate_tile(4);
					bool newbool = true;
					if (newnum % 5 == 0)
					{
						newbool = false;
					}
					n_drugB[i][j] = newbool;
				}
			}
			////////////////////////////////////////
			vector<vector<bool>> n_drugC;
			n_drugC.resize(simsize);
			for(int i = 0; i < simsize; i++)
			{
				n_drugC[i].resize(simsize);
			}
			for(int i = 0; i < simsize; i++)
			{
				for(int j = 0; j < simsize; j++)
				{
					int newnum = P2random::generate_tile(4);
					bool newbool = true;
					if (newnum % 5 == 0)
					{
						newbool = false;
					}
					n_drugC[i][j] = newbool;
				}
			}
            
			Inhibitor drug(simsize);
			Inhibitor drugA(simsize);
			drugA.data = n_drugA;
			Inhibitor drugB(simsize);
			drugB.data = n_drugB;
			Inhibitor drugC(simsize);
			drugC.data = n_drugC;
			Inhibitor drugAB(simsize); 
			drugAB = inhibitor_union(drugA,drugB);
			Inhibitor drugBC(simsize); 
			drugBC = inhibitor_union(drugB,drugC);
			Inhibitor drugCA(simsize); 
			drugCA = inhibitor_union(drugC,drugA);
			Inhibitor drugABC(simsize);
			drugABC = inhibitor_union(drugC,drugAB);
			simdrugs++;
			Network norganismA = norganism;
			Network norganismB = norganism;
			Network norganismC = norganism;
			Network norganismAB = norganism;
			Network norganismBC = norganism;
			Network norganismCA = norganism;
			Network norganismABC = norganism;
			double norganism1 = norganism.mass();
			norganism.Network_update(.01,drug);
			double norganism2 = norganism.mass();
			double norganismA1 = norganismA.mass();
			norganismA.Network_update(.01,drugA);
			double norganismA2 = norganismA.mass();
			double norganismB1 = norganismB.mass();
			norganismB.Network_update(.01,drugB);
			double norganismB2 = norganismB.mass();
			double norganismC1 = norganismC.mass();
			norganismC.Network_update(.01,drugC);
			double norganismC2 = norganismC.mass();
			double norganismAB1 = norganismAB.mass();
			norganismAB.Network_update(.01,drugAB);
			double norganismAB2 = norganismAB.mass();
			double norganismBC1 = norganismBC.mass();
			norganismBC.Network_update(.01,drugBC);
			double norganismBC2 = norganismBC.mass();
			double norganismCA1 = norganismCA.mass();
			norganismCA.Network_update(.01,drugCA);
			double norganismCA2 = norganismCA.mass();
			double norganismABC1 = norganismABC.mass();
			norganismABC.Network_update(.01,drugABC);
			double norganismABC2 = norganismABC.mass();
			///
			double g0 = norganism2 - norganism1;
			double gA = (norganismA1 - norganismA2)/g0;
			double gB = (norganismB1 - norganismB2)/g0;
			double gC = (norganismC1 - norganismC2)/g0;
			double gAB = (norganismAB1 - norganismAB2)/g0;
			double gBC = (norganismBC1 - norganismBC2)/g0;
			double gCA = (norganismCA1 - norganismCA2)/g0;
			double gABC = (norganismABC2 - norganismABC1)/g0;
			///
            // Actual
			double growth_rate_1 = gABC;
            // Second order estimate
			double growth_rate_2 = (gAB * gC) + (gBC * gA) + (gCA * gB) + (2 * gA * gB * gC);
            // First order estimate
			double growth_rate_3 = gA * gB * gC * -1;
			cout << growth_rate_1 << " " << growth_rate_2 << " " << growth_rate_3 << endl;
			norganism = norganism_copy;
		}
		simorganisms++;
	}
}