
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"���³�ħ��ʦ����"NOR);
	set("long", BLU @LONG
������ĳ��У����������ŵĶ���ħ���һЩ���
ħ�壬����������壬�ڼ�ǧ��������£���Ȼ��ǿ��
�����š��ɴ˿��Կ����κ����嶼������ڵ����ɺͷ�
ʽ��������ħ��ʦ���ᡣ����ѧЩʲô��??(skills)
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