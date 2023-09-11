#ifndef __AGENT_H__
#define __AGENT_H__

#include <string>

class Agent
{
public:
    Agent(std::string configuration);
    ~Agent();
    int Run();

private:
    std::string configuration_;
};

#endif //__AGENT_H__