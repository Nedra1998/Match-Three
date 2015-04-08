#include "Libraries.h"
using namespace std;

class Menu{
private:
	GLFWwindow* window;
	bool Good;
	int Main_Menu();
	int Settings_Menu();
	int Games_Menu();
	int Scores_Menu();
	int Levels_Menu();
	int Genoration_Type_Menu();
	bool Close();
public:
	Hephaestus H_Menu;
	int Initilize_Menu(int menu, Hephaestus H, GLFWwindow* In);
};