
#include "imgui.h"
#include "imgui_impl_sdl_gl3.h"
#include <stdio.h>
#include <vector>
#include <GL/gl3w.h>  
#include <SDL.h>
#include <iostream>


#include <iostream>
#include <cmath>

using namespace std;

string mix(const string &st) {
  string res = st;
  int len = st.length()/2;
  int i = 0;
  int j = 0;
  do {
    res[i] = st[j];
    i = (i + 3) % len ;
    j++;
  } while (i != 0);
  return res;
}


class gui {


public:
int show() {
  // Setup SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
    printf("Error: %s\n", SDL_GetError());
    return -1;
  }
  // char bufUser[256] = "";
  // char bufPasswd[256] = "";
  // Setup window
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS,
                      SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_DisplayMode current;
  SDL_GetCurrentDisplayMode(0, &current);
  SDL_Window* window =
      SDL_CreateWindow("Nenufar KeyGen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 300, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  SDL_GLContext gl_context = SDL_GL_CreateContext(window);
  SDL_GL_SetSwapInterval(1);  // Enable vsync
  gl3wInit();

  // Setup Dear ImGui binding
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard
  // Controls
  ImGui_ImplSdlGL3_Init(window);

  // Setup style
  ImGui::StyleColorsDark();



  // bool show_demo_window = true;
  // bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Main loop
  bool done = false;
  bool b = false;
  string str;
  string strMessage;
  string strTitle;
  string key = "8g3hjk1@72";
  string buf;
  char buf01[236] = {0};
  char buf02[236] = {0};
  char buf03[236] = {0};
  char buf04[236] = {0};

  string y = "Y";
  string e = "E";
  string s = "S";
  string k = "K";

  while (!done) {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSdlGL3_ProcessEvent(&event);
      // if (event.type == SDL_KEYDOWN ) {
      //   cout << bufUser << endl;
      // }
      if (event.type == SDL_QUIT) done = true;
    }
    ImGui_ImplSdlGL3_NewFrame(window);

    // 1. Show a simple window.
    // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets
    // automatically appears in a window called "Debug".
    { ImGui::Begin("Pitirre", NULL, ImVec2(400,200)); 
      // ImGui::InputText("username", bufUser,256);
      // ImGui::InputText("password", bufPasswd,256);

    ImGui::InputText("caja A", buf01, 64);
    ImGui::InputText("caja B", buf02, 64);
    ImGui::InputText("caja C", buf03, 64);
    ImGui::InputText("caja D", buf04, 64);

    buf = "";
    buf += buf04;
    buf += buf02;
    buf += buf01;
 
    buf += buf03;



    if (buf == "3~40n7la(r4s" && strlen(buf01) == 3 && strlen(buf02) == 3 && strlen(buf03) == 3 && strlen(buf04) == 3) {
      buf01[0] = buf02[0] = buf03[0] = buf04[0] = 0;
      b = true;
      strTitle = y + e + s;
      strMessage = k+e+y+ ":" + mix(s + y + "m0f0ng0" + e);
    }

      // if (ImGui::Button("A")) {
      //   str = str + "M";
      // }
      // if (ImGui::Button("B")) {
      //   str = str + "E";
      // }
      // if (ImGui::Button("C")) {
      //   str = str + "R";
      // }
      // if (ImGui::Button("D")) {
      //   str = str + "W";
      // }


           if ( ImGui::Button("Ok") ) { 
              b = true;
           
         strTitle = "WRONG!!";
        strMessage = "No key for U :-(";
      
      str="";
      }
      if (b) {
         ImGui::Begin(strTitle.c_str());
    ImGui::Text("%s", strMessage.c_str());
    if ( ImGui::Button("Close") ) {
      b = false;
    }
    ImGui::End();
      }
        //    if (b)
        // {
        //     ImGui::OpenPopup("popup");
        // }

        // if (ImGui::BeginPopupModal("popup"))
        // {
        //     ImGui::Text("Lorem ipsum");
        //     if ( ImGui::Button("Oka") ) {
        //       std::cout << "oka" << std::endl;
        //       b = false;
              
        //     } 
        //     ImGui::EndPopup();
        // }
        
    ImGui::End();
      
    }


    // Rendering
    glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x,
               (int)ImGui::GetIO().DisplaySize.y);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    ImGui_ImplSdlGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
  }


  // Cleanup
  ImGui_ImplSdlGL3_Shutdown();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

private:
  // vector<ImVec2> v;
  // vector < vector <ImVec2> > shapes;
};





int main(int, char**) { 
  gui myGUI;
 
  myGUI.show(); 
}