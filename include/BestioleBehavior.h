#ifndef _BESTIOLE_BEHAVIORS_H
#define _BESTIOLE_BEHAVIORS_H

#include "../include/Bestiole.h"
#include <memory>
#include <vector>

// ====================================================================================================
class BehavingStrategy
{
public:
    virtual void behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b) = 0; // Pure virtual function for defining behavior
    virtual ~BehavingStrategy() = default;                  // Virtual destructor to ensure proper cleanup
};

// ====================================================================================================
class GregariousBehavior : public BehavingStrategy
{
public:
    void behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b) override;
};

// ====================================================================================================
class FearfulBehavior : public BehavingStrategy
{
public:
    void behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b) override;
    // void estimateTrajectory(Bestiole &autre, double &futureX, double &futureY, double delay = 1.0) const;
};

// ====================================================================================================
class KamikazeBehavior : public BehavingStrategy
{
public:
    void behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b) override;
};

// ====================================================================================================
class ForeseeingBehavior : public BehavingStrategy
{
public:
    void behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b) override;
    bool imminent_collision(Bestiole &other, const Bestiole &b, double delay = 1.0);
};

// ====================================================================================================
class BehavingContext
{
private:
    BehavingStrategy* strategy;

public:
    BehavingContext() {};
    BehavingContext(BehavingStrategy* strategy);
    void setStrategy(BehavingStrategy* strategy);
    void executeStrategy(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b);
};

#endif