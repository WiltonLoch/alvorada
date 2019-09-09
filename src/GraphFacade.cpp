#include <GraphFacade.hpp>

GraphFacade::GraphFacade(){}
GraphFacade::~GraphFacade(){}

unsigned char* GraphFacade::generateRawData(unsigned int &size, std::string filename){
	std::unique_ptr<GraphBasicStructure> tmp (new GraphImplementation());
	tmp->initializeFromFile(filename);
	unsigned char* raw_data = tmp->generateRawData(size);
	return raw_data;
}

GraphBasicStructure* GraphFacade::generateStructure(unsigned char* raw_data){
	std::unique_ptr<GraphBasicStructure> tmp (new GraphImplementation());
	tmp->initializeFromRawData(raw_data);
	return teste;
}

bool verifyGraph(){
	std::unique_ptr<GraphBasicStructure> tmp (new GraphImplementation());
	tmp->initializeFromRawData(raw_data);
	tmp->verifyConnectivity();
}
