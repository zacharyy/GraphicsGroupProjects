#include"object.h"

class PlanetObject : public Object {
	public:
			PlanetObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS);
	    void Update(unsigned int dt, glm::mat4 position);
	private:
			double orbitDistance;
			double planetSize;
			double orbitVelocity;
			double rotationSpeed;
			float angle;

};
