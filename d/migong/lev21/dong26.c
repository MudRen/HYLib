
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"���³ǵ����̵�"NOR);
	set("long", BLU @LONG
������ĳ��У����������ŵĶ���ħ���һЩ���
ħ�壬����������壬�ڼ�ǧ��������£���Ȼ��ǿ��
�����š��ɴ˿��Կ����κ����嶼������ڵ����ɺͷ�
ʽ���������̵ꡣ������Щʲô��??(list)
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "south" : __DIR__"dong24",
	]));
         set("objects", ([
              __DIR__"npc/sell2" : 1,
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
