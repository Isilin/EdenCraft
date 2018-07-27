#version 450

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTextCoord;

out vec3 normal;
out vec3 fragPos;
out vec2 textCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	textCoord = inTextCoord;
	normal = transpose(inverse(mat3(view * model))) * inNormal;
	gl_Position = projection * view * model * vec4(vertex_position, 1.0);
	fragPos = vec3(model * vec4(vertex_position, 1.0));
}
