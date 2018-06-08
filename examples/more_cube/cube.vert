#version 450

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 aColor;

out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	color = aColor;
	gl_Position = projection * view * model * vec4(vertex_position, 1.0f);
}
