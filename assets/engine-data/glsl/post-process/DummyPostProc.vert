#version 460 core

out vec2 quad_uv;

// big triangle trick
void main()
{
	float x = -1.0 + float((gl_VertexID & 1) << 2);
	float y = -1.0 + float((gl_VertexID & 2) << 1);
	quad_uv.x = (x+1.0)*0.5;
	quad_uv.y = (y+1.0)*0.5;
	gl_Position = vec4(x, y, 0, 1);
}