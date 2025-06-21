#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <map>
#include <string>
#include "ATarget.hpp"

class TargetGenerator {
private:
    std::map<std::string, ATarget*> targets;

    TargetGenerator(const TargetGenerator&);
    TargetGenerator& operator=(const TargetGenerator&);

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const& type);
    ATarget* createTarget(std::string const& type);
};

#endif