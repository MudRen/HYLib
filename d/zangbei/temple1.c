 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����");
        set("long", @LONG
�����λ��������ѩ����£����������ɼ����£����������������ڴ��
�̷�С�����ڹ����������ȡ������������ïʢ���ݲؾ���˵���ڳ����תʮ��
�ξ��൱����һ�����صĹ��£����Ծ���������ɽ�ϵ�����Ҳ��������תɽת�£�
���Լ����µ����
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"tianxin",
                "south":  __DIR__"zhayi",
                "northeast": __DIR__"temple1a",
        ]));
        set("objects", ([
                __DIR__"npc/monk1":     1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}      
