#version 450

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

    bool diffuseMapEnabled;
    bool specularMapEnabled;

    sampler2D diffuseMap;
    sampler2D specularMap;
};

struct Light
{
    int type;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    /* Basic Light */
    vec3 position;
    /* Directional Light */
    vec3 direction;
    /* Point Light */
    float constant;
    float linear;
    float quadratic;
    /* Spot Light */
    float innerCutoff;
    float outerCutoff;
};

in vec3 normal;
in vec3 fragPos;
in vec2 texturePos;

out vec4 fragColor;

uniform Material material;
uniform Light light;

const int BASIC_LIGHT = 0;
const int DIRECTIONAL_LIGHT = 1;
const int POINT_LIGHT = 2;
const int SPOT_LIGHT = 3;

void main() {
	vec3 lightDir;
    if (light.type == BASIC_LIGHT || light.type == POINT_LIGHT || light.type == SPOT_LIGHT) {
        lightDir = normalize(light.position - fragPos);
    } else if (light.type == DIRECTIONAL_LIGHT) {
        lightDir == normalize(-light.direction);
    }

	float diff = max(dot(normal, lightDir), 0.0);

	vec3 viewPos = vec3(0.0, 0.0, 10.0);
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    vec3 ambient, diffuse, specular;
    if (material.diffuseMapEnabled) {
        ambient = light.ambient * texture(material.diffuseMap, texturePos).rgb;
        diffuse = light.diffuse * diff * texture(material.diffuseMap, texturePos).rgb;
    }
    else {
       ambient = light.ambient * material.ambient;
       diffuse = light.diffuse * (diff * material.diffuse);
    }

    if (material.specularMapEnabled) {
        specular = light.specular * spec * texture(material.specularMap, texturePos).rgb;
    }
    else {
        specular = light.specular * (spec * material.specular);
    }

    if (light.type == POINT_LIGHT || light.type == SPOT_LIGHT) {
        float distance = length(light.position - fragPos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
        ambient *= attenuation;
        diffuse *= attenuation;
        specular *= attenuation;
    }

    if (light.type == SPOT_LIGHT) {
        float angle = dot(lightDir, normalize(-light.direction));
        float cutoffRange = light.innerCutoff - light.outerCutoff;
        float intensity = clamp((angle - light.outerCutoff) / cutoffRange, 0.0, 1.0);

        diffuse *= intensity;
        specular *= intensity;
    }

	vec3 result = (ambient + diffuse + specular);
	fragColor = vec4(result, 1.0);

    fragColor = clamp(fragColor, 0.0, 1.0);
}
