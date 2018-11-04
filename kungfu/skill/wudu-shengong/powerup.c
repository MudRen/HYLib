// powerup.c ���ߴ�

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

       if( target != me ) return notify_fail("��ֻ�����嶾�������Լ���ս������\n");

	if( (int)me->query("neili") < 220 )	return notify_fail("�������������\n");
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("���Ѿ����˾����湦���ˡ�\n");
        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("���Ѿ������򷨹������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");

       if( me->query_temp("powerup") ) return notify_fail("���Ѿ����˹����ˡ�\n");

          skill = me->query_skill("wudu-shengong",1)/2;
        if (skill > 200) skill=200;
	me->add("neili", -200);
 
	message_vision(
        BLU "$N�����嶾��,ͷ���������ڣ�ȫ���������ɫ���ۼף�˫Ŀ�׹����䣡\n" NOR, me);

	me->add_temp("apply/damage", skill*3);
	me->add_temp("apply/armor", skill*3);
	me->add_temp("apply/unarmed", skill);
        me->add_temp("apply/attack",skill);
	me->add_temp("apply/defense",skill);
	me->set_temp("powerup", 1);
me->set_temp("wdpowerup", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	int skill;
        skill = me->query_skill("wudu-shengong",1)/2;
        if (skill > 200) skill=200;
	me->add_temp("apply/damage", -skill*3);
	me->add_temp("apply/armor", -skill*3);
	me->add_temp("apply/unarmed", -skill);
        me->add_temp("apply/attack",-skill);
	me->add_temp("apply/defense",-skill);
        me->delete_temp("wdpowerup", 1);
	me->delete_temp("wdpowerup");
	me->delete_temp("powerup");
      tell_object(me, "����嶾��������ϣ������𽥻ָ�������\n");
}
