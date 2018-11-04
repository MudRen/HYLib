#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, sword;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon")) 
           || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽����������á�����������\n");

        if (weapon->query("unique"))
                return notify_fail("������֮�����Ƿ���֮����ʹ�á�������û��ʲô���ã�\n");

        if( me->query_temp("qz_jianqi") )
                return notify_fail("���ʹ�꡸��������Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
        
        if( (int)me->query_skill("quanzhen-jian", 1) < 150 ||
           (int)me->query_skill("sword", 1) < 150 ||
            (int)me->query_str() <=25 )
                return notify_fail("����Ϊ����������δ�����򡸽�������\n");

        if( me->query_skill("xiantian-qigong", 1) < 150 )
                return notify_fail("����ڹ���Ϊ���δ����ʩչֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("�����õ��ڹ��롸�������ķ���㣣�\n");
        if (me->query_skill_mapped("sword") != "quanzhen-jian" ||
            me->query_skill_mapped("parry") != "quanzhen-jian")
                return notify_fail("�������޷�ʹ�á����������й�����\n");                                                                                 
      
        if( me->query("max_neili") <= 2000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ����������\n");

        if( me->query("neili") <= 600 )
                return notify_fail("�����������������������ʩչ����������\n");

        if( me->query("jing") <= 200 )
                return notify_fail("��ľ������ޣ�������ʩչ����������\n");

        message_vision(GRN"\nˢ��һ���죬$NǱ��������"+weapon->name()+GRN"һ������һ��ʹ�ý����ݺᣬ��Ȼ����ɽ�ȡ���������֮�ˣ��޲����죡\n\n" NOR, me);
        
        damage = me->query_skill("sword");
        damage = damage/6;
        sword = me->query_skill("sword")/3;
        if ( userp(me) ) {
                me->add("neili", -300);
                me->add("jing", -50);
                if ( damage > weapon->query("weapon_prop/damage") * 2)
                        damage = weapon->query("weapon_prop/damage") * 2;
                else weapon->add("rigidity", 1);
        }

        me->set_temp("qz_jianqi", 1); 
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/attack", damage);
        
        call_out("remove_effect1", sword/2, me, weapon, damage);
        call_out("remove_effect2", sword*2/3, me);
//        me->start_exert(sword*2/3, "��������");

        return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
        if (!me) return;
        me->add_temp("apply/attack", -damage);  

        if (!weapon) {
                me->set_temp("apply/damage", 0);
                return;
        }
        me->add_temp("apply/damage", -damage);
        message_vision("\n$Nһ�ס�ȫ�潣����ʹ�꣬����"+weapon->name()+"�ϵĹ�â����Ҳ��ʧ�ˡ�\n", me);                
        weapon->add("jianqi", 1);
        if (weapon && weapon->query("jianqi") >= (3+weapon->query("rigidity"))) {
           message_vision(HIW"\nֻ�����ꡱ��һ����$N���е�$n"HIW"������������ѳ�����Ƭ��\n"NOR,me,weapon);
           weapon->unequip();
           weapon->move(environment(me));
           weapon->set("name", "���ѵ�" + weapon->query("name"));
           weapon->set("value", 49);
           weapon->set("weapon_prop", 0);
           me->reset_action();
           }
}

void remove_effect2(object me)
{
        if (!me) return;
        me->delete_temp("qz_jianqi");
        tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á��������ˡ�\n"NOR); 
}
