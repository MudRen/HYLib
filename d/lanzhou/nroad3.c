// Room: /wizhome/lanzhou/nroad3.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о��ú��Ļ�������
һ����Ҫ��½��ͨ����
������һ������·�ϣ�·��������������ͩ���������˺��٣�ż���м���
�������յ������������ϴҴ���ȥ��
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "southeast" : __DIR__"nroad2",
                "northwest" : __DIR__"nroad4",
        ]));

        setup();
        replace_program(ROOM);
}

