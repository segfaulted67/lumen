#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Utils.h"

namespace Lumen {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();


		void AddBuffer(VertexBuffer& vb, const VertexBufferLayout& layout);

		void Bind() const;
		void Unbind() const;
	private:
		uint m_id;
	};
}
