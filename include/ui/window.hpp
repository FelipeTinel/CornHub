#pragma once

#include <GLFW/glfw3.h>

class Window {
    
    private:

        GLFWwindow * windowId;

        int width;
        int height;
        const char * title;

        bool initGLFW();
        bool initImGui();
        void cleanup();

    public:

        Window(int width = 1280, int height = 720, const char* title = "PopcornHUB");
        
        ~Window();

        void run();
};