// Room: shijie.c
// congw 980829
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ��ʯ�ף�������������Ժ��������һƬ���̵����֡�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
	"southdown" : __DIR__"zizhulin",
	"north" : __DIR__"shuyuan1",
	]));
	setup();
	replace_program(ROOM);
}

