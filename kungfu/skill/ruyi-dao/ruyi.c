//ruyi.c ����������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
                return notify_fail("�������������������õ�����ʩչ��\n");

        if( (int)me->query_skill("ruyi-dao", 1) < 60 )
                return notify_fail("��ġ����⵶����������죬����ʹ�á���������������\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 60 )
                return notify_fail("��ġ���ڤ�񹦡�������죬����ʹ�á���������������\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("�������������\n");

        skill = me->query_skill("ruyi-dao");
	extra = me->query_skill("ruyi-dao",1) / 20;
	extra += me->query_skill("ruyi-dao",1) /20;
me->set_temp("ruyi");
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        msg = HIY "$Nһ����Ц��ֻ���������⣬�������أ��Ĺ�ʲô�Ƿ����裬����һ��������\n"NOR;
        me->add("neili", -200);
        
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	        msg = HIB"$N�������������δ������������һ����\n"NOR;
       
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR"$N���浶ת��˳������һ����\n"NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

if( (int)me->query_skill("ruyi-dao", 1) > 200 )
{
        msg = HIG"$N���浶ת��˳������һ����\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC"$N���浶ת��˳�����һ����\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

}
        msg = HIW"$N������ת������һ���ֻ�ת������\n"NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       me->start_busy(2);
me->delete_temp("ruyi");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        return 1;
}
