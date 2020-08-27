#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//typedef enum {true, false} bool;
//https://stackoverflow.com/a/1344260 for rounding
typedef struct {float price;} pizza;
typedef struct {int pepperonis; int mozzerellas; int nudjas;} basket;

int main(void) {
  basket pizzas;
  pizza pepperoni;
  pizza mozzerella;
  pizza nudja;
  pepperoni.price = 23.99;
  mozzerella.price = 21.00;
  nudja.price = 25.99;
  pizzas.pepperonis = 0;
  pizzas.mozzerellas = 0;
  pizzas.nudjas = 0;
  
  float tax = 0.0575;
  float subtotal = 0;
  char input[50];

  while(true){
    printf("Please select a pizza to add to your basket\nPepperoni price: %f\nMozzerella price: %f\nNudja price: %f\nType 'checkout' to checkout.\nEnter your choice here (all lowercase) >> ",pepperoni.price, mozzerella.price, nudja.price);
    scanf("%s", input);
    if (strcmp(input, "pepperoni") == 0) {
      pizzas.pepperonis++;
    } else if (strcmp(input, "mozzerella") == 0) {
      pizzas.mozzerellas++;
    } else if (strcmp(input, "nudja") == 0) {
      pizzas.nudjas++;
    } else if (strcmp(input, "checkout") == 0) {
      break;
    } else{
      printf("Unknown pizza or command. Please try again\n");
    }
    subtotal = (pepperoni.price*pizzas.pepperonis)+(mozzerella.price*pizzas.mozzerellas)+(nudja.price*pizzas.nudjas);
    subtotal = ((int)(subtotal * 100 + .5) / 100.0);
    printf("Basket:\n%dx Pepperoni\n%dx Mozzerella\n%dx Nudja\nSubtotal: %f\n",pizzas.pepperonis,pizzas.mozzerellas,pizzas.nudjas,subtotal);
  }
  subtotal = (pepperoni.price*pizzas.pepperonis)+(mozzerella.price*pizzas.mozzerellas)+(nudja.price*pizzas.nudjas);
  subtotal = ((int)(subtotal * 100 + .5) / 100.0);
  float total = subtotal*tax+subtotal;
  total = ((int)(total * 100 + .5) / 100.0);
  printf("Subtotal: %f\n Sales tax (5.75 percent): %f\n Total: %f", subtotal, subtotal*tax, total);
  return 0;
}
