#include <kipr/wombat.h>

int forwardsl = 900;
int forwardsr = 885;

int backwardsl = -885;
int backwardsr = -900;

int leftwturnr = 500;
int rightwturnr = -500;

int leftwturnl = -500;
int rightwturnl = 500;

int armdown = 1895; 
int armup = 631;

int leftwbackl = -400;
int rightwbackl = -900;

int leftwbackr = -900;
int rightwbackr = -400;

int clawopen = 1055; 
int clawclose = 1545;

int main()
    
{
    camera_open();
    
    wait_for_light(0);
    
    enable_servos();
    
    shut_down_in(119);
    
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
    msleep(750);
    
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
    
    while (gmpc(0) > -6000)
        
    {
        
   	mav(0,rightwbackl);
    mav(1, leftwbackl); 
    msleep(10);
        
    }
    
    while(analog(5) < 3700)
    {
        mav(0,rightwbackl);
    mav(1, leftwbackl); 
    msleep(10);
    }
    
    cmpc(0);
    
    while (gmpc(0) > -1000)
        
    {
        
    mav(0,rightwbackr);
    mav(1, leftwbackr);
    msleep(10);
    
    }
    cmpc(0);
    
    while (gmpc(0) > -4000)
    {
        mav(0,backwardsr);
        mav(1,backwardsl);
        msleep(10);
        
    }
    
   
    
    cmpc(0);
    
    while (gmpc(0) > -1700)
        
    {
        
    mav(0,rightwbackr);
    mav(1, leftwbackr);
    msleep(10);
    
    }
       
    cmpc(0);
    
    while (gmpc(0) > -3300)
        
    {
        
    mav(0,rightwbackl);
    mav(1, leftwbackl);
    msleep(10);
    
    }
     
    mav(0,backwardsr);
    mav(1,backwardsl);
    msleep(3000);
    
    set_servo_position(0,1900);
    msleep(500);
    set_servo_position(1,clawopen);
    msleep(500);
    
    while(digital(0) == 0 || digital(1) == 0)
        
    {
       
    mav(0, backwardsl);
    mav(1, backwardsr);
    msleep(10);
    
    }
    
    set_servo_position(0,armup);
    set_servo_position(1,clawclose);
   
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(500);
    
    mav(0,rightwturnl);
    mav(1,leftwturnl);
    msleep(2000);
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(1500);
    
    while(analog(5) < 3700)
    {
        mav(0,forwardsr);
        mav(1,forwardsl);
        msleep(10);
    }
    
    mav(1,leftwturnr);
    mav(0,rightwturnr);
    msleep(2000);
    
    cmpc(0);
    
    while(gmpc(0) < 7500)
        
    {
        
        mav(0,forwardsr);
        mav(1,forwardsl);
        msleep(10);
        
    }
    
    mav(1,leftwturnr);
    mav(0,rightwturnr);
    msleep(2000);
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(3500);
    
    mav(1,leftwturnr);
    mav(0,rightwturnr);
    msleep(2000);
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(5000);
    
    mav(0,backwardsr);
    mav(1,backwardsl);
    msleep(1000);
    
    mav(1,leftwturnr);
    mav(0,rightwturnr);
    msleep(2200);
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(3700);
    
    mav(1,leftwturnl);
    mav(0,rightwturnl);
    msleep(2250);
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(3400);
    
    mav(1,leftwturnl);
    mav(0,rightwturnl);
    msleep(1800);
    
    mav(0,forwardsr);
    mav(1,forwardsl);
    msleep(3000);
        
    mav(0,backwardsr);
    mav(1,backwardsl);
    msleep(1000);
    
    mav(1,leftwturnl);
    mav(0,rightwturnl);
    msleep(1000);
    
   while(digital(0)==0)
    
{
    camera_update();
    
    if (get_object_count(0)==0)
        
    {
        mav(0,0);
            mav(1,0);
            msleep(10);
        
        printf("No object detection\n");
        
    }
    
    else
        
    {
        
        if(get_object_center_x(0,0)<70)
            
        {
                       
         mav(0,rightwturnl);
         mav(1,leftwturnl);
         msleep(10);
                
            printf("object on the left\n"); //rainbowdash
            
        }
        
        if(get_object_center_x(0,0)>90)
            
        {
            
            mav(0,rightwturnr);
         mav(1,leftwturnr);
         msleep(10);
            
            printf("object on the right\n"); //pinkypie
            
        }
        
        if(get_object_center_x(0,0)<90 && get_object_center_x(0,0)>70)
            
        {
            
            mav(1,backwardsl);
            mav(0,backwardsr);
            msleep(1000);           
            
            mav(0,forwardsr);
            mav(1,forwardsl);
            msleep(1500);
            
            set_servo_position(0,armdown);
            msleep(500);
            set_servo_position(1,clawopen);
            msleep(500); 
           
            mav(0,forwardsr);
            mav(1,forwardsl);
            msleep(500);
            
            set_servo_position(1,clawclose);
            msleep(500);
            set_servo_position(0,armup);
            msleep(500);
            
            mav(0,backwardsr);
            mav(1,backwardsl);
            msleep(200);
            
            mav(0,rightwturnr);
            mav(1,leftwturnr);
            msleep(500);
            
            set_servo_position(0,armdown);
            msleep(500);        
            set_servo_position(1,clawopen);
            msleep(500);
            
            mav(0,backwardsr);
            mav(1,backwardsl);
            msleep(300);
            
            set_servo_position(0,armup);
            msleep(500);        
            set_servo_position(1,clawclose);
            msleep(500);
            
            mav(0,rightwturnl);
            mav(1,leftwturnl);
            msleep(1000);
            
            mav(0,backwardsr);
            mav(1,backwardsl);
            msleep(500);
            
        }
    }
}
    return 0;
    
    disable_servos();
    
    return 0;
}
