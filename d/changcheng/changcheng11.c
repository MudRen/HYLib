// Room: /d/wizhome/incahome/changcheng11.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",WHT "����");
        set("long", WHT@LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
�Ĺ�ľ���Ѿ����󶫱ߵ���ô���ˣ���Ҳ�����˲��٣��ܶ�ط��Ѿ�¶����һ
ƬƬ�Ļ��������Ŀ��ȥ����µĳ���˳��ɽ����һ�����������ѵ��򱱣���
�������ȥ������ȥ������ϡ�٣�����е�һƬ������
LONG
 NOR       );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"      :__DIR__"changcheng12.c",
                "east"      :__DIR__"changcheng10.c",
        ]));

        setup();
        replace_program(ROOM);
}
