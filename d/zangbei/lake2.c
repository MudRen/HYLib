 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ʥ��֮һ����ľ�룬���������Զ����һ�����£�һ��ӵ����ԭ��һ
������ѩɽ��������ˮ���������Ĺ⣬һ���˵ؾ��򰶱ߣ��Ծ�����ɳ����������
�������ѣ�����ת���������������Ը�������ߵĽ�ʯ��Ҳ���š������������衱
���������ԡ�
LONG
        );
        set("exits", ([ 
                "southwest":  __DIR__"garden",
        "south":  __DIR__"lake1",	
        ]));
        set("objects", ([
                __DIR__"npc/horse2":    1,
"quest/skills2/wunon/yu/yutan" : 1,
        ]) );
        set("outdoors", "guanwai");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}     
