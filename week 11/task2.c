/*
  calculating the speed limits
  for different vehicles by using
  unions and structs
  written by: zeynepsturan
*/

#include <stdio.h>

union VehicleData{
    struct{
        int door;
        int seat;
    }car;

    struct{
        int wheels;
        int power;
    }motorcycle;

    struct{
        int wheels;
    }bicycle;
};

typedef struct{
    int type;
    union VehicleData data;
}Vehicle;

int calculate_max_speed(Vehicle vehicle);
void modify_car_doors(Vehicle *vehicle, int new_doors);

int main(){

    Vehicle vehicle;
    printf("Maximum speeds:\n");

    vehicle.type=0;
    vehicle.data.car.seat=5;
    vehicle.data.car.door=4;
    printf("Car: %dkm/h\n", calculate_max_speed(vehicle));

    vehicle.type=1;
    vehicle.data.motorcycle.wheels=2;
    vehicle.data.motorcycle.power=250;
    printf("Motorcycle: %dkm/h\n", calculate_max_speed(vehicle));

    vehicle.type=2;
    vehicle.data.bicycle.wheels=2;
    printf("Bicycle: %dkm/h\n", calculate_max_speed(vehicle));

    vehicle.type=0;
    modify_car_doors(&vehicle, 2);
    printf("Updated maximum speed of car: %dkm/h\n", calculate_max_speed(vehicle));

    return 0;
}

void modify_car_doors(Vehicle *vehicle, int new_doors){

    if(vehicle->type==0){
        vehicle->data.car.door=new_doors;
    }
}

int calculate_max_speed(Vehicle vehicle){

    int max_speed=0;

    /*speed calculations for all types of vehicles*/
    if(vehicle.type==0){
        max_speed=vehicle.data.car.door*20;
    } 

    else if(vehicle.type==1){
        max_speed=vehicle.data.motorcycle.power/2;
    } 

    else if(vehicle.type==2){
        max_speed=30;
    }
  
    return max_speed;
}
