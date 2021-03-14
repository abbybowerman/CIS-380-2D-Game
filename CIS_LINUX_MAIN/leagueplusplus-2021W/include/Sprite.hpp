#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <string>

class Sprite : public DUGameObject {
public:
	Sprite(std::string* loc);
	Sprite(SDL_Surface* surface);
	~Sprite();
	void update(double delta);
	void draw();
private:
	Vector3 velocity;

};

#endif

