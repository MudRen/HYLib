// /d/yazhang/shanghuang.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���Ų��߽����У�ֻ�������ŵ�������д�š��������С���������
�������︶�ۻ��ۣ����ϵ�С�ź�����ͨ���Ժ���ʷ���
LONG
	);
set("exits", ([
                 "east" : __DIR__"nandajie2",  
                  "southwest" : __DIR__"zhangfang",    
	]));
 set("objects",([ __DIR__"npc/shangren":1,]));
       setup();
	replace_program(ROOM);
}	
