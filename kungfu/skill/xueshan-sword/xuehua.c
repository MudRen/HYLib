
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
 int extra;
        if( !target ) target = offensive_target(me);
 
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��"HIW"ѩ������"NOR"��ֻ����ս����ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(" ��ʹ�õ���������\n");

        if( (int)me->query("neili") < 450 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("bingxue-xinfa",1) < 50 )
                return notify_fail("��ı�ѩ�ķ���Ϊ��������\n");

        if( (int)me->query_skill("sword",1) < 50 ||
            me->query_skill_mapped("sword") != "xueshan-sword" || 
            me->query_skill("xueshan-sword",1) < 50)
                return notify_fail("���ѩɽ������Ϊ�������޷�ʹ�á�ѩ����������\n");

        msg = HIY "$Nһ�����г�����һʽ"HIW"��ѩ��������"NOR+HIY"�������̳������������������ǣ�\n�ó�ѩ�����㣬����һ�����ǰ��Ʈ��ȥ��\n" NOR;
        message_combatd(msg, me);

	extra = me->query_skill("xueshan-sword",1) / 3;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        me->clean_up_enemy();
        ob = me->select_opponent();

weapon=me->query_temp("weapon");
         msg = HIW "��ѩ�ŵ㣡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "��֦��б��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "������Ӱ��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "����˫÷��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "÷ѩ������\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "��Ӱ���㣡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add("neili", -300);
        me->start_busy(2);

        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);
        return 1;
}

