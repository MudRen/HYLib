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
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong63",
		"north" : __DIR__"dong65",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong62",
		"east" : __DIR__"dong6"+(random(3)+3),
		"south" : __DIR__"dong6"+(random(3)+5),
		"north" : __DIR__"dong6"+(random(5)+5),
	]));
        set("objects", ([
              __DIR__"npc/lev7" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
