#include "Renderer.h"

namespace Lumen {
	void Renderer::Clear(uint mask)
	{
        GLCall(glClear(mask));
	}

	void Renderer::ClearColor(float red, float green, float blue, float alpha)
	{
		GLCall(glClearColor(red, green, blue, alpha));
	}

	void Renderer::DrawIndexed(const std::shared_ptr<VertexArray>& va, int mode, int type)
	{
		GLCall(glDrawElements(mode, va->GetIndexBuffer()->GetSize(), type, nullptr));
	}
}
