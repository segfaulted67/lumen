#include "Window.h"


namespace Lumen {
    Window::Window(const std::string& title, uint width, uint height) : m_title(title), m_height(height), m_width(width)
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

    void Window::PollEvents() const
    {
        glfwPollEvents();
    }

    bool Window::ShouldClose() const
    {
        if (glfwWindowShouldClose(m_window)) return true;
        return false;
    }

    GLFWwindow *Window::getGLFWwindow() const
    {
        return m_window;
    }

    uint Window::getWidth() const
    {
        return m_width;
    }

    uint Window::getHeight() const
    {
        return m_height;
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
