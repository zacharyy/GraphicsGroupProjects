#include"object.h"

class PlanetObject : public Object {
	public:
		// Constructor for planet objects with necessary information
		PlanetObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, double sD);

		// Update function for the planets
		virtual void Update(unsigned int dt, glm::mat4 position);
		// Return the position of a planet
		virtual glm::mat4 GetPosition();
	
		// Variables for moving planets correctly and scaling
		double orbitDistance;
		double planetSize;
		double orbitVelocity;
		double rotationSpeed;
		double scaledDistance;
		float orbitAngle;
		float rotateAngle;
		double speedScaler;
		bool sizeScaler;
	public:
		/*function that will get a planet's size*/
		double GetPlanetSize();
};

class MoonObject : public Object {
	public:
		// Moon Object Constructor
           	MoonObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, PlanetObject* planet);

		//Update the position of a moon
	    virtual void Update(unsigned int dt, glm::mat4 position);
	
		// Variables for moving moons correctly and scaling
		double orbitDistance;
		double moonSize;
		double orbitVelocity;
		double rotationSpeed;
		float angle;
		float rotationAngle;
		PlanetObject* planet;

};
