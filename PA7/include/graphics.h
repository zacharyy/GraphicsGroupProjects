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

    /*camera variables*/
    bool normalView;
    bool topDownView;
    bool UpdatedTDView;
    bool moveTDCameraUp;
    bool moveTDCameraDown;
    bool moveTDCameraLeft;
    bool moveTDCameraRight;
    bool zoomInTDCamera;
    bool zoomOutTDCamera;
    int planetSelector;

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

		MoonObject *m_earthMoon;
		MoonObject *m_marsMoon1;
		MoonObject *m_marsMoon2;
		MoonObject *m_jupiterMoon1;
		MoonObject *m_jupiterMoon2;
		MoonObject *m_jupiterMoon3;
		MoonObject *m_jupiterMoon4;
		MoonObject *m_saturnRing;
		MoonObject *m_uranusMoon1;
		MoonObject *m_uranusMoon2;
		MoonObject *m_uranusMoon3;
		MoonObject *m_uranusMoon4;
		MoonObject *m_uranusMoon5;
		MoonObject *m_neptuneMoon1;
		MoonObject *m_neptuneMoon2;
		MoonObject *m_plutoMoon;
};

#endif /* GRAPHICS_H */
