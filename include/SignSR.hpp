#ifndef UTILS_SIGN_H
#define UTILS_SIGN_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/export.hpp>

#include <Key.hpp>
#include <ServiceRequest.hpp>

namespace signature{

	void signServiceRequest(std::shared_ptr<Key> key, std::shared_ptr<ServiceRequest> tx);

};
#endif
