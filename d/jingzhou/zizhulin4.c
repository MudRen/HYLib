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
	"west" : __DIR__"zizhulin3",
	"east" : __DIR__"zizhulin6",
	"southup" : __DIR__"zizhulin4",
	"north" : __DIR__"zizhulin1",
]));
	setup();
	replace_program(ROOM);
}

