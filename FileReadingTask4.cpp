#include <iostream>
#include <fstream>


int main()
{
    std::string adress;
    std::fstream file;
    char buffer[4];
    bool is_ping = false;
    std::cout << "File check!" << std::endl;
        
    file.open("C:\\Practik\\Image.png");
    if (!file)
    {
        std::cerr << "File not found!" << std::endl;
    }
    else
    {
        std::cout << "Working!" << std::endl;
        int temp1 = 0;
        char temp;
        file.read(buffer,sizeof(buffer));
        if ((int)buffer[0] == (int) - 119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')
        {            
            is_ping = true;
            
        }
        
        (is_ping ? std::cout << "Png found!" : std::cout << "Png not found!");
        file.close();
    }
    
}
