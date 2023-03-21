#include "menu.h"


/* ------------------- PARAMÈTRE DE LA CONFIG -------------------
 *
 * POUR AJOUTER OU RETIRER UN PARAMÈTRE DE LA CONFIG, IL FAUT
 * MODIFIER LES TROIS FONCTIONS SUIVANTES ET AJOUTER L'ATTRIBUT
 * CORRESPONDANT DANS LE .H. DE PLUS, IL FAUT MODIFIER LA CONSTANTE
 * NUMBER_OF_PARAMETERS DANS LE FICHIER MENU.H VOIR ALEX SI DES
 * PROBLÈMES S'IMPOSENT.
 */
Menu::Menu()
{
    parameters = new Config[NUMBER_OF_PARAMETERS];

    parameters[0].name = "SCREEN_WIDTH";
    parameters[1].name = "SCREEN_HEIGHT";
    parameters[2].name = "MODE_ACCELEROMETER";
    parameters[3].name = "MODE_JOYSTICK";
    parameters[4].name = "SELECT_LEVEL";

    LoadConfig();

    over = 0;
    index = 1;
}

Menu::Menu(Controller* c)
{
    _keyboard = c;
    parameters = new Config[NUMBER_OF_PARAMETERS];

    parameters[0].name = "SCREEN_WIDTH";
    parameters[1].name = "SCREEN_HEIGHT";
    parameters[2].name = "MODE_ACCELEROMETER";
    parameters[3].name = "MODE_JOYSTICK";
    parameters[4].name = "SELECT_LEVEL";

    LoadConfig();

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

/* ---------------------- SAVE/LOAD CONFIG ----------------------
 *
 * LES DEUX FONCTIONS SUIVANTES PERMETTENT DE CHARGER ET
 * D'ENRERISTRER LES PARAMÈTRES DU JEU. LE CHEMIN VERS LE FICHIER
 * CONTENANT CES PARAMÈTRES EST SPÉCIFIER PAR LA CONSTANTE
 * CONFIG_PATH DANS LE FICHIER MENU.H.
 */

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

        for (int i = 0; i < NUMBER_OF_PARAMETERS; i++)
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

    for (int i = 0; i < NUMBER_OF_PARAMETERS; i++)
    {
        file << parameters[i].name << " " << parameters[i].value << std::endl;
    }

    file.close();
    
    return true;
}


/* ---------------------- INTERFACE DU MENU ----------------------
 *
 * 
 */
void Menu::print(std::ostream& os)
{
    system("CLS");
    os << "FROM KEYBOARD : UP\tDOWN\tENTER\tESC\t";
    Main_Menu(os);
}

void Menu::Main_Menu(std::ostream& os)
{
    os << std::endl << std::endl << std::endl;
    switch (index)
    {
    case 1:
        os << "\x1B[32mPlay game\033[0m\n";
        os << "Change Level\n";
        os << "Settings\n";
        os << "Change controller mode\n";
        os << "Exit\n";
        break;
    case 2:
        os << "Play game\n";
        os << "\x1B[32mChange Level\033[0m\n";
        os << "Settings\n";
        os << "Change controller mode\n";
        os << "Exit\n";
        break;
    case 3:
        os << "Play game\n";
        os << "Change Level\n";
        os << "\x1B[32mSettings\033[0m\n";
        os << "Change controller mode\n";
        os << "Exit\n";
        break;
    case 4:
        os << "Play game\n";
        os << "Change Level\n";
        os << "Settings\n";
        os << "\x1B[32mChange controller mode\033[0m\n";
        os << "Exit\n";
    break;
    case 5:
        os << "Play game\n";
        os << "Change Level\n";
        os << "Settings\n";
        os << "Change controller mode\n";
        os << "\x1B[32mExit\033[0m\n";
        break;
    default:
        break;
    }


    Input in = Navigate();
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

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
        case CHOOSE_LEVEL:
            index = 1;
            index_x = level;
            while (Choose_Level_Menu(std::cout));
            index = 1;
            break;
        case SETTINGS:
            index = 1;
            while (Settings_Menu(std::cout));
            index = 1;
            break;
        case CHOOSE_CONTROLLER:
            index = 1;
            index_x = comPort;
            temp = false;
            while (Choose_Controller_Menu(std::cout));
            temp = false;
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

bool Menu::Choose_Level_Menu(std::ostream& os)
{
    system("CLS");
    os << std::endl << std::endl << std::endl;
    switch (index)
    {
    case 1:
        os << "\x1B[32mLevel\033[0m\t";
        os << "\x1B[32m" << index_x << "\033[0m\n";
        os << "Set Level\n";
        os << "Exit\n";
        break;
    case 2:
        os << "Level\t";
        os << index_x << "\n";
        os << "\x1B[32mSet Level\033[0m\n";
        os << "Exit\n";
        break;
    case 3:
        os << "Level\t";
        os << index_x << "\n";
        os << "Set Level\n";
        os << "\x1B[32mExit\033[0m\n";
        break;
    }

    Input in = Navigate();
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    switch (in)
    {
    case _UP:
        if (index > 1) index--;
        break;
    case _DOWN:
        if (index < NBR_CHOICE_LEVEL) index++;
        break;
    case _LEFT:
        if (index == 1 && index_x > 1) index_x--;
        break;
    case _RIGHT:
        if (index == 1 && index_x < NBR_LEVEL_MODES) index_x++;
        break;
    case _ESC:
        break;
    case _ENTER:
        switch (index)
        {
        case LEVEL_STATUS:
            break;
        case SAVE_LEVEL:
            level = index_x;
            SaveConfig();
            break;
        case EXIT_LEVEL:
            return false;
            break;
        }
        break;
    }

    return true;
}

bool Menu::Choose_Controller_Menu(std::ostream& os)
{
    system("CLS");
    os << std::endl << std::endl << std::endl;
    std::string m = temp ? "< Controller" : "Keyboard >"; 

    switch (index)
    {
    case 1:
        os << "\x1B[32mCOM :\033[0m\t";
        os << "\x1B[32m" << index_x << "\033[0m\n";
        os << "Set COM\n";
        os << "INPUT :\t";
        os << m << "\n";
        os << "Set Input\n";
        os << "Exit\n";
        break;
    case 2:
        os << "COM\t";
        os << index_x << "\n";
        os << "\x1B[32mSet COM\033[0m\n";
        os << "INPUT :\t";
        os << m << "\n";
        os << "Set Input\n";
        os << "Exit\n";
        break;
    case 3:
        os << "COM\t";
        os << index_x << "\n";
        os << "Set COM\n";
        os << "\x1B[32mINPUT :\033[0m\t";
        os << "\x1B[32m" << m << "\033[0m\n";
        os << "Set Input\n";
        os << "Exit\n";
        break;
    case 4:
        os << "COM\t";
        os << index_x << "\n";
        os << "Set COM\n";
        os << "INPUT :\t";
        os << m << "\n";
        os << "\x1B[32mSet Input\033[0m\n";
        os << "Exit\n";
        break;
    case 5:
        os << "COM\t";
        os << index_x << "\n";
        os << "Set COM\n";
        os << "INPUT :\t";
        os << m << "\n";
        os << "Set Input\n";
        os << "\x1B[32mExit\033[0m\n";
        break;
    }

    Input in = Navigate();
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    switch (in)
    {
    case _UP:
        if (index > 1) index--;
        break;
    case _DOWN:
        if (index < NBR_CHOICE_CONTROLLER) index++;
        break;
    case _LEFT:
        if (index == 1 && index_x > 0) index_x--;
        if (index == 3) temp = !temp;
        break;
    case _RIGHT:
        if (index == 1 && index_x < NBR_COM) index_x++;
        if (index == 3) temp = !temp;
        break;
    case _ESC:
        break;
    case _ENTER:
        switch (index)
        {
        case 2:
            Set_comPort(index_x);
            break;
        case 4:
            Set_controllerMode(temp);
            Change_Controller();
            break;
        case 5:
            return false;
            break;
        }
        break;
    }

    return true;
}

bool Menu::Settings_Menu(std::ostream& os)
{
    system("CLS");
    os << std::endl << std::endl << std::endl;
    switch (index)
    {
    case 1:
        os << "\x1B[32mPlaying Mode\033[0m\t";
        if (Is_modeJoystick()) os << "\x1B[32m[JOYSTICK]\033[0m\n";
        else os << "\x1B[32m[ACCELEROMETER]\033[0m\n";
        os << "Load Configuration\n";
        os << "Save Configuration\n";
        os << "Exit\n";
        break;
    case 2:
        os << "Playing Mode\t";
        if (Is_modeJoystick()) os << "[JOYSTICK]\n";
        else os << "[ACCELEROMETER]\n";
        os << "\x1B[32mLoad Configuration\033[0m\n";
        os << "Save Configuration\n";
        os << "Exit\n";
        break;
    case 3:
        os << "Playing Mode\t";
        if (Is_modeJoystick()) os << "[JOYSTICK]\n";
        else os << "[ACCELEROMETER]\n";
        os << "Load Configuration\n";
        os << "\x1B[32mSave Configuration\033[0m\n";
        os << "Exit\n";
        break;
    case 4:
        os << "Playing Mode\t";
        if (Is_modeJoystick()) os << "[JOYSTICK]\n";
        else os << "[ACCELEROMETER]\n";
        os << "Load Configuration\n";
        os << "Save Configuration\n";
        os << "\x1B[32mExit\033[0m\n";
        break;
    }

    Input in = Navigate();
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

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
            Change_mode();
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
    while (1) // APPUYEZ SUR UNE TOUCHE VALIDE POUR SORTIR DE LA BOUCLE
    { 
        _keyboard->receiveInputs();
        if (_keyboard->getJoystick().y == -1) return _UP;
        if (_keyboard->getJoystick().y == 1) return _DOWN;
        if (_keyboard->getJoystick().x == -1) return _LEFT;
        if (_keyboard->getJoystick().x == 1) return _RIGHT;
        if (_keyboard->getButton(1) == 1) return _ENTER;
        if (_keyboard->getButton(2) == 1) return _ESC;
        Sleep(SLEEP);
    }
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

void Menu::Change_Controller() {
    if (Get_controllerMode()) {
        std::string c = "com" + std::to_string(Get_comPort());
        _keyboard = new PhysicalController(c);
    }
    else
        _keyboard = new Keyboard();
}

