// riyun.c

#include <ansi.h>

int exert(object me)
{	
	int nb, nx, nh, improve;
	nx = (int)me->query("max_qi", 1);
	nb = (int)me->query("eff_jing", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);
	if( me->is_fighting() )
		return notify_fail("ս�����˹���������\n");

	if ((int)me->query_skill("linji-zhuang", 1) < 150)
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");
	
      if( me->query_temp("yun_riyue")   )
     		return notify_fail("�����������ټ�ʮ��ׯ�ġ����¡��־���\n");

	write(MAG"��ϯ�ض������������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩�����پ��Լ��������������ˡ�\n"NOR);

	message_vision(HIW"ֻ��$N���Ϻ��ʱ��ʱ�֣���һ��
����������ĵ�վ��������\n"NOR, me);
	if( nx> nb ) {
	improve =  (nx - nb) / 2;
	me->add("max_qi", improve);
	me->add("eff_jing", -improve);
	me->set_temp("yun_riyue", 1);  
        me->add("neili", - 150);    
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2 );
	return 1;
	}
	if( nb > nx ) {
	improve =  (nb - nx) / 2;
	me->add("max_qi", improve);
	me->add("eff_jing", -improve);
	me->set_temp("yun_riyue", 1);  
        me->add("neili", - 150);    
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2 );
	return 1;
	}
}
void remove_effect(object me, int improve)
{
      me->add("max_qi", - improve/2*3);
      me->add("eff_jing", improve);
      me->delete_temp("yun_riyue");
      tell_object(me, HIR"���������֮������ɢ������֮�䣬���ָֻ���ԭ�о�����\n"NOR);
}
