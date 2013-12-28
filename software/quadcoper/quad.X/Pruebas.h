/* 
 * File:   Pruebas.h
 * Author: Raul
 *
 * Created on 22 de agosto de 2013, 20:04
 */

#ifndef PRUEBAS_H
#define	PRUEBAS_H
#include <i2c.h>
#include "CB_I2C.h"
#include "Defines.h"
#include "CB_Timer2.h"
#include "CB_Bluetooth.h"
#include "CB_Inicializaciones.h"

extern char str_blue[40];

void Prueba2_PWM(void);
void Prueba_PWM(void);
void Prueba_Bluetooth(void);
void Prueba_I2C(void);
void Prueba_LED();
void EjecutarPID(void);


#endif	/* PRUEBAS_H */

