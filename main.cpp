#include<iostream>
#include"/usr/include/glad/glad.h"		// glad voor GLFW .. glad declareerd GLFW.
#include "/usr/local/include/GLFW/glfw3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	glfwInit();						// window init
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 		// window instellen op core en niet backwards compatibel.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600,"LearnOpenGL", NULL, NULL); 	// aanmaken windowbuffer.
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))				// init GLAD.. before GLFW.
	{										// GLAD geeft funcionPointers aan het OS
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);							// window size hoogte breedte instellen.



	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// callback if winow changefor changing viewport 

	while(!glfwWindowShouldClose(window))					// loop van window tekenen. anders is het een flits.
		{
			// input
			processInput(window);
			// rendering commands here
			
			glClearColor(0.2f, 0.3f, 0.3f, 1.05);
			glClear(GL_COLOR_BUFFER_BIT);

			// check and call events and swap the buffers
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	glfwTerminate();								//clean up all the resources

	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)		// dit is de callback functie.
		{
			glViewport(0, 0, width, height);
		}

void processInput(GLFWwindow *window)
		{
			if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}

