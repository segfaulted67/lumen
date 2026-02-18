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
		void PollEvents() const;

		bool ShouldClose() const;
		GLFWwindow *getGLFWwindow() const;
		uint getWidth() const;
		uint getHeight() const;
	private:
		static void FrameBufferSizeCallback(GLFWwindow *window, int width, int height);
	private:
		std::string m_title;
		uint m_width, m_height;
		GLFWwindow *m_window;
	};
}
