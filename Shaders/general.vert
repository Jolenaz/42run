#version 410 core

layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec2 vertex_textur;
layout(location = 2) in vec3 vertex_normal;

uniform mat4 VP;
uniform mat4 models[64];

out vec4 color;
out vec2 UV;

void main () {
	color = vec4(1,1,1,1);
	UV = vertex_textur;
	gl_Position = VP* models[ gl_InstanceID ] * vec4(vertex_pos, 1.0);
}
