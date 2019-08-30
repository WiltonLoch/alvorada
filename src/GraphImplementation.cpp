#include <GraphImplementation.hpp>
#include <fstream>
#include <sstream>
#include <utility>
#include <cstring>
#include <bitset>
#include <iostream>

GraphImplementation::GraphImplementation(){}
GraphImplementation::~GraphImplementation(){}

void int2uchar32(unsigned char* pointer, int value){
	for(int i = 0; i < 4; i++){
		pointer[3 - i] = value>>(i*8); 
	}
}

unsigned char* GraphImplementation::generateRawData(int &size){
	size = 8 * graph.size() + 4; // allocates space to write graph size(4 bytes) plus string sizes and edges amount (graph_size * 8)
	for(size_t i = 0; i < graph.size(); i++){
		size += node_descriptions[i].length(); //Each node has a description that holds the machine configuration, wich also needs to be stored, therefore the sizes are collected
		size += graph[i].size() * 12; //Each node has a pair of int and another pair of int (3x4 bytes)
	}

	unsigned char *raw_data = new unsigned char[size];
	int2uchar32(raw_data, graph.size());

	int offset = 4;// starts at four because the graph size is already stored
	for(size_t i = 0; i < graph.size(); i++){
		int2uchar32(raw_data + offset, node_descriptions[i].length());// stores string length 
		offset += 4;//moves offset int size
		memcpy(raw_data + offset, node_descriptions[i].c_str(), node_descriptions[i].length());
		offset +=  node_descriptions[i].length();//moves offset by the size of the stored string
		int2uchar32(raw_data + offset, graph[i].size());// stores the amount of edges
		offset += 4;
		for(size_t j = 0; j < graph[i].size(); j++){
			int2uchar32(raw_data + offset, graph[i][j].first);
			offset += 4;
			int2uchar32(raw_data + offset, graph[i][j].second.first);
			offset += 4;
			int2uchar32(raw_data + offset, graph[i][j].second.second);
			offset += 4;
		}	
	}

    return raw_data;
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
			std::vector<std::pair<int, std::pair<int, int>>> edges;
			for(int j = 0; j < size; j++){	
				int destiny, bandwidth, jitter;
				graph_file >> destiny;
				graph_file >> bandwidth;
				graph_file >> jitter;
				edges.push_back(std::make_pair(destiny, std::make_pair(bandwidth, jitter)));
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

