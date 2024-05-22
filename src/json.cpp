#include "json.h"

#include <utility>

void jsonProject::readJsonFile(const std::string& fileName)
{
    std::filesystem::path if_json(json_folder);
    if_json /= fileName;

    fmt::print("{}\n", if_json.string());

    using json = nlohmann::json;
    std::ifstream ifs(if_json.string());
    try
    {
        jsonFile = json::parse(ifs);
    }
    catch (json::parse_error& ex)
    {
        fmt::print(stderr, "parse json file {}\n", if_json.string());
        fmt::print(stderr, "message: {}\n", ex.what());
        fmt::print(stderr, "exception id: {}\n", ex.id);
        fmt::print(stderr, "byte position of error: {}\n", ex.byte);
    }
    auto prj_name = jsonFile.value("project_name", "default");
}

void jsonProject::loadJsonFile(std::vector<std::unique_ptr<Element>>& vec){
    for (auto& [key, val] : jsonFile.items()){
//        fmt::print("key: {}\n", key);
        if (val.is_object() && val.contains("type")
            && val.at("type") == "pipe"){
            vec.emplace_back(std::move(std::make_unique<Pipe>(
                    key,
                    val["x start"],
                    val["z start"],
                    val["x end"],
                    val["z end"],
                    val["diameter"],
                    val["roughness coefficient"],
                    val["upstream"],
                    val["downstream"])));
        }else if (val.is_object() && val.contains("type")
            && val.at("type") == "boundary condition"){
            vec.emplace_back(std::move(std::make_unique<Local>(
                    key,
                    val["input value"],
                    val["upstream"],
                    val["downstream"])));
        }
    }
}

