//#pragma once
#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <vector>
#include "Camera.h"
#include "Entities.h"

//-------------------------------------------------------------------------

class Scene	
{ 
public:
    Scene(Camera* cam): camera(cam) { };
	  ~Scene();
    void init();
	  void render(); 
	  void sumaAngle() { if (aux != nullptr) { angle+=2;  aux->setAngle(angle); } }
	  RectangleText* help;
	  void update(GLuint timeElapsed) { for each (Entity* it in objetos) {it->update(timeElapsed); } };
	  
protected:
	Diabolo* aux;
	GlassPot* pot;
	GLdouble angle;
	  Camera* camera;
	  std::vector<Entity*> objetos;
	  bool change = false;
	  RectangleText* rect;

};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

