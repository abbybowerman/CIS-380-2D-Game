#ifndef __HPP__LASER__
#define __HPP__LASER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"
#include "Scene.hpp"
#include <string>

class laser : public Sprite {
	public:
		laser();
		~laser();
		void update(double delta);
        Scene* scene;
        int getCurrentX();
        void setCurrentX(int a);
		void draw();
        void setScene(Scene* scene);
	private:
        
        Vector3 velocity;
      


};

#endif // !
