#include <iostream>
#include <bitset>

#include <config.hpp>

#include <Key.hpp>
#include <VerifySig.hpp>
#include <Hash.hpp>
#include <BlockVerificator.hpp>

namespace verification{
	
	bool verifyBlock(std::shared_ptr<Block> block){
		unsigned char * current_hash;
		unsigned char * original_hash = new unsigned char[32];

		memcpy(original_hash, block->getHash(), 32);
		hash::hash(block);
		current_hash = block->getHash();

		for(int i = 0; i < 32; i++) if(original_hash[i] != current_hash[i]) return false;

		delete [] original_hash;

		if(block->getVersion() != VERSION) return false;
		/* if(!signature::verifySig(key, block)) return false; */
		if(!block->verifyTransactions()) return false;

		return true;
	}
};
