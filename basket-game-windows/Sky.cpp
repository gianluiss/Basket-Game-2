#include "Sky.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

void Sky::setupLine()
{
   int counter {};
   while(counter < itemsPerLine)
   {
      int itemPicker {std::rand() % 2};
      char item {itemPicker == 0 ? '$' : '.'};

      int index {std::rand() % lineSize};

      if(line[index] == '$' || line[index] == '.')
	 continue;
      else
      {
	 line[index] = item;
	 counter++;
      }
   }
}
