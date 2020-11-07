/*
* This file is part of <PROJECT> 
* <INSERT PROJECT DESCRIPTION HERE>  
*
* Copyright (C) 2020 Florian Setzwein 
*
* <PROJECT> is free software; you can redistribute it and/or 
* modify it under the terms of the GNU General Public 
* License as published by the Free Software Foundation; 
* either version 2 of the License, or (at your option) 
* any later version.
*
* <PROJECT> is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied 
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
* PURPOSE.  See the GNU General Public License for more 
* details.
*
* You should have received a copy of the GNU General 
* Public License along with <PROJECT>; if not, write to the 
* Free Software Foundation, Inc., 51 Franklin Street, 
* Fifth Floor, Boston, MA 02110-1301, USA.
*/
#define OLC_PGE_APPLICATION

#include <iostream>
#include <string>
#include <algorithm>

#include "aux/olc_pixel_game_engine.hpp"
#include "skeleton/foo.hpp"

/***********************************************************
* 
***********************************************************/
class Skeleton : public olc::PixelGameEngine
{
public:
  Skeleton()
  {
    sAppName = "Skeleton";
  }

private:


public:

  bool OnUserCreate() override
  {
    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override
  {
    return true;
  }
};


/***********************************************************
* The main function
***********************************************************/
int main()
{
	Skeleton demo;
	if (demo.Construct(1600, 960, 1, 1))
		demo.Start();
	return 0;
}

