// Room: /d/wizhome/incahome/changcheng7.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT @LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
���Կ������ٰ����Ĺ�ľ�ԣ������ٵ���Ҳ�������ˣ��ܶ�ط��Ѿ�¶����һ
ƬƬ�Ļ��������Ŀ��ȥ����µĳ���˳��ɽ����һ�����������ѵ��򱱣���
�������ȥ��
LONG
     NOR   );

        set("outdoors", "changcheng");

        set("exits", ([
                "northup"   :__DIR__"FengHuoTai1-1",
                "southeast" :__DIR__"changcheng6",
        ]));

        setup();
        replace_program(ROOM);
}


