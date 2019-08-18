#version 450

layout (location = 0) in vec2 inUV;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec3 inShadowCoord;

layout (binding = 1) uniform LightMVPBlock 
{
	mat4 modelMatrix;
	mat4 viewMatrix;
	mat4 projectionMatrix;
	vec4 direction;
} lightMVP;

layout (binding = 3) uniform ShadowParamBlock 
{
	vec4 bias;
} shadowParam;

layout (binding  = 2) uniform sampler2D shadowMap;

layout (location = 0) out vec4 outFragColor;

void main() 
{
    vec4 diffuse  = vec4(1.0, 1.0, 1.0, 1.0);
    vec3 lightDir = normalize(lightMVP.direction.xyz);
    
    diffuse.xyz   = dot(lightDir, inNormal) * diffuse.xyz; 
    outFragColor  = diffuse;

    float depth0  = inShadowCoord.z - shadowParam.bias.x;
    float depth1  = texture(shadowMap, inShadowCoord.xy).r;
    float shadow  = 1.0;

    if (depth0 >= depth1) {
        shadow = 0.0;
    }

    diffuse.xyz *= shadow;
    outFragColor = diffuse;
}