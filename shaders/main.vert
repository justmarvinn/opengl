#version 330
layout(location = 0) in vec3 pos;
out vec4 pass_pos;
void main() 
{
	gl_Position.xyz = pos;
	gl_Position.w = 1.0;
	pass_pos = gl_Position;
}
