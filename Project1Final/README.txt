CS3013 Project 1 

We are reading from a file, seed.txt, and from that something to spawn or create children that do something. We also did exploring the file system using chdir(). 

I believe something is wrong with the expected output of Pt 4 f the project. For seed 3 './explorer 3' When program randomly chooses to go to '/bin' 
it instead goes to '/usr/bin'. Upon futher investigation, I found that the program actually went to /bin, yet it is displayed as 'usr/bin'. Perhaps something weird
with the chdir() function.

For prolific, explorer, and generation. What I did for the forking process is follow the textbook and powerpoint guidelines. 
I tried to keep as much as prolific.c's code as possible when implemeting the explorer.c and prolific.c to make it easier to do. 

For testing the code, I made a .txt file seed.txt and put the seed 12345 inside there. From this, my programs can read the 12345 seed from the seed.txt file, and 
from that I can debug accordingly. I also added accordingly seed_slug_x.txt files with corresponding seeds to test other sections of the project.
Everything but the PID numbers for the children and parents should be the same. So that is how I tested the code. 