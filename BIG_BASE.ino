#include<avr/io.h>
#include<avr/delay.h>
#include"motor.h"
#include"ps3.h"
#include"mpu.h"



//           (Motor2)
//            /   \
//           /     \
//          /       \
//         /         \
//        /           \
//       /             \
// (Motor1) ---------- (Motor3)
//
//4 - PG5
//5 - PE3
//6 - PH3
//7 - PH4
//8 - PH5
//11 - PB5
//             DIRECTION PINS
//   MOTOR 1- PG5 | MOTOR 2- PH3 | MOTOR 3- PH5
//            PWM PINS
//   MOTOR 1- PE3 | MOTOR 2- PH4 | MOTOR 3- PB5
//    OC3A     |    OC4B      |   OC1A


void setup()
{
  set_mpu();
  motor_setup();
  ps3_setup();
  Serial.begin(115200);
}
  
  

void loop(){
 
  ps3_data();
  pid_mpu();

    if (ps3.cross){
                 motor_degree(0,0,0);
                 while(!ps3.start)ps3_data();
                 reset();
                   while(ps3.R1)
                  {
                    ps3_data();
                  }
                  motor1_value(0);
                  motor2_value(0);
                  motor3_value(0);
                  set_mpu();
                 }
   else if(ps3.up)
               {  
                if (ps3.R1)
                {
                      motor_degree(500,90,);
                }
               }
   else if(ps3.down)
               {  
                      motor_degree(500,270,0);
               }
   else if(ps3.right)
               {  
                      motor_degree(500,0,0);
               }
   else if(ps3.left)
               {  
                      motor_degree(500,180,0);
               }
//   else if(ps3.R1)
//               {  
//                      rotation(500);
//                       reset();
//                   while(ps3.R1)
//                  {
//                    ps3_data();
//                  }
//                  motor1_value(0);
//                  motor2_value(0);
//                  motor3_value(0);
//                  set_mpu();
//               }
//   else if(ps3.L1)
//               {  
//                       rotation(-500);
//                        reset();
//                   while(ps3.R1)
//                  {
//                    ps3_data();
//                  }
//                  motor1_value(0);
//                  motor2_value(0);
//                  motor3_value(0);
//                  set_mpu();
//               }
   else
              {
                  motor1_value(z);
                  motor2_value(z);
                  motor3_value(z/2.8);
//                   motor1_value(0);
//                  motor2_value(0);
//                  motor3_value(0);
//                  k=500;
              }
}
