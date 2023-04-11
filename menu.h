/* La classe Menu permet de gérer les différents paramètres liés à la manette et au jeu.

Elles permet de :
	-Activer certains composants de la manette ou non (acceleromètre, etc)
	-Changer certains paramètres du jeu
	-Loader et sauvegarder une config
*/

///		Libraries
#include <iostream>
#include <fstream>
#include <conio.h>
#include "inputs/Keyboard.h"
#include <string>
#include <filesystem>
#include "application.h"

#include <chrono>
#include <thread>
///

#ifndef MENU_H
#define MENU_H
#define CONFIG_PATH "./config/game.config"		//Location du fichier config
#define LEVEL_PATH "./level"

#define NBR_CHOICE_MAIN 5
#define NBR_CHOICE_SETTINGS 4
#define NBR_CHOICE_LEVEL 3
#define NBR_CHOICE_CONTROLLER 5
#define NBR_COM 5
#define NBR_LEVEL_MODES 4
#define NBR_CHOICE_RESUME 2 

#define PLAY_GAME 1
#define CHOOSE_LEVEL 2
#define SETTINGS 3
#define CHOOSE_CONTROLLER 4
#define EXIT_MENU 5

#define PLAYING_MODE 1
#define LOAD_CONFIGURATION 2
#define SAVE_CONFIGURATION 3
#define EXIT_SETTINGS 4

#define LEVEL_STATUS 1
#define SAVE_LEVEL 2
#define EXIT_LEVEL 3

#define RESUME_GAME 1
#define EXIT_GAME 2


enum Input { _UP, _DOWN, _LEFT, _RIGHT, _ESC, _ENTER };

struct Config
{
	std::string name;
	short value;
};

class Menu
{
private:
	Config* parameters;
	Controller* _keyboard;
	QGraphicsScene* _scene;

	// Devra contenir les différents paramètres
	bool modeAccelerometer;
	bool modeJoystick;
	int screenWidth;
	int screenHeight;
    int level;
	bool play;
	short choice;
	bool over;
	short index;
	int index_x;
	bool temp;
	bool controllerMode = false;
	int comPort = 0;
	const short NBR_OF_PARAMETERS = Count_Parameters();
	const short NBR_OF_LEVELS = Count_Level();
	std::string _col_ = "32m";

	bool is_saved;
	bool is_load;
public:
	

	Menu();
	Menu(Controller* c);
	~Menu() { delete[] parameters;};


	void Update_data();
	void Update_config();
	int Count_Level();
	int Count_Parameters();

	void print(std::ostream & os);
	Input Navigate();
	void Main_Menu(std::ostream& os);
	bool Settings_Menu(std::ostream& os);
	bool Choose_Level_Menu(std::ostream& os);
	bool Choose_Controller_Menu(std::ostream& os);
	bool Resume_Menu(std::ostream& os);
	void Reset();
		

	bool LoadConfig();
	bool SaveConfig();


	void Set_screenWidth(int value) { screenWidth = value; };
	void Set_screenHeight(int value) { screenHeight = value; };
	void Set_modeAccelerometer() { modeAccelerometer = true; modeJoystick = false; };
	void Set_modeJoystick() { modeJoystick = true; modeAccelerometer = false; };
    void Set_Level(int value) { level = value; };
	void Set_playing(bool p) { play = p; };
	void Set_choice(short c) { choice = c; };
	void Set_controllerMode(bool mode) { controllerMode = mode;  };
	void Set_comPort(int port) { comPort = port; };
	void Set_Controller(Controller* c) { _keyboard = c; }


	int Get_screenWidth() { return screenWidth; };
	int Get_screenHeight() { return screenHeight; };
    int Get_Level() { return level; };
	short Get_choice() { return choice; };
	bool Get_controllerMode() { return controllerMode; };
	int Get_comPort() { return comPort; };
	QGraphicsScene* getScene() { return _scene; }
	Controller* Get_Controller() { return _keyboard; }

	void Change_mode() { if (modeJoystick) Set_modeAccelerometer(); else Set_modeJoystick(); };
	void Change_controllerMode() { controllerMode = !controllerMode; };
	void Change_Controller();
	bool Is_modeAccelerometer() { return modeAccelerometer; };
	bool Is_modeJoystick() { return modeJoystick; };
	bool Is_playing() { return play; };
	bool Is_over() { return over; };
};

void Intro(std::ostream& os);

#endif
