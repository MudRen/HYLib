//Cracked by Roath
// road: /zhongnan/hubing.c
// by sdong 08/98

#include <ansi.h>
inherit ROOM;

int do_jump();

void create()
{
		  set("short",HIC"̫�ҳغ���"NOR);
		  set("long",@LONG
�������̫�ҳ�(chi)�����ĺ�������ɽ��ˮ���Ĵ��̲������ʻ�ʢ������ֻ������
�������裬���в���ˮ��ߴߴ����������ȥ����������ȥ������̲�������ɽ��ˮӰ��
�羰ʮ��������������һ�����͵�ɽ�壬��ɽ���Ͽ�������һ���޴��ɽ���������󻨸�
�Ҽ��Ŷ��ɡ�������һ�����͵�С·ͨ��ɽ�ϡ�
LONG);

		  set("exits",([
							  "westup" : __DIR__"xuanya1",
							 ])
			  );


		  set("item_desc", ([
		"chi" :
"\n\n����һ���ܴ��ɽ������̲���������ˮ�峺���ף������̲�ס����(jump)��ȥ\n"
"����һ����\n\n\n",
])  ) ;

		  set("no_clean_up", 0);

	  set("cost",4);
    set("outdoors", "quanzhen");
	  setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump()
{
	object me = this_player();

	if ( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	message_vision(HIY"\n$N��̫�ҳ�����ȥ��\n"NOR, me);
	me->set_temp("taiyi_swimming", 1);
	me->move(__DIR__"taiyici3");
	message_vision(HIY"\n$N��̫�ҳ������˽�����\n"NOR, me);

	return 1;
}
