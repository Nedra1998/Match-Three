#include "Libraries.h"
#include "Hephaestus.h"
#include "Menu.h"
#include "Game.h"
using namespace std;
Hephaestus H;
Menu Men;
Game Gam;
int Stage = 1;
void Key_Call(GLFWwindow* Win, int key, int scancode, int action, int mods){
	H.Key_Call_Back(Win, key, scancode, action, mods);
}
void Mouse_Call(GLFWwindow* Win, int button, int action, int mods){
	if (Stage == 1){
		Men.H_Menu.Mouse_Call_Back(Win, button, action, mods);
	}
	else if (Stage == 2){
		Gam.H_Game.Mouse_Call_Back(Win, button, action, mods);
	}
	H.Mouse_Call_Back(Win, button, action, mods);
}
void Window_Call(GLFWwindow* Win, int width, int hight){
	glfwSetWindowSize(Win, width, hight);
}
int main(){
	GLFWwindow* Win;
	Win = H.Full_Setup();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetKeyCallback(Win, Key_Call);
	glfwSetMouseButtonCallback(Win, Mouse_Call);
	glfwSetWindowSizeCallback(Win, Window_Call);
	srand(time(NULL));
	/*>>>>>Place Before Start Code Here<<<<<*/
	int Menu = 1;
	while (!glfwWindowShouldClose(Win)){
		/*>>>>>Place While Running Code Here<<<<<*/
		if (Stage == 1){
			Menu = Men.Initilize_Menu(Menu, H, Win);
			if (Menu > 10 && Menu < 20){
				Stage = 2;
				Menu = Menu - 10;
			}
			H.Clear_Mouse();
		}
		if (Stage == 2){
			H.Clear_All_Layers();
			Gam.Play_Game(H, Win);
			Menu = 2;
			Stage = 1;
		}
		if (Menu == -1){
			glfwSetWindowShouldClose(Win, 1);
		}
		H.Frame();
	}
	H.Terminate_Log();
	return(0);
}