#version 410 core

in vec4  color;
out vec4 frag_color;
in vec2  UV;
uniform sampler2D myTexture;

void main () {
	frag_color = texture( myTexture, UV);
}