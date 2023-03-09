/* La classe Menu permet de gérer les différents paramètres liés à la manette et au jeu.

Elles permet de :
	-Activer certains composants de la manette ou non (acceleromètre, etc)
	-Changer certains paramètres du jeu
	-Loader et sauvegarder une config
*/

///		Libraries
#include <iostream>
#include <fstream>
#include "GameLoop.h"
#include <conio.h>

///

#ifndef MENU_H
#define MENU_H
#define CONFIG_PATH "./config/game.config"		//Location du fichier config

#define NUMBER_OF_PARAMETERS 5
#define NBR_CHOICE_MAIN 3
#define NBR_CHOICE_SETTINGS 4

#define PLAY_GAME 1
#define SETTINGS 2
#define EXIT_MENU 3

#define PLAYING_MODE 1
#define LOAD_CONFIGURATION 2
#define SAVE_CONFIGURATION 3
#define EXIT_SETTINGS 4


enum Input { _UP, _DOWN, _ESC, _ENTER };

struct Config
{
	std::string name;
	short value;
};

class Menu
{
private:
	Config* parameters;

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

public:
	Menu();
	~Menu();

	void Update_data();
	void Update_config();

	void print(std::ostream & os);
	void Intro(std::ostream& os);
	Input Navigate();
	void Main_Menu(std::ostream& os);
	bool Settings_Menu(std::ostream& os);
		

	bool LoadConfig();
	bool SaveConfig();


	void Set_screenWidth(int value);
	void Set_screenHeight(int value);
	void Set_modeAccelerometer();
	void Set_modeJoystick();
    void Set_Level(int value);
	void Set_playing(bool p) { play = p; };
	void Set_choice(short c) { choice = c; };


	int Get_screenWidth();
	int Get_screenHeight();
    int Get_Level();
	short Get_choice() { return choice; };

	void Change_mode();
	bool Is_modeAccelerometer();
	bool Is_modeJoystick();
	bool Is_playing() { return play; };
	bool Is_over() { return over; };
};


#endif
