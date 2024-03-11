//показывает содержимое и тд 
 


// Этот код показывает содержимое папок и текстовых файлов, работает на таких сайтах как
// -- https://www.programiz.com/cpp-programming/online-compiler/
// -- и еще пару штук, я их потерял)





#include <string> 
#include <iostream> 
#include <fstream> 
#include <filesystem> 
namespace fs = std::filesystem; 
 
void readContentsOfFile(const std::string& filePath) { 
    std::ifstream file(filePath); 
    if (file.is_open()) { 
        std::string line; 
        while (std::getline(file, line)) { 
            std::cout << line << std::endl; 
        } 
        file.close(); 
    } else { 
        std::cerr << "Error opening file " << filePath << std::endl; 
    } 
} 
 
int main() 
{ 
    std::string path = "/"; // сюда путь 
     
    if (fs::is_directory(path)) { 
        for (const auto & entry : fs::directory_iterator(path)) 
            std::cout << entry.path() << std::endl; 
    } else { 
        readContentsOfFile(path); 
    } 
 
    return 0; 
}