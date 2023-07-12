#include "GLFW/glfw3.h"

#include "Paddle.h"

#define Max

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

    Paddle* paddle = new Paddle(GLFW_KEY_W, GLFW_KEY_S);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        int keyWState = glfwGetKey(window, GLFW_KEY_W);
        int keySState = glfwGetKey(window, GLFW_KEY_S);
        paddle->ReceiveInput(keyWState);
        paddle->ReceiveInput(keySState * -1);

        paddle->OnUpdate(1.0f);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}