
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���֮ħ��ʦ����"NOR);
	set("long", HIC @LONG
   ����һ�����ڸ�ɽ�ϵĳǱ���ǽ�ڼ��ذ嶼���Դ���ʯ����� ǽ��
���м�ֻ���ȼ���������컨��������������ֵ�С�ף�Ӧ���Ǵ˳�
����ͨ��ף������ܵľ��￴���˵رض���ǧ�����ϵ���ʷ�����Ǿ���
�����ҿ�������.������ħ��ʦ���ᡣ����ѧЩʲô��??(skills)
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "north" : __DIR__"dong27",
	]));
         set("objects", ([
              __DIR__"npc/master" : 1,
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
