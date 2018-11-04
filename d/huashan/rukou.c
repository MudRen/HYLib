// Room: /d/huashan/canglong.c
// Date: Look 99/03/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
        set("short","ɽ��");
        set("long", @LONG
������ɽ������ڡ�ɽ���������һ�ţ�������ֲ��嶫��������ֻ�ú�
��Ϲ���ˡ�
LONG
        );
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_break", "break");
}

int do_use(string arg)
{
    object room, ob, me;
   me = this_player();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if(!objectp(ob = present("fire", me)))
        return notify_fail("������û�л��ۣ���ô����ɽ�����ж���\n");

        if( !arg || arg=="" ) return 0;

        if( arg == "fire" ) {
        message_vision(HIC"$N��ȼ���ۣ��Ѷ���������һЩ����������һЩ��
΢���Ļ��һ��һ���ġ��㷢�����"HIG"(left)"HIC"�����и�С�ڿ��Թ�ȥ��\n"NOR, me);
        destruct(ob);
        if(!(room = find_object(__DIR__"rukou")))
            room = load_object(__DIR__"rukou");
            set("exits/left", __DIR__"cave");
            if (me->query_temp("mb"))
{
tell_object("���ƺ������ҷ�����һ��С·��(right)\n",me);
             set("exits/right",__DIR__"midao"); 
}
            call_out("delete_exit", 4, room);   
            return 1; }
}
void delete_exit(object room)
{       
        message("vision",BLU"ֻ�����˵�һ��������Ϩ���ˡ�\n"NOR, room);
        delete("exits/left");
        delete("exits/right");
}

int do_break(string arg)
{
        int n;
        object me = this_player();
        object weapon;
        object room;
//        object ob = this_object();
        n = (int)me->query("neili");
        room = find_object(__DIR__"hole");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������޽��������Ʊڣ�\n");
     message_vision(
    "$N�ߵ�ʯ��ǰ���γ����������������˾���ʯ�ڴ��˹�ȥ��\n", me);

    if ( n >= 600 ){
    message_vision(
    "$Nֻ��һ�����죬ʯ�ڱ�ͱ���ˡ���\n", me);
    set("exits/out",__DIR__"hole");
    this_player()->add("neili", -200);
    remove_call_out("close");
    call_out("close", 5, this_object());
    
    if(!(room = find_object(__DIR__"hole")))
         room = load_object(__DIR__"hole");
    if( room = find_object(__DIR__"hole") ) {
    message("vision", "��ֻ������һ�����죬ʯ�����˴�����ͱ���ˣ�¶����һ�����ڡ�\n", room);
    room->set("exits/enter",__DIR__"rukou");
    room->set("exits/out",__DIR__"siguoya");
    remove_call_out("close1");
    call_out("close1", 5, room);   }
    }
    else {
    message_vision(
    "���ֻ��һ���ƺߣ�$N��ʯ�ڵķ����������ǰһ��....\n", me);
    this_player()->unconcious();
    }

    return 1;
}

void close(object ob)
{
        message("vision","���Ϻ�Ȼ������һ���ʯ�������ڷ��˸�����ʵʵ��\n", ob);
        ob->delete("exits/out");
}
void close1(object room)
{       
        message("vision","���Ϻ�Ȼ������һ���ʯ�������ڷ��˸�����ʵʵ��\n", room);
        room->delete("exits/enter");
        room->set("exits/out",__DIR__"siguoya");
}
