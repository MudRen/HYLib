#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ʯ·"NOR);
        set("long", @LONG
��������һ�ΰ�ʯ·��ʯ��ƽ������ɨ�øɸɾ�����·�����и�
ʽ���ݣ����������������������ߡ����������޾��������ǰ���̨��
�嶼��̨�ȵء�
LONG);
        set("outdoors", "������");
        set("exits", ([             
               "north" : __DIR__"wwj",
               "southdown" : __DIR__"yaotai",
        ]));
        setup();
        replace_program(ROOM);
}
