#include "Window.h"


namespace Lumen {
    Window::Window(const std::string& title, uint width, uint height)
		: m_title(title), m_height(height), m_width(width)
    {
        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
		if (!m_window) {
            std::cerr << "Failed to Create Window\n";
            return;
		}
		glfwSetWindowUserPointer(m_window, this);


        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
            return;
        }

		glfwSetFramebufferSizeCallback(m_window, FrameBufferSizeCallback);
    }

    Window::~Window()
    {
		// if (m_window)	glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    int Window::Init()
    {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW\n";
            return 1;
        }
        return 0;
    }

	void Window::WindowHint(int hint, int value)
	{
		glfwWindowHint(hint, value);
	}

    void Window::SwapBuffers() const
    {
        glfwSwapBuffers(m_window);
    }

	void Window::SwapInterval(bool enabled) const
	{
		GLCall(glfwSwapInterval(enabled ? 1 : 0));
	}

	void Window::SetVsync(bool enabled) const
	{
		GLCall(glfwSwapInterval(enabled ? 1 : 0));
	}

    void Window::PollEvents() const
    {
        glfwPollEvents();
    }

    bool Window::ShouldClose() const
    {
        if (glfwWindowShouldClose(m_window)) return true;
        return false;
    }

    GLFWwindow *Window::GetWindow() const
    {
        return m_window;
    }

    uint Window::GetWidth() const
    {
        return m_width;
    }

    uint Window::GetHeight() const
    {
        return m_height;
    }

	float Window::GetTime() const
	{
		return (float)glfwGetTime();
	}

	float Window::GetFrameTime()
	{
		float currentTime = GetTime();
		m_deltaTime = currentTime - m_lastTime;
		m_lastTime = currentTime;
		return m_deltaTime;
	}

	float Window::GetFPS() const
	{
		return 1.0 / m_deltaTime;
	}

	void Window::FrameBufferSizeCallback(GLFWwindow *window, int width, int height)
	{
		(void) window;
        GLCall(glViewport(0, 0, width, height));

		Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		if(win) {
			win->m_width = width;
			win->m_height = height;
		}
	}
}
