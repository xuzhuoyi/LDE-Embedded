/**************************************************************************
  OPEN2440 ds18b20 1-wires driver test
  device node is "/sys/devices/w1 bus master/28-IDNUM/w1_slave"
  IDNUM is read from ds18b20's rom, the value is the only one
  
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>

int main(int argc, char *argv[])
{
	while(1)
	{
	int fd = -1, ret;
	char *tmp1, tmp2[10], ch='t';
	char devname_head[50] = "/sys/devices/w1_bus_master1/28-";
	char devname_end[10] = "/w1_slave";
	char dev_name[100];
	long value;
	int integer, decimal;
	char buffer[100];
	int i,j;
	
	strcpy(dev_name, devname_head);
	strcat(dev_name, argv[1]);
	strcat(dev_name, devname_end);
	
	if ((fd = open(dev_name, O_RDONLY)) < 0)
	{
		perror("open error");
		exit(1);
	}

	ret = read(fd, buffer, sizeof(buffer));
	if (ret < 0)
	{
		perror("read error");
		exit(1);
	}	


	tmp1 = strchr(buffer, ch);		
	sscanf(tmp1, "t=%s", tmp2);
	
	value = atoi(tmp2);	
	integer = value / 1000;
	decimal = value % 1000;
	
	printf("temperature is %d.%d\n", integer, decimal);

	close(fd);
	
	FILE *fp;
	if((fp = fopen("tmdata", "w")) == NULL)
	{
		printf("Cannot open file\n");
	    exit(0);
	}
	fprintf(fp, "%d.%d 0", integer, decimal);
	fclose(fp);
	
	sleep(1);
	}
	return 0;
}
