#include "files/loader.h"
#include "files/writer.h"
#include <iostream>
#include "files/exception.h"
#include "bmp/bmp.h"
#include "png/png.h"
#include "filters/histogram.h"
#include "filters/smoothing.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){
    std::string name{"../assets/lang.bmp"}; 

    std::vector<int> vec{1,2,3,4,5,6,7,8,9}; 

    //std::cout << vec[1, 1] << " "; 
    // for(int i{0}; i < 3; i++){
    //     for(int j{0}; j < 3; j++){
    //         std::cout << vec[i * 3 + j] << " "; 
    //     }
    //     std::cout << std::endl; 
    // }
    
    try{
             
    } catch(Excptn& errorPath){
        std::cout<< errorPath.what() << " " << errorPath.getPath()<<std::endl; 
    }
    
    BMP bmp{name};  

    //Histogram hist{ bmp.getBlue(), bmp.getGreen(), bmp.getRed()}; 
    Smoothing smooth{ bmp.getBlue(), bmp.getGreen(), bmp.getRed(),  bmp.getWidth(),  bmp.getHeight() }; 

    bmp.setColors(smooth.getBlue(), smooth.getGreen(), smooth.getRed()); 

    //PNG png{"lena.png"}; 




    // glfwInit();
    // // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   
    // GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    // if (window == NULL)
    // {
    //     std::cout << "Failed to create GLFW window" << std::endl;
    //     glfwTerminate();
    //     return -1;
    // }


    // glfwMakeContextCurrent(window);
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    // {
    //     std::cout << "Failed to initialize GLAD" << std::endl;
    //     return -1;
    // } 

    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    // {
    //     std::cout << "Failed to initialize GLAD" << std::endl;
    //     return -1;
    // }    


    // while (!glfwWindowShouldClose(window))
    // {
    //     // input
    //     // -----
    //     processInput(window);

    //     // render
    //     // ------
    //     glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //     glDrawPixels(SCR_WIDTH, SCR_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, bmp.pixels.begin());
       
                 
    //     // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    //     // -------------------------------------------------------------------------------
    //     glfwSwapBuffers(window);
    //     glfwPollEvents();
    // }
    //glfwTerminate();

}


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

    
    
