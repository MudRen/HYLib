// Room: /d/wizhome/incahome/changcheng5.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT @LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
���Կ������ٰ����Ĺ�ľ�ԣ����еĵط��Ѿ�¶����һƬƬ�Ļ����أ����Ŀ
��ȥ����µĳ���˳��ɽ����һ�����������ѵ��򱱣����������ȥ��������
��������ԼԼ���Կ��������ƺ���һ���ܴ�Ĺؿ���
LONG
     NOR   );

        set("outdoors", "changcheng");

        set("exits", ([
                "west" :__DIR__"changcheng6.c",
                "eastdown" :__DIR__"changcheng4.c",
        ]));

        setup();
        replace_program(ROOM);
}
