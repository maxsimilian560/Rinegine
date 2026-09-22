#pragma once

namespace Rinegine {
  namespace Graphics {
    // Rinegine::Graphics::Shader::Uniform Rinegine::Graphics::Shader::Uniform::GetDefault();
    // RawShader::RawShader() = default;
    RawShader::RawShader(std::string frag, std::string vert) {
      init(frag, vert);
    }
    void RawShader::init(std::string ifrag, std::string ivert) {
      if (INIT)return;
      INIT = true;
      this->frag = ifrag;
      this->vert = ivert;
    }
    void RawShader::init() {
      if (INIT)return;
      INIT = true;
      if (!Graphics::Window::Default->is_init())RG_LOG_LOCK_FATAL("Window is not init");
      if (Graphics::Window::Default->DefaultOpenGL_Param._gl_ver <= 220) {
        frag = DefaultFragmentShader_120;
        vert = DefaultVertexShader_120;
      }
      else if (Graphics::Window::Default->DefaultOpenGL_Param._gl_ver <= 330) {
        frag = DefaultFragmentShader_330;
        vert = DefaultVertexShader_330;
      }
      else {
        frag = DefaultFragmentShader_460;
        vert = DefaultVertexShader_460;
      }
    }
    std::string RawShader::get_frag() { return frag; }
    std::string RawShader::get_vert() { return vert; }
    const char* RawShader::get_cfrag() { return frag.c_str(); }
    const char* RawShader::get_cvert() { return vert.c_str(); }




    // }RawShader_Standart;


    void Shader::init(RawShader& shader) {
      init(shader.get_cfrag(), shader.get_cvert());
    }

    void Shader::init(const char* frag, const char* vert) {
      INIT = true;
      prog = glCreateProgram();
      ShaderCompiller(frag, vert, prog);
      prepare();
    }
    void Shader::used() {
      Shader::Uniform::GetDefault().prog = prog;
      glUseProgram(prog);
    }
    uint Shader::get_prog() { return prog; }
    bool Shader::is_init() { return INIT; }

    void Shader::prepare() {

      RG_FOR_CYCLEi(Uniform::maxCountMat) {
        Shader::Uniform::GetDefault().MatBuf[i].init(4, 4, Uniform::IdentityMat);
      }
      Shader::Uniform::GetDefault().projMat = &Shader::Uniform::GetDefault().MatBuf[0];

      Shader::Uniform::GetDefault().TEXTURE_2D = glGetUniformLocation(Shader::Uniform::GetDefault().prog, "tex_2d");
      if (Shader::Uniform::GetDefault().TEXTURE_2D == -1) {
        RG_LOG_LOCK_ERROR(std::format("TEXTURE_2D isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().u_viewMat = glGetUniformLocation(Shader::Uniform::GetDefault().prog, "viewMat");
      if (Shader::Uniform::GetDefault().u_viewMat == -1) {
        RG_LOG_LOCK_ERROR(std::format("u_viewMat isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().u_projMat = glGetUniformLocation(Shader::Uniform::GetDefault().prog, "projMat");
      if (Shader::Uniform::GetDefault().u_projMat == -1) {
        RG_LOG_LOCK_ERROR(std::format("u_projMat isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().setTexture = glGetUniformLocation(Shader::Uniform::GetDefault().prog, "setTexture");
      if (Shader::Uniform::GetDefault().setTexture == -1) {
        RG_LOG_LOCK_ERROR(std::format("setTexture isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().Texture2d = glGetUniformLocation(Shader::Uniform::GetDefault().prog, "texture_2d");
      if (Shader::Uniform::GetDefault().Texture2d == -1) {
        RG_LOG_LOCK_ERROR(std::format("Texture2d isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().ColorSet = glGetUniformLocation(Shader::Uniform::GetDefault().prog, "ColorSet");
      if (Shader::Uniform::GetDefault().ColorSet == -1) {
        RG_LOG_LOCK_ERROR(std::format("ColorSet isn't found in shaders"));
      }

      Shader::Uniform::GetDefault().vertex_array_pos = glGetAttribLocation(Shader::Uniform::GetDefault().prog, "rg_Vertex");
      if (Shader::Uniform::GetDefault().vertex_array_pos == -1) {
        RG_LOG_LOCK_ERROR(std::format("vertex_array_pos isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().color_array_pos = glGetAttribLocation(Shader::Uniform::GetDefault().prog, "rg_Color");
      if (Shader::Uniform::GetDefault().color_array_pos == -1) {
        RG_LOG_LOCK_ERROR(std::format("color_array_pos isn't found in shaders"));
      }
      Shader::Uniform::GetDefault().texture_coord_array_pos = glGetAttribLocation(Shader::Uniform::GetDefault().prog, "rg_TextureCoord");
      if (Shader::Uniform::GetDefault().texture_coord_array_pos == -1) {
        RG_LOG_LOCK_ERROR(std::format("texture_coord_array_pos isn't found in shaders"));
      }


      glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, Uniform::IdentityMat);
      glUniformMatrix4fv(Shader::Uniform::GetDefault().u_viewMat, 1, 0, Uniform::IdentityMat);
#ifndef  RG_OPENGL_LEGACY_PROFILE
      glBindFragDataLocation(Shader::Uniform::GetDefault().prog, 0, "rg_Frag");
#endif
    }



  }
}