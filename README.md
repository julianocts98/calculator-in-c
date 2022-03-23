# Calculator in C

This is a simple challenge made by @MrTaiko314 for me and it aimed to serve as a little warming up before getting into the study of Data Structures and Algorithms.

The main idea was quite simple: to make the calculator work by parsing a single string expression that contains two natural numbers and one operand, instead of getting the user input for every number and operand.

I also decided to not use any other lib besides **stdio.h**, though this realy made things harder as I may explain next.

## Problems caused by the constrained use of libraries

Since I couldn't use dynamic allocation with **malloc**, available at the **stdlib.h**, I coulnd't return strings from the local scope of functions.
To bypass this case, I passed the strings I wanted to store the values as arguments for the functions and populated them inside the functions.

I also had a few problems since I couldn't simply copy string arrays easily through the use of **strcpy**. To bypass this, I used the same solution above for the dynamic allocation problem. I had to pass for each fucntion the string I will store the value, and copy char by char of the string.

In the end, to be able to use a simple **switch** for solving the operation, I also couldn't simply convert the strings of the parsed expressions into numbers in an easy way, so I had to manually create functions for converting any string into integers.

## TODO

- [ ] Re-write the code using **stdlib.h** and **string.h** libraries.
- [ ] Accept negative numbers.
- [ ] Accept floating numbers.
- [ ] Accept multiple expressions as arguments, and solve them accordingly their priority.
