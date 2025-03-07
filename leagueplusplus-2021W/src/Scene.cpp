#include <SDL.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"

Scene::Scene(){

}

Scene::~Scene(){

}

void Scene::addUpdateable(Updateable* obj){
	this->updateables.push_back(obj);
}

void Scene::addDrawable(Drawable* obj){
	drawables.push_back(obj);
}

void Scene::addKeyEvent(SDL_Keycode key, Callback fn){
	keyEvents.push_back(std::make_pair(key, fn));	
}
