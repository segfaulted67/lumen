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

	void VertexArray::AddBuffer(const std::shared_ptr<VertexBuffer>& vb, const VertexBufferLayout& layout)
	{
		Bind();
		vb->Bind();

		const auto& elements = layout.GetElements();
		uint offset = 0;

		for (uint i = 0; i < elements.size(); i++) {
			const auto& element = elements[i];
			GLCall(glEnableVertexAttribArray(i));
			GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)(size_t)offset));
			offset += element.count * VertexBufferLayoutElement::GetSizeOfType(element.type);
		}
	}

	void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		m_vertexBuffer.push_back(vertexBuffer);
	}

	void VertexArray::AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		m_indexBuffer = indexBuffer;
	}

	const std::vector<std::shared_ptr<VertexBuffer>>& VertexArray::GetVertexBuffers() const
	{
		return m_vertexBuffer;
	}

	const std::shared_ptr<IndexBuffer>& VertexArray::GetIndexBuffer() const
	{
		return m_indexBuffer;
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
