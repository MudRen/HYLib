#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIW"С����"NOR);
        set("long", @LONG
������䴳����һ��ɽ�ȣ������ľ��쳣���㲻�ɵ�������Щ��ë��
ɽ�����඼���ͱڣ�����һֱͨ��ɽ���������û��ʲô·����ľ
��֦��ס��ǰ����·���������������·
LONG);
        set("outdoors", "������");
        set("exits", ([             
               "west" : __DIR__"songlin-2",
                      ]));

        setup();
        replace_program(ROOM);
}

