// renmu-daofa ȼľ����
// by snowman@SJ 05/12/1999

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,w2;
        int i;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("�����ҡ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "blade"
           || me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("�������޷�ʹ�������ҡ�������\n");

                
        if(me->query_skill("ranmu-daofa", 1) < 150 )
                return notify_fail("���ȼľ������򲻹���ʹ���������ҡ�������\n");

        if(me->query_skill("blade", 1) < 150 )
                return notify_fail("��Ļ�������������죬ʹ���������ҡ�������\n");

        if( (int)me->query_skill("yijinjing", 1) < 120 )
                return notify_fail("����׽�ȼ�������ʹ���������ҡ�������\n");

        if( (int)me->query_str() < 30)
                return notify_fail("�������������ǿ����ʹ���������ҡ�������\n");

        if( (int)me->query_int() < 30)
                return notify_fail("û�д��ǻ۴��������ʹ���������ҡ������ġ�\n");
 
        if ( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("û���׽��Ϊ���������޷�ʹ�������ҡ������ģ�\n"); 

        if(me->query_temp("ranmu")) 
                return notify_fail("����������ʹ�á����ġ�������\n"); 

        if (me->query_temp("fumo"))
                return notify_fail("����������ʹ�á���շ�ħ���񹦡�\n"); 

        if (me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ������\n");

        if (me->query("neili") < 650)
                return notify_fail("�������������\n");

        if (me->query("jing") < 200)
                return notify_fail("��ľ���������\n");

        me->add("neili", -600);
        me->add("jingli", -100);        

//fenwo's damage depends on how many times u pfmd       

        i = me->query("fenwo");
        if (i > me->query_skill("blade")) i = me->query_skill("blade");
	
//and it will not be over ur enable blade skill

	me->add_temp("apply/damage",i);
	me->add_temp("apply/attack",i/2);
        me->set_temp("fenwo_hit", 1);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
        weapon->add("fenwo", 1);
        w2 = target->query_temp("weapon");
        if (random (3)==0 && w2 
        && !w2->query("ownmake")
        ) {
           	message_vision(HIY"\nֻ�������ǡ�������$N���е�$n"HIY"�����ܻ������ѳ�����Ƭ��\n"NOR,me,weapon);
           	w2->unequip();
           	w2->move(environment(target));
           	w2->set("name", "���ѵ�" + weapon->query("name"));
           	w2->set("value", 49);
           	w2->set("weapon_prop", 0);
           	target->reset_action();
        }
        me->add_temp("apply/damage", -i);
        me->add_temp("apply/attack", -i/2);
        me->delete_temp("fenwo_hit");
       me->start_busy(1);
        me->add("fenwo", 1);
        return 1;
}
