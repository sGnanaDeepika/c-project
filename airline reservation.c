// Online C compiler to run C program online
#include <stdio.h>
     struct flight{
        int id[10];
         char from[3][30];
        char to[3][30];
       int avaliableseats[10];
       float prices[10];
    }s1;

    void displaymenu(struct flight s1, int num){
        printf("These flights are avaliable\n");
        for(int i=0;i<num;i++){
                  printf("ID : %d, From : %s, To : %s, Seats : %d, Price : %.2f\n",
               s1.id[i], s1.from[i], s1.to[i], s1.avaliableseats[i], s1.prices[i]);
        }
    }
    // struct booking{
    //     char passenger[30];
    //     int age;
    //     int id_no;
    // }s2;
    void booking_passenger(struct flight s1,int num)
    {
      char name[10];
      printf("Enter your Name:");
      scanf("%s",&name);
      int age;
      printf("Enter your age:");
      scanf("%d",&age);
      int flight_id;
      printf("Enter your flight id:");
      scanf("%d",&flight_id);
      for(int i=0;i<num;i++)
      if(flight_id==s1.id[i]) 
      {
          int seats;
         printf("Enter  no. ofseats:");
         scanf("%d",&seats);
        
        if(seats<=s1.avaliableseats[i]){
          s1.avaliableseats[i]-=seats;
          printf("Your reservation conformed");
          printf("\n Booking sucessful! you have booked %d seats on flight %d",seats,flight_id);
          break;
      }
      else{
          printf("seats are not avaliable\n");
          printf("only %d is avaliable\n please Try again!\n",s1.avaliableseats[i]);
          break;
      }
    }
    }
    
int main(){
        int n=3;
    struct flight s1 = {
        {101, 102, 103}, // Flight IDs
        {"New York", "Chicago", "Dallas"}, // From locations
        {"Los Angeles", "Miami", "Boston"}, // To locations
        {10, 5, 3}, // Seats available
        {150.00, 120.00, 180.00} 
        };
        
    int choice;
    
    while (1) {
        printf("\n----- Airline Reservation System -----\n");
        printf("1. Book flight \n");
        printf("2. View Booking Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displaymenu(s1,n); // Display available flights
                break;
            case 2:
                booking_passenger(s1,n);
// Display booking details
                break;
            case 3:
                printf("Thank you for using the Airline Reservation System.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;

    // displaymenu(s1,n);
    // return 0;
}
