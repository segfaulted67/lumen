#pragma once

#include <iostream>
#include <string>
#include <glad/glad.h>

#ifdef LUMEN_DEBUG

#ifndef DEBUG_BREAK
#	ifdef _MSC_VER
#		define DEBUG_BREAK	__debugbreak()
#	elif defined(__GNUC__) || defined(__clang)
#		define DEBUG_BREAK	__builtin_trap()
#	else
#		define DEBUG_BREAK	abort()
#	endif
#endif

#define ASSERT(x)	if (!(x))	DEBUG_BREAK
#define GLCall(x)	\
	GLClearError();	\
	x;				\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define GLCall(x)	(x)
#endif


inline void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogCall(const char *function, const char *file, const int line)
{
	GLenum error;
	while ((error = glGetError()) != GL_NO_ERROR) {
		std::cerr << "[OpenGl Error] " << function << "{" << error << "}: " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}
