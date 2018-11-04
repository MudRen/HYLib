#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("sword")/ 5;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("����ָ�ὣ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("taiji-jian", 1) < 200 )
                return notify_fail("���̫����������̫ǳ�ˡ�\n");
        if( (int)me->query_skill("sword", 1) < 200 )
                return notify_fail("��Ļ�����������̫ǳ�ˡ�\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 200 )
                return notify_fail("����ڹ�����̫ǳ�ˡ�\n");
        if( (int)me->query("max_neili") < 3000 )
                return notify_fail("�������̫ǳ�ˡ�\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
        if( me->query_temp("tjj/raozhi"))
                return notify_fail("����Ѿ��������ˡ�\n");

        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("����ʲôΪ�ڹ�������ʹ����ָ�ὣ����\n");
        if (!objectp(weapon = me->query_temp("weapon")) ||        weapon->query("skill_type") != "sword" ||
            me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��ʹ���ˡ���ָ�ὣ��ô?\n");
                 
        me->add("neili", -300-random(100));
        me->add_temp("apply/sword", i);
        me->add_temp("apply/damage", i);
        me->set_temp("tjj/raozhi",i);
me->start_busy(3);
        message_vision(HIR"$Nʩչ����ָ�ὣ�����г���������һ�����ߣ��������磬������\n"NOR, me);
        call_out("remove_effect", 1, me, i/5);
//        me->start_perform(999, "����ָ�ὣ��");
        return 1;
}

void remove_effect(object me, int count)
{
        int i;
        if (!me) return;
        if(me->query_skill_mapped("sword") != "taiji-jian" 
           || !me->is_fighting()
           || !me->query_temp("weapon")
           || count < 1){
           i = me->query_temp("tjj/raozhi");
           me->add_temp("apply/sword", -i);
           me->add_temp("apply/damage", -i);
           me->delete_temp("tjj/raozhi");
//           me->start_perform(0);
           message_vision(HIR"$N����������ֹͣ����ָ�ὣ��\n"NOR, me);
           return;
        }
        call_out("remove_effect", 1 , me, count -1);
}


