#ifndef MODULENOVAK_H_INCLUDED
#define MODULENOVAK_H_INCLUDED

void saveRegistryData(const std::vector<Record>& registry, const std::string& filename);

void loadRegistryData(std::vector<Record>& registry, const std::string& filename);

void outputRegistry(const std::vector<Record>& registry, const std::string& filename = "");

void exitProgram(const std::vector<Record>& registry, const std::string& filename)

#endif // MODULENOVAK_H_INCLUDED
