#include "Engine.hpp"
#include "Sprite.hpp"
#include "Elephant.hpp"
#include <string>

Elephant::Elephant() : Sprite("../assets/Elephant.png") {
}

Elephant::~Elephant() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Elephant::update(double delta) {
	// So we stop getting the compiler warning for now.
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if (position.getX() > 1024 - rect->w || position.getX() < 0) {
		velocity.setX(0);
	}
	if (position.getY() > 768 - rect->h || position.getY() < 0) {
		velocity.setY(0);
	}
}

void Elephant::draw() {
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}

void Elephant::left(double delta) {
	if (velocity.getX() > -200) {
		velocity.setX(velocity.getX() - 10);
	}
}
void Elephant::right(double delta) {
	if (velocity.getX() < 200) {
		velocity.setX(velocity.getX() + 10);
	}
}

void Elephant::up(double delta) {
	if (velocity.getY() > -200) {
		velocity.setY(velocity.getY() - 10);
	}
}
void Elephant::down(double delta) {
	if (velocity.getY() < 200) {
		velocity.setY(velocity.getY() + 10);
	}
}