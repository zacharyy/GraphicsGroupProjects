#include"planet_object.h"

PlanetObject::PlanetObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS)
{
  const char *input;
  input = objectFileString.c_str();
	
	textureFile = textureFileString;
	std::cout << textureFile << std::endl;
  // Read our .obj file
  loadOBJ(input);

  angle = 0.0f;
	orbitDistance = oD;
	planetSize = pS;
	orbitVelocity = oV;
	rotationSpeed = rS;
}

void PlanetObject::Update(unsigned int dt,glm::mat4 position)
{
	angle += (dt * orbitVelocity/1000);
  glm::mat4 translate = glm::translate(position, glm::vec3(orbitDistance * cos(angle/3), 0.0f,orbitDistance*sin(angle/3)));
  model = glm::rotate(translate, (angle), glm::vec3(0.0, 1.0, 0.0));
  model = glm::scale(model, glm::vec3(planetSize, planetSize, planetSize));
}

/*function that will get a planet's size*/
double PlanetObject::GetPlanetSize()
{
	return planetSize;
}

glm::mat4 PlanetObject::GetPosition()
{
  return glm::translate(glm::mat4(1.0), glm::vec3(orbitDistance * cos(angle/3), 0.0f,orbitDistance*sin(angle/3)));
}


MoonObject::MoonObject(std::string objectFileString, std::string textureFileString, double oD, double pS, double oV, double rS, PlanetObject* pl)
{
  const char *input;
  input = objectFileString.c_str();
	
	textureFile = textureFileString;
	std::cout << textureFile << std::endl;
  // Read our .obj file
  loadOBJ(input);

  angle = 0.0f;
	orbitDistance = oD;
	moonSize = pS;
	orbitVelocity = oV;
	rotationSpeed = rS;
	planet = pl;
}

void MoonObject::Update(unsigned int dt,glm::mat4 position)
{
	angle += (dt * orbitVelocity/1000);
	model = glm::translate( planet->GetPosition(), glm::vec3( cos( angle ), 0.0f, sin( angle ) ) ) * glm::scale( glm::mat4(1.0f), glm::vec3(moonSize));
}
