#include "CacheableFile.h"

int main() {
    CacheableFile cacheable_file("test.txt");
    // cacheable_file.delete_object_from_cache();
    cacheable_file.load_file();
    std::cout << cacheable_file.get_contents_of_file() << std::endl;

}