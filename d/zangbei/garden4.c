 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ջ�԰");
        set("long", @LONG
�ջ�԰�ܴ��Ա���÷��԰����ĵ����Ǿޱ����ҩ���軨������������԰��˭
Ҳ��֪������ռ�˶��ٵأ�ֻ֪��һ���˾����ߵúܿ�Ҳ����һ����������Ƭ����
һȦ��԰��������ʮ�߶����������ӣ��ϲ������㴨�������ڶ��ࡣ
LONG
        );
        set("exits", ([ 
                "east" :        __DIR__"groom1",
                "north" :       __DIR__"groom3",
                "southwest":    __DIR__"garden1",
        ]));
        set("objects", ([
        
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
