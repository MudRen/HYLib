
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ˮ֮�õ�"NOR);
	set("long", GRN @LONG
    ������о�Ȼ�ں���,�ŵ�������������ġ�ˮ�塻�����Զ���ǧ�ɸߵ�ˮ
ǽ������ˮ����¡¡�ؿ�Ҫ����Ķ�Ĥ����, Ю���������ˮ��,���������ȫ
�����ʪ�ˡ� ˮǽ��һЩ�߲ʰ�쵵���������е�׷����ˣ,��ʱ�ν�����
��,һ��Ҳ�����������,�㲻��������Ҫ����ˮǽȥ��������,ȴ�ƺ��й���
���赲���㡣��������֮�õꡣ�����������ط�˯��??(sleep)��Ҳ������
��Ե�(list)
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
