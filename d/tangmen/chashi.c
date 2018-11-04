// Room: /d/tangmen/chashi.c

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
int do_jump(string);
void delete_served(object);

void create()
{
	set("short", "����");
	set("long", @LONG
    �������Ŵ��͵Ĳ��ҡ����ݲ��㡢�������磬�衢���������š��ٹ�ɽׯ����
���ľ�Ʒ�����ڰ�������£��м��ž��µ�̴��ľ��(table),�Լ���������(chair)��
����̴��񻨴�(window),������������Ļ�԰��
LONG
	);

	set("exits", ([
		"north" : __DIR__ "kefang",
		"southeast" : __DIR__ "huayuan9",
	]));
	
    set("item_desc", ([
	    "table" : "һ�ž��µ�̴��ľ�����������ˮ���̺��������ߡ�\n",
	    "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ��ǳ���⣡\n",
	    "window" : "���Կ��ü���Ƭ��ï�Ļ���,������ɫ������ϲ�ˡ�\n",
	]));
	                                

	set("objects",([
		__DIR__"npc/tangjing" : 1,
		__DIR__"obj/shuimitao" : 2,
		__DIR__"obj/tea" : 1,
		__DIR__"obj/dawancha" : 1,
	]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_tap(string arg)
{

	object me;
	object jing;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("��Ҫ��ʲô��\n");	
	}
		
	me = this_player();	
	if( !objectp(jing = present("tang jing", environment(me))) )
	 	return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о��Լ������ġ�\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("�����������ӣ�ͻȻ��ָ��һ�ۣ�ԭ����ͣ�������һֻ�۷�������һ�ڣ�"
	 		+"\n�������Լ�����ָ������������Ӵ������\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("�ƾ����ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ��"+
				"�㲻���һ��������أ�\n", me);
        return notify_fail("");
    }

	message_vision("$N��������ǰ��������������棬�ƾ�ݸ��һЦ�������к���\n", me);
	
	jing->serve_tea(me) ;

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���£������ϲ衣\n");	
}


int valid_leave(object me, string dir)
{

	if (  (dir == "north")
	   && ( present("tea", this_player())
	        || present("shuimitao", this_player()) ) 
	   && objectp(present("jing", environment(me))) )
	switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("�ƾ�����$N����ָ�����Լ���С�������Ա����㻹Ҫ�ã��ߣ��ߣ��ߣ�\n");
	 break;
	case 1:
	 message_vision("�ƾ���$N����Ц������̫̫˵������ʳ���ô����跿��", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
