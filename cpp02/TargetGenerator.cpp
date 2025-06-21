#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {
    for (auto& pair : targets)
        delete pair.second;
    targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target)
        targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const& type) {
    auto it = targets.find(type);
    if (it != targets.end()) {
        delete it->second;
        targets.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(std::string const& type) {
    auto it = targets.find(type);
    if (it != targets.end())
        return it->second->clone();
    return nullptr;
}