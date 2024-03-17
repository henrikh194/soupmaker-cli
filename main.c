//simple cli game made in an hour late at evening sorry for missing input validation for the name input
#include <stdio.h>
#include <stdbool.h>

int money = 100;
int acres = 0;
int carrots = 0;
int onions = 0;
int meals = 0;
int soldmeals = 0;
bool gamerunning = true;
int command;

void acrecalc(){
	carrots = carrots + acres * 2;
	onions = onions + acres * 3;
}

int main(){
	
	char name[50];
	printf("Your name:");
	scanf("%s",name);
	printf("Hello %s",name);
	
	while (gamerunning == true){
		
		if (money > 200){
			printf("OH NO. The IRS took all your money because you apparently had too much.");
			money = 0;
		}
		
		printf("\nYour Money %i \nYour Acres %i \nYour Carrots %i \nYour Onions %i \nStored Meals %i \nSold Meals %i \n",money,acres,carrots,onions,meals,soldmeals);
		
		scanf("%i",&command);
		switch (command){
			
			case 0:
			acrecalc();
			break;

			case 1:
			if (money > 0){
				acres++;
				money--;
			}
			acrecalc();
			break;

			case 2:
			if (carrots > 2){
				if (onions > 3){
					meals++;
					carrots = carrots - 2;
					onions = onions - 3;
				}
			}
			acrecalc();
			break;

			case 3:
			if (meals > 0){
				meals--;
				money++;
				soldmeals ++;	
			}
			acrecalc();
			break;
			
			case 4:
			printf("Do you really wann end the game?\n");
			scanf("%i",&command);
			if (command == 4){
				gamerunning = false;
			}
			acrecalc();
			break;

			case 10:
			if (money > 9){
				acres = acres + 10;
				money = money - 10;
			}
			acrecalc();
			break;

			case 20:
				if (carrots > 20){
					if (onions > 30){
						meals = meals + 10;
						carrots = carrots - 20;
						onions = onions - 30;
					}
				}
			acrecalc();
			break;

			case 30:
				if (meals > 9){
					meals = meals - 10;
					money = money + 10;
					soldmeals = soldmeals + 10;	
			}
			acrecalc();
			break;

			default:
			printf("Invalid command\n Type 1 for buying an acre, 2 to make a meal, 3 to sell a meal and 4 to end the game :)");
			break;
		}
	}
	return 0;
}

// dictionary for cases
// case 0: wait a turn
// case 1: buy an acre
// case 10: buy 10 acres
// case 2: make a meal
// case 20: make 10 meals
// case 3: sell meal
// case 30: sell 10 meals
// case 4: terminate game
