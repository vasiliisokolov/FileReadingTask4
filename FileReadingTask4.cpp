#include <iostream>
#include <fstream>

bool check_adress(std::string&);

int main()
{
    std::fstream file;
    std::string adress;
    char buffer[4];
    bool is_ping = false;
    std::cout << "File check!" << std::endl;
    std::cout << "Enter file adress" << std::endl;
    std::cin >> adress;
    
        //C:\\Practik\\Image.png
    file.open(adress);
    if (!file)
    {
        std::cerr << "File not found!" << std::endl;
    }
    else
    {
        check_adress(adress);
        std::cout << "Working!" << std::endl;
        if (check_adress(adress))
        {
            file.read(buffer, sizeof(buffer));
                if ((int)buffer[0] == (int)-119 && buffer[1] == 'P' 
                    && buffer[2] == 'N' && buffer[3] == 'G')
                {
                    is_ping = true;

                }
        }
        
        (is_ping ? std::cout << "Png found!" : std::cout << "Png not found!");
        file.close();
    }
    
}
bool check_adress(std::string& adress)
{
    int len = adress.length();
    
    if (adress[len - 3] == 'p' && adress[len - 2] == 'n' && adress[len - 1] == 'g')
    {
        return true;
    }
    else
    {
        return false;
    }
}
