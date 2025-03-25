#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
double scaleX = 1.0;
double scaleY = 1.0;
double offsetX = 0.0;
double offsetY = 0.0;
double minX, maxX;
double minY, maxY;
double initialMinX, initialMaxX;
double initialMinY, initialMaxY;

// Функція, яка обчислює значення функції y = x^3 + 2x^2 + 2
double func(double x) {
    return pow(x, 3) + 2 * pow(x, 2) + 2;
}

// Функція для створення масиву точок графіку
vector<pair<double, double>> generatePoints(double minX, double maxX, double step) {
    vector<pair<double, double>> points;
    for (double x = minX; x <= maxX; x += step) {
        points.push_back(make_pair(x, func(x)));
    }
    return points;
}

// Функція для визначення меж інтервалу
void setBounds() {
    cout << "Enter minimum x value: ";
    cin >> minX;
    cout << "Enter maximum x value: ";
    cin >> maxX;
    vector<double> values;
    for (double x = minX; x <= maxX; x += 0.1) {
        values.push_back(func(x));
    }
    minY = *min_element(values.begin(), values.end());
    maxY = *max_element(values.begin(), values.end());
    initialMinX = minX;
    initialMaxX = maxX;
    initialMinY = minY;
    initialMaxY = maxY;
}

// Функція для відображення графіку
void drawGraph(const vector<pair<double, double>>& points) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Колір фону - білий
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Колір лінії графіку

    // Відображення координатних осей
    glBegin(GL_LINES);
    // Ось x
    glVertex2f(initialMinX / scaleX + offsetX, 0.0);
    glVertex2f(initialMaxX / scaleX + offsetX, 0.0);
    // Ось y
    glVertex2f(0.0, initialMinY / scaleY + offsetY);
    glVertex2f(0.0, initialMaxY / scaleY + offsetY);
    glEnd();

    // Відображення графіку
    glBegin(GL_LINE_STRIP);
    for (const auto& point : points) {
        glVertex2f(point.first, point.second);
    }
    glEnd();
}

// Функція для обробки натискання клавіш
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_EQUAL || key == GLFW_KEY_KP_ADD) {
            scaleX *= 1.2;
            scaleY *= 1.2;
        }
        else if (key == GLFW_KEY_MINUS || key == GLFW_KEY_KP_SUBTRACT) {
            scaleX /= 1.2;
            scaleY /= 1.2;
        }
        else if (key == GLFW_KEY_RIGHT) {
            offsetX += 0.2 / scaleX;
        }
        else if (key == GLFW_KEY_LEFT) {
            offsetX -= 0.2 / scaleX;
        }
        else if (key == GLFW_KEY_UP) {
            offsetY += 0.2 / scaleY;
        }
        else if (key == GLFW_KEY_DOWN) {
            offsetY -= 0.2 / scaleY;
        }

       
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(initialMinX / scaleX + offsetX, initialMaxX / scaleX + offsetX, initialMinY / scaleY + offsetY, initialMaxY / scaleY + offsetY, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
    }
}


void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
   
    if (!glfwInit()) {
        return -1;
    }

    
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "y = x^3 + 2x^2 + 2", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    
    setBounds();

   
    double step = 0.1;
    vector<pair<double, double>> points = generatePoints(minX, maxX, step);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(minX, maxX, minY, maxY, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    
    while (!glfwWindowShouldClose(window)) {
       
        glfwPollEvents();

        // Генерування точок графіку з урахуванням зміщення та масштабу
        points = generatePoints((minX + offsetX) / scaleX, (maxX + offsetX) / scaleX, step);

        // Відображення графіку
        drawGraph(points);

   
        glfwSwapBuffers(window);
    }

    
    glfwTerminate();
    return -1;
}
