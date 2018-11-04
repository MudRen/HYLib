// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,damage,p;
int extra;
  if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("yuxiao-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("tanzhi-shentong", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("bibo-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ�һ�����ѧ��ʹ�����һ����ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

	extra = me->query_skill("yuxiao-jian",1) / 20;
	extra += me->query_skill("bibo-shengong",1) /10;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
if (random(3)==0) target->start_busy(3);
	msg = YEL "$N���ƽ��棬ʹ���һ�����������������������Ȼ�ӿ죡" NOR;
	message_vision(msg, me, target);                
	msg =  YEL  "$N���������ƣ�����һ�Ÿ����߳���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = CYN  "��Ӱ�У�$N����������ƴ����û���$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = YEL  "$N��$n�Ż��󿪣�����������˫����������$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = CYN  "$NԽսԽ�£���Χ����һ�����磬ʹ��$n�����巽��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = YEL "$N���ǹ�է�֣������Դ���Ȼ֮ɫ����$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
	msg = CYN "$N��Хһ��������෢����Ȼת��$n��󣬷�������һ�ƣ�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra*2);

if ( me->query_skill("yuxiao-jian",1) >230)
{
        msg = HIG 
HIG"$Nһ����Х����������������һ����������������һʽ��������������"+weapon->name()
+"������ֹ����Ӱ��ҹĻ������$n��\n"NOR;

	extra = me->query_skill("yuxiao-jian",1) / 5;
	extra += me->query_skill("bibo-shengong",1) /5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2*extra);

       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -2*extra);
	me->add("neili", -150);

}

    msg = HIG "$NĬ����Ӣ�ķ���ʹ����Ӣ���ơ������־����Ӱ��������һƬ��Ӱ����$n��\n"NOR;

	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) 
    {

        damage = (int)me->query_skill("bibo-shengong", 1); 
        damage = damage + random(damage);

        target->receive_damage("qi", damage*2);
        target->receive_wound("qi", damage/2);

        if ( damage < 40 ) msg += HIY"���$N�ܵ�$n������������Ȼ����$N���Լ�ȴ�ƺ�һ���������������\n"NOR;
        else if( damage < 80 ) msg += RED"���$N��$n�����������ؿ������ܵ�һ���ش�����������������\n"NOR;
        else msg += HIR"$nãȻ��֪���룬�����$Nһ�ƻ���ǰ�أ�$n��ǰһ�ڣ������ɳ�����������\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(target);
    } else
    {
        msg += HIG"����$p������$P����ͼ�����������һ�ߡ�\n"NOR;
	message_combatd(msg, me, target);
    }
	msg = CYN "$N˫��һǰһ�󣬻����������ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";

	damage = (int)me->query_skill("tanzhi-shentong", 1) + (int)me->query_skill("bibo-shengong", 1) + 500;
	damage += random(damage / 2);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "$n�������������ۡ���һ������ָ������ǰ�أ�\n";
		target->receive_damage("qi", damage*5);
		target->receive_wound("qi", damage / 3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�ؿ�һ���ʹ����е��أ�\n" ;
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n���Ա�һ�����ù��˾��磬û�뵽���ָ����Ȼ�л�������$n����ת������������$p�ĺ󱳡�\n";
		target->receive_damage("qi", damage *3);
		target->receive_wound("qi", damage / 9);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�����ؿ��е�ʹ��\n" ;
	}
	else {
		msg += "$n���Ա�һ�����ù��˾��磬ȴ��Ȼ�������ָ����Ȼ�л�������æ��ֻ��һ��ǰ�˲ſ��������ģ���Ǳ�֮����\n" NOR;
	}
	message_vision(msg, me, target);

	me->start_busy(4);
	return 1;
}
