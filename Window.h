#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Utils.h"

namespace Lumen {
	class Window {
    public:
		Window(const std::string& title, uint width = 1280, uint height = 720);
		~Window();

        static int Init();
		static void WindowHint(int hint, int value);
		void SwapBuffers() const;
		void SwapInterval(bool enabled = true) const;
		void SetVsync(bool enabled = true) const;
		void PollEvents() const;

		bool ShouldClose() const;
		GLFWwindow *GetWindow() const;
		uint GetWidth() const;
		uint GetHeight() const;
		float GetTime() const;
		float GetFrameTime();
		float GetFPS() const;
	private:
		static void FrameBufferSizeCallback(GLFWwindow *window, int width, int height);
	private:
		float m_lastTime = 0.0;
		float m_deltaTime = 0.0;
		std::string m_title;
		uint m_width, m_height;
		GLFWwindow *m_window;
	};
}
