// ������

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
int extra;
	object weapon;
	string msg;
	extra = me->query_skill("shedao-qigong",1);
	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(weapon = me->query_temp("weapon"))
	&& (string)weapon->query("skill_type") != "staff"
	)
            return notify_fail("�������ʹ�û����ȡ�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("shenlong-bashi", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("shedao-qigong", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("shenlong-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ��������ѧ��ʹ�����������ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",2*extra);
        msg = HIY "$Nʹ���������ľ���ħ����!\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIR "$N���쳤Х��������У�����������Ψ�Ҳ��ܣ�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG "$N�������ͨ����ҽ�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = HIW "$N�е����������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = HIC "$N�е����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = HIB "$N�е����ҽ̵��ӻ��̶�����ͬ�����ã���\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
        msg = YEL "$N�е����������Ŀ��磬�����ķ�����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenlong-xinfa",1)));
	me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-2*extra);
	msg = MAG "$N�Ƴ������������$n��ͷ�ϡ�\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) 
{
		msg += MAG "���ֻ���˵�һ����$p��$Pһ�����У�\n" NOR;
		msg += MAG "$pֻ����ȫ��ů����ģ��е��е���Ʈ�����ᡣ\n" NOR;
        target->apply_condition("snake_poison",60);
        target->apply_condition("cold_poison",60);
	target->receive_damage("qi",(int)me->query_skill("shenlong-xinfa",1)*6);
	target->receive_wound("qi",(int)me->query_skill("shenlong-xinfa",1));

		msg += HIB "��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵�����$p����\n" NOR;
}
	 else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
	}

	message_combatd(msg, me, target);
	msg = HIR "$N���������дʣ����֮���书������߸�Ծ��$P���о޶�����Ѫ����$nȫ����ȥ!\n";

        if( (random(me->query("combat_exp"))) >(int)target->query("combat_exp")/3 )
        {
		msg += MAG "���$p���޶�����Ѫ���С�n" NOR;
	msg += HIR "$pֻ�ŵ�һ��ͷ�裬�����³�һ�����Ѫ��\n" NOR;
	msg += HIC "$p������ð��������������������ǰ�趯����\n" NOR;
	message_combatd(msg, me, target);

        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = HIW "��һ������"+HIR+"����$n������\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);
 target->apply_condition("xuanming_poison",60);
if ((random(me->query("combat_exp"))+extra*800) >(int)target->query("combat_exp")/3 )
{
if (target->query("qi") < 100000)
{
        target->add("jing",-(target->query("jing")/4));
        target->add("eff_jing",-(target->query("eff_jing")/4));
        target->add("qi",-(target->query("qi")/4));
        target->add("eff_qi",-(target->query("eff_qi")/4));
}
else {
	target->receive_damage("qi",(int)me->query_skill("shedao-qigong",1)*6);
	target->receive_wound("qi",(int)me->query_skill("shedao-qigong",1)*2);
}
        msg = RED "$nȫ��������������"+HIR+"�����³�������Ѫ!\n"NOR;   
}
else {

	target->receive_damage("qi",(int)me->query_skill("shedao-qigong",1)*6);
	target->receive_wound("qi",(int)me->query_skill("shedao-qigong",1)*2);
	target->receive_wound("jing", 50);
}
	message_combatd(msg, me, target);
	} else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		message_combatd(msg, me, target);
	}

	me->start_busy(4);
	return 1;
}
