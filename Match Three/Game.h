#include "Libraries.h"
using namespace std;

class Game{
private:
	GLFWwindow* window;
	bool Good;
	int Grid[15][15][3];
	int Score;
	int Objects;

	void Genorate_Grid();
public:
	Hephaestus H_Game;
	void Play_Game(Hephaestus H, GLFWwindow* In);
	
};