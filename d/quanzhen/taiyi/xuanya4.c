//Cracked by Kafei
// road: /zhongnan/xuanya4.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);

void create()
{
		  set("short",HIW"�¶�"NOR);

		  set("long",@LONG
�¶��Ǹ��޴��ƽ̨�������˰�����ѩ����������һ��ʯ���������ƺ�����һ��
��(ci)��վ���¶���������ȥ������ƽ��ãã��һ���޾���ɳĮ��ʧ����ߣ�˵����
������֮�⣬��ֻ�޴�ĺڵ��ڿ�������������
LONG);

		  set("item_desc",(["ci" : "


		��ū�������⻳��

			 ����

    ��綫ȥ��˪�𾡣�ǧ�ﻪ���̲ݡ�������գ���
��ɽ������һƬ�������磬��������������������ۡ�
������Į��ǧ��������

    ң�뷶�����꣬�������۷������ء���ǹ���
�彫����Ӣ�磬߳��䣬��²��ɥ���ѡ����˰��ڣ�˹��
Ǽ�������������ݶ̣�����Ī���塣


\n",]));

		  set("exits",([
	"east": __DIR__"fengdong",
	"west": __DIR__"bingdong",
							 ])
			  );
	  set("cost",4);
set("outdoors", "quanzhen");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
}


int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("�㻹��æ���ء�\n");

	if(arg != "down" )
		return notify_fail("�Ǹ�����û������\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;
	cost *= 2;

	if( me->query("jing") < 30)
		return notify_fail("���۵�ʵ���������ˡ�\n");

	me->add("jing",-cost);
	gain = me->query("con",1)*2;
	gain *= 2;

	if ( me->query_skill("dodge") > 300 ) gain /= 2;

	me->improve_skill( "dodge",random( gain ) );
	if( me->query_skill( "jinyan-gong",1) > 0 )
		me->improve_skill( "jinyan-gong",random( gain ) );


	message_vision( HIY"\n$N�����������ٸ���С�Ľ���������ȥ��\n"NOR, me);
	me->move(__DIR__"xuanya3");
	message_vision( HIY"\n$N����������\n"NOR, me);
	return 1;
}




