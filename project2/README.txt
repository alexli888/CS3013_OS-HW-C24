CS3013 Project 2 WGP  Alex Li Eric Li

This project has 36 baseball players (enough for four teams of 9 players),
44 football players (enough for four teams of 11 players),
and 60 rugby players (enough for four fullteams of 15 players)

We created threads of individual players of a game (baseball'b' football'f' and rugby'r')
Once we have an appropiate amount of threads for a game, that game 'starts(Just wait runs for a random time)
We then printed out the Game Ended, and moved onto other games. 

Challenges with this project is the Rugby, as it can have varying sizes of the team for which it can run. 1-15 pairs, are all valid places where the game can start

For fairness and simplicity, we made the each of the 3 games run twice. And we only used a single unique player individual once. 

Potential defects of the project are that sometimes the output on the terminal may vary, because of the uncontrolled scheduling. So a disclamer is that the output at runtime 
has a chance to be different that output provided in output1.txt. Also do to limited resources, this could lead to less than ideal outputs. 

Note: THE RUGBY GAME RUNS TWICE, BUT THERE IS NOT A <<GAME ENDED>> PRINT ASSOCIATED WITH THIS NEW GAME, WE JUST START AGAIN ON SLOT 1, ACCUMULATING RUGBY PLAYER NUMBER 
