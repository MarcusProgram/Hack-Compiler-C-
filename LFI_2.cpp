//cmd ls 
 

// Это работает абсолютно везде, это своеобразный ls без sudo, показывает только содержимое папок

#include <iostream> 
#include <dirent.h> 
 
int main(int argc, char* argv[]) { 
    const char* path = "/"; 
    if (argc >= 2) { 
        path = argv[1]; 
    } 
 
    DIR* directory; 
    struct dirent* entry; 
 
    if ((directory = opendir(path)) != NULL) { 
        while ((entry = readdir(directory)) != NULL) { 
            std::cout << entry->d_name << std::endl; 
        } 
        closedir(directory); 
    } else { 
        std::cerr << "Error opening directory " << path << std::endl; 
    } 
 
    return 0; 
}
