#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

class Shader {
public:
	unsigned int ID{0};

	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void use() {
		if (ID != 0) {
			glUseProgram(ID);
		}
	}

	void setBool(const std::string& name, bool value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
	}

	void setInt(const std::string& name, int value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void setFloat(const std::string& name, float value) const {
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

	void setVec4f(const std::string& name, float value1, float value2,
		float value3, float value4) const {
		glUniform4f(glGetUniformLocation(ID, name.c_str()), 
			value1, value2, value3, value4);
	}

	void setMatrix4(const std::string& name, const glm::mat4& trans) {
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(trans)); 
	}
};

