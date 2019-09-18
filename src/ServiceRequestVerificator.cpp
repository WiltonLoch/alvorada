#include <config.hpp>

#include <Key.hpp>
#include <VerifySig.hpp>
#include <Hash.hpp>

namespace verification{
	
	bool verifyServiceRequest(std::shared_ptr<ServiceRequest> tx){
		unsigned char * current_hash;
		unsigned char * original_hash = new unsigned char[32];

		memcpy(original_hash, tx->getHash(), 32);
		hash::hash(tx);
		current_hash = tx->getHash();

		for(int i = 0; i < 32; i++) if(original_hash[i] != current_hash[i]) return false;

		delete [] original_hash;

		std::shared_ptr<Key> key (new Key(tx->getAddress()));
		if(tx->getVersion() != VERSION) return false;
		if(!signature::verifySig(key, tx)) return false;

		std::unique_ptr<GraphFacade> graphFacade (new GraphFacade());
		if(!graphFacade->verifyGraph(tx->getGraphData())) return false;
		return true;
	}

}
