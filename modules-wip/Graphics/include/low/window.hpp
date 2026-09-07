#pragma once

namespace Rinegine::Graphics{
  struct glfwHint{
    int hint;
    int mode;
  };
  enum Windows_Render_Types{
    W_Fullscreen,
    W_Borderless,
    W_Windowed,
  };
  struct DifferenceWindow{
    double quotx = 1, quoty = 1, difx = 1, dify = 1;//quotient,difference //for windows.h
  };

  struct Window_Settings{
    Kernel::Array<glfwHint> hints;
    Kernel::vec2<uint> resolution = { 1024,720 };
    Kernel::vec2<uint> WindowResolution = { 1024,720 };
    Kernel::vec2<uint> FullscreanResolution = { 1920,1080 };
    DifferenceWindow monedit, winedit;
    int Vsyn = 1;
    Windows_Render_Types Wtype = W_Windowed;
    std::string name = "Powered by Rinegine";
    std::string PathToIcon;
    GLFWimage picon;
    bool transparent = false;
    bool CenterCursor = false;
    int MSAA = 4;
    bool MSAAon = false;
    bool INIT = false;
    void print(){
      rg_cout << "Resolution: " << resolution.x << "/" << resolution.y << std::endl;
      rg_cout << "Name: " << name << std::endl;
      rg_cout << "Vsyn: " << Vsyn << std::endl;
      rg_cout << "Type: " << Wtype << std::endl;
      rg_cout << "PathToIcon: " << PathToIcon << std::endl;
      rg_cout << "transparent: " << transparent << std::endl;
      rg_cout << "CenterCursor: " << CenterCursor << std::endl;
      rg_cout << "MSAA: " << MSAA << std::endl;
      rg_cout << "MSAA on: " << (MSAAon ? "true\n" : "false\n");
    }
  };
  class Window{
    GLFWwindow* window;
    Window_Settings settings;
    Shader sh;
    bool INIT = false;
    public:

    static OpenGL_Param DefaultOpenGL_Param;
    const static Rinegine::Graphics::Window* Default;
    inline static const GLFWvidmode* DefaultVidmode = nullptr;
    inline static GLFWmonitor* DefaultMonitor = nullptr;
    inline static Kernel::vec2<size_t> DefaultVirtualWindowSize = { 2000,2000 };
    inline static Rinegine::BYTE OpenGLVersion = 0;
    inline static std::string OpenGLVersionSTR = "";
    private:
    GLFWvidmode* used_vidmode;
    GLFWmonitor* used_monitor;
    public:
    bool is_init() const;

    void set_vidmode(GLFWvidmode* in);
    void set_monitor(GLFWmonitor* in);
    //init

    GLFWwindow*& win();

    Window() = default;
    Window(Window_Settings& set);

    void init(Window_Settings& set);

    void Active_Fullscreen();
    Window_Settings& set();
    void use();
    void close();
    ~Window();
    void setVsyn(int mode);


  };
}