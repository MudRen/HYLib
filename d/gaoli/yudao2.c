// /d/gaoli/yudao1
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ʳ�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵����
���ڲ��Ǹߴ��ΰ�Ļʳǳ�ǽ��ǽ��Ʈ����һ����Ļ��㡣
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"yudao4", 
                "east":__DIR__"yudao1",
	]));
	set("objects",([
	  __DIR__"npc/girl":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
