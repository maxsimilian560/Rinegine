#pragma once

namespace Rinegine::Graphics{

  // class Window {

  void Window::set_vidmode(GLFWvidmode* in){
    used_vidmode = in;
  }
  void Window::set_monitor(GLFWmonitor* in){
    used_monitor = in;
  }
  //init

  GLFWwindow*& Window::win(){
    return window;
  }

  // Window::Window() = default;
  Window::Window(Window_Settings& set){
    init(set);
  }

  void Window::init(Window_Settings& set){
    settings = set;
    if (!settings.INIT){
      settings.INIT = 1;
      settings.FullscreanResolution.x = (uint)DefaultVidmode->width;
      settings.FullscreanResolution.y = (uint)DefaultVidmode->height;
    }
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, settings.transparent); //прозрачность окна вкл/откл(по-умол. выкл)
    glfwWindowHint(GLFW_DECORATED, ((settings.Wtype == W_Windowed) ? 1 : 0));
    glfwWindowHint(GLFW_CENTER_CURSOR, settings.CenterCursor);
    glfwWindowHint(GLFW_SAMPLES, settings.MSAA);
    for (glfwHint& i : set.hints){
      glfwWindowHint(i.hint, i.mode);
    }
    switch (settings.Wtype){
      case W_Windowed:
        settings.resolution = settings.WindowResolution;
        window = glfwCreateWindow(
          (int)settings.resolution.x,
          (int)settings.resolution.y,
          settings.name.c_str(),
          nullptr,
          nullptr
        );
        glfwSetWindowPos(window, int(DefaultVidmode->width / 2.) - int(settings.resolution.x / 2.), int(DefaultVidmode->height / 2.) - int(settings.resolution.y / 2.));
        break;
      case W_Fullscreen:
        settings.resolution = settings.FullscreanResolution;
        window = glfwCreateWindow(
          (int)settings.resolution.x,
          (int)settings.resolution.y,
          settings.name.c_str(),
          glfwGetPrimaryMonitor(),
          nullptr
        ); break;
      case W_Borderless:
        settings.resolution.x = (uint)DefaultVidmode->width;
        settings.resolution.y = (uint)DefaultVidmode->height;

        window = glfwCreateWindow(
          (int)settings.resolution.x,
          (int)settings.resolution.y,
          settings.name.c_str(),
          nullptr,
          nullptr
        ); break;
    }
    if (!window){
      glfwTerminate();
      throw(Error::RG_ERROR_WINDOWS_NO_CREATED);
    }

    Window::DefaultMonitor = glfwGetPrimaryMonitor();
    Window::DefaultVidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwMakeContextCurrent(window);

    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)){
      // Не игнорировать. Фиксировать причину, а не симптом.
      throw std::runtime_error("Failed to initialize GLAD: no active context or unsupported GL version");
    }

    const GLubyte* raw_ver = glGetString(GL_VERSION);
    if (!raw_ver){
      throw std::runtime_error("glGetString returned NULL despite successful GLAD init");
    }

    // const GLubyte* raw_ver = glGetString(GL_VERSION);
    if (raw_ver != nullptr){
      size_t major = 0, minor = 0, patch = 0;

      std::sscanf(reinterpret_cast<const char*>(raw_ver), "%ld.%ld.%ld", &major, &minor, &patch);

      Window::DefaultOpenGL_Param._gl_ver = major * 100 + minor * 10 + patch;
      Window::DefaultOpenGL_Param._gl_ver_str = reinterpret_cast<const char*>(raw_ver);
    }

    const GLubyte* raw_vendor = glGetString(GL_VENDOR);
    if (raw_vendor != nullptr){
      Window::DefaultOpenGL_Param._gl_vendor_str = reinterpret_cast<const char*>(raw_vendor);
    }

    const GLubyte* raw_render = glGetString(GL_RENDERER);
    if (raw_render != nullptr){
      Window::DefaultOpenGL_Param._gl_render_str = reinterpret_cast<const char*>(raw_render);
    }

    const GLubyte* raw_glsl = glGetString(GL_SHADING_LANGUAGE_VERSION);
    if (raw_glsl != nullptr){
      Window::DefaultOpenGL_Param._gl_ver_glsl_str = reinterpret_cast<const char*>(raw_glsl);
    }

    Window::DefaultOpenGL_Param._gl_extens_str.clear();

#ifdef RG_OPENGL_CORE_PROFILE
    GLint num_ext = 0;
    glGetIntegerv(GL_NUM_EXTENSIONS, &num_ext);
    for (uint i = 0; (int)i < num_ext; i++){
      const GLubyte* raw_ext = glGetStringi(GL_EXTENSIONS, i);
      if (raw_ext != nullptr){
        Window::DefaultOpenGL_Param._gl_extens_str += reinterpret_cast<const char*>(raw_ext);
        Window::DefaultOpenGL_Param._gl_extens_str += " ";
      }
    }
#else
    const GLubyte* raw_ext = glGetString(GL_EXTENSIONS);
    if (raw_ext != nullptr){
      Window::DefaultOpenGL_Param._gl_extens_str = reinterpret_cast<const char*>(raw_ext);
    }
#endif
    //glEnable(GL_TEXTURE_2D); 	//Разрешить использование текстур
    glEnable(GL_DEPTH_TEST);  	//Проверка глубины
#ifdef RG_OPENGL_LEGACY_PROFILE
    glEnable(GL_ALPHA_TEST); 	  //Разрешить прозрачность 
#endif
    glEnable(GL_BLEND); 		    //Разрешить смешивание
    //glEnable(GL_CULL_FACE); 	//Разрешить обрезание нивидимых обьектов(треугольников)
    //glCullFace(GL_BACK);		  //Отрезание задних треугольнико
    //glFrontFace(GL_CCW);		  //Указание на лицевую сторону (против/по часовой стрелки (CW/CCW))
    glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    if (settings.MSAAon)glEnable(GL_MULTISAMPLE);//Сглаживание
    else glDisable(GL_MULTISAMPLE);

    settings.winedit.quotx = (double)settings.resolution.x / (double)DefaultVirtualWindowSize.x;
    settings.winedit.quoty = (double)settings.resolution.y / (double)DefaultVirtualWindowSize.y;

    settings.winedit.difx = (double)settings.resolution.x - (double)DefaultVirtualWindowSize.x;
    settings.winedit.dify = (double)settings.resolution.y - (double)DefaultVirtualWindowSize.y;


    settings.monedit.quotx = (double)DefaultVidmode->width / (double)DefaultVirtualWindowSize.x;
    settings.monedit.quoty = (double)DefaultVidmode->height / (double)DefaultVirtualWindowSize.y;

    settings.monedit.difx = (double)DefaultVidmode->width - (double)DefaultVirtualWindowSize.x;
    settings.monedit.dify = (double)DefaultVidmode->height - (double)DefaultVirtualWindowSize.y;


    GLFWimage icon;
    if (settings.picon.width != 0 && settings.picon.height != 0){
      glfwSetWindowIcon(window, 1, &settings.picon);
    }elif(settings.PathToIcon.size() >= 1){
      icon.pixels = stbi_load(settings.PathToIcon.c_str(), &icon.width, &icon.height, 0, 4);
      glfwSetWindowIcon(window, 1, &icon);
      stbi_image_free(icon.pixels);
    }

    glfwSwapInterval(settings.Vsyn);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

    EnableClientState(Shader::AT_VERTEX_ARRAY);
    EnableClientState(Shader::AT_COLOR_ARRAY);

  }

  void Window::Active_Fullscreen(){

    if (settings.Wtype != W_Windowed){
      settings.Wtype = W_Windowed;
      settings.resolution.x = settings.WindowResolution.x;
      settings.resolution.y = settings.WindowResolution.y;
      glfwSetWindowAttrib(window, GLFW_DECORATED, 1);
      glfwSetWindowMonitor(window, nullptr, 0, 0, int(settings.WindowResolution.x), int(settings.WindowResolution.y), GLFW_DONT_CARE);
      glfwSetWindowPos(window, int(DefaultVidmode->width / 2. - settings.WindowResolution.x / 2.), int(DefaultVidmode->height / 2. - settings.WindowResolution.y / 2.));
    } else{
      settings.Wtype = W_Fullscreen;
      settings.resolution.x = settings.FullscreanResolution.x;
      settings.resolution.y = settings.FullscreanResolution.y;

      glfwSetWindowAttrib(window, GLFW_DECORATED, 0);
      glfwSetWindowMonitor(window, Window::DefaultMonitor, 0, 0, int(settings.FullscreanResolution.x), int(settings.FullscreanResolution.y), (Window::DefaultVidmode->refreshRate));

    }
  }
  Window_Settings& Window::set(){
    return settings;
  }

  void Window::use(){
    Default = this;
  }
  void Window::close(){
    glfwDestroyWindow(window);
  }
  Window::~Window(){
    close();
  }
  void Window::setVsyn(int mode){
    glfwSwapInterval(mode);
  }
  const Rinegine::Graphics::Window* Rinegine::Graphics::Window::Default;

  bool Window::is_init() const{
    return INIT;
  }
  // };
}