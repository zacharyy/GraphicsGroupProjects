#include <iostream>

#include "engine.h"


int main(int argc, char **argv)
{
  // Check if user entered input correctly
  if(argc != 2)
  {
    cout << "Error: Incorrect input." << endl;
    cout << "Please enter using following format: ./PA5 <object filename>" << endl;
    return 0;
  }
  //save object file input into string
  string objectFileString = argv[1];

  // Start an engine and run it then cleanup after
  Engine *engine = new Engine("Project 6: Assimp with Textures", 800, 600);
  if(!engine->Initialize(objectFileString))
  {
    printf("The engine failed to start.\n");
    delete engine;
    engine = NULL;
    return 1;
  }
  engine->Run();
  delete engine;
  engine = NULL;
  return 0;
}
