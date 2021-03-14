#include "Engine.hpp"
#include "Sprite.hpp"
#include "Elephant.hpp"
#include "Background.hpp"
#include "HUD.hpp"
#include "Slime.hpp"
#include <SDL2/SDL.h>

int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 700);

	Background* g = new Background();
	one.addDrawable(g);

	// Make a banana and add to scene. Should update and draw.
	Elephant* b = new Elephant();
	b->setScene(&one);
	one.addUpdateable(b);
	one.addDrawable(b);
	Slime* s = new Slime();
	one.addUpdateable(s);
	one.addDrawable(s);
	//auto b_up = [b](double delta) { b->up(delta); };
	//auto b_down = [b](double delta) { b->down(delta); };
	auto b_left = [b](double delta) { b->left(delta); };
	auto b_right = [b](double delta) { b->right(delta); };
	auto b_fire = [b](double delta) { b->fire(delta); };
	//one.addKeyEvent( SDLK_w, b_up );
	one.addKeyEvent( SDLK_a, b_left );
	one.addKeyEvent( SDLK_d, b_right );
	//one.addKeyEvent( SDLK_s, b_down );
	one.addKeyEvent(SDLK_SPACE, b_fire);

	// Set the scene in the engine
	engine.setScene(&one);
	
	// Get the engine running.
	engine.run();

	return 0;
}
