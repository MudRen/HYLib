// by dubei
// Modify By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIR"������"NOR);
        set("long", @LONG
�����ƶ��Ƕ����������ܸ�����ʯ�鵹������������ϼ��ب�������ޣ���
Ȼ¥�����ڣ�����ͭ�ı��࣬����ʨ��������������İ���䷿ˮ��֮��������
��̶��ȣ������޵ף�����ïʢ�������죬��ˮ��䧡�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"xqx",
                "northup" : __DIR__"shanjing",
        ]));
        
        set("outdoors", "�����");
        setup();
        replace_program(ROOM);
}
