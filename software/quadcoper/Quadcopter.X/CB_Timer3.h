/* 
 * File:   CB_Timer3.h
 * Author: Raul
 *
 * Created on 28 de agosto de 2013, 11:43
 */

#ifndef CB_TIMER3_H
#define	CB_TIMER3_H

#include "CB_I2C.h"

#define interrupcion	__attribute__((interrupt,no_auto_psv))

void SetupT3ForXmsPID(int _tiempo);
void StartInterrup3();
void StopInterrup3();
void interrupcion _T3Interrupt(void);
void Bucle_Principal();

extern int i;
#endif	/* CB_TIMER3_H */

