// Room: /d/changcheng/FengHuoTai1-2.c
// Date: inca 98/08/30

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", HIY "���̨");
        set("long",WHT  @LONG
�����Ƿ��̨�Ķ�¥��վ����������Կ��ĺ�Զ����ߵĽ�ʿ�Ǿ���
���������������ֹ��ū�Ľ����������߽��İ�ȫ����������������
ԼԼ���Կ��������������ľ�ӹ�ء�
LONG
NOR       );

        set("outdoors", "changcheng");

        set("objects", ([
                 "/d/changcheng/npc/guanbing" : 2,
        ]));

        set("exits", ([
                "down"    :__DIR__"FengHuoTai1-1",
        ]));

        setup();
        replace_program(ROOM);
}
