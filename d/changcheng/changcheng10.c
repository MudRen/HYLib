// Room: /d/wizhome/incahome/changcheng10.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT"����");
        set("long", WHT@LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
���Կ������ٰ����Ĺ�ľ�ԣ������ٵ���Ҳ�������ˣ��ܶ�ط��Ѿ�¶����һ
ƬƬ�Ļ��������Ŀ��ȥ����µĳ���˳��ɽ����һ�����������ѵ��򱱣���
�������ȥ��
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"      :__DIR__"changcheng11.c",
                "southup"   :__DIR__"changcheng9.c",
        ]));

        setup();
        replace_program(ROOM);
}
