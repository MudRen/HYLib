// by dubei
// Modify By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"����ͤ"NOR);
        set("long", @LONG
����ͤ���Ľ�߬�ⶥ���ܽǷ��̣��������У���׾���־��ɡ�ɽ�»���ˮ
�����ƣ�ˮ��������ͤ����ɽʯ������ǧ�ʰ�̬������ͤ�п����̲���������
�����ٺ�����֮�С�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"xiaoxi",
                "east" : __DIR__"xqx",
        ]));

        set("outdoors", "�����");
        setup();
        replace_program(ROOM);
}
