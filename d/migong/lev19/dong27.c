
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�¸�֮��"NOR);
	set("long", HIC @LONG
   ����һ�����ڸ�ɽ�ϵĳǱ���ǽ�ڼ��ذ嶼���Դ���ʯ����� ǽ��
���м�ֻ���ȼ���������컨��������������ֵ�С�ף�Ӧ���Ǵ˳�
����ͨ��ף������ܵľ��￴���˵رض���ǧ�����ϵ���ʷ�����Ǿ���
�����ҿ�������.
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "east" : __DIR__"dong22",
                "west" : __DIR__"dong33",
		"south" : __DIR__"dong28",
                "north" : __DIR__"dong29",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
