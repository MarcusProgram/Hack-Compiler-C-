#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>

void searchFiles(const std::string& path, const std::string& targetFile, std::vector<std::string>& foundFiles) {
    DIR* directory;
    struct dirent* entry;
    struct stat fileInfo;

    if ((directory = opendir(path.c_str())) != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            std::string full_path = path + "/" + entry->d_name;

            if (stat(full_path.c_str(), &fileInfo) == 0) {
                if (S_ISDIR(fileInfo.st_mode)) {
                    if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
                        searchFiles(full_path, targetFile, foundFiles);
                    }
                } else if (S_ISREG(fileInfo.st_mode)) {
                    if (std::string(entry->d_name) == targetFile) {
                        foundFiles.push_back(full_path);
                    }
                }
            }
        }
        closedir(directory);
    } 
   
}

int main() {
    const std::string rootDir = "/proc"; // dir
    const std::string targetFile = "passwd"; // file
    std::vector<std::string> foundFiles;

    searchFiles(rootDir, targetFile, foundFiles);

    if (foundFiles.empty()) {
        std::cout << "File not found." << std::endl;
    } else {
        std::cout << "Found " << foundFiles.size() << " occurrences of '" << targetFile << "':" << std::endl;
        for (const auto& file : foundFiles) {
            std::cout << file << std::endl;
        }
    }

    return 0;
}
