#pragma once

#include <string>
namespace Rinegine {
	namespace Graphics {

		const char RawShader::DefaultFragmentShader_120[] = \
			R"(#version 120

uniform sampler2D tex_2d;
varying vec4 color;
varying vec2 texCoord;

uniform int setTexture;
uniform int ColorSet;

void main()
{
    gl_FragColor = color;

   	if(setTexture > 0)
   	{
   		gl_FragColor *= texture2D(tex_2d, texCoord);
   	    
   		if(ColorSet == 1)
   		{
            gl_FragColor.rgb = color.rgb;
        }
   	}
})";
const char RawShader::DefaultVertexShader_120[] = \
R"(#version 120

uniform mat4 projMat;
uniform mat4 viewMat;

attribute vec3 rg_Vertex;
attribute vec4 rg_Color;
attribute vec2 rg_TextureCoord;

varying vec4 color;
varying vec2 texCoord;

void main()
{
	color = rg_Color;
	texCoord = rg_TextureCoord;
	gl_Position = vec4(rg_Vertex, 1.0) * projMat * viewMat;
})";


	}
}