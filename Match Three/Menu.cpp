#include "Libraries.h"
#include "Hephaestus.h"
#include "Logging.h"
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
	else if (menu == 5){
		return(Levels_Menu());
	}
	else if (menu == 6){
		return(Genoration_Type_Menu());
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
	H_Menu.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/Menu Background", 4, 1, 1, 0, 0);
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
		if (Update > 0){
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
	H_Menu.Clear_All_Layers();
	return(Go_To);
}
int Menu::Games_Menu(){
	H_Menu.Clear_All_Layers();
	Good = true;
	int Layer = -1, Button = -1, Action = -1, Update = 10, Go_To = 0;
	H_Menu.Create_New_Layer();
	H_Menu.Create_New_Layer();
	H_Menu.Layers[0]->Initilize_Object(2);
	H_Menu.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/Menu Background", 4, 1, 1, 0, 0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[0]->New_Button("NEW GAME", "Textures/Buttons/Transparent", "Basic/Black", 0.5, 0.2);
	H_Menu.Layers[1]->Button_Objects[0]->Translate_Button(0.0, 0.7, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[1]->New_Button("Chalange", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[1]->Translate_Button(0.0, 0.3, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[2]->New_Button("Free Play", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[2]->Translate_Button(-0.0, 0.0, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[3]->New_Button("Speed", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[3]->Translate_Button(0.0, -0.3, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[4]->New_Button("Back", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[4]->Translate_Button(0.0, -0.7, 0.0);
	while (Good == true){
		if (Update > 0){
			Update--;
			H_Menu.Clear_Mouse();
		}
		if (Update == 0){
			H_Menu.Check_All_Buttons(Layer, Button, Action);
		}
		if (Layer == 1 && Button == 1){
			Good = false;
			Go_To = 5;
		}
		if (Layer == 1 && Button == 2){
			Good = false;
			Go_To = 6;
		}
		if (Layer == 1 && Button == 3){
			Good = false;
			Go_To = 6;
		}
		if (Layer == 1 && Button == 4){
			Good = false;
			Go_To = 1;
		}
		Close();
		H_Menu.Display_All_Layers();
		H_Menu.Frame();
	}
	H_Menu.Clear_Mouse();
	H_Menu.Clear_All_Layers();
	return(Go_To);
}
int Menu::Scores_Menu(){
	return(1);
}
int Menu::Settings_Menu(){
	return(1);
}
int Menu::Levels_Menu(){
	H_Menu.Clear_All_Layers();
	Good = true;
	bool New = true;
	int Layer = -1, Button = -1, Action = -1, Update = 10, Go_To = 0, Page = 0, Objects = 0, Save_Level = 0;
	int Starts[5] = { 1, 21, 41, 61, 81 };
	float x, y;
	ifstream Save("Save Data.Save");
	if (Save.is_open()){
		Save >> Save_Level;
		Save.close();
	}
	else{
		Logging::log_error("No save file existed", "Saves");
		ofstream Create("Save Data.Save");
		if (Create.is_open()){
			Logging::log_success("Created new save file", "Saves");
			Create << 1;
			Save_Level = 1;
			Create.close();
		}
	}
	H_Menu.Create_New_Layer();
	H_Menu.Create_New_Layer();
	H_Menu.Create_New_Layer();
	H_Menu.Layers[0]->Initilize_Object(2);
	H_Menu.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/Menu Background", 4, 1, 1, 0, 0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[0]->New_Button("LEVELS", "Textures/Buttons/Transparent", "Basic/Black", 0.5, 0.2);
	H_Menu.Layers[1]->Button_Objects[0]->Translate_Button(0.0, 0.7, 0.0);
	H_Menu.Layers[1]->Initilize_Object(4);
	H_Menu.Layers[1]->Button_Objects[1]->New_Button("Back", "Textures/Buttons/ButtonA", "Basic/Black", 0.5, 0.1);
	H_Menu.Layers[1]->Button_Objects[1]->Translate_Button(0.0, -0.7, 0.0);
	while (Good == true){
		if (New == true){
			Update = 10;
			Objects = 2;
			x = -0.8;
			y = 0.45;
			H_Menu.Layers[2]->Clear_All();
			if (Page == 0){
				H_Menu.Layers[2]->Initilize_Object(4);
				H_Menu.Layers[2]->Button_Objects[0]->New_Button("PREVIOUS", "Textures/Buttons/ButtonB", "Basic/Black", 0.2, 0.1);
				H_Menu.Layers[2]->Button_Objects[0]->Translate_Button(-0.7, 0.7, 0.0);
			}
			else if (Page != 0){
				H_Menu.Layers[2]->Initilize_Object(4);
				H_Menu.Layers[2]->Button_Objects[0]->New_Button("PREVIOUS", "Textures/Buttons/ButtonA", "Basic/Black", 0.2, 0.1);
				H_Menu.Layers[2]->Button_Objects[0]->Translate_Button(-0.7, 0.7, 0.0);
			}
			if (Page == 4){
				H_Menu.Layers[2]->Initilize_Object(4);
				H_Menu.Layers[2]->Button_Objects[1]->New_Button("NEXT", "Textures/Buttons/ButtonB", "Basic/Black", 0.2, 0.1);
				H_Menu.Layers[2]->Button_Objects[1]->Translate_Button(0.7, 0.7, 0.0);
			}
			else if (Page != 4){
				H_Menu.Layers[2]->Initilize_Object(4);
				H_Menu.Layers[2]->Button_Objects[1]->New_Button("NEXT", "Textures/Buttons/ButtonA", "Basic/Black", 0.2, 0.1);
				H_Menu.Layers[2]->Button_Objects[1]->Translate_Button(0.7, 0.7, 0.0);
			}
			while (Objects < 22){
				H_Menu.Layers[2]->Initilize_Object(4);
				if (Objects + Starts[Page] - 2 <= Save_Level){
					H_Menu.Layers[2]->Button_Objects[Objects]->New_Button(to_string(Objects + Starts[Page] - 2), "Textures/Buttons/ButtonA", "Basic/Black", 0.1, 0.1);
				}
				else if (Objects + Starts[Page] - 2 > Save_Level){
					H_Menu.Layers[2]->Button_Objects[Objects]->New_Button(to_string(Objects + Starts[Page] - 2), "Textures/Buttons/ButtonB", "Basic/Black", 0.1, 0.1);
				}
				H_Menu.Layers[2]->Button_Objects[Objects]->Translate_Button(x, y, 0.0);
				Objects++;
				x = x + 0.4;
				if (Objects == 7 || Objects == 12 || Objects == 17){
					y = y - 0.3;
					x = -0.8;
				}
			}
			New = false;

		}
		if (Update > 0){
			Update--;
			H_Menu.Clear_Mouse();
		}
		H_Menu.Check_All_Buttons(Layer, Button, Action);
		if (Layer == 1 && Button == 1){
			Good = false;
			Go_To = 2;
		}
		if (Layer == 2 && Button == 0 && Page != 0){
			New = true;
			Page--;
		}
		if (Layer == 2 && Button == 1 && Page != 4){
			New = true;
			Page++;
		}
		if (Layer == 2 && Button != 0 && Button != 1 && (Button + Starts[Page] - 2) <= Save_Level){
			Go_To = Button - 2 + Starts[Page];
			Go_To = Go_To * 10;
			Good = false;
		}
		Close();
		H_Menu.Display_All_Layers();
		H_Menu.Frame();
	}
	H_Menu.Clear_Mouse();
	H_Menu.Clear_All_Layers();
	return(Go_To);
}
int Menu::Genoration_Type_Menu(){
	return(1);
}