#version 330 core

in vec3 pos;

out vec4 FragColor;

uniform ivec2 screenSize;
/* uniform int octaves; */

float map(float value, float min1, float max1, float min2, float max2)
{
    return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

vec2 hash(vec2 p)
{
    p  = 50.0*fract( p*0.3183099 + vec2(0.71,0.113));
    return p;
    /* return -1.0+2.0*fract( p.x*p.y*(p.x+p.y) ); */
}

void main()
{
    int h, w;
    w = int(map(pos.x, -1, 1, 0, 1) * screenSize.x);
    h = int(map(pos.y, -1, 1, 0, 1) * screenSize.y);

    vec2 tlg = normalize(hash(vec2(-1, 1)));
    vec2 trg = normalize(hash(vec2(1, 1)));
    vec2 blg = normalize(hash(vec2(-1, -1)));
    vec2 brg = normalize(hash(vec2(1, -1)));

    vec2 tld = vec2(pos.x+1, 1-pos.y) / 2;
    vec2 trd = vec2(1-pos.x, 1-pos.y) / 2;
    vec2 bld = vec2(pos.x+1, pos.y+1) / 2;
    vec2 brd = vec2(1-pos.x, pos.y+1) / 2; 

    float t1 = mix(dot(tlg, tld), dot(trg, trd), pos.x);
    float t2 = mix(dot(blg, bld), dot(brg, brd), pos.x);
    float t = mix(t1, t2, pos.y);

    FragColor = vec4(t, t, t, 1);
    /* FragColor = vec4(tmp, tmp, tmp, 1); */

    /* vec3 p; */
    /* p.x = map(pos.x, -1, 1, 0, 1); */
    /* p.y = map(pos.y, -1, 1, 0, 1); */
    /* p.z = map(pos.z, -1, 1, 0, 1); */
    /* FragColor = vec4(p, 1); */
}
