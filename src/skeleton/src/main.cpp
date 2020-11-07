/*
* 
* This is a small CAD tool
* *
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

