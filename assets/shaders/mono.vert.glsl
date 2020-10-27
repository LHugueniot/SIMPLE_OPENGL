#version 330

layout(location = 0) in vec3 vertex_position;
uniform vec3 base_colour;
uniform mat4 MVP;
out vec3 frag_colour;

void main() {
    frag_colour = base_colour;
    gl_Position = MVP * vec4(vertex_position, 1.0);
}