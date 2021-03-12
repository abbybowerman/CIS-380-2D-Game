#ifndef __ELEPHANT__HPP__
#define __ELEPHANT__HPP__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"
#include <string>


class Elephant : public Sprite {
	public:
		Elephant();
		~Elephant();
		void left(double delta);
		void right(double delta);
		void up(double delta);
		void down(double delta);
		void update(double delta);
		void draw();
		void setScene(Scene* scene);
		void fire(double delta);
	
	private:
		Vector3 velocity;
		Scene* scene;
};

#endif // !__ELEPHANT__HPP__

