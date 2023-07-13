#pragma once
#include <string>
#include "GL/glew.h"

class Shader
{
private:
	unsigned int m_Id = 0;
public:
	Shader(const std::string &vsPath, const std::string &fsPath);
	~Shader();

	void Bind();
	void Unbind();
	

private:
	void CreateShader(const std::string &vsSource, const std::string &fsSource);
	unsigned int CompileShader(const unsigned int type, const std::string& shaderSource);
	std::string ReadShaderSource(const std::string &filepath) const;
	

};
