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
	"northup" : __DIR__"shuyuan1",
	]));
	setup();
	replace_program(ROOM);
}

