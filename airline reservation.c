#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 10
#define MAX_PASSENGERS 100

struct Flight {
    int id;
    char from[30];
    char to[30];
    int availableSeats;
    float price;
};

struct Booking {
    char passengerName[30];
    int age;
    int flightId;
    int seatsBooked;
};

void displayMenu(struct Flight flights[], int num) {
    printf("These flights are available:\n");
    for (int i = 0; i < num; i++) {
        printf("ID: %d, From: %s, To: %s, Seats: %d, Price: %.2f\n",
               flights[i].id, flights[i].from, flights[i].to, flights[i].availableSeats, flights[i].price);
    }
}

void bookFlight(struct Flight flights[], int num, struct Booking bookings[], int *bookingCount) {
    struct Booking newBooking;
    printf("Enter your Name: ");
    scanf("%s", newBooking.passengerName);
    printf("Enter your age: ");
    scanf("%d", &newBooking.age);
    printf("Enter your flight ID: ");
    scanf("%d", &newBooking.flightId);

    int flightFound = 0;
    for (int i = 0; i < num; i++) {
        if (newBooking.flightId == flights[i].id) {
            flightFound = 1;
            int seats;
            printf("Enter number of seats: ");
            scanf("%d", &seats);

            if (seats <= flights[i].availableSeats) {
                flights[i].availableSeats -= seats;
                newBooking.seatsBooked = seats;
                bookings[*bookingCount] = newBooking; // Store the booking
                (*bookingCount)++;
                printf("Your reservation is confirmed.\n");
                printf("Booking successful! You have booked %d seats on flight %d.\n", seats, newBooking.flightId);
            } else {
                printf("Seats are not available.\n");
                printf("Only %d seats are available. Please try again!\n", flights[i].availableSeats);
            }
            break;
        }
    }
    if (!flightFound) {
        printf("Flight ID %d not found. Please try again!\n", newBooking.flightId);
    }
}

void viewBookings(struct Booking bookings[], int bookingCount) {
    if (bookingCount == 0) {
        printf("No bookings found.\n");
        return;
    }
    printf("Booking Details:\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("Passenger: %s, Age: %d, Flight ID: %d, Seats Booked: %d\n",
               bookings[i].passengerName, bookings[i].age, bookings[i].flightId, bookings[i].seatsBooked);
    }
}

int main() {
    int n = 3;
    struct Flight flights[MAX_FLIGHTS] = {
        {101, "New York", "Los Angeles", 10, 150.00},
        {102, "Chicago", "Miami", 5, 120.00},
        {103, "Dallas", "Boston", 3, 180.00}
    };

    struct Booking bookings[MAX_PASSENGERS];
    int bookingCount = 0;
    int choice;

    while (1) {
        printf("\n----- Airline Reservation System -----\n");
        printf("1. View available flights\n");
        printf("2. Book flight\n");
        printf("3. View Booking Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(flights, n); // Display available flights
                break;
            case 2:
                displayMenu(flights, n); // Display available flights before booking
                bookFlight(flights, n, bookings, &bookingCount); // Book a flight
                break;
            case 3:
                viewBookings(bookings, bookingCount); // Display booking details
                break;
            case 4:
                printf("Thank you for using the Airline Reservation System.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
