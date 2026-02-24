#pragma once

#include "Math.h"

namespace Lumen {
	enum class ProjectionType {
		PERSPECTIVE,
		ORTHOGONAL,
	};
	class Camera {
	public:
		Camera(const float fov, const float aspect, const float z_near, const float z_far);
		Camera(const float left, const float right, const float top, const float bottom,
			   const float z_near, const float z_far);

		void SetPosition(const cx::Vec3& position = cx::Vec3::zero());
		const cx::Vec3 GetPosition() const;
		void Move(const cx::Vec3& delta);

		void SetRotation(const cx::Quat& rotation = cx::Quat::identity());
		const cx::Quat& GetRotation() const;
		void Rotate(const cx::Vec3& axis, float angle);

        inline cx::Vec3 GetForward() const { return m_rotation.rotate(cx::Vec3(0, 0, -1)).normalize(); }
        inline cx::Vec3 GetRight() const { return m_rotation.rotate(cx::Vec3(1, 0, 0)).normalize(); }
        inline cx::Vec3 GetUp() const { return m_rotation.rotate(cx::Vec3(0, 1, 0)).normalize(); }

		const cx::Mat4& GetViewMatrix() const;
		void SetProjectionMatrix(const float fov, const float aspect, const float z_near, const float z_far);
		void SetProjectionMatrix(const float left, const float right, const float bottom, const float top,
			   					 const float z_near, const float z_far);
		const cx::Mat4& GetProjectionMatrix() const;
		ProjectionType GetProjectionType() const { return m_projectionType; }
		void SetFOV(const float fov);
		void SetAspect(const float aspect);
		const cx::Mat4 GetViewProjectionMatrix() const;
	private:
		float m_fov, m_aspect, m_znear, m_zfar;
		float m_left, m_right, m_top, m_bottom;
		ProjectionType m_projectionType;
		cx::Vec3 m_position;
		cx::Quat m_rotation;
		mutable cx::Mat4 m_projection;
		mutable cx::Mat4 m_view;
		mutable bool m_projDirty = true;
		mutable bool m_viewDirty = true;
	private:
		void RecalculateViewMatrix() const;
		void RecalculateProjectionMatrix() const;
	};
}
