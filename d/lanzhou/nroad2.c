// Room: /wizhome/lanzhou/nroad2.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о��ú��Ļ�������
һ����Ҫ��½��ͨ����
������һ������·�ϣ�·��������������ͩ���������˲��Ǻֻܶ࣬��һ
Щ���������յ������������ϴҴ��߹���ż���������������ڴ���԰���
��С̯��������������ԼԼ���Կ������ݳǡ�
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "south"     : __DIR__"nroad1",
                "northwest" : __DIR__"nroad3",
        ]));

        setup();
        replace_program(ROOM);
}

