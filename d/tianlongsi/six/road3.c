#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ʯ·"NOR);
        set("long", @LONG
��������һ�ΰ�ʯ·��ʯ��ƽ������ɨ�øɸɾ�����·�����и�ʽ��
�ݣ����������������������ߡ�
LONG);
        set("outdoors", "������");
        set("exits", ([             
               "west" : __DIR__"wwj",
        ]));

        setup();
        replace_program(ROOM);
}