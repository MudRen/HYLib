#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�ص�"NOR);
        set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ�����������һ���
ʯ��(shizhu)�������ϵĳ��ڣ���ǰ�ߺ�����Կ���һ�����⡣
LONG);
        set("item_desc",([
        "shizhu" : "���Ǹ�����Բ����������Ӧ�ÿ��԰�(move)������\n",
        ]));
        set("exits", ([
              "west" : __DIR__"midao1",
        ]));
        setup(); 
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object room, me = this_player();
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if( !arg || arg!="shizhu" ) return 0;
        
        message("vision","ʯ����Ȼ������������������һ�໺���ƿ�������¶��һ�������ĳ��ڡ�\n", this_object() );
        set("exits/up", __DIR__"yuanzi4");
        if( room = load_object(__DIR__"yuanzi4") ) {
                 room->set("exits/down", __FILE__);
                 message("vision","ʯ����Ȼ����������������¶��һ���ڶ����Ķ��ڡ�\n",room );
        } 
        remove_call_out("close_door");
        call_out("close_door", 5);
        return 1;
}

void close_door()
{
        object room;
        if( !query("exits/up") ) return;
        message("vision","ͷ���Ϻ�Ȼ����������������ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n", this_object() );
        if( room = load_object(__DIR__"yuanzi4") ) {
                room->delete("exits/down");
                message("vision", "ʯ����Ȼ�����������������������ƻ�ԭ���������µĶ��ڸ�ס�ˡ�\n", room );
                }
        delete("exits/up");
}