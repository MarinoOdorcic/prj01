#ifndef PRJ01_JSON_H
#define PRJ01_JSON_H

#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include <fmt/core.h>
#include <filesystem>
#include <fstream>

#include "pathconfig.h"
#include "element.h"
#include "pipe.h"
#include "local.h"

class jsonProject {
private:
    nlohmann::json jsonFile;
public:
    void readJsonFile(const std::string& fileName);
    void loadJsonFile(std::vector<std::unique_ptr<Element>>& vec);
};


#endif //PRJ01_JSON_H
