#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <config.hpp>

#include <Key.hpp>
#include <VerifySig.hpp>

namespace verification{
	
	bool verifyBlock(std::shared_ptr<Block> block){
		std::shared_ptr<Key> key (new Key(block->getAddress()));
		if(block->getVersion() != VERSION) return false;
		/* if(!signature::verifySig(key, block)) return false; */

		return true;
	}

}


#endif
