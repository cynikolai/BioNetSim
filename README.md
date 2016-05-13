# BioNetSim
A biological network simulator I created for a research project in 2014.

This project creates an object oriented simulator for the time evolution of a hypothesized model of biological organisms.
It describes essentially a markov growth process of quantities describing the network called nodes. The functions defining this growth are called links.

It was previously observed that inhibitors acting on organisms (such as bacteria) in conjunction had effects on the growth rate of the network that were computable using a simple equation. 
In particular this could be extended to the application of 3 inhibitors simeltaneously with knowledge of the combined growth rates of all three pairs of two drugs with great accuracy.

This simulator exists to test the model against the result for 3 inhibitors. 

Above is the results for a 5 node, 25 node, and 50 node network (in the .txt files). The first number is the actual growth rate, while the second number is the growth rate estimate taking into account the pairwise growth rates, and the third only the individual growth rates.
The simulation results reflect the increased accuracy of the pairwise growth rate estimate, suggesting the model was a success.
It was later found that this model contains unnecessary assumptions perhaps not reflective of real organisms, but that the principle we were testing for applies more generally without these assumptions.
