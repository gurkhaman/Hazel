#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>

#include "glad/glad.h"

namespace Hazel
{
	OpenGLContext::OpenGLContext(struct GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!");
	}


	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		auto status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialized Glad!");

		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		HZ_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		HZ_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
