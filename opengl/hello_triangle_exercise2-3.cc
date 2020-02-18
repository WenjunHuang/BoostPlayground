//
// Created by rick on 2020/2/16.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebufferSizeCallback(GLFWwindow*,int, int);
void processInput(GLFWwindow*);

// settings
constexpr unsigned int kScrWidth = 800;
constexpr unsigned int kScrHeight= 600;

const char *vertexShaderSource = R"(
#version 330 core
layout(location=0) in vec3 aPos;
void main() {
    gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);
}
)";

const char *fragmentShader1Source = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor =vec4(1.0f,0.5f,0.2f,1.0f);
}
)";

const char *fragmentShader2Source = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(1.0f,1.0f,0.0f,1.0f);
}
)";

int main() {
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif

    // glfw window creation
    if (auto window = glfwCreateWindow(kScrWidth,kScrHeight,"LearnOpenGL",nullptr,nullptr)) {
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);

        // glad
        if (!gladLoadGLLoader(((GLADloadproc)glfwGetProcAddress))) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        // build and compile our shader program
        auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
        auto fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
        auto fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
        auto shaderProgramOrange = glCreateProgram();
        auto shaderProgramYellow = glCreateProgram();

        glShaderSource(vertexShader,1,&vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        glShaderSource(fragmentShaderOrange,1,&fragmentShader1Source,nullptr);
        glCompileShader(fragmentShaderOrange);
        glShaderSource(fragmentShaderYellow,1,&fragmentShader2Source,nullptr);
        glCompileShader(fragmentShaderYellow);

        // link the first program object
        glAttachShader(shaderProgramOrange,vertexShader);
        glAttachShader(shaderProgramOrange,fragmentShaderOrange);
        glLinkProgram(shaderProgramOrange);

        // link the second program object
        glAttachShader(shaderProgramYellow,vertexShader);
        glAttachShader(shaderProgramYellow,fragmentShaderYellow);
        glLinkProgram(shaderProgramYellow);

        // set up vertex data (and buffer(s)) and configure vertex attributes
        float firstTriangle[] = {
            -0.9f,-0.5f,-0.0f,
            -0.0f,-0.5f,0.0f,
            -0.45f,0.5f,0.0f
        };

        float secondTriangle[] = {
            0.0f,-0.5f,0.0f,
            0.9f,-0.5f,0.0f,
            0.45f,0.5f,0.0f
        };

        unsigned int VBOs[2],VAOs[2];
        glGenVertexArrays(2,VAOs);
        glGenBuffers(2,VBOs);

        // first triangle setup
        glBindVertexArray(VAOs[0]);
        glBindBuffer(GL_ARRAY_BUFFER,VBOs[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(firstTriangle),firstTriangle,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);

        // second triangle setup
        glBindVertexArray(VAOs[1]);
        glBindBuffer(GL_ARRAY_BUFFER,VBOs[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(secondTriangle),secondTriangle,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
        glEnableVertexAttribArray(0);

        while (!glfwWindowShouldClose(window)) {
            // input
            processInput(window);

            glClearColor(0.2f,0.3f,0.3f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgramOrange);
            glBindVertexArray(VAOs[0]);
            glDrawArrays(GL_TRIANGLES,0,3);

            glUseProgram(shaderProgramYellow);
            glBindVertexArray(VAOs[1]);
            glDrawArrays(GL_TRIANGLES,0,3);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glDeleteVertexArrays(2,VAOs);
        glDeleteBuffers(2,VBOs);
        glfwTerminate();
        return 0;
    } else {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window,true);
}

void framebufferSizeCallback(GLFWwindow* window,int width,int height) {
    glViewport(0,0,width,height);
}