# SNHU-Portfolio
Summarize the project and what problem it was solving.

  This project is a c++ project that works with files. The given requirements were for the program to take in a file for reading, allow the user to access the frequency of the data within the file in a few different ways, and then to output the frequency of items in a new file. The project is solving a means to give the user the ability to work with and create data files given some basic options. In this example it would be useful as a grocery
store tracking program that could allow the sales team to understand which products are being bought the most.

What did you do particularly well?

  I think that I orgranized the project well. It seems easy to understand, there isn't a ton of code within main, and There are comments for all of the functionality. Most of the functionality is easy to understand and doesn't require too much jumping around.
  
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

  I could definitely had chose better names for the option functions. The names don't exactly specify what the function does, which creates ambiguity. I could of also specified most of my MenuHandler class functions as const, which would allow any future programmers to know that the function doesn't change any variables, which would be useful when debugging. There could also be a little more data checking verification with inputs. I implemented a little, but it's better to be completely thorough with potential misentries that could break the program. I also could have made a call to the "option 2" function in the "WriteItems" function since most of the functionality is identical, just with a couple add-ons to reduce repeated code.
  
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

  Without a doubt, finding a way to iterate over a map was the most difficult part. I am accustomed to working with OOP languages that already have built in objects with functionality to iterate over them. I had outsourced to reddit and found that using an unordered map instead would allow iteration. I am also not terribly used to working with files still, so while it wasn't terribly difficult, I did have to review the zybooks lesson on it to ensure my program was checking if files were opened and working correctly. One other thing is that I do not understand how to dynamically include paths for project files in the program, and rely on the user to enter their own path.
  
What skills from this project will be particularly transferable to other projects or course work?

  As with most projects, you run into times where you have to apply probelm-solving logic and think outside of the box. I think that is the most useful part of experience with every program. More specifically for this project though, it helped me get more practice with file manipulation and I had to learn about maps, which gives me another option to think about in future scenarios.
  
How did you make this program maintainable, readable, and adaptable?

  The program is maintainable by implementing a class, which easily allows functionality to be added or removed. Comments are also a large part of maintainability so any future programmers don't struggle to understand the code. The class is also organized into a header and a cpp file, which make it easier to view which specific functions a class has and their necessary attributes.
