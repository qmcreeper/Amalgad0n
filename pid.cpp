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


/////////////////////λ��ʽpid/////////////////////////

PositionPID::PositionPID()
{
}

/**
* @brief ��ʼ��λ��ʽpid������
*
* @param N_times �ܴ���
* @param pid_target ����ֵ
* @param Kp ����
* @param Ki ����
* @param Kd ΢��
* @param T ��������
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
* @brief ���ڼ���ĳ��״̬��λ��ʽpid������
* 
* @param N_times �ܴ���
* @param pid_target ����ֵ
* @param pid_actual ʵ��ֵ
* @param Kp ����
* @param Ki ����
* @param Kd ΢��
* @param err ƫ��
* @param last_err ��һ�ε�ƫ��
* @param out pid�������
* @param T ��������
* @param integral ����ֵ
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
