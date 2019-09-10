#ifndef UTILS_SIGN_H
#define UTILS_SIGN_H

#include <memory>

#include <Key.hpp>
#include <ServiceRequest.hpp>

namespace signature{

	void signServiceProposal(std::shared_ptr<Key> key, std::shared_ptr<ServiceProposal> tx);

};
#endif
