#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>

void displayFileSystem(const std::string& path, const std::string& indent = "") {
    DIR* directory;
    struct dirent* entry;
    struct stat fileInfo;

    if ((directory = opendir(path.c_str())) != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            std::string full_path = path + "/" + entry->d_name;

            if (stat(full_path.c_str(), &fileInfo) == 0) {
                if (S_ISDIR(fileInfo.st_mode)) {
                    if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
                        std::cout << indent << "📁 " << full_path << std::endl;
                        displayFileSystem(full_path, indent + "    "); 
                    }
                } else {
                    std::cout << indent << "📄 " << full_path << std::endl;
                }
            }
        }
        closedir(directory);
    }
}

int main() {
    const std::string rootDir = "/"; 
    displayFileSystem(rootDir);

    return 0;
}
