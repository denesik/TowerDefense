#pragma once

#ifndef RenderErrorChecker_h__
#define RenderErrorChecker_h__

#include <GL/glew.h>

template<class T>
void RenderCheckErrors(T &dst)
{
  while(unsigned int openGLError = glGetError())
  {													
    dst << "OGL error " << openGLError << std::endl;
  };
}

void RenderCheckErrors();


#endif // RenderErrorChecker_h__
