// zhujia.c ���׷�
// ����lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "��Ȫ�Ƽ�");
        set("long", @LONG
����ȫ����������Ȫ�Ƶ�Ĵ�����ȫ������ʳ�����ﶼ��
�Ե�,��������������˵Ĳ���,�����ȥ����ĳ�������
��.....
LONG
        );

        set("exits", ([
                "north" : "d/beijing/dongcha1",
                "east" : __DIR__"shaocai",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

