#ifndef COMMOM_VERIFICATOR_H
#define COMMON_VERIFICATOR_H

#include <config.hpp>

#include <Key.hpp>
#include <VerifySig.hpp>

namespace verification{
	
	bool verifyBlockHeader(std::shared_ptr<BlockHeader> block_header){
		std::shared_ptr<Key> key (new Key(block_header->getAddress()));
		if(block_header->getVersion() != VERSION) return false;
		/* if(!signature::verifySig(key, block_header)) return false; */

		return true;
	}

}


#endif
