// /d/kunming/shilin1
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "��ʫ��" NOR);
        set("long", @LONG
������ʯ�������İ�ʫ��壬�ഫ�ܾ���ǰ�������Ĺ��������
��ʫ���ڴ˵Ⱥ����İ��ڸ磬Ȼ������ȴ�������ϲ�ɱ���ˣ���ʫ��
�Ȱ��ȣ�ʼ��û�е����İ������ɣ��վ�������һ��ʯ�壬��Զ����
����ȥ��
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "northeast" : __DIR__"shilin", 
                "west"  :__DIR__"shilin2",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
