#ifndef GRAPHICS_HEADERS_H
#define GRAPHICS_HEADERS_H
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/color4.h>
#include <Magick++.h>
#include <btBulletDynamicsCommon.h>

#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED

#if defined(__APPLE__) || defined(MACOSX)
  #include <OpenGL/gl3.h>
  #include <OpenGL/GLU.h>
#else //linux as default
  #include <GL/glew.h>
  //#include <GL/glu.h>
#endif

// GLM for matricies
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>

#define INVALID_UNIFORM_LOCATION 0x7fffffff

struct Vertex
{
  glm::vec3 vertex;
  glm::vec3 normal;
  glm::vec2 texture;
	glm::vec3 diffuse;
	glm::vec3 ambient;
	glm::vec3 specular;
  Vertex(glm::vec3 v, glm::vec3 n, glm::vec2 t, glm::vec3 d, glm::vec3 a, glm::vec3 s): vertex(v), normal(n), texture(t), diffuse(d), ambient(a), specular(s) {}
};

#endif /* GRAPHICS_HEADERS_H */
