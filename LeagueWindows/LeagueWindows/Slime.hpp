#include "Utility.hpp"
#include <string>
#include "Sprite.hpp"

class Slime : public DUGameObject {
	public:
		Slime();
		~Slime();
		void update(double delta);
		void draw();
		Vector2 getPosition();
	private:
		Vector3 velocity;
};