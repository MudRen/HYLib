// boat2.c С��
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","С��");
        set("long", @LONG
������һҶ����֮�ڣ�������С�쳣�����Ҳ�����ض��������ˡ���˫
�ְ⽰����������Ϫ���С�
LONG
        );
        set("exits", ([ 
		"out"  : __DIR__"xiaoxi",
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
        message_vision(HIW"\n�ֻ��������Ϫ�ĺ��оſ��ʯӭ����������������һ�㣬��ס������ȥ·��\n"NOR,this_player());
}
