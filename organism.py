import process

# Number of organism nodes (sparsly connected)
organism_dim_sparse = 20
organism_dim_dense = 10

# Growth intervals
orgamism_time = 20

# p Parameter for geometric distribution of number of vertices for hypergraph edge
organism_scale = .5

# Generates a random subset of output values (sparse)
# Power law (exponential) distribution of random output values
def random_subset_sparse()
    function_dim = numpy.random.geometric(organism_scale, size=None)
    input_index = np.random.choice(organism_dim_sparse, function_dim, replace=False)
    return function_dim, input_index

# Generates a random subset of output values (dense)
# Power law (exponential) distribution of random output values
def random_subset_dense(input_index_first)
    random_set = np.arrange(organism_dim_dense)
    np.delete(random_set, input_index_first)
    function_dim = numpy.random.geometric(organism_scale, size=None)
    input_index = np.random.choice(random_set, function_dim - 1, replace=False)
    return function_dim, input_index


class organism:

    # Initialize new organism
    # Type: distribution of number of connections between nodes
    def __init__(self, type):

        # Initialize type
        # Type 0: Sparsly connected network
        # Type 1: Highly connected network
        self.type = type
        function_set = []

        # Initialize process set based on type
        if(type == 0):
            self.organism_dim = orgamism_dim_sparse
            for output_index in range(self.organism_dim):
                function_dim, input_index = random_subset_sparse()
                function_set.append(random_function(function_dim, input_index, output_index)

        if(type == 1):
            self.organism_dim = orgamism_dim_dense
            for i in range(self.organism_dim):
                for j in range(self.organism_dim):
                    function_dim, input_index = random_subset_dense(j)
                    function_set.append(random_function(function_dim, input_index, output_index))
                    
        # Initialize state value
        state_value_initial = np.random.uniform(size = organism_dim)
        state_value = state_value_initial

    # Return organism mass
    def mass(self):
        return np.sum(self.state_value)

    # Apply the effects of a drug to the organism
    # Inhibit value: values of change in state caused by drug
    def inhibit(self, inhibit_value):
        state_value_new = self.state_value - inhibit_value

    def grow(self):
        for t in range(organism_time):
            output_val_total = np.empty(self.organism_dim)
            for function in function_set:
                output_index, output_val = function.process(self.state_value)
                output_val_new = output_val_total[output_index] + output_val
                output_val_total[output_index] = output_val_new
            self.state_value = self.state_value + output_val_total
        return self.mass()

    # Reset the organism to the original
    # Removes growth and applied drugs
    def reset(self):
        state_value = state_value_initial
