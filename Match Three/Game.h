#include "Libraries.h"
using namespace std;

class Game{
private:
	struct Set_Num{
		int Number, Value;
	};
	GLFWwindow* window;
	bool Good;
	int Grid[15][15][3];
	int Score, Speed;
	int Objects;
	bool Close();
	bool Check_For_Win();
	void Genorate_Grid();
	void Play_Game(Hephaestus H, GLFWwindow* In);
	void Load_Grid(string File);
	void FlipA();
	void FlipB(string Tex);
	void FlipC(string Tex);
	void FlipD();
	int X1, Y1, X2, Y2;
	float xa, xb, ya, yb, size;
public:
	Hephaestus H_Game;
	void Initilize_Game(string File, Hephaestus H, GLFWwindow* In);
	
};