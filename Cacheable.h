#ifndef LIBHPCACHE_CACHEABLE_H
#define LIBHPCACHE_CACHEABLE_H

#include <string>
#include <iostream>

class Cacheable {
public:
    /// Get name of cacheable object
    virtual std::string get_name() = 0;

    /// Get size of cacheable object
    virtual size_t get_size() = 0;

    /// Directly read object from it's resource
    virtual const void *get_from_resource() = 0;

    /// Delete object from cache
    virtual void delete_object_from_cache();

    /**
     * Checks if object with given name exists in cache and return it.
     * If can't find that object in the cache simply get it from it's resource
     * and save it to cache and return it.
     */
    virtual void operator()(void *buffer);
};

#endif //LIBHPCACHE_CACHEABLE_H
