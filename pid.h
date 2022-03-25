#ifndef PID_H
#define PID_H

#include <iostream>
#include <vector>

/**
* @brief pid控制实现
* @note 字面意思，pid，计划改成通用型
*/
class pidbase
{
protected:
    int N_times;
    float pid_target;
    float pid_actual;  
    float Kp;
    float Ki;
    float Kd;
    float err;               
    float last_err;          
    float out;          
    float T;                 
    float integral;
    std::vector<float> result;
public:
    pidbase();
    virtual void pidrunonce() { std::cerr << "error runonce" << std::endl; return; }
    virtual void pidrun() { std::cerr << "error run" << std::endl; return; }
    virtual std::vector<float> getresult() { std::cerr << "error get result" << std::endl; return; }
};

class PositionPID :
    public pidbase
{
public:
    PositionPID();
    PositionPID(int N_times,
        float pid_target,
        float Kp, float Ki, float Kd,
        float T);
    PositionPID(int N_times,
        float pid_target,
        float pid_actual, 
        float Kp, float Ki, float Kd, 
        float err,float last_err,
        float out,
        float T,
        float integral);
    virtual void pidrunonce();
    virtual void pidrun();
    virtual std::vector<float> getresult() { return result; };
};



#endif  //PID_H
