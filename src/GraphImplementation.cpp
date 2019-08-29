#include <GraphImplementation.hpp>
#include <fstream>
#include <sstream>
#include <utility>
#include <bitset>
#include <iostream>

GraphImplementation::GraphImplementation(){}
GraphImplementation::~GraphImplementation(){}


unsigned char* GraphImplementation::generateRawData(int &size){
	std::vector<unsigned char*> raw_descriptions;
	std::vector<unsigned char*> raw_info;
	int teste_var = 5;
	unsigned char* teste_convert = (unsigned char*)(&teste_var);
	printf("%d\n", sizeof(teste_var));

	std::bitset<32> bitteste (teste_convert[3]);
    	for(int i = 2; i >= 0; i--){
       		bitteste = bitteste<<8;    
	        bitteste |= teste_convert[i];
	}
	std::cout << "Digest: " << bitteste.to_string() << std::endl;

//	for(size_t i = 0; i < graph.size(); i++){
//		for(size_t j = 0; j < graph[i].size(); j++){
//					
//		}	
//	}

    return nullptr;
}

void GraphImplementation::initializeFromFile(std::string filename){
	std::fstream graph_file;
	graph_file.open(filename.c_str(), std::fstream::in);
       	if(graph_file){
		int graph_size = 0;
		graph_file >> graph_size;

		std::string line;
		for(int i = 0; i < graph_size; i++){
			graph_file.get();
			std::getline(graph_file, line);
			node_descriptions.push_back(line);
			
			int size = 0;
			graph_file >> size;
			std::vector<std::pair<int, int>> edges;
			for(int j = 0; j < size; j++){	
				int destiny, weight;
				graph_file >> destiny;
				graph_file >> weight;
				edges.push_back(std::make_pair(destiny, weight));
			}
			graph.push_back(edges);
		}

	}else{
		printf("Error trying to open the graph file %s", filename.c_str());
	}
	graph_file.close();
}

void GraphImplementation::printGraph(){
	printf("%d\n", graph.size());
	for(size_t i = 0; i < graph.size(); i++){
		printf("%s\n", node_descriptions[i].c_str());
		for(size_t j = 0; j < graph[i].size(); j++){
			printf("%d -- %d\n", graph[i][j].first, graph[i][j].second);
		}
	}

}

