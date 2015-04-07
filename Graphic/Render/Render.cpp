#include "Render.h"

#include "RenderErrorChecker.h"
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>


Render::Render(void)
{
//  glEnable(GL_DEPTH_TEST);
//  glDepthFunc(GL_LESS);

//  glEnable(GL_CULL_FACE);
//  glCullFace(GL_BACK);

  RenderCheckErrors();

  glClearDepth( 1.0f );              // Разрешить очистку буфера глубины
  glEnable( GL_DEPTH_TEST );            // Разрешить тест глубины
  glDepthFunc( GL_LEQUAL );            // Тип теста глубины

  RenderCheckErrors();
}


Render::~Render(void)
{
}

void perspective(GLdouble fovY,  GLdouble aspect,  GLdouble zNear,  GLdouble zFar)
{
  const GLdouble PI = 3.1415926535897932384626433832795;

  GLdouble fW, fH;

  fH = tan(fovY / 180.0 * PI) * zNear / 2.0;

  fW = fH * aspect;

  glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}

void Render::Initialize()
{
  glewExperimental = true; // Needed in core profile

  GLenum error = glewInit();
  if(error != GLEW_OK)
  {
    printf("glew error: %s\n", glewGetErrorString(error));
    throw new RenderException(RenderException::RENDER_NOT_INITIALIZED);
  }
  glGetError();

  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);            // Выбор матрицы проекций
  glLoadIdentity();              // Сброс матрицы проекции

  // Вычисление соотношения геометрических размеров для окна
  perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);            // Выбор матрицы вида модели
  glLoadIdentity();              // Сброс матрицы вида модели

  glGetError();
}

void Render::Draw(const PCamera &)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.6f, 0.0f);
  glLoadIdentity();

  glTranslatef(-1.5f, 0.0f, -6.0f);
  //glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f, 1.0f, 0.0f);  // Вверх
    glVertex3f(-1.0f,-1.0f, 0.0f);  // Слева снизу
    glVertex3f( 1.0f,-1.0f, 0.0f);  // Справа снизу
  glEnd();

  glGetError();
}

void Render::DrawModel(const PCamera &camera, const PModel &model, const glm::vec3 &position, const glm::vec3 &)
{
  // Вычисляем матрицу модели, добавляем модель в список на рисование.

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.6f, 0.0f);
  glLoadIdentity();

  GLuint MatrixID = model->GetShader()->GetUniformLocation("MVP");

  glm::mat4 modelMatrix(1.0f);
  modelMatrix = glm::translate(modelMatrix, position);
//   modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
//   modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
//   modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

  glm::mat4 MVP = camera->GetProject() * camera->GetView() * modelMatrix;

  model->GetShader()->Use();
  model->GetMaterial()->Use(model->GetShader());
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
  model->GetMesh()->Use();
}










