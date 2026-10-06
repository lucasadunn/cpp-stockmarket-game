# cpp-stockmarket-game
This is a short and simple game I made as my first project in C++. It contains initial stocks which the player invests in, and as they progress through 3 levels, the stocks change value randomly. The player can buy or sell stocks during each level, and the goal is to end with more money than they started with.

Starting with $10,000, the player is given the choice to invest in 5 companies.

APPLE  
NVIDIA  
MICROSOFT  
TESLA  
AMAZON

These stocks are all given an initial value based on their real-world value. The user is prompted for each stock individually, and they enter how many of each they want to buy. After all 5 stocks are completed, the first round starts. Using `random_device`, each stock is given a new random coefficient between 0.75 and 1.25 at the beginning of each new round, which is then multiplied by the stock's value at the start of the round. This represents a random change in price similar to how stock prices may look random in the short term.

Each round, the user is given the option to buy or sell stocks, or to continue. If buy is chosen, they can buy more stocks from one company if they have money left. If sell is chosen, they can sell a chosen amount of a stock of their choosing.

At the end of the 3 rounds, if the person's portfolio, which is the value of all their stocks owned, and their cash, the money they did not spend on stocks, combine to more than the $10,000 they had to begin with, they win. If not, they lose.

Concepts used: 
- C++
- Loops
- Conditional statements
- Switch statements
- Functions/logic
- Random number generation
- User input
- Floating-point arithmetic
