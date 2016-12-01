#ifndef LIBHPCACHE_CACHEABLEEXAMPLE_H
#define LIBHPCACHE_CACHEABLEEXAMPLE_H

#include <string>

#include "Cacheable.h"

class CacheableFile : public Cacheable {
public:
    explicit CacheableFile(std::string file_name);

    std::string get_name() final;

    size_t get_size() final;

    const void *get_from_resource() final;

    /// Loads the file from disk
    void load_file();

    /// Returns the contents of file.
    std::string get_contents_of_file();

private:
    std::string file_name;
    std::string content;
};


#endif //LIBHPCACHE_CACHEABLEEXAMPLE_H
