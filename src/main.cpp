#include <memory>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "PongConfig.h"

#include "Pong.h"



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    // Size should be variable, hard coded so far
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();

    std::unique_ptr<Pong> pong = std::make_unique<Pong>();


    double lastTimeStamp = glfwGetTime();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        double currentTimeStamp = glfwGetTime();
        double deltaTime = currentTimeStamp - lastTimeStamp;
        glClear(GL_COLOR_BUFFER_BIT);

        pong->OnUpdate(deltaTime, window);


        pong->OnRender();

    	lastTimeStamp = currentTimeStamp;
        /* Swap front and back buffers */
    	glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
