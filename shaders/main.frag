#version 330
in vec4 pass_pos;
void main() 
{
	vec2 uv = pass_pos.xy * 0.5 + 0.5;
	gl_FragColor = vec4(uv, 0.0, 1.0);
}
