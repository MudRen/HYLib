// Room: /d/wizhome/incahome/changcheng20.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long",WHT @LONG
���ڳ����ܵ���ɳ����ʴ�����ٳ�ǽ�Ѿ�������ǽ�ǵĻ�ɳ�������
�ӳ�ǽ�ϵ���������ש��̧����ȥ��ֻ����ǽ����һ���ޱߵĻ�ɳ����Χ
�������ˣ���һƬ���������磬ż�����Ϸɹ�һֻ��ӥ��ԶԶ�Ŀ��Կ���
������һ���ؿ���
LONG
   NOR     );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"      :__DIR__"changcheng21.c",
                "northeast" :__DIR__"changcheng19.c",
        ]));

        setup();
        replace_program(ROOM);
}
