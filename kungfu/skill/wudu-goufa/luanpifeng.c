// luanpifeng.c ������ 
// by snowman@SJ 30/09/1999

#include <ansi.h>

inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
    object weapon = me->query_temp("weapon");  
    int skill;
    
    if( !target ) target = offensive_target(me);
     
    if( !target || !me->is_fighting(target))
                return notify_fail("�������硹ֻ����ս���жԶ���ʹ�á�\n");
    
    
 	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������硹��ʼʱ��������һ�ѽ���\n");
     
	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("����嶾����Ϊ��������\n");

	if( (int)me->query_skill("sword",1) < 50 ||
	    me->query_skill_mapped("sword") != "wudu-goufa")
		return notify_fail("����嶾�����������ң��޷�ʹ�������磡\n");

	if( (int)me->query_skill("wudu-goufa",1) < 50 )
		return notify_fail("����嶾�����������ң��޷�ʹ�������磡\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

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

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");

    if ( (int)me->query_temp("zhuihun/lpf") ) 
        return notify_fail("������ʹ���嶾׷�깳֮�������硹��\n");

    message_vision(HIY "\n$N������⿪����ͷɢ������ɫͻȻ��ף����е�"+weapon->name()+"Ҳ���ž��Ҷ����ţ�
ͻȻ$Pһ���񺿣�����޹���Ƶ���Х������أ������ƵĽ��嶾׷�깳����ʹ����\n"NOR, me);                 
    
    skill = me->query_skill("wudu-goufa", 1);
    
    	me->add_temp("apply/attack",  skill/3);
//    	me->add_temp("apply/dodge",  skill/4);

    	
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    	me->set_temp("ryb_fumo", 1);
	me->set_temp("zhuihun/lpf",1);
me->start_busy(3);
//	me->start_perform(1, "������");
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/3 );
        return 1;
}

int remove_effect(object me)
{
	if(!me) return 0;
        me->add_temp("apply/attack", - (me->query_skill("wudu-goufa", 1)/3));
//        me->add_temp("apply/dodge", - (me->query_skill("wudu-goufa", 1)/4));
        me->delete_temp("zhuihun/lpf");
        if(living(me))
        	message_vision(HIG "\n$N��ڴ�ڵش���������Ҳ�����ָ������������������˲��ٵ�������\n\n" NOR, me);

        return 0;
}

