// Room: /d/wizhome/incahome/changcheng4.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT @LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
�������ǰ����Ĺ�ľ�ԣ����Ŀ��ȥ����µĳ���˳��ɽ����һ������������
���򱱣����������ȥ����������������ԼԼ���Կ��������������ľ�ӹ�ء�
LONG
   NOR     );

        set("outdoors", "changcheng");

        set("exits", ([
                "westup" :__DIR__"changcheng5.c",
                "eastdown" :__DIR__"changcheng3.c",
        ]));

        setup();
        replace_program(ROOM);
}
