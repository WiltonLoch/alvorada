#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include<BlockHeader.hpp>
#include<Block.hpp>

namespace verification{
	
	bool verifyBlockHeader(std::shared_ptr<BlockHeader> block_header);

}


#endif
