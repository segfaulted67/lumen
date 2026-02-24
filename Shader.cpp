#include "Shader.h"

#include <glad/glad.h>

namespace Lumen {
	Shader::Shader(const std::string& vert, const std::string& frag)
	{
		std::string vertSource = readShaderSource(vert);
		std::string fragSource = readShaderSource(frag);

		const char* vertexSrc = vertSource.c_str();
		const char* fragmentSrc = fragSource.c_str();

		int success;
		char infoLog[512];

		uint vertex = GLCall(glCreateShader(GL_VERTEX_SHADER));
		uint fragment = GLCall(glCreateShader(GL_FRAGMENT_SHADER));

		GLCall(glShaderSource(vertex, 1, &vertexSrc, NULL));
		GLCall(glCompileShader(vertex));

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		GLCall(glShaderSource(fragment, 1, &fragmentSrc, NULL));
		GLCall(glCompileShader(fragment));

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		m_id = GLCall(glCreateProgram());
		GLCall(glAttachShader(m_id, vertex));
		GLCall(glAttachShader(m_id, fragment));
		GLCall(glLinkProgram(m_id));

		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_id, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		GLCall(glDeleteShader(vertex));
		GLCall(glDeleteShader(fragment));
	}

	Shader::~Shader()
	{
		GLCall(glDeleteProgram(m_id));
	}

	void Shader::Bind() const
	{
		GLCall(glUseProgram(m_id));
	}

	void Shader::Unbind() const
	{
		GLCall(glUseProgram(0));
	}

	void Shader::SetUniform1f(const std::string& name, const float v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform1f(loc, v1));
	}

	void Shader::SetUniform2f(const std::string& name, const float v1, const float v2)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform2f(loc, v1, v2));
	}

	void Shader::SetUniform3f(const std::string& name, const float v1, const float v2, const float v3)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform3f(loc, v1, v2, v3));
	}

	void Shader::SetUniform4f(const std::string& name, const float v1, const float v2, const float v3, const float v4)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform4f(loc, v1, v2, v3, v4));
	}

	void Shader::SetUniform1i(const std::string& name, const int v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform1i(loc, v1));
	}

	void Shader::SetUniform2i(const std::string& name, const int v1, const int v2)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform2i(loc, v1, v2));
	}

	void Shader::SetUniform3i(const std::string& name, const int v1, const int v2, const int v3)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform3i(loc, v1, v2, v3));
	}

	void Shader::SetUniform4i(const std::string& name, const int v1, const int v2, const int v3, const int v4)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform4i(loc, v1, v2, v3, v4));
	}

	void Shader::SetUniform1ui(const std::string& name, const uint v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform1ui(loc, v1));
	}

	void Shader::SetUniform2ui(const std::string& name, const uint v1, const uint v2)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform2ui(loc, v1, v2));
	}

	void Shader::SetUniform3ui(const std::string& name, const uint v1, const uint v2, const uint v3)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform3ui(loc, v1, v2, v3));
	}

	void Shader::SetUniform4ui(const std::string& name, const uint v1, const uint v2, const uint v3, const uint v4)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform4ui(loc, v1, v2, v3, v4));
	}

	void Shader::SetUniformVec2(const std::string& name, const cx::Vec2& v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform2fv(loc, 1, v1.data()));
	}

	void Shader::SetUniformVec3(const std::string& name, const cx::Vec3& v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform3fv(loc, 1, v1.data()));
	}

	void Shader::SetUniformVec4(const std::string& name, const cx::Vec4& v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniform4fv(loc, 1, v1.data()));
	}

	void Shader::SetUniformMat2(const std::string& name, const cx::Mat2& v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniformMatrix2fv(loc, 1, GL_TRUE, v1.data()));
	}

	void Shader::SetUniformMat3(const std::string& name, const cx::Mat3& v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniformMatrix3fv(loc, 1, GL_TRUE, v1.data()));
	}

	void Shader::SetUniformMat4(const std::string& name, const cx::Mat4& v1)
	{
		int loc = getUniformLocation(name);
		GLCall(glUniformMatrix4fv(loc, 1, GL_TRUE, v1.data()));
	}

	std::string Shader::readShaderSource(const std::string& filePath)
	{
		std::ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Failed to open shader file: " << filePath << std::endl;
			return "";
		}

		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}

	int Shader::getUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
			return m_UniformLocationCache[name];
		}

		int loc = GLCall(glGetUniformLocation(m_id, name.c_str()));
		if (loc == -1) {
			std::cout << "Warning: Uniform '" << name << "' not found." << std::endl;
		}
		m_UniformLocationCache[name] = loc;

		return loc;
	}
}
