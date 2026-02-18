#pragma once

#include <fstream>
#include <unordered_map>
#include <sstream>
#include "types.h"
#include "Utils.h"

#include "Math.h"

namespace Lumen {
	class Shader {
	public:
		Shader(const std::string& vert, const std::string& frag);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void setUniformFloat(const std::string& name, const float v1);
		void setUniformFloat(const std::string& name, const float v1, const float v2);
		void setUniformFloat(const std::string& name, const float v1, const float v2, const float v3);
		void setUniformFloat(const std::string& name, const float v1, const float v2, const float v3, const float v4);

		void setUniformInt(const std::string& name, const int v1);
		void setUniformInt(const std::string& name, const int v1, const int v2);
		void setUniformInt(const std::string& name, const int v1, const int v2, const int v3);
		void setUniformInt(const std::string& name, const int v1, const int v2, const int v3, const int v4);

		void setUniformUInt(const std::string& name, const uint v1);
		void setUniformUInt(const std::string& name, const uint v1, const uint v2);
		void setUniformUInt(const std::string& name, const uint v1, const uint v2, const uint v3);
		void setUniformUInt(const std::string& name, const uint v1, const uint v2, const uint v3, const uint v4);

		void setUniformVec2(const std::string& name, const cx::Vec2& v1);
		void setUniformVec3(const std::string& name, const cx::Vec3& v1);
		void setUniformVec4(const std::string& name, const cx::Vec4& v1);

		void setUniformMat2(const std::string& name, const cx::Mat2& v1);
		void setUniformMat3(const std::string& name, const cx::Mat3& v1);
		void setUniformMat4(const std::string& name, const cx::Mat4& v1);
	private:
		uint m_id;
		std::unordered_map<std::string, int> m_UniformLocationCache;

	private:
		std::string readShaderSource(const std::string& filePath);
		uint getUniformLocation(const std::string& name);
	};
}
