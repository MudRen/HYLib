
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���֮�õ�"NOR);
	set("long", HIC @LONG
   ����һ�����ڸ�ɽ�ϵĳǱ���ǽ�ڼ��ذ嶼���Դ���ʯ����� ǽ��
���м�ֻ���ȼ���������컨��������������ֵ�С�ף�Ӧ���Ǵ˳�
����ͨ��ף������ܵľ��￴���˵رض���ǧ�����ϵ���ʷ�����Ǿ���
�����ҿ�������.�����������ط�˯��??(sleep)��Ҳ�������Ե�(list)
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
                "south" : __DIR__"dong27",
                "north" : __DIR__"dong30",
	]));
         set("objects", ([
              __DIR__"npc/sell3" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
