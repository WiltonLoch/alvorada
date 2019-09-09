#include <memory>
#include <GraphFacade.hpp>

GraphFacade::GraphFacade(){}
GraphFacade::~GraphFacade(){}

unsigned char* GraphFacade::generateRawData(unsigned int &size, std::string filename){
	std::unique_ptr<GraphBasicStructure> tmp (new GraphImplementation());
	tmp->initializeFromFile(filename);
	unsigned char* raw_data = tmp->generateRawData(size);
	return raw_data;
}

std::shared_ptr<GraphBasicStructure> GraphFacade::generateStructure(unsigned char* raw_data){
	std::unique_ptr<GraphBasicStructure> tmp (new GraphImplementation());
	tmp->initializeFromRawData(raw_data);
	return tmp;
}

bool GraphFacade::verifyGraph(unsigned char* raw_data){
	std::unique_ptr<GraphBasicStructure> tmp (new GraphImplementation());
	tmp->initializeFromRawData(raw_data);
	if(!tmp->verifyCoherence()) return false;
	if(!tmp->verifyConnectivity()) return false;
	if(!tmp->verifyInfo()) return false;
	return true;
}
