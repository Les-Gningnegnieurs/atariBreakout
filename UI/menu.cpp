#include "menu.h"
////// LEVEL DOIT ETRE DONNÉE PAR COUNT LEVEL

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
    parameters = new Config[NBR_OF_PARAMETERS+1];

    parameters[0].name = "SCREEN_WIDTH";
    parameters[1].name = "SCREEN_HEIGHT";
    parameters[2].name = "MODE_ACCELEROMETER";
    parameters[3].name = "MODE_JOYSTICK";
    parameters[4].name = "SELECT_LEVEL";

    LoadConfig();

    over = false;
    index = 1;
}

Menu::Menu(Controller* c)
{
    _keyboard = c;
    parameters = new Config[NBR_OF_PARAMETERS + 1];
    
    parameters[0].name = "SCREEN_WIDTH";
    parameters[1].name = "SCREEN_HEIGHT";
    parameters[2].name = "MODE_ACCELEROMETER";
    parameters[3].name = "MODE_JOYSTICK";
    parameters[4].name = "SELECT_LEVEL";

    LoadConfig();

    over = false;
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

    int i = 0;
    while (!file.eof())
    {
        file >> parameter;
        file >> value;
        parameters[i].name = parameter;
        parameters[i++].value = value;
    }

    Update_data();

    file.close();

    return true;
}

void Menu::Reset() {
    over = false;
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

    for (int i = 0; i < NBR_OF_PARAMETERS; i++)
        file << parameters[i].name << " " << parameters[i].value << std::endl;
    
    file.close();

    return true;
}


int Menu::Count_Level()
{
    int count = 0;

    for (const auto& entry : std::filesystem::directory_iterator(LEVEL_PATH)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            count++;
        }
    }

    return count;
}

int Menu::Count_Parameters()
{
    std::ifstream file(CONFIG_PATH);
    int count = 0;
    std::string line;

    while (std::getline(file, line)) {
        count++;
    }

    return count;
}



void Menu::Change_Controller() {

    if (Get_controllerMode()) {
        if (_keyboard != nullptr)
            delete _keyboard;
        std::string c = "com" + std::to_string(Get_comPort());
        _keyboard = new PhysicalController(c);
    }
     if (!_keyboard->ConnectionStatus())
        {
            emit connectionFailed();
            delete _keyboard;
            _keyboard = new Keyboard();
            
        }
    
   
    
}

