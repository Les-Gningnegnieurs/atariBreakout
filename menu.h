/* La classe Menu permet de gérer les différents paramètres liés à la manette et au jeu.

Elles permet de :
	-Activer certains composants de la manette ou non (acceleromètre, etc)
	-Changer certains paramètres du jeu
	-Loader et sauvegarder une config
*/

///		Libraries
#include <iostream>
#include <fstream>
///

#ifndef MENU_H
#define MENU_H
#define CONFIG_PATH "./config/game.config"		//Location du fichier config
#define NUMBER_OF_PARAMETERS 4

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

public:
	Menu();
	~Menu();

	void update_data();
	void update_config();


	bool loadConfig();
	bool saveConfig();


	void set_screenWidth(int value);
	void set_screenHeight(int value);
	void set_modeAccelerometer();
	void set_modeJoystick();


	int get_screenWidth();
	int get_screenHeight();

	bool is_modeAccelerometer();
	bool is_modeJoystick();
};


#endif
