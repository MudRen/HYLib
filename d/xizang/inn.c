#include <room.h>
inherit ROOM; 
string look_sign(object me); 
void create()
{
        set("short", "ӭ÷��ջ");
        set("long", @LONG
���ǲ�������������һ�ҿ�ջ����˵��ҵ�����һ������������ˡ�������
�￪��ջ����ϣ������������ԭʧɢ�������ܹ�֪�������������������ᡣ��
�ǿ�ջ��ҵ���꣬��ԭ������������������û�д������������˵�һ����Ϣ����Ϊ
�������˺��У���ջ�����嵭������������ϻҲ��������˳������ط��Ƴ�
�����⡣
LONG
        );
      
        set("valid_startroom", 1);
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("exits", ([
                "west"   : __DIR__"octo1",
                "north"   : __DIR__"majiu",
                	]) );
        set("objects", ([
                __DIR__"npc/waiter" : 1, 
            //    "/obj/npc/trashcan":1,
                ]) ); 
        set("coor/x",-1190);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        
} 
    
