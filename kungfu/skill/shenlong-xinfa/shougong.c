// shougong.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	if(me->query_temp("sld/shougong")==1)
		return 0;
	if(me->query_temp("sld/wudi")==1) {
		me->set_temp("sld/shougong",1);
		message_vision(CYN"$N�����ջ����������еĺ����������������\n"NOR,me);
	}
	else	{
		return notify_fail("�������޷��չ���\n");
	}

	return 1;
}
