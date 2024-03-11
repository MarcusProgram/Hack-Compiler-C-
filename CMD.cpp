#include <cstdlib> 
#include <iostream> 

int main() { 
    FILE *pipe = popen("cd /etc/ | mkdir \"good2\"", "r");  // сюда любую команду не трубующую особого разрешения
    if (!pipe) { 
        std::cerr << "Error running command." << std::endl; 
        return 1; 
    } 

    char buffer[128]; 
    while (fgets(buffer, 128, pipe) != NULL) { 
        std::cout << buffer; 
    } 

    pclose(pipe); 

    return 0; 
}