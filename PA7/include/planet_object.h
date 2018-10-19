#include"object.h"

class PlanetObject : public Object {
	public:
		PlanetObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, double sD);
		virtual void Update(unsigned int dt, glm::mat4 position);
		virtual glm::mat4 GetPosition();
	
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
            MoonObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, PlanetObject* planet);
	    virtual void Update(unsigned int dt, glm::mat4 position);
	
		double orbitDistance;
		double moonSize;
		double orbitVelocity;
		double rotationSpeed;
		float angle;
		float rotationAngle;
		PlanetObject* planet;

};
