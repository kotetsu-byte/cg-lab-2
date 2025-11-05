#version 410 core
out vec4 frag_color;
uniform float timeValue;
void main() {
    float r = abs(sin(timeValue));
    float g = abs(sin(timeValue + 2.0));
    float b = abs(sin(timeValue + 4.0));
    frag_color = vec4(r, g, b, 1.0);
}