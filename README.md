# R2-Robot-base-Holonomic-Drive
In the ABU ROBOCON 2022 Theme, the robot must be able to accomplish a preset objective, such as pilling the lagori disc and picking and passing the ball to the R1 Robot. 

Holonomic is one of the methods used in navigating the omnidirectional movement of mobile robot applications. Because the movement is designed without changing the position of the robot in the direction of the facing, the omnidirectional wheels are used which has the ability to move freely in two directions.

A 3 wheeled holonomic drive drives the robot according to the velocity which is given to its equilateral triangular arrangement of omnidirectional wheels separated at an angle of 120°. Robot moves in two dimensions [x-y plane]. 
To achieve robustness in the three-wheels motion of the robot in a dynamic environment, the MPU6050 Gyro Sensor (5V DC, I2C Interface) is used to continuously detect the orientation of the robot and maintain the given orientation throughout its movement.   
 
Rotary encoders(600 PPR) are mounted on dummy wheels to measure the distance and direction of the motion in two separate axes (X & Y). These feedbacks are used to calculate the speed that controls the robot to move from a specific coordinate to another. Speeds calculated according to the vectors are given to the DC base motors.

Refer below link for Calculation,  

https://drive.google.com/file/d/1C4hd8ts8ad3OGhdXZ-yxOw4AmtdHCDf0/view?usp=drivesdk.  

Refer below link for video, 

https://drive.google.com/drive/folders/1nhqXtcSqdH0lOfhl00C4aJQwhX-kikgi

 
 
