
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ˮû���й㳡"NOR);
	set("long", GRN @LONG
    ������о�Ȼ�ں���,�ŵ�������������ġ�ˮ�塻�����Զ���ǧ�ɸߵ�ˮ
ǽ������ˮ����¡¡�ؿ�Ҫ����Ķ�Ĥ����, Ю���������ˮ��,���������ȫ
�����ʪ�ˡ� ˮǽ��һЩ�߲ʰ�쵵���������е�׷����ˣ,��ʱ�ν�����
��,һ��Ҳ�����������,�㲻��������Ҫ����ˮǽȥ��������,ȴ�ƺ��й���
���赲���㡣�����и�ħ���㣬����Լ�¼һ��(save)��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong21",
                "north" : __DIR__"dong23",
                "east" : __DIR__"dong24",
                "west" : __DIR__"dong27",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(3),
         ]));
 set("valid_startroom", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
