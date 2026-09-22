#pragma once

namespace Rinegine {
  namespace Graphics {
    struct OpenGL_Param {
      inline static size_t _gl_ver = 0;
      inline static std::string _gl_ver_str;
      inline static std::string _gl_vendor_str;
      inline static std::string _gl_render_str;
      inline static std::string _gl_ver_glsl_str;
      inline static std::string _gl_extens_str;
    };
    struct RawShader {
      std::string frag;
      std::string vert;
      bool INIT = false;
    public:
      static const char DefaultFragmentShader_120[];
      static const char DefaultVertexShader_120[];

      static const char DefaultFragmentShader_330[];
      static const char DefaultVertexShader_330[];

      static const char DefaultFragmentShader_460[];
      static const char DefaultVertexShader_460[];

      RawShader() = default;
      RawShader(std::string frag, std::string vert);
      void init(std::string frag, std::string vert);
      void init();
      std::string get_frag();
      std::string get_vert();
      const char* get_cfrag();
      const char* get_cvert();


    };
    inline void ShaderCompiller(const char* frag, const char* vert, uint prog) {
      RG_LOG_LOCK_INFO("Compiling shaders");

      uint vshader = glCreateShader(GL_VERTEX_SHADER);
      uint fshader = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(vshader, 1, &vert, NULL);
      glShaderSource(fshader, 1, &frag, NULL);
      glCompileShader(vshader);
      glCompileShader(fshader);

      int vsok;
      int fsok;
      int vpok;
      int fpok;


      glGetShaderiv(vshader, GL_COMPILE_STATUS, &vsok);
      glGetShaderiv(fshader, GL_COMPILE_STATUS, &fsok);

      glAttachShader(prog, vshader);
      glAttachShader(prog, fshader);

      glLinkProgram(prog);

      glGetProgramiv(vshader, GL_LINK_STATUS, &vpok);
      glGetProgramiv(fshader, GL_LINK_STATUS, &fpok);



      char temp[2048];
      std::string log;
      if (!vsok) {
        glGetShaderInfoLog(vshader, 2048, nullptr, temp);
        log += "Vertex shaders error:\n";
        log += temp;
        //DEBUG
        RG_LOG_LOCK_ERROR("Vertex shader compilation error:\n" + (std::string)temp);
        //DEBUG
      }
      if (!vpok) {
        glGetProgramInfoLog(vshader, 2048, nullptr, temp);
        log += "Vertex program error:\n";
        log += temp;
        //DEBUG
        std::string tempa = temp;
        if (tempa.size() <= 0) {
          RG_LOG_LOCK_DEBUG("Vertex shader linking error");
        }
        else {
          RG_LOG_LOCK_DEBUG("Vertex shader linking error:\n" + (std::string)temp);
        };
        //DEBUG
      }
      if (!fsok) {
        glGetShaderInfoLog(fshader, 2048, nullptr, temp);
        log += "Fragment shaders error:\n";
        log += temp;
        //DEBUG
        RG_LOG_LOCK_DEBUG("Fragment shader compilation error:\n" + (std::string)temp);
        //DEBUG
      }
      if (!fpok) {
        glGetProgramInfoLog(fshader, 2048, nullptr, temp);
        log += "Fragment program error:\n";
        log += temp;
        //DEBUG
        std::string tempa = temp;
        if (tempa.size() <= 0) {
          RG_LOG_LOCK_DEBUG("Fragment shader linking error");
        }
        else {
          RG_LOG_LOCK_DEBUG("Fragment shader linking error:\n" + (std::string)temp);
        };
        //DEBUG
      }
    }
    class Shader {
    public:
      enum ATTRIB_CONST {
        AT_VERTEX_ARRAY,
        AT_COLOR_ARRAY,
        AT_TEXTURE_COORD_ARRAY
      };
      enum TYPE_DRAW_SHADER {
        DS_TDS_COLOR,
        DS_TDS_TEXTURE,
        DS_TDS_TEXT,
      };
      struct Uniform {
        inline static float IdentityMat[4 * 4] = {
          1,0,0,0,
          0,1,0,0,
          0,0,1,0,
          0,0,0,1
        };
        uint prog;
        int TEXTURE_2D;
        int u_viewMat, u_projMat;
        int setTexture, Texture2d;
        int ColorSet;
        int vertex_array_pos, color_array_pos, texture_coord_array_pos;
        uint SSP_COLOR, SSP_TEXTURE, SSP_TEXT;
        uint countMat = 0;
        inline static uint maxCountMat = 64;
        Kernel::Matrix <float>* projMat;
        Kernel::Array<Kernel::Matrix <float>> MatBuf{ Uniform::maxCountMat };

        float calculateTransformedZ(Kernel::Matrix<float>& mA, Kernel::Matrix<float>& mB) {
          float transformedZ =
            mA.get(2, 0) * mA.get(2, 1) * mA.get(2, 2) * mA.get(2, 3) +
            mB.get(2, 0) * mB.get(2, 1) * mB.get(2, 2) * mB.get(2, 3);
          return transformedZ;
        }
        static Uniform& GetDefault() {
          static Uniform out;
          return out;
        }
      };
      // static Uniform StandartShaderUniform;

    private:
      // inline static Uniform StandartShaderUniform;
      uint prog;
      bool INIT = false;

    public:
      void init(RawShader& shader);
      void init(const char* frag, const char* vert);
      void used();
      uint get_prog();
      bool is_init();
      void prepare();
    };
    // inline static Shader::Uniform StandartShaderUniform;


  }
}