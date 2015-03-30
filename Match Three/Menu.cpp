#include "Libraries.h"
#include "Hephaestus.h"
#include "Menu.h"
using namespace std;

int Menu::Initilize_Menu(int menu, Hephaestus H, GLFWwindow* In){
	window = In;
	H_Menu = H;
	if (menu == 1){
		return(Main_Menu());
	}
	else if (menu == 2){
		return(Games_Menu());
	}
	else if (menu == 3){
		return(Scores_Menu());
	}
	else if (menu == 4){
		return(Settings_Menu());
	}
}
bool Menu::Close(){
	if (glfwWindowShouldClose(window)){
		Good = false;
		return(true);
	}
	return(false);
}

int Menu::Main_Menu(){
	Good = true;
	int Layer = -1, Button = -1, Action = -1, Update = 10, Go_To = 0;
	H_Menu.Create_New_Layer();
	H_Menu.Create_New_Layer();
	H_Menu.Layers[0]->Initilize_Object(2);
	H_Menu.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/BackgroundB", 4, 1, 1, 0, 0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[0]->New_Button("MATCH THREE", "Textures/Buttons/Transparent", "Basic/Black", 0.5, 0.2);
	H_Menu.Layers[1]->Button_Objects[0]->Translate_Button(0.0, 0.7, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[1]->New_Button("Play", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[1]->Translate_Button(0.0, 0.4, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[2]->New_Button("High Scores", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[2]->Translate_Button(0.0, 0.1, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[3]->New_Button("Settings", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[3]->Translate_Button(0.0, -0.2, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[4]->New_Button("Quit", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[4]->Translate_Button(0.0, -0.5, 0.0);
	H_Menu.Clear_Mouse();
	while (Good == true){
		while (Update > 0){
			Update--;
			H_Menu.Clear_Mouse();
		}
		if (Update == 0){
			H_Menu.Check_All_Buttons(Layer, Button, Action);
		}
		if (Layer == 1 && Button == 1){
			Good = false;
			Go_To = 2;
		}
		if (Layer == 1 && Button == 2){
			Good = false;
			Go_To = 3;
		}
		if (Layer == 1 && Button == 3){
			Good = false;
			Go_To = 4;
		}
		if (Layer == 1 && Button == 4){
			H_Menu.Clear_All_Layers();
			Good = false;
			Go_To = -1;
		}
		Close();
		H_Menu.Display_All_Layers();
		H_Menu.Frame();
	}
	H_Menu.Clear_Mouse();
	return(Go_To);
}
int Menu::Games_Menu(){
	H_Menu.Clear_All_Layers();
	Good = true;
	int Layer = -1, Button = -1, Action = -1, Update = 10, Go_To = 0;
	H_Menu.Create_New_Layer();
	H_Menu.Create_New_Layer();
	H_Menu.Layers[0]->Initilize_Object(2);
	H_Menu.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/BackgroundB", 4, 1, 1, 0, 0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[0]->New_Button("NEW GAME", "Textures/Buttons/Transparent", "Basic/Black", 0.5, 0.2);
	H_Menu.Layers[1]->Button_Objects[0]->Translate_Button(0.0, 0.7, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[1]->New_Button("Story", "Textures/Buttons/ButtonA", "Basic/Black", 0.3, 0.1);
	H_Menu.Layers[1]->Button_Objects[1]->Translate_Button(-0.4, 0.2, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[2]->New_Button("Chalange", "Textures/Buttons/ButtonA", "Basic/Black", 0.3, 0.1);
	H_Menu.Layers[1]->Button_Objects[2]->Translate_Button(0.4, 0.2, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[3]->New_Button("Free Play", "Textures/Buttons/ButtonA", "Basic/Black", 0.3, 0.1);
	H_Menu.Layers[1]->Button_Objects[3]->Translate_Button(-0.4, -0.2, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[4]->New_Button("Versus", "Textures/Buttons/ButtonA", "Basic/Black", 0.3, 0.1);
	H_Menu.Layers[1]->Button_Objects[4]->Translate_Button(0.4, -0.2, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[5]->New_Button("Back", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[5]->Translate_Button(0.0, -0.7, 0.0);
	while (Good == true){
		while (Update > 0){
			Update--;
			H_Menu.Clear_Mouse();
		}
		if (Update == 0){
			H_Menu.Check_All_Buttons(Layer, Button, Action);
		}
		if (Layer == 1 && Button == 1){
			Good = false;
			Go_To = 11;
		}
		if (Layer == 1 && Button == 2){
			Good = false;
			Go_To = 12;
		}
		if (Layer == 1 && Button == 3){
			Good = false;
			Go_To = 13;
		}
		if (Layer == 1 && Button == 4){
			Good = false;
			Go_To = 14;
		}
		if (Layer == 1 && Button == 5){
			Good = false;
			Go_To = 1;
		}
		Close();
		H_Menu.Display_All_Layers();
		H_Menu.Frame();
	}
	H_Menu.Clear_Mouse();
	return(Go_To);
}
int Menu::Scores_Menu(){
	return(1);
}
int Menu::Settings_Menu(){
	return(1);
}