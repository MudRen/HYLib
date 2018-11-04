// tianwai.c ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;
int extra;
        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yuxiao-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( me->query_skill("bibo-shengong",1) < 120)
            return notify_fail("��ı̲��񹦵ȼ�����, ����ʹ�á�������������\n");

        if( skill < 90)
            return notify_fail("������｣���ȼ�����, ����ʹ�á�������������\n");

        if( me->query("neili") < 250 )
            return notify_fail("��������������޷����á�������������\n");

        msg = HIG 
"$Nһ����Х����������������һ����������������һʽ��������������"+weapon->name()
+"������ֹ����Ӱ��ҹĻ������$n��\n";

	extra = me->query_skill("yuxiao-jian",1) / 5;
	extra += me->query_skill("bibo-shengong",1) /5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);

 	me->add("neili", -50);
	me->start_busy(1);
        return 1;
}
