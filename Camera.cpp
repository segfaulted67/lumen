#include "Camera.h"

namespace Lumen {
	Camera::Camera(const float fov, const float aspect, const float z_near, const float z_far)
		: m_fov(fov), m_aspect(aspect), m_znear(z_near), m_zfar(z_far),
		m_position(cx::Vec3::zero()), m_rotation(cx::Quat::identity()),
		m_view(cx::Mat4::zero())
	{
		m_projectionType = ProjectionType::PERSPECTIVE;
		m_projection = cx::Mat4::perspectiveRH_NO(m_fov, m_aspect, m_znear, m_zfar);
		m_projDirty = true;
	}

	Camera::Camera(const float left, const float right, const float top, const float bottom,
			const float z_near, const float z_far)
		: m_left(left), m_right(right), m_top(top), m_bottom(bottom), m_znear(z_near), m_zfar(z_far),
		m_position(cx::Vec3::zero()), m_rotation(cx::Quat::identity()),
		m_view(cx::Mat4::zero())
	{
		m_projectionType = ProjectionType::ORTHOGONAL;
		m_projection = cx::Mat4::orthogonalRH_NO(m_left, m_right, m_top, m_bottom, m_znear, m_zfar);
		m_projDirty = true;
	}

	void Camera::SetPosition(const cx::Vec3& position)
	{
		m_viewDirty = true;
		m_position = position;
	}

	const cx::Vec3 Camera::GetPosition() const
	{
		return m_position;
	}

	void Camera::Move(const cx::Vec3& delta)
	{
		m_viewDirty = true;
    	m_position += m_rotation.rotate(delta);
	}

	void Camera::SetRotation(const cx::Quat& rotation)
	{
		m_viewDirty = true;
		m_rotation = rotation.normalize();
	}

	const cx::Quat& Camera::GetRotation() const
	{
		m_viewDirty = true;
		return m_rotation;
	}

	void Camera::Rotate(const cx::Vec3& axis, float angle)
	{
		m_viewDirty = true;
		m_rotation = cx::Quat::fromAxisAngle(axis, angle) * m_rotation;
		m_rotation = m_rotation.normalize();
	}

	const cx::Mat4& Camera::GetViewMatrix() const
	{
		if (m_viewDirty) {
			RecalculateViewMatrix();
			m_viewDirty = false;
		}
		return m_view;
	}

	void Camera::SetProjectionMatrix(const float fov, const float aspect, const float z_near, const float z_far)
	{
		m_fov = fov;
		m_aspect = aspect;
		m_znear = z_near;
		m_zfar = z_far;
		m_projection = cx::Mat4::perspectiveRH_NO(fov, aspect, z_near, z_far);
	}

	void Camera::SetProjectionMatrix(const float left, const float right, const float bottom, const float top,
								const float z_near, const float z_far)
	{
		m_left = left;
		m_right = right;
		m_bottom = bottom;
		m_top = top;
		m_znear = z_near;
		m_zfar = z_far;
		m_projection = cx::Mat4::orthogonalRH_NO(left, right, bottom, top, z_near, z_far);
	}

	void Camera::SetFOV(const float fov)
	{
		m_fov = fov;
		m_projDirty = true;
	}

	void Camera::SetAspect(const float aspect)
	{
		m_aspect = aspect;
		m_projDirty = true;
	}

	const cx::Mat4& Camera::GetProjectionMatrix() const
	{
		if (m_projDirty) {
			RecalculateProjectionMatrix();
			m_projDirty = false;
		}
		return m_projection;
	}

	const cx::Mat4 Camera::GetViewProjectionMatrix() const
	{
		return GetProjectionMatrix() * GetViewMatrix();
	}

	void Camera::RecalculateViewMatrix() const
	{
		m_view = cx::Mat4::fromQuat(m_rotation.conjugate().normalize()) * cx::Mat4::translation(-m_position.x(),
																								-m_position.y(),
																								-m_position.z());
	}

	void Camera::RecalculateProjectionMatrix() const
	{
		if (m_projectionType == ProjectionType::PERSPECTIVE) {
			m_projection = cx::Mat4::perspectiveRH_NO(m_fov, m_aspect, m_znear, m_zfar);
		}
		else {
			m_projection = cx::Mat4::orthogonalRH_NO(m_left, m_right, m_top, m_bottom, m_znear, m_zfar);
		}
	}
}
