// Room in ����
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�洬");
	set("long", @LONG
�洬������һ�룬���Ҷ�������һģһ���ģ�������ͷ���ۻ�����
Ȼһ������ӿ������һ�����ȣ����������������㼸�������˺�ȥ��
LONG
	);
	set("exits", ([
	"north" : __FILE__,
	"west" : __FILE__,
	"south" : __DIR__"yuchuan",
	"northwest" : __DIR__"yucun",
	]));
	setup();
	replace_program(ROOM);
}

