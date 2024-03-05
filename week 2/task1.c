/*
    the program that calculates the day interval
    between the two given dates and calculates
    the following date for the first date
    written by zeynepsturan
*/

#include <stdio.h>
//function declarations
int LeapYear(int year), DayCalculate(int day, int month, int year);
void FollowingDay(int day, int month, int year);

int main(){
  //variable declarations
	int day1,day2,month1,month2,year1,year2;
	int totalday1,totalday2,daycount;

  //inputs
	printf("Please enter the first date(DD MM YYYY): ");
	scanf("%d %d %d",&day1,&month1,&year1);

	printf("Please enter the second date(DD MM YYYY): ");
	scanf("%d %d %d",&day2,&month2,&year2);

  //calculating the day 
  totalday1=DayCalculate(day1,month1,year1);
	totalday2=DayCalculate(day2,month2,year2);
	daycount=totalday2-totalday1;

    //output
	printf("Day count: %d\n",daycount);
    FollowingDay(day1,month1,year1);

	return 0;
}

//function definitions
int LeapYear(int year){

    int leapcheck=0;

    if(year%4==0){
      
		  leapcheck=1;
	}

	if(year%100==0){

		  leapcheck=0;
	}

	if(year%400==0){

		  leapcheck=1;
	}

  return leapcheck;
}

int DayCalculate(int day, int month, int year){

    int totalday=year*365;
    int leapcheck;
	  for(int i=0;i<year;i++){

		  leapcheck=LeapYear(i);
      
			if(leapcheck==1){

				totalday+=1;

			}

	  }

	for(int i=month-1;i>0;i--){

		switch(i){

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		    totalday+=31;
		    break;

		case 4:
		case 6:
		case 9:
		case 11:
		    totalday+=30;
		    break;

		case 2:
            leapcheck=LeapYear(year);
            if(leapcheck==1){

                totalday+=29;

            }

            else{

                totalday+=28;

            }

	    }

	}	

	totalday+=day;
    return totalday;
}

void FollowingDay(int day, int month, int year){

    int followingday,followingmonth,followingyear,leapcheck;

    followingday=day+1;
	  followingmonth=month;
	  followingyear=year;

    switch(month){

      case 1:
      case 3:
		  case 5:
		  case 7:
		  case 8:
		  case 10:
		  case 12:
          if(followingday>31){

            followingday-=31;
            followingmonth+=1;

          }
          break;

      case 4:
		  case 6:
		  case 9:
		  case 11:
        if(followingday>30){

			    followingday-=30;
          followingmonth+=1;
		  }
      break;

      case 2:
        leapcheck=LeapYear(year);

			  if(leapcheck==1){

				  if(followingday>29){

				    followingday-=29;
				    followingmonth+=1;

				  }
        }

        else if(leapcheck==0){

				  if(followingday>28){

				    followingday-=28;
				    followingmonth+=1;

          } 
        }       

    }

    if(followingmonth>12){

	    followingmonth-=12;
		  followingyear+=1;
	}

    printf("Following: %d/%d/%d\n",followingday,followingmonth,followingyear);
}

