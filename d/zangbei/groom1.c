 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�鷿");
        set("long", @LONG
�鷿���ϲ��Ľ��أ�����������˵ʲô�������±����������������ǲ����ϲ�
�����ѣ��������ô�¿�������ֻҪ�㵽�˾ջ�԰���ϲ��������������������
����˵������⡣��ϲ����ȫ���ˣ�ϲ������������һ�в��������£�����������
���յ�ũ�ˣ�����ȳ漱�ڳ���һ����
LONG
        );
        set("exits", ([ 
                "west" :   __DIR__"garden4",
                "north":        __DIR__"groom2",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
