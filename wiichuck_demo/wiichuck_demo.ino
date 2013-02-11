/*
 * WiiChuckDemo -- 2008 Tod E. Kurt, http://thingm.com/
 * Slight revisions to get more details
 */

// Original obtained from http://todbot.com/blog/2008/02/18/wiichuck-wii-nunchuck-adapter-available/comment-page-10/
// See also http://github.com/todbot/wiichuck_adapter/ (in firmware/WiichuckDemo)

// Wii Nunchuck pins: Data -> Leonardo digital 2 or Uno A4
//                    Clk  -> Leonardo digital 3 or Uno A5

#include <Wire.h>
#include "nunchuck_funcs.h"

int loop_cnt=0;

int accx, accy, accz, joyx, joyy, zbut, cbut;
int ledPin = 13;


void setup()
{
    Serial.begin(9600);
//    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake
    
    Serial.print("WiiChuckDemo ready\n");
}

void loop()
{
    if( loop_cnt > 100 ) { // every 100 msecs get new data
        loop_cnt = 0;

        nunchuck_get_data();

        accx = nunchuck_accelx(); // ranges from approx 70 - 182
        accy = nunchuck_accely(); // ranges from approx 65 - 173
        accz = nunchuck_accelz();
        joyx = nunchuck_joyx();
        joyy = nunchuck_joyy();
        zbut = nunchuck_zbutton();
        cbut = nunchuck_cbutton(); 
            
	nunchuck_print_data();
	delay(500);
    }
    loop_cnt++;
    delay(1);
}

