#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǽ�����ԼĪ���ɼ�����һ���ʯ�ң�ǽ�ںͶ��嶼�Ǵ�ʯ������
ǽ�������һֻ��Ͱ�������ŵ��ľ��ǳ�����ù����������ǽ�ϵ�С����
ȥ�����Լ������ָ���һ�ǡ�
LONG
        );

        set("exits", ([
                  "east" : __DIR__"bingying1",
        ]));
        set("objects", ([
                __DIR__"npc/dingdian" : 1,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}
