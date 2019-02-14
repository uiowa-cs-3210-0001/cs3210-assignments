#include "file_handle.hpp"
#include <vector>

int main()
{
    std::vector<file_handle> files;
    files.push_back( open_file( "hello.txt", "w" ) );
    files.push_back( open_file( "goodbye.txt", "w" ) );

    fputs( "Hello, Bob!\n", files[0] );
    fputs( "Goodbye, Bob!\n", files[1] );
}
