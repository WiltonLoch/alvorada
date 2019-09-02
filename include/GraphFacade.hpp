#ifndef GRAPH_FACADE_H
#define GRAPH_FACADE_H

#include <GraphBasicStructure.hpp>
#include <GraphImplementation.hpp>

class GraphFacade{
    private:
        GraphBasicStructure *graphStructure;
    public:
        GraphFacade();
        ~GraphFacade();

        unsigned char* generateRawData(int &size, std::string filename);

        GraphBasicStructure* generateStructure(unsigned char* raw_data);
};

#endif
