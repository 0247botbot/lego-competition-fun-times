#include <kipr/wombat.h>

int forwardsl = 900;
int forwardsr = 885;

int backwardsl = -875;
int backwardsr = -900;

int leftwturnr = 500;
int rightwturnr = -500;

int leftwturnl = -500;
int rightwturnl = 500;

int armdown = 1882; 
int armup = 631;

int leftwbackl = -400;
int rightwbackl = -900;

int leftwbackr = -900;
int rightwbackr = -400;

int clawopen = 1055; 
int clawclose = 1906;

int main()
    
{

    enable_servos();
    
    set_servo_position(0,armup);
    set_servo_position(1,clawclose);
    
while (digital(2) == 0)
    
{
    
    mav(1,forwardsl);
    mav(0,forwardsr); 
    msleep(10);
    
}
    
    mav(0,backwardsr);
    mav(1,backwardsl);
    msleep(500);
    
    mav(1,leftwturnl);
    mav(0,rightwturnl);
    msleep(2000);
    
    while(digital(0) == 0 || digital(1) == 0)
        
    {
        
    mav(0,backwardsr);
    mav(1,backwardsl); 
    msleep(10);
          
    }
    
    mav(0,0);
    mav(1,0);
        msleep(1000);
    
 	set_servo_position(0,armdown);
    set_servo_position(1,clawopen);
    msleep(1000);
    
    mav(1,leftwturnr);
    mav(0,rightwturnr);
    msleep(200);
        
    mav(0,1000);
    mav(1,1000);
    msleep(3000);
    
    set_servo_position(1,clawclose);
    msleep(500); 
    set_servo_position(0,armup);
    msleep(500);
    
    cmpc(0);
    
    while (gmpc(0) > -7000)
        
    {
        
   	mav(0,rightwbackl);
    mav(1, leftwbackl); 
    msleep(10);
        
    }
    
    cmpc(0);
    
    while (gmpc(0) > -1500)
        
    {
        
    mav(0,rightwbackr);
    mav(1, leftwbackr);
    msleep(10);
    
    }
    cmpc(0);
    
    while (gmpc(0) > -5000)
    {
        mav(0,backwardsr);
        mav(1,backwardsl);
        msleep(10);
        
    }
    
    
    cmpc(0);
    
    while (gmpc(0) > -1200)
        
    {
        
    mav(0,rightwbackr);
    mav(1, leftwbackr);
    msleep(10);
    
    }
        
    
    while(digital(0) == 0 || digital(1) == 0)
        
    {
       
    mav(0, backwardsl);
    mav(1, backwardsr);
    msleep(10);
    
    }
    
    
    
    return 0;
}
