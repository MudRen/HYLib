// Room: /d/wizhome/incahome/changcheng22.c
// Date: inca 98/08/13

#include <ansi.h>

inherit ROOM;

void create()
{

        set("short",WHT"����"NOR);
        set("long", WHT@LONG
���ڳ����ܵ���ɳ����ʴ�����ٳ�ǽ�Ѿ�������ǽ�ǵĻ�ɳ�������
�ӳ�ǽ�ϵ���������ש��ǰ�治Զ�����ǳ��ǵ��յ�--�����ء���������
������ͨ�����ڵıؾ�֮·��������Ҳ����������ֻ�������۽𷢵���
�˴������ǵ��̶ӴҴ�����ȥ��
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "southwest"      :"/d/jyguan/wall.c",
                "east"           :__DIR__"changcheng20.c",
        ]));

        setup();
        replace_program(ROOM);
}
