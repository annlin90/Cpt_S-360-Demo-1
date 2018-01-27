//Ext Partition 4 : start sector= 1800

#include <stdio.h>
#include <fcntl.h>
#include "demo.c"

typedef unsigned char u8;
typedef unsigned int u32;

struct partition {
	u8 drive;
	u8 head;
	u8 sector;
	u8 cylinder;

	u8 sys_type;

	u8 end_head;
	u8 end_sector;
	u8 end_cylinder;

	u32 start_sector;
	u32 nr_sectors;

};

char *dev="vdisk";
int read(), lseek();

/*int main(int argc, char *argv[])
{
	int fd, i;
	struct partition *p, *ep;

	char buf[512];
	if(argc>1) {
	dev = argv[1];
	printf("dev = %s\n", argv[1]);
	}
	
	Myprintf("cha=%c  string=%s  unt = %u dec=%d hex=%x oct=%o neg=%d", 'A', "hello", 100, 100,100,100, 100);
	printf("\n");

	fd = open(dev, O_RDONLY);
	read(fd, buf, 512);
	p=(struct partition *)(&buf[0x1be]);
	printf(".......RAW form ......\n");
	for(i=0;i<4;i++) {
	printf("%2x", p->drive);

	printf("%4d", p->head);
	printf("%4d", p->sector);
	printf("%4d", p->cylinder);

	printf("    %2x", p->sys_type);	

	printf("%4d", p->end_head);
	printf("%4d", p->end_sector);
	printf("%4d", p->end_cylinder);

	printf("%8d", p->start_sector);
	printf("%8d", p->nr_sectors);
	printf("\n");
	
	p++;
 }

	printf("\n--------Linux fdisk form-----------\n");
	printf("start_cyl end_cyl size\n");
	p = (struct partition *)(&buf[0x1be]);
}*/

