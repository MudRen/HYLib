// /d/yazhang/nanmen
// Room in ����
// rich 99/05/17
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��ͻ���ǲ�ԭ�İ������ʶ���ǽ��ķ�ͬһ�㣬��ǽ�������ɸߣ�
���Ž����ָ��ִ���������С�
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
		"south" : __DIR__"guandao1",
		"north" : __DIR__"nandajie1", 
	]));
	set("objects",([
	__DIR__"npc/dun":1,
	  __DIR__"npc/bing":2,	
	]));
       setup();
	replace_program(ROOM);
}	
