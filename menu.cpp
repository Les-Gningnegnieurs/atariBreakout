#include "menu.h"


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
    over = 0;
    index = 1;
}

void Menu::Update_data()
{
    screenWidth = parameters[0].value;
    screenHeight = parameters[1].value;
    modeAccelerometer = parameters[2].value;
    modeJoystick = parameters[3].value;
    level = parameters[4].value;

}

void Menu::Update_config()
{
    parameters[0].value = screenWidth;
    parameters[1].value = screenHeight;
    parameters[2].value = modeAccelerometer;
    parameters[3].value = modeJoystick;
    parameters[4].value = level;
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

void Menu::print(std::ostream& os)
{
    system("CLS");

    Main_Menu(os);
    
    

    

}

void Menu::Main_Menu(std::ostream& os)
{
    os << std::endl << std::endl << std::endl;
    switch (index)
    {
    case 1:
        os << "\x1B[32mPlay game\033[0m\n";
        os << "Settings\n";
        os << "Exit\n";
        break;
    case 2:
        os << "Play game\n";
        os << "\x1B[32mSettings\033[0m\n";
        os << "Exit\n";
        break;
    case 3:
        os << "Play game\n";
        os << "Settings\n";
        os << "\x1B[32mExit\033[0m\n";
        break;
    default:
        break;
    }

    Input in = Navigate();

    switch (in)
    {
    case _UP:
        if (index > 1) index--;
        break;
    case _DOWN:
        if (index < NBR_CHOICE_MAIN) index++;
        break;
    case _ESC:
        break;
    case _ENTER:
        switch (index)
        {
        case PLAY_GAME:
            over = true;
            play = true;
            break;
        case SETTINGS:
            index = 1;
            while (Settings_Menu(std::cout));
            index = 1;
            break;
        case EXIT_MENU:
            over = true;
            play = false;
            break;
        }
        break;
    }
}

bool Menu::Settings_Menu(std::ostream& os)
{
    system("CLS");
    os << std::endl << std::endl << std::endl;
    switch (index)
    {
    case 1:
        os << "\x1B[32mPlaying Mode\033[0m\n";
        os << "Load Configuration\n";
        os << "Save Configuration\n";
        os << "Exit\n";
        break;
    case 2:
        os << "Playing Mode\n";
        os << "\x1B[32mLoad Configuration\033[0m\n";
        os << "Save Configuration\n";
        os << "Exit\n";
        break;
    case 3:
        os << "Playing Mode\n";
        os << "Load Configuration\n";
        os << "\x1B[32mSave Configuration\033[0m\n";
        os << "Exit\n";
        break;
    case 4:
        os << "Playing Mode\n";
        os << "Load Configuration\n";
        os << "Save Configuration\n";
        os << "\x1B[32mExit\033[0m\n";
        break;
    default:
        break;
    }

    Input in = Navigate();
    switch (in)
    {
    case _UP:
        if (index > 1) index--;
        break;
    case _DOWN:
        if (index < NBR_CHOICE_SETTINGS) index++;
        break;
    case _ESC:
        break;
    case _ENTER:
        switch (index)
        {
        case PLAYING_MODE:
            break;
        case LOAD_CONFIGURATION:
            LoadConfig();
            break;
        case SAVE_CONFIGURATION:
            SaveConfig();
            break;
        case EXIT_SETTINGS:
            return false;
            break;
        }
        break;
    }
    
    return true;
}


Input Menu::Navigate()
{
    choice = getch();
    if (choice == 72) return _UP;
    if (choice == 80) return _DOWN;
    if (choice == 13) return _ENTER;
    if (choice == 27) return _ESC;
}

void Menu::Intro(std::ostream& os)
{
    os << std::endl << std::endl << std::endl;
    os << "\x1B[32m                                     LL      EEEEEE  SSSSSS\033[0m\n";
    os << "\x1B[32m                                     LL      EE      SS\033[0m\n";
    os << "\x1B[32m                                     LL      EEEE    SSSSSS\033[0m\n";
    os << "\x1B[32m                                     LL      EE          SS\033[0m\n";
    os << "\x1B[32m                                     LLLLLL  EEEEEE  SSSSSS\033[0m\n";

    std::cout << std::endl << std::endl << std::endl;

    os << "\x1B[32mGGGGGGG  NN   NN  II  GGGGGGG  NN   NN  EEEEEE  GGGGGGG  NN   NN  EEEEEE  UU  UU  RRRRRR  SSSSSS\033[0m\n";
    os << "\x1B[32mGG       NNN  NN  II  GG       NNN  NN  EE      GG       NNN  NN  EE      UU  UU  RR  RR  SS\033[0m\n";
    os << "\x1B[32mGG   GG  NNNNNNN  II  GG   GG  NNNNNNN  EEEE    GG   GG  NNNNNNN  EEEE    UU  UU  RRRRR   SSSSSS\033[0m\n";
    os << "\x1B[32mGG    G  NN  NNN  II  GG    G  NN  NNN  EE      GG    G  NN  NNN  EE      UU  UU  RR  RR      SS\033[0m\n";
    os << "\x1B[32mGGGGGGG  NN   NN  II  GGGGGGG  NN   NN  EEEEEE  GGGGGGG  NN   NN  EEEEEE  UUUUUU  RR   R  SSSSSS\033[0m\n";

    Sleep(1000);
    system("CLS");

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
