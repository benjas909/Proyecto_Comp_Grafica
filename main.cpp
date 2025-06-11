#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main() {
  glfwInit(); // Inicializa GLFW

  // Setea la versión de OpenGL a 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // Declara que se quiere usar el perfil core de OGL
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Crea la ventana, con dimensiones y título
  GLFWwindow* window = glfwCreateWindow(800, 600, "Holaaa", NULL, NULL);
  if (window == NULL) {
    cout << "Falló la creación de la ventana" << endl;
    glfwTerminate();
    return -1;

  }
  glfwMakeContextCurrent(window); // Le dice a GLFW que nuestra ventana será el contexto principal de este thread

  // Inicializamos GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "Fallo al inicializar GLAD" << endl;
    return -1;
  }

  glViewport(0, 0, 800, 600); // Se setea el ViewPort, los dos primeros parámetros setean la posición de la ventana

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f

  };

  unsigned int VBO;
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);



  // Cada iteración es un frame!!
  while (!glfwWindowShouldClose(window)) {
    processInput(window); // Procesa input (tecla ESC)


    glfwPollEvents();
    glfwSwapBuffers(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  glfwTerminate();
  return 0;

}