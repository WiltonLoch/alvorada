#ifndef BLOCK_HEADER_VERIFICATOR_H
#define BLOCK_HEADER_VERIFICATOR_H

#include<BlockHeader.hpp>

namespace verification{
	
	bool verifyBlockHeader(std::shared_ptr<BlockHeader> block_header);

};


#endif
