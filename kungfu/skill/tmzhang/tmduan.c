
// tmduan.c ��ħ��
// 99.2.1  by Bless
 
#include <ansi.h>
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon2, target;
        int skill, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("tmzhang",1);

        if( !(me->is_fighting() ))
                return notify_fail("����ħ�ϡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ħ�ϡ�ֻ�ܿ���ʹ�á�\n");		

    if (me->query("family/family_name") != "�������" )
        return notify_fail("�㲻��������̵��ӣ�����ʹ�����������\n");
        
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "sword")
         {
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "axe")
         {
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "blade")
         {
        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "staff")         
                return notify_fail("����������õı������ԣ����޷�ʹ������ħ�ϡ���\n");
}
}
}

        if( skill < 140)
                return notify_fail("�����ħ�Ƶȼ�����, �в���ʹ�á���ħ�ϡ���\n");

        if ( (int)me->query_str() < 30 )
                return notify_fail("�����������������ʹ������ħ�ϡ����\n");

        if( me->query("max_neili") < 1500 )
                return notify_fail("��������������޷�ʹ�á���ħ�ϡ���\n");

        if( me->query("neili") < 800 )
                return notify_fail("��������������޷�ʹ�á���ħ�ϡ���\n");

        msg = HIC "$N������ȣ�ͻȻ������$n��ǰ�����ƻ��˸��󻡣�����ǧ����Ӱ������$n�ı�����ȥ��\n";
        message_vision(msg, me, target);
 
        damage = 10 + random(skill / 2)+ 500;
        ap = me->query_skill("strike") + skill;
        dp = target->query_skill("parry");
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-500);
                msg = "$n��ʱ������ǰһ����ֻ������ॡ�һ��������";
                msg += weapon2->name();
                msg += "��Ϊ���أ�\n" NOR;

                target->receive_damage("qi", damage);
                target->start_busy(2);
                weapon2->move(environment(me));
                weapon2->set("name","���˵�"+weapon2->query("name"));
                weapon2->unequip();
                weapon2->set("value",0);
                weapon2->set("weapon_prop", 0);
        }
        else
        {
                if(userp(me))
                        me->add("neili",-300);
                msg = "$n���һ������ָ����$N����һ�㣬$Næ��������һ����ԶԶ�ر��˿�ȥ��\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
