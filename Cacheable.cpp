#include "Cacheable.h"

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;

void Cacheable::operator()(void *buffer) {
    try {
        // Load the object from cache
        shared_memory_object shm(open_only, get_name().c_str(), read_only);
        mapped_region region(shm, read_only);
        // Copy loaded object to given buffer
        std::memcpy(buffer, region.get_address(), get_size());
    }
    catch (const std::exception &ex) {
        /*
         * If failed to load object from cache, load it from resource and also
         * copy it to cache.
         */
        shared_memory_object shm(create_only, get_name().c_str(), read_write);
        shm.truncate(get_size());
        mapped_region region(shm, read_write);
        const void *object = get_from_resource();
        std::memcpy(region.get_address(), object, get_size());
        std::memcpy(buffer, region.get_address(), get_size());
    }
}

void Cacheable::delete_object_from_cache() {
    shared_memory_object::remove(get_name().c_str());
}

