#include "circle.hpp"
#include "filled_circle.hpp"
#include "rectangle.hpp"
#include "filled_rectangle.hpp"
#include "read_shape.hpp"

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


void write_shapes( vector< unique_ptr<Shape> >& shapes, std::ostream& out )
{    
    for (auto& s : shapes)
        s->write( out );
}

void write_to_file( 
    vector< unique_ptr<Shape> >& shapes, 
    std::string const& filename 
    )
{
    std::ofstream output( filename );
    write_shapes( shapes, output );
}

vector< unique_ptr<Shape> > read_shapes( std::istream& in )
{    
    vector< unique_ptr<Shape> > result;
    std::string line;
    while ( std::getline( in, line ) )
        if ( !line.empty() )
        {
            std::istringstream ss( line );    
            result.push_back( read_shape( ss ) );
        }

    return result;
}

vector< unique_ptr<Shape> > read_from_file( std::string const& filename )
{
    std::ifstream input( filename );
    return read_shapes( input );
}


int main()
{
    vector< unique_ptr<Shape> > shapes;
    shapes.push_back( make_unique<Circle>( Point{5,5}, 10 ) );
    shapes.push_back( make_unique<Circle>( Point{-1,-1}, 5 ) );
    shapes.push_back( make_unique<Rectangle>( Point{1,1}, Point{10,10} ) );
    shapes.push_back( make_unique<Filled_Circle>( Point{-5,1}, 17 ) );
    shapes.push_back( make_unique<Filled_Rectangle>( Point{2,0}, Point{8,10} ) );

    write_to_file( shapes, "shapes.txt" );

    vector< unique_ptr<Shape> > shapes2( read_from_file( "shapes.txt" ) );
    write_to_file( shapes2, "shapes2.txt" );
}
