Section 1 : I used a local VM (Option 2)

For tutorials, I followed the link to the wpi CS dept VM site https://web.cs.wpi.edu/Media/CSVM.html, and then
followed the instructions accordingly. 

- Just waited for the download to finish, left clicked it, then followed post download instructions 
https://web.cs.wpi.edu/Media/Inst/CSVM-Instr-Post-Install.txt

It was pretty simple, no complications on my end. Although it recommended some updates that are only for unbutu pro, 
so I couldnt get it. Mabye provide better instructions that if the updates require unbutu pro, dont do it.

Section 3: 

- The strcpy() function copies the string pointed to by the src. 
- The printf() function allows us to format and print out data, either through manually inputted data, or a function call, or a pointer. 
- the exit() function allows us to terminate our program. 
- the -g flag with the gcc command produces more debugging information that can be used to better debug code using GDB. Essentially, 
  adding this -g flag allows us to better debug our code.

  Section 4: 

  Program received signal SIGSEGV, Segmentation fault.
  0x0000555555555183 in main () at /home/student/project_0/test.c:6
  6     strncpy(buffer, "Hello, world!", 14);

- gdb indicated that line 6 in main causedthe problem. 

- I believe that the error in this code is that we didn't allocate memory to the buffer pointer. 
  If we were to do so using something like alloc for lets say 15 bytes inclduing the null terminator, the error should be fixed. 


// Potentially useful info 
- For the recording script part, i didn't record the entire process accidently, so I 'simulated' the process by making a file called project_0, 
  then changing my directory to the one that is already complete, then following procedures from there.

  Also, for this line in the script make: "Nothing to be done for 'all'."   
  // this means that my executable file was already created, as I changed my directory to the one that was already complete and frogot to delete my previous executable file.