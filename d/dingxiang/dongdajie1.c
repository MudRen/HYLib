// /d/yazhang/dongdajie1.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ������
������һ�����У��ϱ��������̣��ڴ�����㶼�����������������Ĵ�
������
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"masi",  
                  "south" : __DIR__"datiepu",  
                  "east" : __DIR__"dongmen",  
                  "west" : __DIR__"dongdajie2",    
	]));
       setup();
	replace_program(ROOM);
}	
