//houting ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"����"NOR);
        set("long", @LONG
�������Խ�ɽׯ�ĺ��������ڷǳ��ɾ���ׯ��ƽʱ��̫ϲ��İ���˽�����
�ķ��䣬���ӵĺ�����һ�Ȳ����۵�С�ţ���֪��ͨ���δ���
LONG
        );
        set("exits", ([        
        "south" : __DIR__"zoulang2",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
     
        setup();
}

