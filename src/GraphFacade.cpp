#include <GraphFacade.hpp>

GraphFacade::GraphFacade(){}
GraphFacade::~GraphFacade(){}

unsigned char* GraphFacade::generateRawData(int &size, std::string filename){
    GraphBasicStructure *tmp = new GraphImplementation();
    tmp->initializeFromFile(filename);
    unsigned char* raw_data = tmp->generateRawData(size);
    printf("%d\n", size);
    return raw_data;
}

GraphBasicStructure* GraphFacade::generateStructure(unsigned char* &raw_data){
    GraphBasicStructure *teste = new GraphImplementation();
    return teste;
}
