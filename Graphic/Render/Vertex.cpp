#include "Vertex.h"




Vertex::Vertex()
{

}

Vertex::Vertex(const glm::vec3 &p, const glm::vec2 &t, const glm::vec4 &c)
  : position(p), texcoord(t), color(c)
{

}
