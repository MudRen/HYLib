// Room: /d/wizhome/incahome/changcheng17.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",WHT "����");
        set("long",WHT @LONG
���Ѿ��ƹ��˵����ĳ�ǽ���лص��˳����ϡ�վ�ڼ�ʵ�ĳ�ש�ϣ������
�ĳ�����������ﳤ�����������������������������ڿտ���ɽ�ϴ��˺�Զ��
��Զ��
LONG
 NOR       );

        set("outdoors", "changcheng");

        set("exits", ([
                "westup"    :__DIR__"changcheng18.c",
                "southdown" :__DIR__"changcheng16.c",
        ]));

        setup();
        replace_program(ROOM);
}
