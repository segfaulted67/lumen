#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Utils.h"
#include <memory>

namespace Lumen {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();


		void AddBuffer(const std::shared_ptr<VertexBuffer>& vb, const VertexBufferLayout& layout);

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
		void AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);
		const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const;
		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const;

		void Bind() const;
		void Unbind() const;
	private:
		uint m_id;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffer;
		std::shared_ptr<IndexBuffer> m_indexBuffer;
	};
}
