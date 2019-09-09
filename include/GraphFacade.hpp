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

        unsigned char* generateRawData(unsigned int &size, std::string filename);

	std::shared_ptr<GraphBasicStructure> generateStructure(unsigned char* raw_data);

	bool verifyGraph(unsigned char* raw_data);
};

#endif
