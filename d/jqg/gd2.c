// Room: /u/dubei/u/gumu/jqg/gd2
// by dubei
#include <ansi.h> 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", WHT"����ȵ�"NOR);
	set("long", @LONG
ֻ������ҫ�ۣ������˱ǣ����Ǳ�����أ�������������
Ŀ�Ĺˣ�ֻ��������ݣ�����ͬһ������Ļ�԰��Ȼ��Ӱ������
�Ĺ����ˡ����־���ϲ�������ˮ����ʮ�������м���é�ݡ�
LONG
	);
        set("exits", ([
                "enter" : __DIR__"mw",

        ]));
        setup();
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "tan di" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;

       message_vision("$N������̶���˽�ȥ��\n", me);
       me->move(__DIR__"ht1");
       tell_room(environment(me), me->name() + "�Ӱ������˽�����\n", ({ me }));
       return 1;
}