#pragma once


#if defined(_WIN64)
#include "../other/FreeType/64/include/freetype2/ft2build.h"
#include FT_FREETYPE_H
#include "../other/FreeType/64/include/freetype2/freetype/ftoutln.h"
#include "../other/FreeType/64/include/freetype2/freetype/freetype.h"
#else
#include "freetype2/ft2build.h"
#include FT_FREETYPE_H
#include "freetype2/freetype/ftoutln.h"
#include "freetype2/freetype/freetype.h"
#endif


#include <glad/gl.h>
#include <GLFW/glfw3.h>



#if defined(GLFW_EXPOSE_NATIVE_WIN32)
#include <GLFW/glfw3native.h>
#endif
#define RG_DEF_WINOS

#if !defined(RinegineLib)
#define STB_IMAGE_IMPLEMENTATION	
#endif
#include "stb/stb_image.h"	

#if !defined(RinegineLib)
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif
#include "stb/stb_image_write.h"	

inline FT_Face DefFace;
inline FT_Library library;

// double RG_Render_Distance[2] = {10,10};