// sanqing.c һ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���Ҵ�ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("dagou-bang",1) < 80 )
                return notify_fail("�����Ĵ򹷰���������죬����ʹ�á��Ҵ򡹣�\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

        msg = YEL "$N����һ��,ûͷû�Ե���ǰ����˳�ȥ,�����Ǵ򹷰����ľ�Ҫ֮���ڣ�\n" NOR;
        msg+= HIR"$Nŭ��һ�������"+ weapon->name()+HIG"һ�����Ծ����δ�������ȵ��������»�����ʩ����ɱ�֣�\n" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", (int)me->query_skill("dagou-bang",1)/2);
       msg = WHT  "$Nת��"+ weapon->name()+HIG"��ˢˢˢ��������������������ף����Ǵ򹷰����е�ɱ�У�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 120 )
{
       msg = WHT  "����������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi", random(me->query_skill("dagou-bang",1)));
}
        msg = HIC  "$NͻȻ�ɳ�"+ weapon->name()+HIG"��ӭ������$n������������£�������ʱ֮��ֵ�$p�ؿ�������Ѩ��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 220 )
{
       msg = HIC  "�������£�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi", random(me->query_skill("dagou-bang",1)));
}

        msg = RED "$N����ӳ�������Ϊ�������ӳ��򹷰����еĹ��֣�����������ɱ�У�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 299 )
{
       msg = RED  "����ɱ�У�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 350  && me->query_skill_mapped("force") == "huntian-qigong")
{

        msg = RED "��һ�� $N����ӳ���ʹ���˷��־���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "�ڶ��� $N����ӳ���ʹ����ת�־���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "������ $N����ӳ���ʹ���˰��־�����" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
target->receive_wound("qi", random(me->query_skill("dagou-bang",1)));
}



        me->add_temp("apply/attack", - (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", - (int)me->query_skill("dagou-bang",1)/2);
        me->add("neili", -300);
        me->start_busy(2);

        return 1;
}

