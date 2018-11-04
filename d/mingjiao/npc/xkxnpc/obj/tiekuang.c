//Cracked by Roath
// Room: /d/mingjiao/luanshidui.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int start_wa(object me);
int check_busy(object me);

void create()
{
        set("short",HIR "����" NOR);
        set("long", HIW @LONG
������һ����ͺͺ��Сɽ������ʲô������ľҲû�С���ϸһ����
����ɽ����Χ��Щ������Ĵ�ʯͷ������ǹ�����ʢ�����ڽ�����ʯ����
�̽����õı������������ֿ�ʯ������ɣ���֮Ѱ����������ı�����Ϊ
��̣�������
LONG NOR
);      
        set("exits", ([ /* sizeof() == 1 */
	  "northeast" : __DIR__"shanlu23",
	]));

         set("invalid_startroom", 1);
		 set("wa_times",15);
		setup();

}

void init()
{
          add_action("do_save", "save");
		  add_action("do_wa", "excavate");
		  add_action("do_wa", "dig");
}

int do_save(string arg)
{
           
	write("���ﲢ��һ��ط�,�����������¼��\n");
	return 1;
	
}

int do_wa(string arg)
{
	object qiao,me;

	me = this_player();

	if( me->is_busy() || me->query_temp("pending/job_busy") )
		return notify_fail("����æ���ء�\n");

	if( me->query("mingjiao/job") != "jin_caikuang")
		return notify_fail("���ﲻ��������ڣ�\n");

	if( present("wujin kuangshi", me) )
		return notify_fail("���Ѿ���һ���ʯ��ʵ�ڱ������ڶ����ˡ�\n");

	if( !objectp(qiao = present("tie qiao", me)) )
		 return notify_fail("��û�г��ֵĹ��ߣ��޷���������\n");

	if (me->query("jingli") < 90)
		return notify_fail("���Ѿ���ƣ�����ˣ�\n");

	if(query("wa_times")>0)
	{
		message_vision("$N�������������ϣ���׼��һ���������ڽ�����ʯ������������ȥ��\n",me);
		me->set_temp("pending/job_busy",1);
		call_out("start_wa", 10, me);
		me->start_busy( (: check_busy :) );
	}
	else
		tell_object(me,"��ʯ�ƺ������ڹ��ˡ�\n");
	
	return 1;
	
}

int check_busy(object me)
{
	if (me->query_temp("pending/job_busy")) return 1;
	return 0;
}

int start_wa(object me)
{
	object kuangshi;

	if(me->query("jingli")>90&&random(3)==1)
	{
		message_vision("$N��һС��"+HIB"�ڽ��ʯ"NOR+"���˳����������ϡ�\n",me);
		add("wa_times",-1);
		kuangshi=new("/d/kunlun/obj/kuangshi");
		kuangshi->move(me);
		me->add("jingli",-70);
	}
	else
	{
		tell_object(me,HIR"��ͻȻ�����������ã�����Ҳ�޷����ǿ��ʯ�ڳ���\n"NOR);
		me->add("jingli",-70);

	}

	me->delete_temp("pending/job_busy");
	return 1;

}

int valid_leave(object me, string dir)
{
        object ob;

        if (dir == "northeast" && me->query_temp("job_busy") )
               return notify_fail("����æ���ڿ��أ�\n");

        return ::valid_leave(me, dir);
}
