
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"��֮����"NOR);
	set("long", GRN @LONG
     һ�����˴����ҽ��ϣ���������ˮ���������ܲ������ܸ�����
���紵����ԶԶ�����������洬���沨�ظ����򣻻ް���������գ���
���Ŵغ���һֻֻ����������צ��Ұ�ޡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong32",
		"east" : __DIR__"dong52",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(2)+4),
		"north" : __DIR__"dong3"+(random(2)+4),
		"west" : __DIR__"dong52",
                "east" : __DIR__"dong32",
	]));
        set("objects", ([
              __DIR__"npc/lev2" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

