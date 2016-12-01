#include "CacheableFile.h"

#include <fstream>

constexpr size_t DEFAULT_FILE_SIZE = 1024;

CacheableFile::CacheableFile(std::string file_name) : file_name{file_name} {
}

std::string CacheableFile::get_name() {
    return file_name;
}

size_t CacheableFile::get_size() {
    return DEFAULT_FILE_SIZE;
}

void CacheableFile::load_file() {
    char buffer[DEFAULT_FILE_SIZE];
    // Calls functor of this to load the object.
    (*this)(buffer);
    content = std::string(reinterpret_cast<const char *>(buffer), DEFAULT_FILE_SIZE);
}

std::string CacheableFile::get_contents_of_file() {
    return content;
}

const void *CacheableFile::get_from_resource() {
    std::cout << "Loading the resource data!" << std::endl;
    std::ifstream ifs(file_name);
    content = std::string((std::istreambuf_iterator<char>(ifs)),
                          (std::istreambuf_iterator<char>()));
    return content.c_str();
}