#pragma once
namespace Rinegine {
	namespace Graphics {

		const char RawShader::DefaultFragmentShader_460[] = \
			R"(#version 330 core

uniform sampler2D tex_2d;
in vec4 color;

in vec2 texCoord;

out vec4 Frag;

uniform int setTexture;
uniform int ColorSet;

void main()
{
    Frag = color;

   	if(setTexture > 0)
   	{
   		Frag *= vec4(texture(tex_2d, texCoord));
   	    
   		if(ColorSet == 1)
   		{
            Frag.rgb = color.rgb;
        }
   	}
})";
const char RawShader::DefaultVertexShader_460[] = \
R"(#version 330 core

//in vec3 RG_VERTEX_ARRAY;

uniform mat4 projMat = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},viewMat = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
//{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}

layout (location = 0) in vec3 rg_Vertex;
layout (location = 1) in vec4 rg_Color;
layout (location = 2) in vec2 rg_TextureCoord;

out vec4 color;
out vec2 texCoord;

void main()
{
	color = rg_Color;
	texCoord = rg_TextureCoord;
	//vec4 vert = vec4(RG_VERTEX_ARRAY,1);
	gl_Position = vec4(rg_Vertex,1) *projMat*viewMat;
})";

	}
}
