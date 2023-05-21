#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTex;
					
out vec2 texCoord;
uniform vec2 screenSize;

void main()
{
	gl_Position = vec4(aPos.x * 2 / screenSize.x - 1, aPos.y * 2 / screenSize.y - 1, 1.0, 1.0);
	texCoord = aTex;
}