// /d/yazhang/xiaolu2.c
// Room in ����
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
������һ��ȥ���ԭ�ıؾ�֮·��С·�����Ӳ��ڶ࣬·������Ҳ
���١�
LONG 
        );
	set("exits", ([
		"northwest" : __DIR__"xiaolu2",
		"east" : __DIR__"xiaolu2-2",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

