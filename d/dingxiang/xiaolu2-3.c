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
		"west" : __DIR__"xiaolu2-2",
		"southeast" : __DIR__"xiaolu3",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

