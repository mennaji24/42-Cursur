#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void){
	char *line;
	int fd;

	fd = open("/Users/mennaji/Desktop/get_next_line/gnlTester/files/42_no_nl", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s",line);
		free(line);
	}
	close(fd);
	return (0);

}
