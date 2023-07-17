#include "Mesh.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/gtc/matrix_transform.hpp"
#include "Paddle.h"
#include "Puck.h"
#include "Shader.h"

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


    Shader shader = Shader("assets/shaders/vBase.shader", "assets/shaders/fBase.shader");
    Paddle* paddleLeft = new Paddle(GLFW_KEY_W, GLFW_KEY_S, {30, 400});
    Paddle* paddleRight = new Paddle(GLFW_KEY_UP, GLFW_KEY_DOWN, {970, 400});
    std::vector<Paddle*> paddles = { paddleLeft, paddleRight };

    glm::mat4 proj = glm::ortho(0.0f, 1000.0f, 0.0f, 800.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 0.0f),   // Camera position (eye)
        glm::vec3(0.0f, 0.0f, -1.0f),  // Target position (center)
        glm::vec3(0.0f, 1.0f, 0.0f)    // Up vector
    );

    Puck* puck = new Puck();

    int playerScoreLeft = 0;
    int playerScoreRight = 0;
    
    double lastTimeStamp = glfwGetTime();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        double currentTimeStamp = glfwGetTime();
        double deltaTime = currentTimeStamp - lastTimeStamp;
        glClear(GL_COLOR_BUFFER_BIT);


        for(Paddle* paddle : paddles)
        {
            paddle->ReceiveInput(glfwGetKey(window, paddle->GetKeyUp()));
            // Invert direction
            paddle->ReceiveInput(glfwGetKey(window, paddle->GetKeyDown()) * -1);

            paddle->OnUpdate(deltaTime);

            glm::mat4 model = paddle->GetModelMatrix();
            shader.SetUniformMat4("u_MVP", proj * view * model);

            Mesh* mesh = paddle->GetMesh();
            mesh->Bind();
            mesh->Draw();
        }

        glm::mat4 model = puck->GetModelMatrix();
        shader.SetUniformMat4("u_MVP", proj * view * model);
        puck->OnUpdate(deltaTime);
        puck->CheckIfScored(paddleLeft, paddleRight);

        if(puck->GetDirection().x < 0)
        {
            puck->CheckPlayerCollision(paddleLeft);
        } else
        {
            puck->CheckPlayerCollision(paddleRight);
        }
        puck->GetMesh()->Bind();
        puck->GetMesh()->Draw();
       

        lastTimeStamp = currentTimeStamp;
        /* Swap front and back buffers */
    	glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
