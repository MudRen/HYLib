// /d/yazhang/xidajie1.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ������
�������ӻ��̣�������һ�ҿ�ջ��
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                   "north" : __DIR__"zahuopu",  
                   "south" : __DIR__"yanfuge",  
                  "east" : __DIR__"xidajie2",  
                  "west" : __DIR__"ximen",    
	]));
	set("objects",([
	  __DIR__"npc/tuli":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
