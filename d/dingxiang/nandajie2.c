// /d/yazhang/nandajie2.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
������ɽ�˺����㲻�ɵķ����Ų��������������У�һ�ҾƵ��ڴ�
���϶����ż����㣬������һ�����У��������˲��ϡ�
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"guangchang",  
                  "south" : __DIR__"nandajie1",  
                  "east" : __DIR__"jiudian",  
                  "west" : __DIR__"shanghang",    
	]));
	set("objects",([
           __DIR__"npc/tuobayu":1,
           ]));
       setup();
	replace_program(ROOM);
}	
