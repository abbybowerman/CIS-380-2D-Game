#include "Engine.hpp"
#include "Sprite.hpp"
#include "Background.hpp"
#include "Slime.hpp"
#include <string>

std::string loc3 = "assets/Background.png";
Background::Background() : Sprite(&loc3) {
    
	position.setX(0);
	position.setY(0);
}

Background::~Background() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Background::draw() {
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}

void Background::update(double delta) {
}
