#include "menu.h"

int main()
{
    Menu menu;

    //menu.loadConfig();

    //using namespace std;
    //cout << menu.get_modeAccelerometer() << endl;
    //cout << menu.get_modeJoystick() << endl;
    //cout << menu.get_screenHeight() << endl;
    //cout << menu.get_screenWidth() << endl;

    //menu.set_modeAccelerometer();
    //menu.set_screenHeight(900);
    //menu.set_screenWidth(1600);

    //menu.saveConfig("config/new config.config");

    return 0;
}

Menu::Menu()
{
    parameters = new Config[NUMBER_OF_PARAMETERS];

    parameters[0].name = "SCREEN_WIDTH";
    parameters[1].name = "SCREEN_HEIGHT";
    parameters[2].name = "MODE_ACCELEROMETER";
    parameters[3].name = "MODE_JOYSTICK";
}

void Menu::update_data()
{
    screenWidth = parameters[0].value;
    screenHeight = parameters[1].value;
    modeAccelerometer = parameters[2].value;
    modeJoystick = parameters[3].value;
}

void Menu::update_config()
{
    parameters[0].value = screenWidth;
    parameters[1].value = screenHeight;
    parameters[2].value = modeAccelerometer;
}

Menu::~Menu() { delete[] parameters; }

bool Menu::loadConfig()
{
   std::ifstream file(CONFIG_PATH);

    if (!file.is_open())
    {
        std::cout << "Ouverture du fichier config echoue depuis: " << CONFIG_PATH << std::endl;
        return false;
    }

    std::string parameter;
    int value;

    while (!file.eof())
    {
        file >> parameter;
        file >> value;

        for (int i = 0; i < NUMBER_OF_PARAMETERS; i++)
        {
            if (parameter == parameters[i].name)
                parameters[i].value = value;
        }
    }

    update_data();

    file.close();

    return true;
}		


bool Menu::saveConfig(std::string location)
{
    update_config();
    
    std::ofstream file(location);

    if (!file.is_open())
    {
        std::cout << "Creation du fichier config echoue a l'adresse: " << location << std::endl;
        return false;
    }

    for (int i = 0; i < NUMBER_OF_PARAMETERS; i++)
    {
        file << parameters[i].name << " " << parameters[i].value << std::endl;
    }

    file.close();

    return true;
}

void Menu::set_screenWidth(int value)
{
    screenWidth = value;
}


void Menu::set_screenHeight(int value)
{
    screenHeight = value;
}

void Menu::set_modeAccelerometer()
{
    modeAccelerometer = true;
    modeJoystick = false;
}

void Menu::set_modeJoystick()
{
    modeJoystick = true;
    modeAccelerometer = false;
}

int Menu::get_screenWidth()
{
    return screenWidth;
}

int Menu::get_screenHeight()
{
    return screenHeight;
}

bool Menu::get_modeAccelerometer()
{
    return modeAccelerometer;
}

bool Menu::get_modeJoystick()
{
    return modeJoystick;
}
