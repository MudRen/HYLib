#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string wn, msg;
        int i = me->query_skill("sword")/ 5;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("����ָ�ὣ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("raozhi-roujian", 1) < 200 )
                return notify_fail("���̫����������̫ǳ�ˡ�\n");
        if(me->query_temp("tjj/raozhi"))
                return notify_fail("������ʹ�á���ָ�ὣ����\n");

        if( (int)me->query_skill("sword", 1) < 200 )
                return notify_fail("��Ļ�����������̫ǳ�ˡ�\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 180 )
                return notify_fail("��ı����ڹ�����̫ǳ�ˡ�\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");
        if (!objectp(weapon = me->query_temp("weapon")) ||        weapon->query("skill_type") != "sword" ||
            me->query_skill_mapped("sword") != "raozhi-roujian")
                return notify_fail("��ʹ���ˡ���ָ�ὣ��ô?\n");
                 
        me->add("neili", -300-random(100));
        me->add_temp("apply/sword", i);
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 300);
        me->set_temp("tjj/raozhi",i);
        message_vision(HIR"$Nʩչ����ָ�ὣ�����г���������һ�����ߣ��������磬������\n"NOR, me);
         msg = HIG "$N��ת���棬�������ݳ�һ����\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         msg = HIY "$N��ת���棬�������ݳ�һ����\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         msg = HIR "$N��ת���棬������ݳ�һ����\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        call_out("remove_effect", 1, me, i/5);
        return 1;
}

void remove_effect(object me, int count)
{
        int i;
        if (!me) return;
        if(me->query_skill_mapped("sword") != "raozhi-roujian" 
           || !me->is_fighting()
           || !me->query_temp("weapon")
           || count < 1){
           i = me->query_temp("tjj/raozhi");
           me->add_temp("apply/sword", -i);
        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -300);
           me->delete_temp("tjj/raozhi");
           message_vision(HIR"$N����������ֹͣ����ָ�ὣ��\n"NOR, me);
           return;
        }
        call_out("remove_effect", 1 , me, count -1);
}


