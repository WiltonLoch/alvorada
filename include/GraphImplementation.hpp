#ifndef GRAPH_IMPLEMENTATION_H
#define GRAPH_IMPLEMENTATION_H

#include <cstdlib>
#include <vector>
#include <GraphBasicStructure.hpp>

class GraphImplementation : public GraphBasicStructure{
    private:
        std::vector<std::string> node_descriptions;
    	std::vector<std::vector<std::pair<int, std::pair<int, int>>>> graph;
    public:
        GraphImplementation();
        ~GraphImplementation();
        
        unsigned char* generateRawData(unsigned int &size);
        void initializeFromFile(std::string filename);
        void initializeFromRawData(unsigned char* raw_data);
	bool verifyConnectivity();
	bool verifyCoherence();
	bool verifyInfo();
	void printGraph();
};

#endif
