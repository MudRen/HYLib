// /d/yazhang/dongmen.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��ͻ���ǲ�ԭ�İ������ʶ���ǽ��ķ�ͬһ�㣬��ǽ�������ɸߣ�
���Ž����ָ��ִ���������С�һ�����ͨ��ɽ���ء�
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
"northeast" : __DIR__"shop",
                  "west" : __DIR__"dongdajie1",    
	]));
  set("objects",([
	  __DIR__"npc/wujiang":1,
	  __DIR__"npc/bing":2,	
	  ]));
       setup();
	replace_program(ROOM);
}	
