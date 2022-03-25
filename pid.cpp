#include "pid.h"


/////////////////////pidbase/////////////////////////

pidbase::pidbase()
{
    N_times = 0;
    pid_target = 0;
    pid_actual = 0;
    Kp = 0;
    Ki = 0;
    Kd = 0;
    err = 0;
    last_err = 0;
    out = 0;
    T = 0;
    integral = 0;
}


/////////////////////位置式pid/////////////////////////

PositionPID::PositionPID()
{
}

/**
* @brief 初始化位置式pid控制器
*
* @param N_times 总次数
* @param pid_target 期望值
* @param Kp 比例
* @param Ki 积分
* @param Kd 微分
* @param T 更新周期
*/
PositionPID::PositionPID(int N_times, float pid_target, float Kp, float Ki, float Kd, float T)
{
    this->N_times = N_times;
    this->pid_target = pid_target;
    this->pid_actual = 0;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->err = 0;
    this->last_err = 0;
    this->out = 0;
    this->T = T;
    this->integral = 0;
}

/**
* @brief 用于加载某种状态的位置式pid控制器
* 
* @param N_times 总次数
* @param pid_target 期望值
* @param pid_actual 实际值
* @param Kp 比例
* @param Ki 积分
* @param Kd 微分
* @param err 偏差
* @param last_err 上一次的偏差
* @param out pid单次输出
* @param T 更新周期
* @param integral 修正值
*/
PositionPID::PositionPID(int N_times, float pid_target, float pid_actual, float Kp, float Ki, float Kd, float err, float last_err, float out, float T, float integral)
{
    this->N_times = N_times;
    this->pid_target = pid_target;
    this->pid_actual = pid_actual;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->err = err;
    this->last_err = last_err;
    this->out = out;
    this->T = T;
    this->integral = integral;
}

void PositionPID::pidrunonce()
{
    err = pid_target - pid_actual;
    integral = integral + err;
    out = err * Kp + integral * T * Ki + (err - last_err) * Kd;
    last_err = err;
    pid_actual = out;
    return;
    //pid_actualspeed
}

void PositionPID::pidrun()
{
    while (N_times > 0)
    {
        pidrunonce();
        std::cout << pid_actual <<std::endl;
        result.push_back(pid_actual);
        N_times--;
    }
}
