#include "Pong.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Paddle.h"
#include "Puck.h"
#include "Mesh.h"
#include "Shader.h"


Pong::Pong()
{
    // Game Objects
    m_Puck = new Puck();
    m_PaddleLeft = new Paddle(GLFW_KEY_W, GLFW_KEY_S, { 30, 400 });
    m_PaddleRight = new Paddle(GLFW_KEY_UP, GLFW_KEY_DOWN, { 970, 400 });
    m_Paddles = { m_PaddleLeft, m_PaddleRight };

    // Render Objects
	m_Shader = new Shader("assets/shaders/vBase.shader", "assets/shaders/fBase.shader");
}

Pong::~Pong()
{
    delete m_Puck;
    delete m_PaddleLeft;
    delete m_PaddleRight;
    delete m_Shader;
}

void Pong::OnUpdate(double deltaTime, GLFWwindow* window)
{
    for (Paddle* paddle : m_Paddles)
    {
        paddle->ReceiveInput(glfwGetKey(window, paddle->GetKeyUp()));
        // Invert direction
        paddle->ReceiveInput(glfwGetKey(window, paddle->GetKeyDown()) * -1);

        paddle->OnUpdate(deltaTime);
        
    }

    m_Puck->OnUpdate(deltaTime);
    m_Puck->CheckIfScored(m_PaddleLeft, m_PaddleRight);

    if (m_Puck->GetDirection().x < 0)
    {
        m_Puck->CheckPlayerCollision(m_PaddleLeft);
    }
    else
    {
        m_Puck->CheckPlayerCollision(m_PaddleRight);
    }
}

void Pong::OnRender()
{
    // could make constant (should make constant)
    glm::mat4 proj = glm::ortho(0.0f, 1000.0f, 0.0f, 800.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 0.0f),   // Camera position (eye)
        glm::vec3(0.0f, 0.0f, -1.0f),  // Target position (center)
        glm::vec3(0.0f, 1.0f, 0.0f)    // Up vector
    );

    for (Paddle* paddle : m_Paddles)
    {
        glm::mat4 model = paddle->GetModelMatrix();
        m_Shader->SetUniformMat4("u_MVP", proj * view * model);

        Mesh* mesh = paddle->GetMesh();
        mesh->Bind();
        mesh->Draw();
    }

    glm::mat4 model = m_Puck->GetModelMatrix();
    m_Shader->SetUniformMat4("u_MVP", proj * view * model);

    m_Puck->GetMesh()->Bind();
    m_Puck->GetMesh()->Draw();
}
