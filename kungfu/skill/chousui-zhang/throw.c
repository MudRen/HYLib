// throw.c ������ʩ��
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object obj,weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( !target || !target->is_character() )
		return notify_fail("ʩ��ֻ�ܶԶ���ʹ�á�\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ʩ����\n");

        
	if( (int)me->query_skill("chousui-zhang", 1) < 40 )
		return notify_fail("��ĳ����Ʋ�����죬����ʩ����\n");

    if( environment(me)->query("no_fight") && userp(target))
        return notify_fail("���ﲻ׼ս����\n");

     if( target->query("env/no_fight") && userp(target) )
        return notify_fail("���ܴ򣬴򲻵ð���\n");
     if( target->query_temp("no_kill") && userp(target) )
        return notify_fail("���ܴ򣬴򲻵ð���\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
    if(target==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
    if(me->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");
if( !living(target) && userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");

//pk
    if( userp(target) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(target) && target->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");


//��սϵͳ
        if (userp(me) && userp(target)
         && target->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(target)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(target) && target->query_condition("nokill")
    && !target->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if( !living(target) && userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");      
	
	if ( !(objectp(obj=present("corpse", environment(me))) 
        || objectp(obj=present("corpse", me))
        || objectp(obj=present("Skeleton", environment(me)))
        || objectp(obj=present("Skeleton", me)) ) )
		return notify_fail("����Χû��ʬ�塣\n");

	msg = CYN "$N˳��ץ��ʬ�壬�������������ϣ�����$n��\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("chousui-zhang",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " ���$p��$P���˸����ţ�\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("chousui-zhang",1)*2);
            target->receive_wound("qi",55 + random(10));
            target->receive_wound("jing", 50);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
target->apply_condition("fire_poison",60);
            target->apply_condition("xx_poison", random(me->query_skill("chousui-zhang",1)/10) + 10 +
			target->query_condition("xx_poison"));
			target->start_busy(1 + random(2));
	message_combatd(msg, me, target);
	COMBAT_D->report_status(target);

	} else {
		msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(4);
		message_combatd(msg, me, target);
	}
me->kill_ob(target);
//	if( !target->is_killing(me) ) target->kill_ob(me);
		destruct(obj);
	return 1;
}
