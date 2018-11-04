//Cracked by Kafei
// road: /zhongnan/xuanya1.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);
int do_exercise(string arg);
int do_practice(string arg);
int do_study(string arg);

void create()
{
		  set("short",HIC"����"NOR);

		  set("long",@LONG
�����������ϣ������¸ߴ���ʮ�ɣ����ʽ��ƣ���Щ�ط�ֱ��ǽ��һ�㶸�ͣ�
�������涼�����ҹ�ʯ��Խ���Ͼ�Խ���ʣ������������¶���ڣ���ݲ�������
��һ�ƣ�ֻ�ŵû����ɢ��ԭ������ʱһ������Ӳͦ�����ԭ·��ȥʱ����������
��֮���Ѹ�͹������ʯ��ס����Ҳ��������������ӿ������һ�����Ʊ�����ɽʯ��
ײ������ֻ�޴�ĺڵ������ڿ��С�
LONG);

	  set("cost",4);
set("outdoors", "quanzhen");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_exercise",  "exercise");
	add_action("do_exercise",  "dazuo");
	add_action("do_exercise",  "respirate");
	add_action("do_exercise",  "tuna");
	add_action("do_practice",  "practice");
	add_action("do_practice",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
}

int do_exercise(string arg)
{
		  object me = this_player();
		  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ�������������\n");
		  return 1;
}

int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ�������������\n");
		  return 1;
}

int do_study(string arg)
{
		  object me = this_player();
		  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ��������鰡��\n");
		  return 1;
}

int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("�㻹��æ���ء�\n");

	if(me->query_skill("dodge") < 45 && arg == "up" )
		return notify_fail("�����������¶���ڣ����Ṧ��������ôҲ������ȥ��\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;

	if( me->query("jing") < 30)
		return notify_fail("���۵�ʵ���������ˡ�\n");

	me->add("jing",-cost);

	if( arg != "up" && arg != "down" )
		return notify_fail("�Ǹ�����û������\n");

	gain = me->query("con",1)*2;

	if ( me->query_skill("dodge") > 200 ) gain /= 2;

	me->improve_skill( "dodge",gain+random( gain ) );
	if( me->query_skill( "jinyan-gong",1) > 0 )
		me->improve_skill( "jinyan-gong",random( gain ) );


	if(arg == "up" )
	{
		message_vision( HIY"\n$N�����������ٸ���һ����������ȥ��\n"NOR, me);
		me->move(__DIR__"xuanya2");
		message_vision( HIY"\n$N����������\n"NOR, me);
		me->improve_skill( "dodge",(gain+random( gain ))/2 );
		me->add("jing",-cost);
		me->start_busy( 1 );
		return 1;
	}
	else if(arg == "down" )
	{
		message_vision( HIY"\n$N�����������ٸ���С�Ľ���������ȥ��\n"NOR, me);
		me->move(__DIR__"hubing");
		message_vision( HIY"\n$N����������\n"NOR, me);
		return 1;
	}

	return notify_fail("�Ǹ�����û������\n");
}

