// houshan.c ��ɽ
// zly 99.7.28

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ɽ"NOR);
        set("long", @LONG
�����Ǻ�ɽ��һ�����ε�Сɽ�ȣ������˼����������й������죬
����ɭɭ����ʧΪһ����������ĺõط���ż����Զ���������������
��������������㣬��ֱ���������Լ�����������Դ��
LONG
        );
        set("exits", ([
            "south" : __DIR__"shulin",
        ]));

        set("objects", ([
             __DIR__"npc/xiaozh" : 1,
             __DIR__"npc/yuangn" : 1,
        ]));

        setup();
}
