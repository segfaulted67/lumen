#include "IndexBuffer.h"

namespace Lumen {
	IndexBuffer::IndexBuffer(const void *data, uint size, GLenum usage) : m_size(size)
	{
		GLCall(glGenBuffers(1, &m_id));
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage));
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	IndexBuffer::~IndexBuffer()
	{
		GLCall(glDeleteBuffers(1, &m_id));
	}

	uint IndexBuffer::getSize() const
	{
		return m_size;
	}

	void IndexBuffer::Bind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
	}

	void IndexBuffer::Unbind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}
