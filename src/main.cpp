#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/gtc/matrix_transform.hpp"
#include "Paddle.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 800, "Pong", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();


    

    Paddle* paddle = new Paddle(GLFW_KEY_W, GLFW_KEY_S);

    glm::mat4 proj = glm::ortho(0.0f, 100.0f, 0.0f, 800.0f, -1.0f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        int keyWState = glfwGetKey(window, GLFW_KEY_W);
        int keySState = glfwGetKey(window, GLFW_KEY_S);
        paddle->ReceiveInput(keyWState);
        paddle->ReceiveInput(keySState * -1);

        paddle->OnUpdate(1.0f);
        
    	paddle->OnDraw();
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
