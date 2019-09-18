#ifndef BLOCK_VERIFICATOR_H
#define BLOCK_VERIFICATOR_H

#include<BlockHeader.hpp>
#include<Block.hpp>

namespace verification{
	
	bool verifyBlock(std::shared_ptr<Block> block);

};


#endif
