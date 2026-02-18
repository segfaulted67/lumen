#include "VertexBuffer.h"

namespace Lumen {
	VertexBuffer::VertexBuffer(const void *data, uint size, GLenum usage)
	{
		GLCall(glGenBuffers(1, &m_id));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
		GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, usage));
	}

	VertexBuffer::~VertexBuffer()
	{
		GLCall(glDeleteBuffers(1, &m_id));
	}

	void VertexBuffer::Bind() const
	{
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
	}

	void VertexBuffer::Unbind() const
	{
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}
