// feiying.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,obj;
        int lvl;

        lvl = (me->query_skill("yuxiao-jian", 1)+me->query_skill("tanzhi-shentong", 1)+me->query_skill("luoying-zhang", 1)+me->query_skill("lanhua-shou", 1)+me->query_skill("xuanfeng-tui", 1))/5;
        lvl = lvl + me->query_skill("suibo-zhuliu", 1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�÷�Ӱ��\n");
        weapon = me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

  
	if (!objectp(obj=present("yuxiao", me))
	&& userp(me))
            return notify_fail("������û��������\n");

        if( (int)me->query_skill("yuxiao-jian", 1) < 180 )
                return notify_fail("������｣��������죬�޷�ʩչ����Ӱ��\n");
        if( (int)me->query_skill("qimen-wuxing", 1) < 180 )
                return notify_fail("������Ű��Բ�����죬�޷�ʩչ����Ӱ��\n");
        if( (int)me->query_skill("tanzhi-shentong", 1) < 180 )
                return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʩչ����Ӱ��\n");
        if( (int)me->query_skill("lanhua-shou", 1) < 180 )
                return notify_fail("���������Ѩ�ֲ�����죬�޷�ʩչ����Ӱ��\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 180 )
                return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʩչ����Ӱ��\n");
        if( (int)me->query_skill("xuanfeng-leg", 1) < 180 )
                return notify_fail("�������ɨҶ�Ȳ�����죬�޷�ʩչ����Ӱ��\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 200)
                return notify_fail("��ı̲���������򲻹����޷�ʩչ����Ӱ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 200)
                return notify_fail("��İ�Ӱ�����򲻹����޷�ʩչ����Ӱ��\n");
        if ( (int)me->query("max_neili") < 1000)
                return notify_fail("��������������޷�ʩչ����Ӱ��\n");
        if ( (int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʩչ����Ӱ��\n");

//        me->start_perform(2, "��Ӱ");
        message_vision(HIW"$N��һ������ʹ���һ���������Ӱ������$n��\n"NOR,me, target);
        me->add("neili", -(400 +random(100)) );
	me->add_temp("apply/attack", lvl/8);	
	me->add_temp("apply/damage", lvl/8);
        me->add_temp("apply/dexerity",lvl/10);
        me->add_temp("apply/strength",lvl/20);
        me->start_busy(1);
        message_vision(HIG"$N���е�����������ˮһ�㣬��$n�����Ĺ�ȥ��\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3)
{
        message_vision(HIG"$n����������˷����ǽ�Ӱ����֪���룡\n\n"NOR,me, target);
        if (!target->is_busy())
        target->start_busy(2);
}
        weapon->unequip(); 
        me->prepare_skill("hand");
        me->prepare_skill("strike");
        me->prepare_skill("cuff");
        me->prepare_skill("finger");
        me->prepare_skill("leg");
        me->prepare_skill("claw");
        message_vision(HIC"$N���������䣬˫������������$n��ȥ��\n"NOR,me, target);
        me->prepare_skill("hand", "lanhua-shou");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        message_vision(HIC"$N���÷�����$n��С����ԪѨ��$n�����������޷��������ۣ�\n\n"NOR,me, target);
        target->add("neili",-(target->query("neili")/5));
     message_vision(HIM"$Nٿ��ת��Ϊ�ƣ�$n�����õ�������Ӱ������ʵʵ�޷�׽����\n"NOR,me, target);
        me->prepare_skill("hand");
        me->prepare_skill("strike","luoying-zhang");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
     message_vision(HIM"$NͻȻ����$n��������Ѩ�ϣ�$n���ɵ����˿���Ѫ��\n\n"NOR,me, target);
        target->receive_wound("qi",100);

        message_vision(HIR"$N��δ���ƣ�����ɨҶ���Ѿ�����$n��ǰ��\n"NOR,me, target);
        me->prepare_skill("strike");
        me->prepare_skill("leg","xuanfeng-leg");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        message_vision(HIR"$N�������ü���$n���������ˣ���Ͼ������\n\n"NOR,me, target);
        target->set("jiali",0);

        message_vision(HIY"$N���Ƴ�ָ������$n��ǰ��Ѩ��\n"NOR,me, target);
        me->prepare_skill("leg");
        me->prepare_skill("finger","tanzhi-shentong");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
       message_vision(HIY"$NͻȻһָ��$n̫��Ѩ��ȥ��$nҡҡ�λΣ��ٲ�Ϊ�衣\n\n"NOR,me, target);
        target->add("jing",-(target->query("jing")/5));

        message_vision(HIW"$N��Ӱ��ʹ��ϣ���һ�ν����û����С�\n"NOR,me, target);
        weapon->wield();
        me->start_busy(3);
	me->add_temp("apply/attack", -lvl/8);	
	me->add_temp("apply/damage", -lvl/8);
        me->add_temp("apply/dexerity",-lvl/10);
        me->add_temp("apply/strength",-lvl/20);
        return 1;
}

