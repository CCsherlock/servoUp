#include <iostream>
#include "serialSend.h"
#include "windows.h"
using namespace std;
SerialInterface serial;

struct servoSendStr
{
    /* data */
    uint8_t frameHead = 0xA5;
    uint8_t servoCmd[14];
    uint8_t frameCheck;
};

servoSendStr sendStr;   // 舵机控制结构体
uint8_t sendBuffer[16]; // 串口发送数据
/**
 * @brief 串口初始化函数 记得修改串口号，波特率任意
 *
 */
void serialInit()
{
    if (!serial.openSyn("\\\\.\\COM14", CBR_256000, NOPARITY, 8, ONESTOPBIT))
    {
        cout << " Unable open serial" << endl;
        cout << serial.getSerialLastError() << endl;
        getchar();
        return;
    }
    cout << "COM open Succeed!" << endl;
}
/**
 * @brief 计算一个数组中有多少个1（1校验）
 *
 * @param arr 数组入参
 * @param size 数组长度
 * @return int 1的个数
 */
int countOnes(uint8_t *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
    }
    return count;
}

void serialSend() // 发送函数
{
    sendStr.frameCheck = countOnes(sendStr.servoCmd, 14); // 1个数校验
    memcpy(sendBuffer, &sendStr, sizeof(sendBuffer));     // 拷贝数据
    serial.writeData(sendBuffer, sizeof(sendBuffer));     // 发送
}
uint8_t dir = 1;
int main(int argc, const char **argv)
{
    serialInit();
    while (1)
    {
        /* code */
        if(dir) dir = 0;
        else dir = 1;
        for (uint8_t i = 0; i < 14; i++)
        {
            /* code */
            sendStr.servoCmd[i] = dir; // 这里设定各个舵机状态 0或1
            serialSend();              // 发送函数可以放在循环中
            Sleep(200);
        }
    }

    return 0;
}