// /d/yazhang/zhubaodian.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�鱦��");
	set("long", @LONG
����һ��ר�ų��۹��ر�����鱦�ꡣ�����鱦����ƵĹ����ɫ��
�����ɫ���㿴����������챦�����ۻ����ң�����������
LONG
	);
set("exits", ([
                 "west" : __DIR__"beidajie2",  
	]));
 set("objects",([ __DIR__"npc/zhubaoshang":1,]));
       setup();
	replace_program(ROOM);
}	
