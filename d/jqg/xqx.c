// by dubei
// Modify By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"�����"NOR);
        set("long", @LONG
�Ϊ���䣬���ϱ�����Ϊ��ѡ����Ϊ���䣬����ƽֱ���ṹ���ɡ������
������Ȫ��ص����������������ţ�����ˮ��ʯʱ��������ɪ����ˬ���壬��
�Ǹ����������ĺ�ȥ����
LONG
        );

        set("exits", ([
                "northup" : __DIR__"fyy",
                "west" : __DIR__"glt",
        ]));

        set("outdoors", "�����");
        setup();
        replace_program(ROOM);
}
