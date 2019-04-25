#include <iostream>
#include <vector>
#include <cmath>

bool checkCollision(std::vector<float> &pos1, std::vector<float> &pos2, float r) {
    float dist = sqrt(pow(pos1.at(0) - pos2.at(0), 2) + pow(pos1.at(1) - pos2.at(1), 2));

    if (dist <= r) {
        std::cout << "Target reached" << std::endl;
        return true;
    }
    return false;
}

void step(std::vector<float> &pos, std::vector<float> &vel, float &dt) {
    pos.at(0) += vel.at(0) * dt;
    pos.at(1) += vel.at(1) * dt;
}

void runModel(std::vector<float> &aircraftPos, std::vector<float> &aircraftVel, std::vector<float> &missilePos,
              std::vector<float> &missileVel, float dt, float endTime, float r) {
    float currTime = 0;
    while (!checkCollision(aircraftPos, missilePos, r) && currTime < endTime) {
        std::cout << "Modeling time: " << currTime << " aircraft pos: " << aircraftPos.at(0) << " " << aircraftPos.at(1)
                  << " Missile pos: " << missilePos.at(0) << " " << missilePos.at(1) << std::endl;

        step(aircraftPos, aircraftVel, dt);
        step(missilePos, missileVel, dt);

        currTime += dt;
    }
}


int main(int argc, char **argv) {
    if (argc == 10) {
        std::vector<float> aircraftPos(2);
        std::vector<float> missilePos(2);
        std::vector<float> aircraftVel(2);
        std::vector<float> missileVel(2);

        // read init airctaft pos and vel
        aircraftPos.at(0) = strtof(argv[1], nullptr);
        aircraftPos.at(1) = strtof(argv[2], nullptr);
        aircraftVel.at(0) = strtof(argv[3], nullptr);
        aircraftVel.at(1) = strtof(argv[4], nullptr);

        // read init missile pos and vel
        missilePos.at(0) = 0;
        missilePos.at(1) = 0;
        missileVel.at(0) = strtof(argv[5], nullptr);
        missileVel.at(1) = strtof(argv[6], nullptr);
        // radius of missile affected area
        float r = strtof(argv[7], nullptr);
        // time step of modeling
        float dt = strtof(argv[8], nullptr);
        // model time
        float endTime = strtof(argv[9], nullptr);

        runModel(aircraftPos, aircraftVel, missilePos, missileVel, dt, endTime, r);

        std::cout << "Modeling end" << std::endl;
        return 0;
    }
}