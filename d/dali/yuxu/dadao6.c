// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
���ڴ���ϣ����߶���������������·���������˲����ࡣ
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"dadao7",
	    "south" : __DIR__"dadao5",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
