#pragma once

#include "types.h"
#include "Utils.h"
#include "external/stb_image.h"

namespace Lumen {
	class Texture {
	public:
		Texture(const std::string& path);
		~Texture();

		void Bind(uint slot = 0) const;
		void Unbind() const;

		inline int GetWidth() const;
		inline int GetHeight() const;
	private:
		uint m_id;
		std::string m_filePath;
		unsigned char *m_localBuffer;
		int m_width, m_height, m_BPP;
	};
}
