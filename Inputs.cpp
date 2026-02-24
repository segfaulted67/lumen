#include "Inputs.h"

namespace Lumen {
	bool Input::m_currentKeys[GLFW_KEY_LAST + 1] = { };
	bool Input::m_previousKeys[GLFW_KEY_LAST + 1] = { };

	bool Input::m_currentButtons[GLFW_MOUSE_BUTTON_LAST + 1] = { };
	bool Input::m_previousButtons[GLFW_MOUSE_BUTTON_LAST + 1] = { };

	int Input::m_key = 0;

	double Input::m_mouseX = 0.0;
	double Input::m_mouseY = 0.0;
	double Input::m_deltaX = 0.0;
	double Input::m_deltaY = 0.0;

	double Input::m_scrollX = 0.0;
	double Input::m_scrollY = 0.0;

	void Input::Init(GLFWwindow *window)
	{
		glfwSetKeyCallback(window, KeyCallback);
		glfwSetMouseButtonCallback(window, MouseButtonCallback);
		glfwSetCursorPosCallback(window, CursorPosCallback);
		glfwSetScrollCallback(window, ScrollCallback);
	}

	void Input::Update()
	{
		memcpy(m_previousKeys, m_currentKeys, sizeof(m_currentKeys));
		memcpy(m_previousButtons, m_currentButtons, sizeof(m_currentButtons));

		m_scrollX = 0.0;
		m_scrollY = 0.0;

		m_deltaX = 0.0;
		m_deltaY = 0.0;
	}

	bool Input::IsKeyDown(int key)
	{
		return m_currentKeys[key];
	}

	bool Input::IsKeyPressed(int key)
	{
		return m_currentKeys[key] && !m_previousKeys[key];
	}

	bool Input::IsKeyRelease(int key)
	{
		return !m_currentKeys[key] && m_previousKeys[key];
	}

	bool Input::IsMouseDown(int button)
	{
		return m_currentButtons[button];
	}

	bool Input::IsMousePressed(int button)
	{
		return m_currentButtons[button] && !m_previousButtons[button];
	}

	bool Input::IsMouseRelease(int button)
	{
		return !m_currentButtons[button] && m_previousButtons[button];
	}

	void Input::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
	{
		m_key = key;
		if (key < 0 || key > GLFW_KEY_LAST) {
			return;
		}

		if (action == GLFW_PRESS) {
			m_currentKeys[key] = true;
		}
		else if (action == GLFW_RELEASE) {
			m_currentKeys[key] = false;
		}
	}

	void Input::MouseButtonCallback(GLFWwindow *window, int button, int action, int mode)
	{
		if (button < 0 || button > GLFW_MOUSE_BUTTON_LAST) {
			return;
		}

		if (action == GLFW_PRESS) {
			m_currentButtons[button] = true;
		}
		else if (action == GLFW_RELEASE) {
			m_currentButtons[button] = false;
		}
	}

	void Input::CursorPosCallback(GLFWwindow *window, double xPos, double yPos)
	{
		m_deltaX += xPos - m_mouseX;
		m_deltaY += yPos - m_mouseY;

		m_mouseX = xPos;
		m_mouseY = yPos;
	}

	void Input::ScrollCallback(GLFWwindow *window, double offsetX, double offsetY)
	{
		m_scrollX += offsetX;
		m_scrollY += offsetY;
	}
}
