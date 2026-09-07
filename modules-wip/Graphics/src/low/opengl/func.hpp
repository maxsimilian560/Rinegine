#pragma once

namespace Rinegine {
  namespace Graphics {


    //функции для шедеров
    //VERTEX
    void Vertex3d(double x, double y, double z) {
      glVertexAttrib3d((uint)Shader::Uniform::GetDefault().vertex_array_pos, x, y, z);
    }
    void Vertex3f(float x, float y, float z) {
      glVertexAttrib3f((uint)Shader::Uniform::GetDefault().vertex_array_pos, x, y, z);
    }
    void Vertex2f(float x, float y) {
      glVertexAttrib2f((uint)Shader::Uniform::GetDefault().vertex_array_pos, x, y);
    }

    //COLOR
    void ColorSet(bool type) {
      glUniform1i(Shader::Uniform::GetDefault().ColorSet, type);
    }

    void Color4d(double r, double g, double b, double a) {
      glVertexAttrib4d((uint)Shader::Uniform::GetDefault().color_array_pos, r, g, b, a);
    }


    void TexCoord2f(float x, float y) {
      glVertexAttrib2f((uint)Shader::Uniform::GetDefault().texture_coord_array_pos, x, y);
    }








    //POINTERS
    void VertexPointer(int size, uint type, int stride, const void* pointer) {
      glVertexAttribPointer((uint)Shader::Uniform::GetDefault().vertex_array_pos, size, type, 1, stride, pointer);
      //glVertexPointer(size,type,stride,pointer);
    }


    void ColorPointer(int size, uint type, int stride, const void* pointer) {
      glVertexAttribPointer((uint)Shader::Uniform::GetDefault().color_array_pos, size, type, 1, stride, pointer);
      //glColorPointer(size,type,stride,pointer);
    }

    void TexCoordPointer(int size, uint type, int stride, const void* pointer) {
      glVertexAttribPointer((uint)Shader::Uniform::GetDefault().texture_coord_array_pos, size, type, 1, stride, pointer);
      //glColorPointer(size,type,stride,pointer);
    }











    //////////////////////////////////////////////////////////////////////////////////////////



    //PERSPECT
    void Frustum(float left, float right, float bottom, float top, float zNear, float zFar, Kernel::Matrix <float>& mat, bool use) {
      float FurstumMat[16] =
      {
        ((2.f * zNear) / (right - left)),	0,							((right + left) / (right - left)),	0,

        0,							((2.f * zNear) / (top - bottom)),	((top + bottom) / (top - bottom)),	0,

        0,							0,							-((zFar + zNear) / (zFar - zNear)),	-((2.f * zFar * zNear) / (zFar - zNear)),

        0,							0,							-1,								0
      };
      mat *= FurstumMat;
      if (use)glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, mat.get());
    }
    void Ortho(float left, float right, float bottom, float top, float zNear, float zFar, Kernel::Matrix <float>& mat, bool use) {
      float orthoMat[16] =
      {
        (2.f / (right - left)),	0,					0,						-((right + left) / (right - left)),

        0,					(2.f / (top - bottom)),	0,						-((top + bottom) / (top - bottom)),

        0,					0,					((-2.f) / (zFar - zNear)),	-((zFar + zNear) / (zFar - zNear)),

        0,					0,					0,						1
      };
      mat *= orthoMat;
      if (use)glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, mat.get());
    }


    void LoadIdentity(Kernel::Matrix<float>& mat) {
      mat.reInit(4, 4, Shader::Uniform::GetDefault().IdentityMat);
    }

    //MATRIX
    void LoadMatrixf(Kernel::Matrix<float>& m) {
      glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, m.get());
    }

    void LoadMatrixf(Kernel::Matrix<float>& m, int id) {
      glUniformMatrix4fv(id, 1, 0, m.get());
    }

    void LoadMatrixf(float* m) {
      glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, m);
    }
    void LoadIdentityMatrix() {
      glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, Shader::Uniform::GetDefault().IdentityMat);
    }
    void LoadIdentityMatrix(int id) {
      glUniformMatrix4fv(id, 1, 0, Shader::Uniform::GetDefault().IdentityMat);
    }

    void LoadMatrixf(float* m, int id) {
      glUniformMatrix4fv(id, 1, 0, m);
    }

    void ReloadMatrix(Kernel::Matrix<float>& mat, bool use) {
      if (use)glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, mat.get());
    }

    //ROTATEf
    void Rotatef(float a, float x, float y, float z, Kernel::Matrix <float>& mat, bool use) {
      float c = (float)cos(a / (float)180.f * (float)M_PI);
      float s = (float)sin(a / (float)180.f * (float)M_PI);

      float rotateMat[16] =
      {
        (x * x * (1.f - c) + c)		,(x * y * (1.f - c) - z * s)	,(x * z * (1.f - c) + y * s)	,0,

        (y * x * (1.f - c) + z * s)	,(y * y * (1.f - c) + c)	,(y * z * (1.f - c) - x * s)	,0,

        (z * x * (1.f - c) - y * s)	,(z * y * (1.f - c) + x * s)	,(z * z * (1.f - c) + c)	,0,

        0							,0							,0							,1
      };

      //MultyMat4(projMat,rotateMat,projMat);
      mat *= rotateMat;
      if (use)glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, mat.get());
    }

    //SCALEF
    void Scalef(float x, float y, float z, Kernel::Matrix <float>& mat, bool use) {

      float scaleMat[16] =
      {
        x,0,0,0,
        0,y,0,0,
        0,0,z,0,
        0,0,0,1
      };

      //MultyMat4(projMat,scaleMat,projMat);
      mat *= scaleMat;
      if (use)glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, mat.get());
    }


    //TRANSFORM
    void Translatef(float x, float y, float z, Kernel::Matrix <float>& mat, bool use) {

      float TranslMat[16] =
      {
        1,0,0,x,
        0,1,0,y,
        0,0,1,z,
        0,0,0,1
      };

      mat *= TranslMat;
      if (use)glUniformMatrix4fv(Shader::Uniform::GetDefault().u_projMat, 1, 0, mat.get());
    }

  }
}