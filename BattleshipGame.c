#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rows 5
#define columns 5

int mainint main(){
srand(time(NULL));
int grid[rows][columns], attemps=0, ships;
int sunk;

printf("Let's play the battleship game!\n");
printf("You have 20 tries.\n");

printf("Enter the number of ships: ");
scanf("%d",&ships);

prepare_grid(grid); //Prepare grid with items of value -1 
gen_ships(grid,ships); //Generate random ships surrounded by water (value 1)
print_grid(grid); //Print grid without showing the generated ships (all items will be "~" meaning "undiscovered water).

sunk=0;

for (int a=0;a<20;a++){
    shoot(grid,sunk,ships);
    attemps++;
    print_grid(grid);

    printf("\nAttemps: %d\n",attemps);
}

print_secret_grid(grid); //Print final grid, showing all sunk ships and positions shot

return 0;
}

void shoot(int grid[rows][columns], int sunk, int ships) {

int x, y;

printf("\nLine --> ");
scanf("%d", &x);
printf("Column --> ");
scanf("%d", &y);

do {
    if (grid[x-1][y-1] == 1) {
        grid[x-1][y-1] = 2;                               //We assign value 2 because we want to print only the ones the user hits, it will print X which means "hit and sunk".
        sunk++;
        printf("\nHit and sunk\n");
        printf("Sunk ships:%d \n\n", sunk);
    } else if (grid[x - 1][y - 1] == -1) {  //It will print "*" which means "discovered water".
        grid[x - 1][y - 1] = 0;  
        printf("\nMiss\n\n");
    }
  }while (sunk=!ships);
}