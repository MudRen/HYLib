#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"ˮ��ɽ��"NOR);
	set("long", WHT @LONG
    ��һ�����صĵط����˴���һ�����ܶ�Χ������ɽ�����ɽ��
ɽ�ȵĵ�������һ��Ư���ĺ����������������Ĵ�����ұ��
�ʻ��̲ݣ����ҴӴ���ȥ��������ɼ����������Ǹ�������Դ��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong9"+(random(4)+6),
	"east" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/lev9" : 2,
     __DIR__"npc/lev7" : 2,
         ]));
	setup();
	replace_program(ROOM);
}
