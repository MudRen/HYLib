// Room: /d/wizhome/incahome/changcheng18.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT @LONG
���Ѿ��ƹ��˵����ĳ�ǽ���ֻص��˳����ϡ�վ�ڼ�ʵ�ĳ�ש�ϣ������
�ĳ�����������ﳤ�����������������������������ڿտ���ɽ�ϴ��˺�Զ��
��Զ��
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "southwest"  :__DIR__"changcheng19.c",
                "eastdown"   :__DIR__"changcheng17.c",
        ]));

        setup();
        replace_program(ROOM);
}
