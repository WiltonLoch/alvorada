#include <GraphFacade.hpp>

GraphFacade::GraphFacade(){}
GraphFacade::~GraphFacade(){}

unsigned char* GraphFacade::generateRawData(int &size, std::string filename){
    GraphBasicStructure *tmp = new GraphImplementation();
    tmp->initializeFromFile(filename);
    return nullptr;
//    unsigned char* raw_data = tmp->generateRawData(size);
//    return raw_data;
}

GraphBasicStructure* GraphFacade::generateStructure(unsigned char* &raw_data){
    GraphBasicStructure *teste = new GraphImplementation();
    return teste;
}
