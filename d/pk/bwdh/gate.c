//�Խ�ɽׯ  gate.c

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIR"�Խ�ɽׯ"NOR);
        set("long", @LONG
�����ׯԺ�����������µ��Խ�ɽׯ�ˣ��㲻������һ������ǰ��ɽׯ�ĵ�
�ϴ�ɨ��һ����Ⱦ�����������ɵ�̨�׺������ţ��ź�ľ���ƵĴ��Ž����ţ�ʹ
���޷���Ϥ���ڵ�һ�У����ɶ�ߵ�����ǽ��͸����Ҷ��������ҫ������������
�ž�������ֻ�ŵ�Զ���������������
LONG
        );
        set("exits", ([
        "southdown" : "/d/pk/pk/turen9",        
        "north" : __DIR__"qianting",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "�Խ�ɽׯ");

        setup();
}

