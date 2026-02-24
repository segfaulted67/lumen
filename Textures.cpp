#include "Textures.h"

namespace Lumen {
	Texture::Texture(const std::string& path)
		: m_id(0), m_filePath(path), m_localBuffer(nullptr), m_width(0), m_height(0), m_BPP(0)
	{
		stbi_set_flip_vertically_on_load(1);
		m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

		GLCall(glGenTextures(1, &m_id));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_id));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		if (m_localBuffer) {
			stbi_image_free(m_localBuffer);
		}
	}

	Texture::~Texture()
	{
		GLCall(glDeleteTextures(1, &m_id));
	}

	void Texture::Bind(uint slot) const
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_id));
	}

	void Texture::Unbind() const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}

	inline int Texture::GetWidth() const
	{
		return m_width;
	}

	inline int Texture::GetHeight() const
	{
		return m_height;
	}
}
