// jingsng.c ���ȭ ������ͨ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
	object weapon, ob;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if( !me->is_fighting() )
    	return notify_fail("��������ͨ��ֻ����ս����ʹ�á�\n");
      if( !target ) target = offensive_target(me);
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"����Ϣ�����ڰ�������У�һʱ�᲻���׽�񹦡�\n"NOR);

      if( !target || !me->is_fighting(target) )
      return notify_fail("��������ͨ��ֻ����ս���жԶ���ʹ�á�\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("��������ʹ�á�������ͨ����\n");

    if( (int)me->query("neili") < 500 )
		return notify_fail("��������������ߣ�\n");

	if( (int)me->query_skill("hunyuan-yiqi", 1) < 60)
		return notify_fail("��Ļ�Ԫһ��������Ϊ����������ʹ�ô�����ͨ! \n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�ô�����ͨ��\n");

	if( me->query_skill_mapped("cuff") != "jingang-quan") 
		return notify_fail("��û�м������ȭ���޷�ʹ�ô�����ͨ��\n");
	
//        if( me->query_temp("apply/strength", 1) > 1 )
//                return notify_fail("�㻹��ʹ��̫����һ��Ĺ��򣬲���ʹ�ô�����ͨ��\n");
       
//        if( me->query_temp("apply/dexerity", 1) > 1 )
//                return notify_fail("�㻹��ʹ��̫����һ��Ĺ��򣬲���ʹ�ô�����ͨ��\n");

	
    msg = HIY "$Nʹ������ȭ�ľ�����������ͨ����������Ȼ���ӣ�\n" NOR;
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("jingang-quan",1) / 3);
	count = (int) (me->query_skill("jingang-quan",1) / 3);
	d_count = (int) (me->query_skill("jingang-quan",1) / 5);

	if(qi > (maxqi * 0.1))
	{	
	if( (int)me->query_temp("jingang") ) 
		return notify_fail(HIG"���Ѿ����˹����ˡ�\n");

    	message_vision(msg, me, target);
		
		me->add_temp("apply/strength", count);	
		me->add_temp("apply/dexerity", d_count);
		me->set_temp("jingang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

		me->add("neili", -300);
    	return 1;
	}
	else{
		msg = HIR "$Nƴ����������ʹ���˴���ȭ���ռ�����, ȫ�����һ����, �������ͬ���ھ�!\n" NOR;
		message_vision(msg, me, target);
		me->add_temp("apply/strength", count);	
		me->add_temp("apply/dexerity", d_count);
		me->set_temp("jingang", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0 :), 2);

                ob = me->select_opponent();
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);		
		msg = HIR "$N�þ������һ������, ���һ����Ѫ, һͷ�Ե��ڵ�!\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -300);
		return 1;
	}
}

void remove_effect(object me, int aamount, int damount)
{
	int d_count, count,  skill;	
	count = (int) (me->query_skill("jingang-quan",1) / 3);
	d_count = (int) (me->query_skill("jingang-quan",1) / 5);
	if ( (int)me->query_temp("jingang") ) 
	{
		me->add_temp("apply/strength", -count);	
		me->add_temp("apply/dexerity", -d_count);
		me->delete_temp("jingang");
		tell_object(me, HIY "��Ĵ�����ͨ������ϣ��������ջص��\n" NOR);
	}
}
