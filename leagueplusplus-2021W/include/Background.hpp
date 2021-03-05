#ifndef __GRASS__HPP__
#define __GRASS__HPP__


#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <string>


class Background : public Sprite {
public:
	Background();
	~Background();
	void draw();
	void update(double delta);
};


#endif
