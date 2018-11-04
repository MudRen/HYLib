//sanzhao.c ���������� 
//rama@hx
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
string *limbs =
({
        "ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
        "�ұ�", "����", "����", "����", "����", "����", "С��",
        "����", "����", "����", "���", "�ҽ�", "���", "�Ҷ�"
});
void chkpfm(object me, object target, int amount);
void remove_effect(object me, object target, int amount);
int perform(object me, object target)
{
        object weapon, weapon1;
        int lvl1, lvl2, amount,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        
        if (!living(target))
                return notify_fail("���Ѿ��ε��ˣ���������׵�ɱ������\n");



        if( me->query_skill_mapped("force") != "shenlong-xinfa"  )
                return notify_fail("�����õĲ��������ķ����޷�ʩչ���������У�\n");

        if( (lvl1=me->query_skill("shenlong-xinfa", 1)) < 150 )
                return notify_fail("��������ķ����δ�����޷�ʩչ���������У�\n");

        if( (lvl2=me->query_skill("diwangquan")) < 200 )
                return notify_fail("�������书��Ϊ���㣬������ʹ�ö��������У�\n");

        if( (lvl2 - lvl1) < lvl2 / 4 && lvl1 < 200)
                return notify_fail("������������Ҫ����տ�����գ�\n");

        amount = (lvl1+lvl2) / 5;

        if ( amount < 60 ) amount = 60;
        if ( amount > 200 ) amount = 200;

        if( me->query("neili") <= amount*10 )
                return notify_fail("�����������ʹ�ö��������У�\n");
        if( me->query("jing") <= amount*5 )
                return notify_fail("��ľ�������ʹ�ö��������У�\n");

        if(!me->query_temp("sanxianjian")){
                me->add_temp("apply/damage", amount*2);
                me->add_temp("apply/attack", amount);
                me->add_temp("apply/dodge", amount);
                me->add_temp("apply/defense", amount);
                me->set_temp("sanxianjian",1);
                me->start_busy(1);
               me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, amount:), amount/15);
        }
        message_vision(HIW "$nץס$N�ĺ󾱣�һ������$N����������ת����$n��Ҹ��ɦ��һ�ѣ�\n$n��������������$N������ס$nҸ�£�����������ת��ץס$n��ڣ�����\n����$n�����ӣ������Լ�ͷ��������ˤ����\n"NOR, me, target);
        chkpfm(me, target, amount);
        message_vision(HIW "$N�������ϣ�$n������̤ס$N�ĺ�����$N˫��һ����������ݣ�\n�ұ�ȴ�������Ӷ�����ͻȻ��һ�������$n�Ŀ�����ȥ��ֻһ����\n������ץס$n�ҽ����ף�������$nС����ȥ��\n"NOR, me, target);
        chkpfm(me, target, amount);
        me->set_temp("sxj-c" , 3);
        message_vision(HIW"$N˫�۷��ڱ���ͻȻ˫��ʮָ���𣬸��ɰ���֮�Σ��������һײ\nʮָ��ץ��$n���ز���$n���һ����$NͻȻһ�������������Ծ��\n˫��һ�֣��ѿ���$n��ͷ��ͬʱ˫�ְ�ָѹס$n̫��Ѩ��ʳָ��ü����ָ���ۣ�\n"NOR, me, target);
        chkpfm(me, target, amount);
        
        

        if((int)target->query("eff_qi") * 100 /(int)target->query("max_qi") <= 20
         &&(int)target->query("qi") * 100 /(int)target->query("max_qi") <= 5
         && me->query_temp("sxj-c") == 3)
        {
                message_vision(HIR "\n$N"+HIR+"�����ھ���ע������ǿ��֮����$n���类��շ������ش�ɨ�����������һ����Ѫ����\n" NOR, me, target);
                if (wizardp(me))
                        tell_object(me,HIR"super attack!!\n"NOR);
                damage=target->query("eff_qi")/2;
                if (damage > 20000) damage=20000;
                target->add("eff_qi",-damage);
                target->add("qi",-damage);
        }
        
        me->start_busy(2);
        return 1;
}
void chkpfm(object me, object target, int amount)
{
        object weapon2 = target->query_temp("weapon");
        string attack_skill, dodge_skill, parry_skill, result, msg = "";
        int ap, dp, pp, damage, level;

        if( !me->is_fighting(target) || !living(target) ) 
                return;

        level = me->query_skill("diwangquan", 1);
        damage = amount+random(level)*2+800;
        ap = COMBAT_D->skill_power(me, "finger", SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;

        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        if( target->is_busy() ) dp /= 3;
        if( dp < 1 ) dp = 1;
        if( random(ap + dp) < dp )
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg();
        }
        else
        {
                pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
                if( target->is_busy() ) pp /= 2;
                if( pp < 1 ) pp = 1;

                if( random(ap + pp) < pp )
                {
                        parry_skill = target->query_skill_mapped("parry");
                        if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
                                parry_skill = "parry";
                        msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
                }
                else 
                {
                        target->receive_damage("qi", damage);
                        target->receive_wound("qi", damage/2);
                        if (me->query_temp("sxj-c") == 3)
                                result = COMBAT_D->damage_msg(damage, "����");
                        else result = COMBAT_D->damage_msg(damage, "����");
                        msg += result;
                        result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
                                (int)target->query("max_qi"));
                        msg += "( $n"+result+" )\n";
                        target->start_busy(1);
                }
        }
        result = limbs[random(sizeof(limbs))];
        msg = replace_string( msg, "$l", result );
        message_vision(msg, me, target);
}
void remove_effect(object me, object target, int amount)
{
        if (!me) return;
        me->delete_temp("sanxianjian");
        if( me->is_fighting() && living(target))
        {
                message_vision(HIY "\n$n��������Ӧ��$P���������е�������\n" NOR, me, target);
                target->set_temp("sxj-t",time());
        }
        else message_vision(HIY "\n$N�ջ��ھ�,��ʽҲ�ָ���ƽ����\n" NOR, me);
        me->add_temp("apply/damage", -amount*2);
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/dodge", -amount);
        me->add_temp("apply/defense", -amount);
}

