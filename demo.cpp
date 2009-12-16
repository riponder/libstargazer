// File:           demo.cpp
// Creation Date:  Wednesday, December 16 2009
// Author:         Julius Ziegler <ziegler@mrt.uka.de>

#include <iostream>

#include "StarGazer.hpp"

using namespace std;

int main( int, char** )
{
  StarGazer sg;

  while( true )
    {
      StarGazer::PositionData pd;

      pd = sg.get_position();
      
      if( pd.dead )
	{
	  cout << "dead!\n";
	}
      else
	{
	  cout << "x, y, z, theta: " << pd.x << ", "  << pd.y << ", "  << pd.z << ", "  << pd.theta << "\n"; 
	}      
    }
}
