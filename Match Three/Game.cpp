#include "Libraries.h"
#include "Hephaestus.h"
#include "Game.h"
using namespace std;


void Game::Genorate_Grid(){
	Objects = 0;
	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 10; x++){
			Grid[x][y][0] = Objects;
			Grid[x][y][1] = rand() % 7 + 1;
			Grid[x][y][2] = -1;
			H_Game.Layers[1]->Initilize_Object(4);
			H_Game.Layers[1]->Button_Objects[Objects]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", 0.05, 0.05);
			H_Game.Layers[1]->Button_Objects[Objects]->Translate_Button(-0.5, 0.5, 0.0);
			for (int X = 0; X < x; X++){
				H_Game.Layers[1]->Button_Objects[Objects]->Translate_Button(0.1, 0.0, 0.0);
			}
			for (int Y = 0; Y < y; Y++){
				H_Game.Layers[1]->Button_Objects[Objects]->Translate_Button(0.0, -0.1, 0.0);
			}
			Objects++;
		}
	}
}

void Game::Play_Game(Hephaestus H, GLFWwindow* In){
	H_Game = H;
	window = In;
	Good = true;
	bool First = false, Check = false;
	int Layer = -1, Button = -1, Action = -1, Update = 10;
	int X1 = 0, Y1 = 0, X = 0, Y = 0, X2 = 0, Y2 = 0, Flip = 0, Pause = 0;
	float  size = 0.05, xa, ya, xb, yb, x, y;
	string Tiles_Textures[7] = {
		"Red",
		"Blue",
		"Green",
		"Purple",
		"Yellow",
		"Dark Blue",
		"Brown"
	};
	Score = 0;
	H_Game.Create_New_Layer();
	H_Game.Create_New_Layer();
	H_Game.Create_New_Layer();
	H_Game.Create_New_Layer();
	H_Game.Layers[0]->Initilize_Object(1);
	H_Game.Layers[0]->Colored_Objects[0]->New_Colored_Object(4, 1, 1, 1, 1, 1, 1, 0, 0);
	Genorate_Grid();
	while (Good == true){
		if (Flip > 10){
			float t;
			cout << "A\n";
			Flip--;
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
			t = H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Return_Float_Value(4);
			cout << t << endl;
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
			
			t = H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Return_Float_Value(4);
			cout << t << endl;
			size = size - 0.005;
		}
		if (Flip > 0 && Flip <= 10){
			cout << "B\n" << Grid[X2][Y2][0];
			Flip--;
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("A", "Textures/Tiles/" + Tiles_Textures[Grid[X1][Y1][1] - 1], "Special", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("A", "Textures/Tiles/" + Tiles_Textures[Grid[X2][Y2][1] - 1], "Special", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
			size = size + 0.0055;
		}
		if (Flip < -10){
			cout << "C\n";
			Flip++;
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("A", "Textures/Tiles/" + Tiles_Textures[Grid[X1][Y1][1] - 1], "Special", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("A", "Textures/Tiles/" + Tiles_Textures[Grid[X2][Y2][1] - 1], "Special", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
			size = size - 0.005;
		}
		if (Flip < 0 && Flip >= -10){
			cout << "D\n";
			Flip++;
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
			H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
			size = size + 0.0055;
		}
		if (Flip == 0 && Check == true && Pause == 0){
			size = 0.05;
			if (Grid[X1][Y1][1] == Grid[X2][Y2][1]){
				H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(5, 5, 0.0);
				H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(5, 5, 0.0);
			}
			else if (Grid[X1][Y1][1] != Grid[X2][Y2][1]){
				Flip = -20;
			}
			First = false;
			Check = false;
		}
		if (Pause > 0){
			Pause--;
		}
		if (Pause == 1){
			size = 0.05;
			if (Grid[X1][Y1][1] == Grid[X2][Y2][1]){
				H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(5, 5, 0.0);
				H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(5, 5, 0.0);
			}
			else if (Grid[X1][Y1][1] != Grid[X2][Y2][1]){
				Flip = -20;
			}
			First = false;
		}
		if (Update > 0){
			Update--;
			H_Game.Clear_Mouse();
		}
		if (Flip == 0 && Pause == 0){
			H_Game.Check_All_Buttons(Layer, Button, Action);
		}
		if (Layer == 1 && Button != -1){
			Update = 5;
			//x = H_Game.Layers[1]->Button_Objects[Button]->Return_Float_Value(2);
			//y = H_Game.Layers[1]->Button_Objects[Button]->Return_Float_Value(3);
			//H_Game.Layers[1]->Button_Objects[Button]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", 0.05, 0.05);
			//H_Game.Layers[1]->Button_Objects[Button]->Translate_Button(x, y, 0.0);
			if (First == false && Flip == 0){
				First = true;
				Y1 = 0;
				if (Button > 9){
					Y1++;
				}
				if (Button > 19){
					Y1++;
				}
				if (Button > 29){
					Y1++;
				}
				if (Button > 39){
					Y1++;
				}
				if (Button > 49){
					Y1++;
				}
				if (Button > 59){
					Y1++;
				}
				if (Button > 69){
					Y1++;
				}
				if (Button > 79){
					Y1++;
				}
				if (Button > 89){
					Y1++;
				}
				X1 = Button - (10 * Y1);
				xa = H_Game.Layers[1]->Button_Objects[Button]->Return_Float_Value(2);
				ya = H_Game.Layers[1]->Button_Objects[Button]->Return_Float_Value(3);
			}
			else if (First == true && Flip == 0){
				Y2 = 0;
				if (Button > 9){
					Y2++;
				}
				if (Button > 19){
					Y2++;
				}
				if (Button > 29){
					Y2++;
				}
				if (Button > 39){
					Y2++;
				}
				if (Button > 49){
					Y2++;
				}
				if (Button > 59){
					Y2++;
				}
				if (Button > 69){
					Y2++;
				}
				if (Button > 79){
					Y2++;
				}
				if (Button > 89){
					Y2++;
				}
				X2 = Button - (10 * Y2);
				xb = H_Game.Layers[1]->Button_Objects[Button]->Return_Float_Value(2);
				yb = H_Game.Layers[1]->Button_Objects[Button]->Return_Float_Value(3);
				if (X1 != X2 || Y1 != Y2){
					cout << X1 << ":" << Y1 << ":" << Grid[X1][Y1][0] << endl;
					cout << X2 << ":" << Y2 << ":" << Grid[X2][Y2][0] << endl;
					cout << xa << ' ' << ya << endl;
					cout << xb << ' ' << yb << endl;
					size = 0.05;
					Flip = 20;
					Check = true;
				}
			}
		}
		H_Game.Display_All_Layers();
		H_Game.Frame();
	}
}