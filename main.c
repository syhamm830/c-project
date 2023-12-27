#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    int id;
    char descri[150];
    char state[15];
    int userRating;
};

struct Rental {
    int carId;
    char startD[15];
    char endD[15];
};

void principal_Menu() {
    system("cls");
    printf("\n==========Welcome to E-Cars Rental. How can we help you today?==========");
    printf("\n1. Rent a car");
    printf("\n2. Show car description");
    printf("\n3. Remove a malfunctioning car");
    printf("\n4. Modify car details");
    printf("\n5. Show rental history");
    printf("\n6. Return a car");
    printf("\n7. Automatic Discount system");
    printf("\n8. leave a rating");
    printf("\n9. show car ratings");
    printf("\n10. Exit");
    printf("\n=========================================");
    printf("\nWhat is your choice: ");}




void rent_a_Car(struct Car cars[], struct Rental rentals[], int *carCount, int *rentalCount) {
    printf("Enter your choice: car ID to rent: ");
    int carId;
    scanf("%d", &carId);
    if (carId >= 0 && carId < *carCount && strcmp(cars[carId].state, "Available") == 0) {
        strcpy(cars[carId].state, "Rented");
        printf("Enter the start date of renting (DD/MM/YYYY): ");
        scanf("%s", rentals[*rentalCount].startD);
        printf("Enter the finish date of renting (DD/MM/YYYY): ");
        scanf("%s", rentals[*rentalCount].endD);
        rentals[*rentalCount].carId = carId;
        (*rentalCount)++;
        printf("Congratulations, Car rented successfully! Thank you for trusting us\n");
    } else {
        printf("Invalid car ID or the car is not available for rent at the moment. Try a different car. We are sorry for this inconvenience\n");
    }
}

void Show_Car_Description(struct Car cars[], int carCount) {
    printf("\nCar ID\tDescri\tState");
    for (int i = 0; i < carCount; i++) {
        printf("\n%d\t%s\t\t%s", cars[i].id, cars[i].descri, cars[i].state);
    }
    printf("\n");
}

void remove_Malfunctioning_Car(struct Car cars[], int *carCount) {
    printf("If you want to remove a car, enter its ID: ");
    int carId;
    scanf("%d", &carId);
    if (carId >= 0 && carId < *carCount) {
        for (int i = carId; i < (*carCount - 1); i++) {
            cars[i] = cars[i + 1];
        }
        (*carCount)--;
        printf("Car removed successfully!\n");
    } else {
        printf("Invalid car ID. Verify and try again.\n");
    }
}

void modify_Car_Details(struct Car cars[], int carCount) {
    printf("If you want to modify a car details, enter its ID: ");
    int carId;
    scanf("%d", &carId);
    if (carId >= 0 && carId < carCount) {
        printf("Enter the new description: ");
        scanf("%s", cars[carId].descri);
        printf("Enter the new state (Available/Rented): ");
        scanf("%s", cars[carId].state);
        printf("Car details modified successfully!\n");
    } else {
        printf("Invalid car ID. Verify and try again.\n");
    }
}

void show_Rental_History(struct Rental rentals[], int rentalCount, struct Car cars[], int carCount) {
    printf("\nRental History:");
    printf("\nCar ID\tStart Date\tEnd Date\tDescription");
    for (int i = 0; i < rentalCount; i++) {
        int carId = rentals[i].carId;
        printf("\n%d\t%s\t\t%s\t\t%s", carId, rentals[i].startD, rentals[i].endD, cars[carId].descri);
    }
    printf("\n");
}

void return_a_Car(struct Car cars[], struct Rental rentals[], int *carCount, int *rentalCount) {
    printf("If you want to return a car, enter its ID: ");
    int carId;
    scanf("%d", &carId);
    if (carId >= 0 && carId < *carCount && strcmp(cars[carId].state, "Rented") == 0) {
        strcpy(cars[carId].state, "Available");
        printf("Congratulations! Car returned successfully! Thank you for trusting us\n");
    } else {
        printf("Invalid car ID or the car is not currently rented. Please verify and try again.\n");
    }
}

void automatic_Discount_System(struct Car cars[], struct Rental rentals[], int carCount, int rentalCount) {
    printf("Implementing automatic discount system...\n");
    for (int i = 0; i < rentalCount; ++i) {
        int userId = rentals[i].carId;
        int user_Rental_Count = 0;
        for (int j = 0; j < rentalCount; ++j) {
            if (rentals[j].carId == userId) {
                user_Rental_Count++;
            }
        }
        if (user_Rental_Count > 5) {
            printf("Discount applied for user %d!\n", userId);
        }
    }

    printf("Automatic discount system implemented successfully!\n");}

void leave_Rating(struct Car cars[], int carCount) {
    printf("Enter the car ID  you want to leave a rating for: ");
    int carId;
    scanf("%d", &carId);

    if (carId >= 0 && carId < carCount && strcmp(cars[carId].state, "Rented") == 0) {
        printf("Enter your rating (1-5): ");
        int rating;
        scanf("%d", &rating);

        if (rating >= 1 && rating <= 5) {
            cars[carId].userRating = rating;
            printf("Thank you for your rating! we only grow with your trust\n");
        } else {
            printf("Invalid rating. Rating must be between 1 and 5.\n");
        }
    } else {
        printf("Invalid car ID or the car is not currently rented. Please verify and try again.\n");
    }
}

void show_Car_Ratings(struct Car cars[], int carCount) {
    printf("Enter the car ID to show ratings: ");
    int carId;
    scanf("%d", &carId);

    if (carId >= 0 && carId < carCount) {
        printf("Car ID: %d\n", carId);
        printf("User Rating: %d\n", cars[carId].userRating);
    } else {
        printf("Invalid car ID. Verify and try again.\n");
    }
}


int main() {
    struct Car cars[100];
    struct Rental rentals[100];
    int carCount = 0;
    int rentalCount = 0;
    int choice;
    while (1) {
        principal_Menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rent_a_Car(cars, rentals, &carCount, &rentalCount);
                break;
            case 2:
                Show_Car_Description(cars, carCount);
                break;
            case 3:
                remove_Malfunctioning_Car(cars, &carCount);
                break;
            case 4:
                modify_Car_Details(cars, carCount);
                break;
            case 5:
                show_Rental_History(rentals, rentalCount, cars, carCount);
                break;
            case 6:
                return_a_Car(cars, rentals, &carCount, &rentalCount);
                break;
            case 7:
                automatic_Discount_System(cars, rentals, carCount, rentalCount);;
                break;
            case 8:
                leave_Rating(cars, carCount);
                break;
            case 9:
                show_Car_Ratings(cars, carCount);
                break;
            case 10:
                printf("Exiting program.\n");
                free(cars);
                free(rentals);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
