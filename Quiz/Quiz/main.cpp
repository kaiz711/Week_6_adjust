#include "Square.h"
#include "Circle.h"
#include "main.h"

using namespace std;

template<class T_CLASS> // Problem 1
void print(const T_CLASS& i)
{
	cout << i << endl;
}

template<class T_A> // Problem 2
class Vector2D
{
public:
	T_A x, y;

	void draw()
	{
		cout << x << endl;
		cout << y << endl;
	}
};

class GeometricObjectInterface
{
public:
	virtual void draw()
	{

	}
};

template<class T>
class Geometric : public GeometricObjectInterface
{
public:
	void draw()
	{
		T drawShape;
		drawShape.draw();
	}
};

void drawOnPixelBuffer()
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	std::vector<GeometricObjectInterface*> obj_list;

	obj_list.push_back(new Geometric<Square>);
	obj_list.push_back(new Geometric<Circle>);

	for (auto itr : obj_list)
		itr->draw();

}

int main(void)
{
	cout << "Problem 1" << endl;
	print(1);
	print(2.345f);
	print("Hello World");
	cout << "" << endl;

	cout << "Problem 2" << endl;
	Vector2D<int> ex_vector;		// VectorInt2D
	Vector2D<float> ex_vector2;		// VectorFloat2D
	Vector2D<double> ex_vector3;	// VectorDouble2D

	ex_vector.x = 1;
	ex_vector.y = 2;
	ex_vector.draw();

	ex_vector2.x = 3.33f;
	ex_vector2.y = 4.44f;
	ex_vector2.draw();

	ex_vector3.x = 5.5555;
	ex_vector3.y = 6.6666;
	ex_vector3.draw();

	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(width, height, "Week 6", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	while (!glfwWindowShouldClose(window))
	{
		drawOnPixelBuffer();

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		glfwSwapBuffers(window);

		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array

	return 0;
}