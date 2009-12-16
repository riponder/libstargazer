// File:           demo.cpp
// Creation Date:  Tuesday, September 29 2009
// Author:         Julius Ziegler <ziegler@mrt.uka.de>

#include <iostream>

#include <boost/program_options.hpp>

#include "StarGazer.hpp"

int ref_id;
int no_ids;

std::string device;

void parse_commandline( int argc, char** argv )
{
  namespace po = boost::program_options;

  using namespace std;

  // parse program options
  po::options_description desc("Allowed options");
  desc.add_options()
    ( "help,h", "produce help message" )
    ( "reference-id,r", po::value<int>( &ref_id )->default_value( 18966 ), "use this as reference id" )
    ( "no-ids,n", po::value<int>( &no_ids )->default_value( 11 ), "learn this number of ids" )
    ( "device-node,d", po::value<string>( &device )->default_value( "/dev/ttyS0" ), "device node of serial port" )
    ;

  po::variables_map vm;
  try
    {
      po::store( po::parse_command_line( argc, argv, desc ), vm );
      po::notify( vm );
    } 
  catch( ... )
    {
      std::cout << "Usage: \n\n" << desc << std::endl;
      exit( 1 );
    }
  
  if (vm.count("help")) {
    cout << desc << "\n";
    exit( 0 );
  }
}


int main( int argc, char** argv )
{
  parse_commandline( argc, argv );

  StarGazer sg( device );

  // set mark mode to "Map" (alternative is "Alone")
  // sg.write_parameter( "MarkMode", "Map" );
  // sg.write_parameter( "MarkType", "HLD1L" );

  /*
  sg.write_parameter( "MarkMode", "Alone" );
  sg.start_calc();

  while( true )
    {
      std::string loc = sg.get_string();
      if( loc != "" ) std::clog << loc << "\n";
      else std::clog << ".";
    }
  */

  std::clog << "MarkMode \t"   << sg.read_parameter( "MarkMode" )  << "\n";
  std::clog << "HeightFix: \t" << sg.read_parameter( "HeightFix" ) << "\n";
  std::clog << "MarkType: \t"  << sg.read_parameter( "MarkType" )  << "\n";

  sg.build_map( no_ids, ref_id ); 
}
