// Room: /wizhome/lanzhou/nroad4.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о��ú��Ļ�������
һ����Ҫ��½��ͨ����
������һ������·�ϣ�·����������һЩ��ͩ���������˺��٣�ż���м�
���������յ������������ϴҴ���ȥ��·�����߶��ǻ���������ȥ�ܻ�������
������������ˮ����ǰ�������һ���ӡ�
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "southeast" : __DIR__"nroad3",
                "north"     : __DIR__"river-nan",
        ]));

        setup();
        replace_program(ROOM);
}

