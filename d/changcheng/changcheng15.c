// Room: /d/wizhome/incahome/changcheng15.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT"����");
        set("long", WHT @LONG
���ڳ����ܵ���ɳ����ʴ��һС�γ�ǽ�Ѿ���������ֻ����ʱ���Աߵ�
С·�ƹ�ȥ������������Կ�������Ȼ�еĵط��Ѿ�������������������Ȼ
��ΰ��������ɽ�����������������ȥ��
LONG
NOR    );

        set("outdoors", "changcheng");

        set("exits", ([
                "northwest" :__DIR__"changcheng16.c",
                "east"      :__DIR__"changcheng14.c",
        ]));

        setup();
        replace_program(ROOM);
}
