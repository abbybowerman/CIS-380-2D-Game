#ifndef __HPP__LASER__
#define __HPP__LASER__

#include <SDL2-2.0.14/SDL.h>
#include <SDL2-2.0.14/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"

class laser : public DUGameObject {
	public:
		laser();
		~laser();
		void update(double delta);
		void draw();
	private:
		Vector3 velocity;

	friend class Elephant;

};

#endif // !
