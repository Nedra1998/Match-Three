#include "Libraries.h"
#include "Hephaestus.h"

#include "Logging.h"
#include "Game.h"
using namespace std;

bool Game::Close(){
	if (glfwWindowShouldClose(window)){
		Good = false;
		return(true);
	}
	return(false);
}
bool Game::Check_For_Win(){
	bool Win = true;
	for (int a = 0; a < 10; a++){
		for (int b = 0; b < 10; b++){
			if (Grid[a][b][2] != 1){
				Win = false;
			}
		}
	}
	return(Win);
}

void Game::Genorate_Grid(){
	Objects = 0;
	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 10; x++){
			Grid[x][y][0] = Objects;
			Grid[x][y][1] = rand() % 7 + 1;
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
void Game::Load_Grid(string File){
	bool New_Number;
	int a = 0, b = 0, x = 0, y = 0, Min = 0, Max = 49, Total, Temp;
	int Spots[10][10];
	float xa, ya;
	string Line;
	string Special[10];
	vector<Set_Num> Set_Numbers;
	Set_Numbers.clear();
	//for (int d = 0; d < 10; d++){
		//for (int e = 0; e < 10; e++){
			//Grid[d][e][2] = 0;
		//}
	//}
	ifstream Load(File.c_str());
	if (Load.is_open()){
		Load >> Min;
		Load >> Max;
		Load >> a;
		if (a != 0){
			getline(Load, Line);
		}
		ya = 0.2 / a;
		Total = a;
		while (a > 0){
			getline(Load, Line);
			Special[b] = Line;
			xa = (2 * (ya / 6)) * Special[b].size();
			H_Game.Layers[2]->Initilize_Object(4);
			H_Game.Layers[2]->Button_Objects[b]->New_Button(Special[b], "Textures/Buttons/ButtonC", "Basic/Black", xa, ya);
			H_Game.Layers[2]->Button_Objects[b]->Translate_Button(0.0, 0.78, 0.0);
			Temp = b;
			while (Temp < (float)Total / 2){
				Temp++;
				H_Game.Layers[2]->Button_Objects[b]->Translate_Button(0.0, 2*ya, 0.0);
			}
			while (Temp > (float)Total / 2){
				Temp--;
				H_Game.Layers[2]->Button_Objects[b]->Translate_Button(0.0, -2 * ya, 0.0);
			}
			a--;
			b++;
		}
		a = 0;
		while (a < 100){
			Grid[x][y][0] = a;
			Load >> Spots[x][y];
			New_Number = true;
			if (Spots[x][y] == 00){
				New_Number = false;
				Grid[x][y][1] = 00;
			}
			for (unsigned c = 0; c < Set_Numbers.size(); c++){
				if (Spots[x][y] == Set_Numbers[c].Number){
					New_Number = false;
					Grid[x][y][1] = Set_Numbers[c].Value;
				}
			}
			if (New_Number == true){
				Set_Num Temp;
				Temp.Number = Spots[x][y];
				Temp.Value = Min + (rand() % Max);
				Grid[x][y][1] = Temp.Value;
				Set_Numbers.push_back(Temp);
				New_Number = false;
			}
			H_Game.Layers[1]->Initilize_Object(4);
			H_Game.Layers[1]->Button_Objects[a]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", 0.05, 0.05);
			H_Game.Layers[1]->Button_Objects[a]->Translate_Button(-0.5, 0.5, 0.0);
			if (Grid[x][y][1] != 00){
				Grid[x][y][2] = 0;
				for (int X = 0; X < x; X++){
					H_Game.Layers[1]->Button_Objects[a]->Translate_Button(0.1, 0.0, 0.0);
				}
				for (int Y = 0; Y < y; Y++){
					H_Game.Layers[1]->Button_Objects[a]->Translate_Button(0.0, -0.1, 0.0);
				}
			}
			else{
				Grid[x][y][2] = 1;
				H_Game.Layers[1]->Button_Objects[a]->Translate_Button(0.0, -2.0, 0.0);
			}
			a++;
			x++;
			if (x == 10){
				y++;
				x = 0;
			}
		}
		Load.close();
	}
	else{
		Logging::log_error("Level file does not exist", "Level Loading");
	}
}

void Game::FlipA(){
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
}
void Game::FlipB(string Tex){
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("", "Textures/Tiles/" + Tex, "Special", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("", "Textures/Tiles/" + Tex, "Special", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
}
void Game::FlipC(string Tex){
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("", "Textures/Tiles/" + Tex, "Special", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("", "Textures/Tiles/" + Tex, "Special", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
}
void Game::FlipD(){
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(xa, ya, 0.0);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->New_Button("", "Textures/Tiles/Unknown", "Basic/Black", size, 0.05);
	H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(xb, yb, 0.0);
}
void Game::Play_Game(Hephaestus H, GLFWwindow* In){
	bool First = false, Check = false, BCheck = false;
	int Layer = -1, Button = -1, Action = -1, Update = 10;
	int Flip = 0, Pause = 0;
	X1 = 0;
	Y1 = 0;
	X2 = 0;
	Y2 = 0;
	size = 0.05;
	string Tiles_Textures[49] = {
		"Red",
		"Blue",
		"Green",
		"Purple",
		"Yellow",
		"Dark Blue",
		"Brown",
		"A Red",
		"A Blue",
		"A Green",
		"A Purple",
		"A Yellow",
		"A Dark Blue",
		"A Brown",
		"B Red",
		"B Blue",
		"B Green",
		"B Purple",
		"B Yellow",
		"B Dark Blue",
		"B Brown",
		"C Red",
		"C Blue",
		"C Green",
		"C Purple",
		"C Yellow",
		"C Dark Blue",
		"C Brown",
		"D Red",
		"D Blue",
		"D Green",
		"D Purple",
		"D Yellow",
		"D Dark Blue",
		"D Brown",
		"E Red",
		"E Blue",
		"E Green",
		"E Purple",
		"E Yellow",
		"E Dark Blue",
		"E Brown",
		"F Red",
		"F Blue",
		"F Green",
		"F Purple",
		"F Yellow",
		"F Dark Blue",
		"F Brown"
	};
	Score = 0;
	while (Good == true){
		if (Flip > 10 && Pause == 0){
			float t;
			Flip--;
			FlipA();
			size = size - 0.005;
		}
		if (Flip > 0 && Flip <= 10 && Pause == 0){
			Flip--;
			FlipB(Tiles_Textures[Grid[X1][Y1][1] - 1]);
			size = size + 0.0055;
		}
		if (Flip < -10 && Pause == 0){
			Flip++;
			FlipC(Tiles_Textures[Grid[X1][Y1][1] - 1]);
			size = size - 0.005;
		}
		if (Flip < 0 && Flip >= -10 && Pause == 0){
			Flip++;
			FlipD();
			size = size + 0.0055;
		}

		if (Pause > 0){
			Pause--;
		}
		if (Flip == 0 && Check == true && Pause == 0){
			Pause = 15;
			Check = false;
			BCheck = true;
		}
		if (Pause == 0 && BCheck == true && Flip == 0){
			size = 0.05;
			if (Grid[X1][Y1][1] == Grid[X2][Y2][1]){
				H_Game.Layers[1]->Button_Objects[Grid[X1][Y1][0]]->Translate_Button(5, 5, 0.0);
				H_Game.Layers[1]->Button_Objects[Grid[X2][Y2][0]]->Translate_Button(5, 5, 0.0);
				Grid[X1][Y1][3] = 1;
				Grid[X2][Y2][3] = 1;
			}
			else if (Grid[X1][Y1][1] != Grid[X2][Y2][1]){
				Flip = -20;
			}
			First = false;
			BCheck = false;
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
			if (First == false && Flip == 0 && Check == false && BCheck == false){
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
			else if (First == true && Flip == 0 && Check == false && BCheck == false){
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
					size = 0.05;
					Flip = 20;
					Check = true;
				}
			}
		}
		//if (Check_For_Win() == true){
		//	cout << "Win\n";
		//}
		Close();
		H_Game.Display_All_Layers();
		H_Game.Frame();
	}
}

void Game::Initilize_Game(string File, Hephaestus H, GLFWwindow* In){
	H_Game = H;
	window = In;
	Good = true;
	H_Game.Create_New_Layer();
	H_Game.Create_New_Layer();
	H_Game.Layers[0]->Initilize_Object(1);
	H_Game.Layers[0]->Colored_Objects[0]->New_Colored_Object(4, 1, 1, 1, 1, 1, 1, 0, 0);
	if (File == "NULL"){
		Genorate_Grid();
		Play_Game(H, In);
	}
	else if (File != "NULL"){
		Load_Grid(File);
		Play_Game(H, In);
	}
}