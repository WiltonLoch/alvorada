#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include<BlockHeader.hpp>
#include<Block.hpp>

namespace verification{
	
	bool verifyBlock(std::shared_ptr<Block> block);

}


#endif
