#ifndef GRAPH_STRUCTURE_H
#define GRAPH_STRUCTURE_H

#include <string>

class GraphBasicStructure{
    public:
        GraphBasicStructure(){};
        ~GraphBasicStructure(){};

        virtual unsigned char* generateRawData(unsigned int &size) = 0;
        virtual void initializeFromFile(std::string filename) = 0;
        virtual void initializeFromRawData(unsigned char* raw_data) = 0;
	virtual bool verifyConnectivity() = 0;
};

#endif
