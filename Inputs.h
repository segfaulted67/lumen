#pragma once

#include <GLFW/glfw3.h>
#include <cstring>

namespace Lumen {
	class Input {
	public:
		static void Init(GLFWwindow *window);
		static void Update();

		static bool IsKeyDown(int key);
		static bool IsKeyPressed(int key);
		static bool IsKeyRelease(int key);

		static bool IsMouseDown(int button);
		static bool IsMousePressed(int button);
		static bool IsMouseRelease(int button);

		static inline int GetKey() { return m_key; }

		static inline double GetMousePosX() { return m_mouseX; }
		static inline double GetMousePosY() { return m_mouseY; }
		static inline double GetMouseDeltaPosX() { return m_deltaX; }
		static inline double GetMouseDeltaPosY() { return m_deltaY; }

		static inline double GetScrollX() { return m_scrollX; }
		static inline double GetScrollY() { return m_scrollY; }
	private:
		static bool m_currentKeys[GLFW_KEY_LAST + 1];
		static bool m_previousKeys[GLFW_KEY_LAST + 1];

		static bool m_currentButtons[GLFW_MOUSE_BUTTON_LAST + 1];
		static bool m_previousButtons[GLFW_MOUSE_BUTTON_LAST + 1];

		static int m_key;

		static double m_mouseX;
		static double m_mouseY;
		static double m_deltaX;
		static double m_deltaY;

		static double m_scrollX;
		static double m_scrollY;

	private:
		static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
		static void MouseButtonCallback(GLFWwindow *window, int button, int action, int mode);
		static void CursorPosCallback(GLFWwindow *window, double xPos, double yPos);
		static void ScrollCallback(GLFWwindow *window, double offsetX, double offsetY);
	};
}
