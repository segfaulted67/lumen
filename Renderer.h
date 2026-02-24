#pragma once

#include <iostream>
#include <glad/glad.h>
#include "VertexArray.h"
#include "Utils.h"

namespace Lumen {
	class Renderer {
	public:
		static void Clear(uint mask = GL_COLOR_BUFFER_BIT);
		static void ClearColor(float red = 0.0, float green = 0.0, float blue = 0.0, float alpha = 1.0);
		static void DrawIndexed(const std::shared_ptr<VertexArray>& va, int mode = GL_TRIANGLES, int type = GL_UNSIGNED_INT);
	};
}
