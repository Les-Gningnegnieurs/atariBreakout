#include "menu.h"

/*int main()
{
    Menu menu;

    //menu.LoadConfig();

    //using namespace std;
    //cout << menu.Get_modeAccelerometer() << endl;
    //cout << menu.Get_modeJoystick() << endl;
    //cout << menu.Get_screenHeight() << endl;
    //cout << menu.Get_screenWidth() << endl;

    menu.Set_modeJoystick();
    menu.Set_screenHeight(900);
    menu.Set_screenWidth(1600);

    menu.SaveConfig();

    return 0;
}*/

/* ----------- PARAMÈTRE DE LA CONFIG --------------
 *
 * POUR AJOUTER OU RETIRER UN PARAMÈTRE DE LA CONFIG,
 * IL FAUT MODIFIER LES TROIS FONCTIONS SUIVANTES ET
 * AJOUTER L'ATTRIBUT CORRESPONDANT DANS LE .H.
 * DE PLUS IL FAUT DÉFINIR LES GETTERS/SETTERS.
 */

Menu::Menu()
{
    parameters = new Config[NUMBER_OF_PARAMETERS];

    parameters[0].name = "SCREEN_WIDTH";
    parameters[1].name = "SCREEN_HEIGHT";
    parameters[2].name = "MODE_ACCELEROMETER";
    parameters[3].name = "MODE_JOYSTICK";
    parameters[4].name = "SELECT_LEVEL";

    Update_data();
}

void Menu::Update_data()
{
    screenWidth = parameters[0].value;
    screenHeight = parameters[1].value;
    modeAccelerometer = parameters[2].value;
    modeJoystick = parameters[3].value;
    parameters[4].value=level;

}

void Menu::Update_config()
{
    parameters[0].value = screenWidth;
    parameters[1].value = screenHeight;
    parameters[2].value = modeAccelerometer;
    parameters[3].value = modeJoystick;
    parameters[4].value=level;
}

Menu::~Menu() { delete[] parameters; }

bool Menu::LoadConfig()
{
   std::ifstream file(CONFIG_PATH);

    if (!file.is_open())
    {
        std::cout << "Ouverture du fichier config echoue depuis: " << CONFIG_PATH << std::endl;
        return false;
    }

    std::string parameter;
    short value;

    while (!file.eof())
    {
        file >> parameter;
        file >> value;

        for (int i = 0; i < NUMBER_OF_PARAMETERS - 1; i++)
        {
            if (parameter == parameters[i].name)
                parameters[i].value = value;
        }
    }

    Update_data();

    file.close();

    return true;
}		


bool Menu::SaveConfig()
{
    Update_config();
    
    std::ofstream file(CONFIG_PATH);

    if (!file.is_open())
    {
        std::cout << "Creation du fichier config echoue a l'adresse: " << CONFIG_PATH << std::endl;
        return false;
    }

    for (int i = 0; i < NUMBER_OF_PARAMETERS - 1; i++)
    {
        file << parameters[i].name << " " << parameters[i].value << std::endl;
    }

    file.close();

    return true;
}

void Menu::Set_screenWidth(int value)
{
    screenWidth = value;
}


void Menu::Set_screenHeight(int value)
{
    screenHeight = value;
}

void Menu::Set_modeAccelerometer()
{
    modeAccelerometer = true;
    modeJoystick = false;
}

void Menu::Set_modeJoystick()
{
    modeJoystick = true;
    modeAccelerometer = false;
}
void Menu::Set_Level(int value)
{
    level=value;
}

int Menu::Get_screenWidth()
{
    return screenWidth;
}

int Menu::Get_screenHeight()
{
    return screenHeight;
}
int Menu::Get_Level()
{
    return level;
}

bool Menu::Is_modeAccelerometer()
{
    return modeAccelerometer;
}

bool Menu::Is_modeJoystick()
{
    return modeJoystick;
}
