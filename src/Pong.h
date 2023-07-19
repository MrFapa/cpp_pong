#pragma once

#include <vector>

class Pong
{
private:
	class Puck* m_Puck;
	class Paddle* m_PaddleLeft;
	class Paddle* m_PaddleRight;
	std::vector<class Paddle*> m_Paddles;

	class Shader* m_Shader;
public:

	Pong();
	~Pong();
	void OnUpdate(double deltaTime, struct GLFWwindow* window);
	void OnRender();
};