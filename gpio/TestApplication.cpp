/*
 * TestApplication.cpp
 *
 * Copyright Derek Molloy, School of Electronic Engineering, Dublin City University
 * www.derekmolloy.ie
 *
 * YouTube Channel: http://www.youtube.com/derekmolloydcu/
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL I
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include "SimpleGPIO.h"
using namespace std;

unsigned int LEDGPIO = 60;   // GPIO1_28 = (1x32) + 28 = 60
unsigned int ButtonGPIO = 15;   // GPIO0_15 = (0x32) + 15 = 15
unsigned int GPIO_D1[] = { 66, 67, 69, 68, 45, 44 };
unsigned int GPIO_D2[] = { 23, 26, 47, 46, 27, 65 };
int GPIO_PIN_COUNT = 6;

int main(int argc, char *argv[]){

	cout << "Testing the GPIO Pins" << endl;

	int i = 0;

	for(i=0; i<GPIO_PIN_COUNT;i++){
		gpio_export(GPIO_D1[i]);
		gpio_export(GPIO_D2[i]);
        	gpio_set_dir(GPIO_D1[i], OUTPUT_PIN);
		gpio_set_dir(GPIO_D2[i], OUTPUT_PIN);
	}

	cout << "Starting the test on" << endl;

	for(i=0; i<GPIO_PIN_COUNT; i++){
                gpio_set_value(GPIO_D1[i], HIGH);
		usleep(2000000);         // on for 2s
                gpio_set_value(GPIO_D1[i], LOW);
	}

	for(i=0; i<GPIO_PIN_COUNT; i++){
                gpio_set_value(GPIO_D2[i], HIGH);
		usleep(2000000);         // on for 2s
                gpio_set_value(GPIO_D1[i], LOW);
	}

	cout << "Finished Testing the GPIO Pins" << endl;

	for(i=0; i<GPIO_PIN_COUNT;i++){
		gpio_unexport(GPIO_D1[i]);     // unexport the LED
		gpio_unexport(GPIO_D2[i]);  // unexport the push button
	}
	
	return 0;
}

