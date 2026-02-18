#include "VertexArray.h"

namespace Lumen {
	VertexArray::VertexArray()
	{
		GLCall(glGenVertexArrays(1, &m_id));
		GLCall(glBindVertexArray(m_id));
	}

	VertexArray::~VertexArray()
	{
		GLCall(glDeleteVertexArrays(1, &m_id));
	}

	void VertexArray::AddBuffer(VertexBuffer& vb, const VertexBufferLayout& layout)
	{
		Bind();
		vb.Bind();

		const auto& elements = layout.GetElements();
		uint offset = 0;

		for (uint i = 0; i < elements.size(); i++) {
			const auto& element = elements[i];
			GLCall(glEnableVertexAttribArray(i));
			GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)(size_t)offset));
			offset += element.count * VertexBufferLayoutElement::GetSizeOfType(element.type);
		}
	}

	void VertexArray::Bind() const
	{
		GLCall(glBindVertexArray(m_id));
	}

	void VertexArray::Unbind() const
	{
		GLCall(glBindVertexArray(0));
	}
}
