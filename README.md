# Get next line

Function to read line by line from file. 2021-2022

## Declaration

```c
char	*get_next_line(int fd);
```


## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/Ra-Wo/Get-next-line.git && cd Get_next_line

# Create a main file
touch main.c
```

```c
/*
** Example of a main, change "myfile.txt"
** to a file you want to read
*/

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;

	fd = open("myfile.txt", O_RDONLY);

	while (1)
  {
    printf("%s", get_next_line(fd));
  }
	return (0);
}
```

```bash
# Compile the files, example:
gcc get_next_line.c get_next_line.h get_next_line_utils.c main.c

# Execute your program
./a.out

# Well done!
```


[[forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)]
