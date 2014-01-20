/*
 * File:   main.c
 * Author: rbpkirow
 *
 * Created on 29 de junio de 2013, 19:05
 */

#include "main.h"


#define MY_FRC                  0xF9E3

//DEFINES DE DEBUG



// FUSES
// -----------------------------------------------------------

_FOSC(MY_FRC & CSW_FSCM_ON) //   0xF9E3 & 0x3FFF --> Arranca sin PLL (8MHz) y se habilita el clockSwitch
_FGS(GWRP_OFF & CODE_PROT_OFF)
_FICD(ICS_PGD1)
_FWDT(WDT_OFF)
_FBORPOR(PWRT_OFF & BORV27 & PBOR_OFF & MCLR_DIS)
// FIN FUSES



int main(void)
{
    //#define DATO_KALMAN
    //#define ARRANQUE
volatile int chanel1 = 0;
volatile int chanel2 = 0;
volatile int chanel3 = 0;
volatile int chanel4 = 0;
volatile int chanel5 = 0;

#define CALIBRADO
    int calibra_ax, calibra_ay, calibra_az, calibra_gx, calibra_gy, calibra_gz, ax, ay, az, gx, gy, gz;
    calibra_ax = calibra_ay = calibra_az = calibra_gx = calibra_gy = calibra_gz = ax = ay = az = gx = gy = gz = 0;
#define DEBUG
    Init_Hw();
    Init_Pll();
    LED_ALL_OFF();
    
    Init_Bluetooh();
#ifdef ARRANQUE
    enviar_mensaje("Bluetooth inicializado...");
#endif
    Delay1msT1(0);
#ifdef ARRANQUE
    enviar_mensaje("Iniciando el I2C...");
#endif
    Delay1msT1(0);
    Init_I2C();
#ifdef ARRANQUE
    enviar_mensaje("I2C inicializado...");
#endif
    Delay1msT1(0);
#ifdef ARRANQUE
    enviar_mensaje("Iniciando el PWM...");
#endif
    Delay1msT1(0);
    Init_PWM();
#ifdef ARRANQUE
    enviar_mensaje("PWM inicializado...");
#endif
    //  SetupT3FormsPID(4);
    // StartPID();
ACT_ACE=1;
set_inicial();


    while(1)
    {
        if (get_who_I_AM() == 104)
        {
        get_acelerometro(&ax, &ay, &az, &gx, &gy, &gz);
        plot4(ax,ay,az,gx);
        DelayXmsT1(10);

        }
        else
        {
            enviar_valor("error -->valor who i am", get_who_I_AM());
           
            ACT_ACE=0;
            LEDROJO=1;
            LEDAZUL=0;
            DelayXmsT1(1000);
            ACT_ACE=1;
            }

        
       
    }
    return 0;
}