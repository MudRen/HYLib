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
	"west" : __DIR__"zizhulin5",
	"east" : __DIR__"zizhulin1",
	"south"	: __DIR__"zizhulin7",
	"north" : __DIR__"zizhulin2",
]));
	setup();
	replace_program(ROOM);
}

