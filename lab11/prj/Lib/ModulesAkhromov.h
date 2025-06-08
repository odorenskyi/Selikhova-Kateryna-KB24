#ifndef MODULEAKHROMOV_H_INCLUDED
#define MODULEAKHROMOV_H_INCLUDED

void saveRegistryData(const std::vector<Record>& registry, const std::string& filename);

void loadRegistryData(std::vector<Record>& registry, const std::string& filename);

void outputRegistry(const std::vector<Record>& registry, const std::string& filename = "");

void exitProgram(const std::vector<Record>& registry, const std::string& filename)

#endif // MODULEAKHROMOV_H_INCLUDED
