#include "Engine.hpp"
#include "laser.hpp"
#include "Sprite.hpp"
#include "Elephant.hpp"
#include <string>

int aba = 0;
std::string loc6 = "assets/laser.png";
laser::laser() : Sprite(&loc6) {
	//surface = IMG_Load("assets/laser.png");
	if (surface == NULL) {
		SDL_Log("The laser won't load!");
		//exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if (texture == NULL) {
		//SDL_Log("----> HAVE YOU CREATED THE ENGINE YET?!");
		//SDL_Log("Unable to create texture. %s", SDL_GetError());
	}

	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
    

    
    

}

void laser::setCurrentX(int a){
    
 aba = a;
    
    
}

int laser::getCurrentX(){
    return aba;
    
}

laser::~laser() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void laser::update(double delta) {
    
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if (position.getX() > 1024 - rect->w || position.getX() < 0) {
     velocity.setX(-velocity.getX());
	}
	if (position.getY() > 768 - rect->h || position.getY() < 0) {
		velocity.setY(-velocity.getY());
	}
	
    
   position.setX(getCurrentX() - 32);

}


void laser::setScene(Scene* scene) {
	this->scene = scene;
    
}

void laser::draw() {
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
    
    //Two SDL Render to create a stobe effetct seen in blasts
    position.setX(getCurrentX());
	position.setY(50);
    SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
    
    //Smooth Gameplay  
    int a;
    int t;
    while (a < t + 100000 ){
     t = SDL_GetTicks();
     if (a<t){
     a = t;}
    a++;
}
   //Move Ray off Screen
   setCurrentX(-5000);
   SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
