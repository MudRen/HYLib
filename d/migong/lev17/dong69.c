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
set("no_npc",1);
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong6"+(random(7)+3),
		"north" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong6"+(random(7)+3),
		"north" : __DIR__"dong70",
	]));
       set("objects", ([
              __DIR__"npc/player" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
