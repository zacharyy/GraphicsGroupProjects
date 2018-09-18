#include "object.h"

Object::Object()
{  
  /*
    # Blender File for a Cube
    o Cube
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000
    s off
    f 2 3 4
    f 8 7 6
    f 1 5 6
    f 2 6 7
    f 7 8 4
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 2 1 6
    f 3 2 7
    f 3 7 4
    f 5 1 8
  */

  Vertices = {
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
  };

  Indices = {
    2, 3, 4,
    8, 7, 6,
    1, 5, 6,
    2, 6, 7,
    7, 8, 4,
    1, 4, 8,
    1, 2, 4,
    5, 8, 6,
    2, 1, 6,
    3, 2, 7,
    3, 7, 4,
    5, 1, 8
  };

  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

  //angle = 0.0f;
  spin_angle = 0.0f;
  rev_angle = 0.0f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::PlanetUpdate(unsigned int dt, bool pspin_reverse, bool pspin_stop, bool prevolution_reverse, bool prevolution_stop)
{
  //check if planet spin false, if its true we do nothing to spin angle
  if(pspin_stop == false)
  {
    //if planet reverse spin is falles we add to the spin angle
    if(pspin_reverse == false)
    {
      spin_angle += dt * M_PI/2000;
    }
    //if false we subtract from the spin angle 
    else if(pspin_reverse == true)
    {
      spin_angle -= dt * M_PI/2000; 
    }
  }
  //check if planet revolution false, if its true we do nothing to revolution angle
  if(prevolution_stop == false)
  {
    //if planet reverse revolution is falles we add to the revolution angle
    if(prevolution_reverse == false)
    {
      rev_angle += dt * M_PI/2000;
    }
    //if false we subtract from the revolution angle 
    else if(prevolution_reverse == true)
    {
      rev_angle -= dt * M_PI/2000;
    }
  }

  //set to rotate on y-axis with speed based on rev_angle
  //glm::mat4 revolution_matrix = glm::rotate(glm::mat4(1.0f), (rev_angle), glm::vec3(0.0, 1.0, 0.0));
  
  //place cube 8 out from x-axis (desired effect can also be achieved by placing 8 out from z-axis)
  //glm::mat4 translate_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(8.0, 0.0, 0.0));

  //set to rotate on y-axis with speed based on spin_angle
  //glm::mat4 spin_matrix = glm::rotate(glm::mat4(1.0f), (spin_angle), glm::vec3(0.0, 1.0, 0.0));

  //first concatenate the revolution and tranlation matrix, this will cause the cube to orbit
  //then concatenate the result with the spin matrix, this will cause the cube to spin
  //model = revolution_matrix * translate_matrix;
  //model *= spin_matrix;

  //tranlate planet based on revolution angle 
  model = glm::translate( glm::mat4(1.0f),glm::vec3(6.0*sin(rev_angle), 0.0, 6.0*cos(rev_angle)));
  //rotate planet based on spin angle 
  model = glm::rotate( model, (spin_angle*2), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Object::UpdateMoon(unsigned int dt, glm::mat4 parent_model, 
                        bool& mspin_reverse, bool& mspin_stop, 
                        bool& mrevolution_reverse, bool& mrevolution_stop)
{
  //spin_angle += dt * M_PI/1000;
 // rev_angle += dt * M_PI/2000;
  //check if planet spin false, if its true we do nothing to spin angle
  if(mspin_stop == false)
  {
    //if planet reverse spin is falles we add to the spin angle
    if(mspin_reverse == false)
    {
      spin_angle += dt * M_PI/1000;
    }
    //if false we subtract from the spin angle 
    else if(mspin_reverse == true)
    {
      spin_angle -= dt * M_PI/1000; 
    }
  }
  //check if planet revolution false, if its true we do nothing to revolution angle
  if(mrevolution_stop == false)
  {
    //if planet reverse revolution is falles we add to the revolution angle
    if(mrevolution_reverse == false)
    {
      rev_angle += dt * M_PI/1500;
    }
    //if false we subtract from the revolution angle 
    else if(mrevolution_reverse == true)
    {
      rev_angle -= dt * M_PI/1500;
    }
  }
  model = glm::translate( parent_model,glm::vec3(4.0*sin(rev_angle), 0.0, 4.0*cos(rev_angle)));
  model = glm::rotate( model, (spin_angle*2), glm::vec3(0.0f, 1.0f, 0.0f));
  model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

