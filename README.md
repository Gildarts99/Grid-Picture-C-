# Grid-Picture-C-
- this program takes in commands from a file called commands.txt and then moves around a grid to compleate the commands of that file
- the grid is constructed of linked nodes making a 50 x 50 grid
- the pen moves node by node and depending on the command, will write on the node that it passes on just moves over the node
- the commands are: 
      - 1:  have the pen 'hover' the grid so that it moves without drawint
      - 2:  have the pen 'touch' the grid so it can draw
      - 3:  move the pen
            - N -> North
            - S -> South
            - E -> East
            - W -> West
      - 4:  print the current output to the console
      - B:  make the pen print in bold
      - b:  make the pen print unbolded
- at the end of the program we draw the compleated picture to an output file called print.txt
