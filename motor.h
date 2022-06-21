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
 int a=0,d1,d2,d3;
 int k=0;
 float z=0;


void motor_setup(){

  DDRG = (1<<PING5);
  DDRE = (1<<PINE3);
  DDRH = (1<<PINH3)|(1<<PINH5)|(1<<PINH4);
  DDRB = (1<<PINB5);

  // ALL DIRECTION PINS ARE SET HIGH ==> Base Anti-clock
  PORTG |=(1<<PING5);
  PORTH |=(1<<PINH3)|(1<<PINH5);

  TCCR3A =(1<<COM3A1)|(1<<WGM31);
  TCCR3B =(1<<WGM33)|(1<<WGM32)|(1<<CS31); // 1/8 PRESCALER , NON INVERTING MODE 
  TCCR4A =(1<<COM4B1)|(1<<WGM41);
  TCCR4B =(1<<WGM43)|(1<<WGM42)|(1<<CS41); // 1/8 PRESCALER , NON INVERTING MODE 
  TCCR1A =(1<<COM1A1)|(1<<WGM11);
  TCCR1B =(1<<WGM11)|(1<<WGM12)|(1<<CS11); // 1/8 PRESCALER , NON INVERTING MODE 
  
  ICR1 = 2000;
  ICR3 = 2000;
  ICR4 = 2000;
}
void motor1_value(int a)
{
           if(a>=0)
          {
            PORTG &=~(1<<PING5);//DIR FOR MOTOR1.WHEEL ANTICLOCKWISE  
            
          }

         else if(a<0)
          {
         PORTG |= (1<<PING5);//DIR FOR MOTOR1. WHEEL CLOCKWISE
        
          }
           OCR3A= constrain(abs(a),0,2000); //MOTOR1
}
void motor2_value(int a)
{
    if(a>=0)
          {
            PORTH &=~(1<<PINH3);//DIR FOR MOTOR2.WHEEL ANTICLOCKWISE  
             
          }

         else if(a<0)
          {
         PORTH |= (1<<PINH3);//DIR FOR MOTOR2.WHEEL CLOCKWISE
         
          }
          OCR4B=constrain(abs(a),0,2000); //MOTOR1
}
void motor3_value(int a)
{
    if(a>=0)
          {
            PORTH &=~(1<<PINH5);//DIR FOR MOTOR3.WHEEL ANTICLOCKWISE  
          }

         else if(a<0)
          {
         PORTH |= (1<<PINH5);//DIR FOR MOTOR3.WHEEL CLOCKWISE
        
          }
 OCR1A=constrain(abs(a),0,2000); //MOTOR1
}

void motor_degree(float base_speed,float degree,float wr)
 {
  double radian=(degree+180)*(0.01745);
  float vx = cos(radian);
  float vy = sin(radian);
  
    if(k<base_speed)
  {
    d2 = ((k*2)*(((-2*vx/3)+(0*vy)+(0.33*wr))));
    d1 = ((k*2)*(((vx/3)-(vy/(sqrt(3))+(0.33*wr)))));
    d3 = ((k/2)*((vx/3)+(vy/(sqrt(3))+(0.33*wr))));
    k+=5;
    if(k>1000)
    { 
      k=1000;
    }
    
    
  }
  else
  {
    d2 = ((base_speed*2)*(((-2*vx/3)+(0*vy)+(0.33*wr))));
    d1 = ((base_speed*2)*(((vx/3)-(vy/(sqrt(3))+(0.33*wr)))));
    d3 = ((base_speed/2)*((vx/3)+(vy/(sqrt(3))+(0.33*wr))));
  }
//    d2 = (base_speed*(((-2*vx/3)+(0*vy)+(0.33*wr))));
//    d1 = (base_speed*(((vx/3)-(vy/(sqrt(3))+(0.33*wr)))));
//    d3 = (base_speed*((vx/3)+(vy/(sqrt(3))+(0.33*wr))));

    motor1_value(d1+z);
    motor2_value(d2+z);
    motor3_value(d3+(z/2.8));
}
void rotation(float zoom)
{    // motor 1,2 have 500
     // motor 3 have 175
     // therefore ratio is 500/175 =2.8
    motor1_value(zoom);
    motor2_value(zoom);
    motor3_value(zoom/2.8);
}
