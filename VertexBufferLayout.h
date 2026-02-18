#pragma once
#include <vector>
#include <glad/glad.h>
#include "types.h"

namespace Lumen {

    struct VertexBufferLayoutElement {
        uint type;
        uint count;
        unsigned char normalized; // Use unsigned char for GL_TRUE/GL_FALSE

        static uint GetSizeOfType(uint type) {
            switch(type) {
                case GL_FLOAT:         return 4;
                case GL_UNSIGNED_INT:  return 4;
                case GL_UNSIGNED_BYTE: return 1;
            }
            return 0;
        }
    };

    class VertexBufferLayout {
    public:
        VertexBufferLayout() : m_stride(0) {}

        template<typename T>
        void Push(uint count) { }

        inline const std::vector<VertexBufferLayoutElement>& GetElements() const { return m_elements; }
        inline uint GetStride() const { return m_stride; }
	private:
		std::vector<VertexBufferLayoutElement> m_elements;
		uint m_stride;
    };

    template<>
    inline void VertexBufferLayout::Push<float>(uint count) {
        m_elements.push_back({ GL_FLOAT, count, GL_FALSE });
        m_stride += count * VertexBufferLayoutElement::GetSizeOfType(GL_FLOAT);
    }

    template<>
    inline void VertexBufferLayout::Push<uint>(uint count) {
        m_elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
        m_stride += count * VertexBufferLayoutElement::GetSizeOfType(GL_UNSIGNED_INT);
    }

    template<>
    inline void VertexBufferLayout::Push<unsigned char>(uint count) {
        m_elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
        m_stride += count * VertexBufferLayoutElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }
}
