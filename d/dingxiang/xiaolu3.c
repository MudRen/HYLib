// /d/yazhang/xiaolu3.c
// Room in ����
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
������һ��ȥ���ԭ�ıؾ�֮·��С·�����Ӳ��ڶ࣬·������Ҳ
���١��������һ���޼ʵĴ��ԭ�ˡ�
LONG 
        );
	set("exits", ([
		"northwest" : __DIR__"xiaolu2-3",
		"south" : "/d/suiye/caoyuan",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

