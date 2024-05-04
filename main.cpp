#include <fmt/core.h>
#include <iostream>
#include <cmath>
#include <vector>
//#include <nlohmann/json.hpp>
//#include <fstream>


class Local{
private:
    double coefficient;
public:
    Local(double K){
        coefficient = K;
    }
    double pressureDrop(double flow) {
        double drop = coefficient * pow(flow, 2);
        return drop;
    }
};

class Pipe{
private:
    double diameter;
    double length;
    double friction;
    double constant = 8 / (9.81 * pow(M_PI,2));
public:
    Pipe(double D, double L, double F){
        diameter = D; length = L; friction = F;
    }
    double pressureDrop(double flow) {
        double drop = constant * length * friction * pow(flow, 2) / pow(diameter, 5);
        return drop;
    }
};

class Series{
private:
    double flow;
public:
    Series(double Q){
        flow = Q;
    }
    // Add pipe to the series
    std::vector<Pipe> pipes;
    std::vector<Local> locals;

    void addPipe(const Pipe& pipe) {
    pipes.push_back(pipe);
    }
    void addLocal(const Local& local) {
        locals.push_back(local);
    }

    double totalPressureDrop() {
        double totalDrop = 0.0;
        for (auto& pipe : pipes) {
            totalDrop += pipe.pressureDrop(flow);
        }
        for (auto& local : locals) {
            totalDrop += local.pressureDrop(flow);
        }
        return totalDrop;
    }
};


int main()
{
    Pipe pipe1(1,100,0.001);
    Pipe pipe2(1.5,50,0.001);
    Local local1(0.003);
    Local local2(0.002);

    Series system(30);
    system.addPipe(pipe1);
    system.addPipe(pipe2);
    system.addLocal(local1);
    system.addLocal(local2);

    fmt::print("{}: {}\n", "pipe1", pipe1.pressureDrop(30));
    fmt::print("{}: {}\n", "pipe2", pipe2.pressureDrop(30));
    fmt::print("{}: {}\n", "local1", local1.pressureDrop(30));
    fmt::print("{}: {}\n", "local2", local2.pressureDrop(30));

    fmt::print("{}: {}\n", "system", system.totalPressureDrop());
    return 0;
}

//using json = nlohmann::json;

//int main()
//{
//    std::ifstream file("input.json");
//    nlohmann::json data = nlohmann::json::parse(file);
//    std::cout << data<< std::endl;

//    fmt::print("{}: {}\n", "odgovor", 42);
//    return 0;
//}

