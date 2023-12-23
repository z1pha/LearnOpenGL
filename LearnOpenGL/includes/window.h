#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <string>

unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window {
	GLFWwindow* window;
	std::string windowTitle = "UNDEFINED";
	

public:
	Window() {
		// glfw: initialize and configure
		// ------------------------------
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		// glfw window creation
		// --------------------
		this->window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, this->windowTitle.c_str(), NULL, NULL);
		if (window == NULL) {
			std::cout << "Failed to create GLFW window" << std::endl;
			throw - 1;
		}
		glfwMakeContextCurrent(this->window);
		glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
	}

	// process all input: query GLFW whether relevant keys are pressed/released this frame and 
	// react acoordingly
	// ---------------------------------------------------------------------------------------
	void processInput() {
		if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(this->window, true);
		}
	}

	void swapAndPoll() {
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}

	bool shouldClose() {
		return glfwWindowShouldClose(this->window);
	}
};

// glfw: whenever the window size chaged (by OS or user resize) this callback function executes
// --------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// make sure the viewport matches the new window dimension; note that width
	// and height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}