#include"planet_object.h"

PlanetObject::PlanetObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, double sD)
{
  const char *input;
  input = objectFileString.c_str();
	
	textureFile = textureFileString;
	//std::cout << textureFile << std::endl;
  // Read our .obj file
  loadOBJ(input);
  rotateAngle = 0.0f;
  orbitAngle = 0.0f;
	orbitDistance = oD;
	planetSize = pS;
	orbitVelocity = oV;
	rotationSpeed = rS;
	scaledDistance = sD;
	sizeScaler = false;
}

void PlanetObject::Update(unsigned int dt,glm::mat4 position)
{
	double distance;
	if(sizeScaler)
		distance = scaledDistance;
	else
		distance = orbitDistance;
	orbitAngle += ((speedScaler * orbitVelocity/(2*M_PI))*dt/(1000));
	rotateAngle = -(orbitAngle*rotationSpeed);
	//std::cout << orbitAngle/(2*3.14159) << " " << rotateAngle/(2*3.14159) << " " << orbitVelocity << std::endl;
	glm::mat4 translate = glm::translate(position, glm::vec3(distance * cos(orbitAngle), 0.0f,distance *sin(orbitAngle)));
  model = glm::rotate(translate, (rotateAngle), glm::vec3(0.0, 1.0, 0.0));
  model = glm::scale(model, glm::vec3(planetSize, planetSize, planetSize));
}

/*function that will get a planet's size*/
double PlanetObject::GetPlanetSize()
{
	return planetSize;
}

glm::mat4 PlanetObject::GetPosition()
{
	if(sizeScaler)
		return glm::translate(glm::mat4(1.0), glm::vec3(scaledDistance * cos(orbitAngle), 0.0f,scaledDistance*sin(orbitAngle)));
	else
  	return glm::translate(glm::mat4(1.0), glm::vec3(orbitDistance * cos(orbitAngle), 0.0f,orbitDistance*sin(orbitAngle)));
}


MoonObject::MoonObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, PlanetObject* pl)
{
  const char *input;
  input = objectFileString.c_str();
	
	textureFile = textureFileString;
	//std::cout << textureFile << std::endl;
  // Read our .obj file
  loadOBJ(input);
  rotationAngle = 0.0f;
  angle = 0.0f;
	orbitDistance = oD;
	moonSize = pS;
	orbitVelocity = oV;
	rotationSpeed = rS;
	planet = pl;
}

void MoonObject::Update(unsigned int dt,glm::mat4 position)
{
	rotationAngle -= dt * rotationSpeed/3000;
	angle += (dt * orbitVelocity/1000);
	model = glm::translate( planet->GetPosition(), glm::vec3( orbitDistance * cos( angle ), 0.0f, orbitDistance * sin( angle ) ) ) * glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0)) * glm::scale( glm::mat4(1.0f), glm::vec3(moonSize));
}
