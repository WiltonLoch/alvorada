#ifndef GRAPH_IMPLEMENTATION_H
#define GRAPH_IMPLEMENTATION_H

#include <cstdlib>
#include <vector>
#include <GraphBasicStructure.hpp>

class GraphImplementation : public GraphBasicStructure{
    private:
        std::vector<std::string> node_descriptions;
    public:
        GraphImplementation();
        ~GraphImplementation();
        
        unsigned char* generateRawData(int &size);
        void initializeFromFile(std::string filename);
};

#endif