#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
//#include "demo.c"
#include "partition.c"

char buf[512];
int fd;
struct partition *p;
struct partition *p1;
struct partition *p2;
struct partition *p3;
struct partition *p4;

int main(int argc, char *argv[ ], char *env[ ])
{

   	int tempSector, r, origs, ii = 0, iii =0;
   	fd = open("vdisk", O_RDONLY);          // open disk iamge file for READ

   	r = read(fd, buf, 512);                // read FIRST 512 bytes into buf[ ]
   	p = (struct partition *)(&buf[0x1BE]); // p points at Ptable in buf[ ]

	Myprintf("cha=%c  string=%s  unt = %u dec=%d hex=%x oct=%o neg=%d \n", 'A', "hello this is a test", 100, 100,100,100, -100);
	 
	 
 	Myprintf("argc: %d", argc);
	
	while(*argv!=NULL) {
	Myprintf("Count: %d  argv: %s\n", ii, *argv); //prints everything in argv
	argv++;
	ii++;
	}
	
	while(*env!=NULL) {
	Myprintf("Count: %d  env: %s\n", iii, *env); //prints everything in env
	env++;
	iii++;
	}
	
       Myprintf(".......RAW form ......\n");
	   for(int i=0;i<4;i++) {
     
      Myprintf("%d %d %d %d %x %d %d %d %d %d\n", p->drive, p->head, p->sector, p->cylinder, p->sys_type, p->end_head, p->end_sector, p->end_cylinder, p->start_sector, p->nr_sectors); //all the entries in partition
      	
	p++;

	}


        Myprintf("\n--------Linux fdisk form-----------\n");
	printf("start_cyl   end_cyl    size\n");
	p1 = (struct partition *)(&buf[0x1BE]);
	for(int i=0;i<4;i++) {
      Myprintf("%d         %d       %d", p1->start_sector, (p1->start_sector-1+p1->nr_sectors), p1->nr_sectors);
       Myprintf("\n");
	p1++;
	}


        Myprintf("\n--------Look for Extended Partition-----------\n");
	
   // p->cylinder, p->sector, etc.

	p3 = (struct partition *)(&buf[0x1BE])+3; //to 4

	if(5!=p3->sys_type) { //if it has five it's partionable
		return 0;
	}

	Myprintf("Ext Partition: 4  start sector: %d\n", p3->start_sector);//shows start sector

	tempSector = p3->start_sector;  //temp current sector	
	origs = p3->start_sector;  //sector I started from	

	while(p3->start_sector!=0) { //link list ends with 0 in the last local MBR
   	lseek(fd, (long)(tempSector*512), 0);     // seek to sector 10           
   	read(fd, buf, 512);                   // read sector 10 into buf[ ], etc.

   
  	p3 = (struct partition *)(&buf[0x1BE]);
	//MBR contains parition table with two entries: start sector number and size
   	Myprintf("Local MBR start_sector = %d partition start_sector = %d\n", tempSector, p3->start_sector);
	Myprintf("start  end  size\n");
  	Myprintf("%d %d %d\n", (tempSector+p3->start_sector), (((tempSector+p3->start_sector)+p3->nr_sectors)-1), p3->nr_sectors);
	p3++;
	tempSector = p3->start_sector+origs; //progresses through the list
 	}
	close(fd);
}

