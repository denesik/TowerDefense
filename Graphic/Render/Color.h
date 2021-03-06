#pragma once

#ifndef Color_h__
#define Color_h__

#include <glm/glm.hpp>

struct Color
{
public:
  Color();

  Color(const glm::uvec4 &color);

  Color(glm::u8 r, glm::u8 g, glm::u8 b, glm::u8 a);

  glm::vec4 Tof32Color() const;

public:
  glm::uvec4 raw;

public:
  const static Color black;
  const static Color white;
  const static Color red;
  const static Color green;
  const static Color blue;
};



#endif // Color_h__
