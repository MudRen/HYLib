// Room: /d/wizhome/incahome/changcheng2.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",WHT "����");
        set("long", WHT @LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
�������ǰ����Ĺ�ľ�ԣ����Ŀ��ȥ����µĳ���˳��ɽ����һ������������
���������ȥ��������������Կ��������������ľ�ӹ�ء�
LONG
  NOR );

        set("exits", ([
                "westup" :__DIR__"changcheng3.c",
                "east" :__DIR__"changcheng1.c",
        ]));

        setup();
        replace_program(ROOM);
}
