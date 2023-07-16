#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 texCoord;
uniform mat4 scale;
uniform mat4 translate;

void main() {
  // first do scaling operations, then rotations and lastly translations
  gl_Position = translate * scale * vec4(aPos, 1.0f);
  texCoord = aTexCoord;
}