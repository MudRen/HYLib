// /d/kunming/shilin
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "ʯ��" NOR);
        set("long", @LONG
������״�����ʯͷ���е����ˣ��е��������е��������
��߿�����������Ҳ�����Ƕ����������ģ�ǧ�˰�̬�������۾���
�����ˡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "north" : __DIR__"xiaolu1", 
                "southwest"  :__DIR__"shilin1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
