#include "file_handle.hpp"
#include <iostream>
#include <cstdio>
#include <cerrno>


file_handle::~file_handle()
{
    if ( this->handle )
        fclose( this->handle );
}


file_handle open_file( 
    std::string const&  filename,
    char const*         mode
    )
{    
    file_handle result( fopen( filename.c_str(), mode ) );
    if ( !result )
        throw std::runtime_error( std::string( "Can't open file: " ) + strerror( errno ) );

    return result;
}
