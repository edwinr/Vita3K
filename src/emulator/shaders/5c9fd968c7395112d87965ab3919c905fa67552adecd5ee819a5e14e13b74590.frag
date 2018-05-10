// https://github.com/Rinnegatamante/vitaQuake/blob/master/shaders/modulate_rgba_alpha_fog_f.cg
#version 410

uniform sampler2D tex;
in vec4 vColor;
in vec2 vTexcoord;
in float vFog;
out vec4 fragColor;

void main()
{
    vec4 c = texture(tex, vTexcoord) * vColor;
    c.rgb = c.rgb * vFog;
    if (c.a > 0.666) fragColor = c;
    else discard;
}
