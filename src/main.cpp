#include "files/loader.h"
#include "files/writer.h"
#include <iostream>
#include "files/exception.h"
#include "bmp/bmp.h"
#include "GLFW/glfw3.h"

int main(){
    // std::string name{"../assets/land.bmp"}; 
    // std::string copy{"../assets/forWrite.bmp"}; 
    
    // try{
        

    //     BMP bmp{name}; 
        
       
        
    // } catch(Excptn& errorPath){
    //     std::cout<< errorPath.what() << " " << errorPath.getPath()<<std::endl; 
    // }


     GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;


    
}