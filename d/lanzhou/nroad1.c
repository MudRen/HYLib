// Room: /wizhome/lanzhou/nroad1.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о��ú��Ļ�������
һ����Ҫ��½��ͨ����
������һ����������ϣ�·��������������ͩ�������������ǳ���æ��
��ʱ�����������յ��������˴ҴҶ�������౾�����ڴ�����԰���һЩ
С��̯�������������������--���ݡ�
LONG
        );
        set("outdoors", "lanzhou");

        set("exits", ([
                "south" : __DIR__"beimen",
                "north" : __DIR__"nroad2",
        ]));

        setup();
        replace_program(ROOM);
}

