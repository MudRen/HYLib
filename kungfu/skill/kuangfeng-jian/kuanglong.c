// feilong.c  ���콣�����������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("װ��������ʹ�á����������\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("kuangfeng-jian", 1) < 150 )
        return notify_fail("����콣������죬ʹ�����������������\n");
    if ((int)me->query_skill("huashan-neigong", 1) < 120 )
        return notify_fail("�㻪ɽ�ڹ���򲻹���ʹ�����������������\n");
    if ((int)me->query("max_neili") < 600)
        return notify_fail("��������Ϊ���㣬�޷�����������\n");
    if ((int)me->query("neili") < 400)
    {
        return notify_fail("����������������û�ܽ������������ʹ�꣡\n");
    }
    weapon = me->query_temp("weapon");
msg = HIC "$N���������һ�������������̽����˾��ڱۣ�����һ����$n���˳�ȥ��"NOR;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//    weapon->move(environment(me));
       me->start_busy(2);
    return 1;
}
