#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include "planet_object.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height, string objectFileString);
    void Update(unsigned int dt);
    void Render();

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    Object *m_sun;
		PlanetObject *m_earth;
		PlanetObject *m_mars;
		PlanetObject *m_mercury;
		PlanetObject *m_venus;
		PlanetObject *m_jupiter;
		PlanetObject *m_saturn;
		PlanetObject *m_uranus;
		PlanetObject *m_neptune;
		PlanetObject *m_pluto;
};

#endif /* GRAPHICS_H */
