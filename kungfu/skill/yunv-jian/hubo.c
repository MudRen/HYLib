//by sdong 07/98

#include <ansi.h>

inherit F_SSERVER;

private int remove_effect(object me, int amount,object weapon);

int perform(object me, object target)
{
        int skill, skill1, skill2;
        object victim;
        object weapon,weapon2;
    object *inv;
    int i, count;
        string bei_skill;

        if( !victim ) victim = offensive_target(me);


        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("˫��������һ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if(     me->query_skill("yunv-jian",1) < 1 ||
                me->query_skill("quanzhen-jian",1) < 1 
                )
                return notify_fail("����ͨ����������Ů������ȫ�潣������˫��������һ�����\n");

        if(me->query_skill("quanzhen-jian",1) <120)
                return notify_fail("���ȫ�潣����������������˫��������һ�����\n");

        if(me->query_skill("yunv-jian",1) <180)
                return notify_fail("�����Ů������������������˫��������һ�����\n");

        if( me->query_skill_mapped("force") != "yunv-xinfa" 
                )
                return notify_fail("�����õĲ�����Ů�ľ����޷�ʩչ˫��������һ�����\n");

        if( me->query_skill("yunv-xinfa", 1) < 180 
                )
                return notify_fail("�����Ů�ľ����δ�����޷�ʩչ˫��������һ�����\n");
        if( !objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("�������˫�����ܺ�����һ�����\n");

     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
           if( inv[i]->query("skill_type") == "sword" ) 
                   {
                           weapon2 = inv[i];
                           break;
                   }
     }
        if( me->query("neili") <= 400 )
                return notify_fail("�����������ʹ��˫��������һ�����\n");
        if( me->query("jing") <= 100 )
                return notify_fail("��ľ�����ʹ��˫��������һ�����\n");

        skill =  ( me->query_skill("yunv-jian",1) + me->query_skill("yunv-jian",1)
                + me->query_skill("quanzhen-jian",1) +me->query_skill("yunv-xinfa",1) 
                + me->query_skill("yunv-xinfa")) / 10; 
        message_vision(
        HIR "$NͻȻ�����ֳ����һ�ѽ���˫��ʹ����Ȼ��ͬ�Ľ������������һ���������\n"+HIC"ֻ��$N˫��һ������������Ů������ȫ�潣����ϵ������޷죬����֮����Ȼ������\n\n" NOR, me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage", skill/2);
        me->add_temp("apply/dodge",  skill/2);
        me->add_temp("apply/parry",  skill/2);
        me->set_temp("hubo", 1);

    me->add_temp("apply/damage", 180);

        bei_skill = me->query_skill_mapped("sword");
    me->map_skill("sword", "yunv-jian");
        message_vision(HIG"�˼����ģ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"��ǰ���£�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"���ٰ�����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");

        message_vision(
        HIR "$N������������,���ǻ����Ӧ������ɱ��ȴ�ǲ������\n" NOR, me);

        me->setup();
        message_vision(HIY"С԰�վգ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"����ҹ����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"���¶��ģ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIG"����С����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

    me->map_skill("sword", bei_skill);
        me->setup();
    me->add_temp("apply/damage", -180);
        me->add("jing", -50);
        me->add("neili", -400);
        me->start_busy(2+random(2));


        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2,weapon2 :), 6);
        return 1;
}

private int remove_effect(object me, int amount,object weapon)
{
        int skill;
        skill =  ( me->query_skill("yunv-jian",1) + me->query_skill("yunv-jian",1)
                + me->query_skill("quanzhen-jian",1) +me->query_skill("yunv-xinfa",1) 
                + me->query_skill("yunv-xinfa")) / 10; 

        me->add_temp("apply/attack", -skill/2);
        me->add_temp("apply/damage", -skill/2);
        me->add_temp("apply/parry", -skill/2);
        me->add_temp("apply/dodge", -skill/2);
        me->delete_temp("hubo");
        message_vision(
        HIY "\n$N����һ���������������ؽ�����Ľ�" + HIY "��ؽ��ʣ��ջ����һ���������\n\n" NOR, me,weapon);

        return 0;
}
