// yingyang ������
// updated force->neili, force_factor->jiali (by xbd)

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("taiji-quan", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

       if( !wizardp(me) &&(int)me->query_skill("taiji-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("taiji-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

        if( !wizardp(me) && me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

//    if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "sword")
//        return notify_fail("��ʲô��Ц��ûװ��������ʹ�������ѩ����\n");


        extra = me->query_skill("taiji-shengong",1);
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

	me->add("jiali",extra/3);
	orforce = (int) me->query("force");
//	me->add("neili",extra/3*100);

	weapon = me->query_temp("weapon");
	me->add("str", extra/6);
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra*2);

        msg = HBWHT "$N��ͨ�䵱��ѧ��ʹ�����䵱�ľ�ѧ֮���裡\n" NOR;
        message_vision(msg, me, target);               

	msg = MAG  "$N˫�ֱ��˸�̫��ʽ��ԲȦ����������̫�����Ѵ������һ���Ķ������ľ��磬��\n"NOR;
	message_vision(msg,me,target);
	msg = WHT  "���һ���������" NOR;

if (random(3)==0) target->start_busy(3);

	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "���һ���������" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "��������������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "��������������" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "��������������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "��������������" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "�����Ǿ�������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�����Ǿ�������" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "�������������" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�������������" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg = WHT"              ����˫��           !!\n"NOR;
		msg += MAG"��մ���������־��������־��������־���!!\n"NOR;
		damage = extra * 6 + random(extra);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
	message_vision(msg, me, target);
}
	
        me->start_busy(4);
	me->set("jiali",0);
         me->add("str", -extra/6);
        me->add_temp("apply/attack",-extra/2);
        me->add_temp("apply/damage",-extra*2);
	me->add("neili", -me->query("max_neili")/7);
	return 1;
}
