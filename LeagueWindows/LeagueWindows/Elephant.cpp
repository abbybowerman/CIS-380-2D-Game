#include "Engine.hpp"
#include "Sprite.hpp"
#include "Elephant.hpp"
#include "laser.hpp"
#include <string>

Elephant::Elephant() : Sprite("../assets/Elephant.png") {
	//this places the elephant on the grass
	position.setX(0);
	position.setY(550);
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

void Elephant::setScene(Scene* scene) {
	this->scene = scene;
}

void Elephant::fire(double delta) {
	/*laser* l = new laser();
	l->position.setX(position.getX());
	l->position.setY(position.getY());
	l->velocity.setX(velocity.getX() * 2);
	l->velocity.setY(velocity.getY() * 2);
	this->scene->addDrawable(l);
	this->scene->addUpdateable(l);*/
}