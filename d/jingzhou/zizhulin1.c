// Room: zizhulin
// congw 980829
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ���̵İ�Χ֮�У�������ʧ�˷���
LONG
	);
        set("outdoors", "city");

	set("exits", ([
	"southdown" : __DIR__"zizhulin3",
	"northup" : __DIR__"zizhulin",
	"southup" : __DIR__"zizhulin2",
	"northdown" : __DIR__"zizhulin3",
]));
	setup();
	replace_program(ROOM);
}

