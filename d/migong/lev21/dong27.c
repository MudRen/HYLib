
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"���³�"NOR);
	set("long", BLU @LONG
������ĳ��У����������ŵĶ���ħ���һЩ���
ħ�壬����������壬�ڼ�ǧ��������£���Ȼ��ǿ��
�����š��ɴ˿��Կ����κ����嶼������ڵ����ɺͷ�
ʽ��
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
