 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ڰ���");
        set("long", @LONG 
�����������ֲ�����ָ����ʲôҲ����������ֻ������ԼԼ����ǰ���д��صĺ������� 
LONG
        );
        set("exits", ([ 
                "south":        __DIR__"tunnel3",
        ]));
        set("no_fly",1);
        set("item_desc", ([
                
        ]));
        set("objects", ([
                __DIR__"npc/sunju":     1,
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object obj, string dir){
        if (userp(obj) && dir=="south") {
                obj->delete_temp("block_msg/all",1);
                tell_object(obj,HIG"�������߳�������ڵľ�ͷ��������ϡ���ϳ���Χ�������\n"NOR);
                return 1;
                }
        return 1;
} 
