// boat5.c С��
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","С��");
        set("long", @LONG
������һҶ����֮�ڣ�������С�쳣�����Ҳ�����ض��������ˡ���˫
�ְ⽰��������˳Ϫ���¡�
LONG
        );
        set("exits", ([ 
		"out"  : __DIR__"xibian",
        ]));

        set("outdoors","�����"); 
        setup();
}

void init()
{
        call_out("run", 0, this_player());
}

void run()
{
        if (environment(this_player())== this_object())
        message_vision(HIW"\n�ֻ��������Ϫ�����ۣ�С�۾������˼�������ֻص�Ϫ�ߡ�\n"NOR,this_player());
}
