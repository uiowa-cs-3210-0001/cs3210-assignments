#ifndef CS3210_HW6_FILE_HANDLE_HPP
#define CS3210_HW6_FILE_HANDLE_HPP

#include <string>


class file_handle
{
public:
    file_handle( FILE* h )
        : handle( h )
    {}

    ~file_handle();

    operator FILE*() const { return this->handle; }

private:
    FILE* handle;
};


file_handle open_file( 
    std::string const&  filename,
    char const*         mode
    );

#endif
