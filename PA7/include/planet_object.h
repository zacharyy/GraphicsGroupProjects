#include"object.h"

class PlanetObject : public Object {
	public:
			PlanetObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS);
	    void Update(unsigned int dt, glm::mat4 position);
	    glm::mat4 GetPosition();
	private:
			double orbitDistance;
			double planetSize;
			double orbitVelocity;
			double rotationSpeed;
			float angle;
	public:
			/*function that will get a planet's size*/
			double GetPlanetSize();
};

class MoonObject : public Object {
	public:
            MoonObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, PlanetObject* planet);
	    void Update(unsigned int dt, glm::mat4 position);
	private:
			double orbitDistance;
			double moonSize;
			double orbitVelocity;
			double rotationSpeed;
			float angle;
			PlanetObject* planet;

};
