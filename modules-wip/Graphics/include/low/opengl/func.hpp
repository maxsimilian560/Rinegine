#pragma once

namespace Rinegine {
  namespace Graphics {

    void Vertex3d(double x, double y, double z);
    void Vertex3f(float x, float y, float z);
    void Vertex2f(float x, float y);
    
    void ColorSet(bool type);
    void Color4d(double r, double g, double b, double a);

    void TexCoord2f(float x, float y);

    
    void VertexPointer(int size, int type, int stride, const void* pointer);


    void ColorPointer(int size, int type, int stride, const void* pointer);
    void TexCoordPointer(int size, int type, int stride, const void* pointer);


    

    
    void Frustum(float left, float right, float bottom, float top, float zNear, float zFar, Kernel::Matrix <float>& mat, bool use);
    void Ortho(float left, float right, float bottom, float top, float zNear, float zFar, Kernel::Matrix <float>& mat, bool use);


    void LoadIdentity(Kernel::Matrix<float>& mat);

    
    void LoadMatrixf(Kernel::Matrix<float>& m);

    void LoadMatrixf(Kernel::Matrix<float>& m, uint id);

    void LoadMatrixf(float* m);
    void LoadIdentityMatrix();
    void LoadIdentityMatrix(uint id);
    void LoadMatrixf(float* m, uint id);

    void ReloadMatrix(Kernel::Matrix<float>& mat = (*Shader::Uniform::GetDefault().projMat), bool use = false);

    
    void Rotatef(float a, float x, float y, float z, Kernel::Matrix <float>& mat = (*Shader::Uniform::GetDefault().projMat), bool use = false);

    
    void Scalef(float x, float y, float z, Kernel::Matrix <float>& mat = (*Shader::Uniform::GetDefault().projMat), bool use = false);


    
    void Translatef(float x, float y, float z, Kernel::Matrix <float>& mat = (*Shader::Uniform::GetDefault().projMat), bool use = false);

    
    inline void DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) {
      

      glDrawElements(mode, count, type, indices);
    }

    inline void DrawArrays(GLenum mode, GLint first, GLsizei count) {
      

      glDrawArrays(mode, first, count);
    }
    
#ifdef RG_OPENGL_LEGACY_PROFILE
    inline void Begin(GLenum mode) {
      
      glBegin(mode);
    }

    inline void End() {
      glEnd();
    }
#endif

    
    inline void EnableClientState(Shader::ATTRIB_CONST type) {
      glEnableVertexAttribArray(type);

    }
    inline void DisableClientState(Shader::ATTRIB_CONST type) {
      glDisableVertexAttribArray(type);
    }
    
    inline void BindTexture(int id, [[maybe_unused]] int type = GL_TEXTURE_2D) {
      glUniform1i(Shader::Uniform::GetDefault().setTexture, id);
    }
  }
}