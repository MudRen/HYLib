// /d/yazhang/ximen.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��ͻ���ǲ�ԭ�İ������ʶ���ǽ��ķ�ͬһ�㣬��ǽ���������ɸߣ�
���Ž����ָ��ִ���������С�
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                  "east" : __DIR__"xidajie1",  
                  "west" : __DIR__"caoyuan",    
	]));
  set("objects",([
	  __DIR__"npc/wujiang":1,
	  __DIR__"npc/bing":2,	
	  ]));
       setup();
	replace_program(ROOM);
}	
