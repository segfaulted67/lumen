#pragma once

#include "types.h"
#include <glad/glad.h>
#include "Utils.h"

namespace Lumen {
	class VertexBuffer {
	public:
		VertexBuffer(const void *data, uint size, GLenum usage = GL_STATIC_DRAW);
		~VertexBuffer();

		uint GetSize() const;
		void Bind() const;
		void Unbind() const;
	private:
		uint m_size;
		uint m_id;
	};
}
