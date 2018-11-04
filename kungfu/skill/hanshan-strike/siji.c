#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extra;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("hanshan-strike",1);
        if ( extra < 100) return notify_fail("��������书���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷����ļ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("��ķ�ѩӳ÷����Ϊ������\n");

         if((int)me->query_skill("hanshan-strike",1) < 50)
                return notify_fail("��������书��Ϊ������\n");
                
        //me->add("force_factor",extra/5);
        //me->set("force",extra/5*10);

        me->add_temp("apply/attack",extra/10);
        weapon = me->query_temp("weapon");
        msg = HIR  "$Nʹ����ɽ�Ʒ��еĲ��������۷����ļ��ݣ�һ��������ʽ��$n������\n" NOR;
        message_vision(msg,me,target);
        msg = HIG  "\n~~~ �ٻ�ӭ�� ~~~~ ��" NOR;
        message_vision(msg,me,target);
        msg = HIG "$N˫�Ʒ���, ����ƬƬ����,����������ľ���,�������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "������ƬƬ�ɻ�,$n����ǰ�����˴��̵Ĵ�����ɫ..." NOR;
        if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp")/3)
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIB "$N���Ʒ������Ļ������Ի�,�Ե�Ŀ�����...,�����Ű���һ���ҽ�, һ��������$N������ӿ������\n" NOR,target);
        target->receive_wound("jing",extra);
        me->receive_heal("jing",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,��Ŀ��Ϣ,��Ϊ�������Ի�...\n" NOR,target);
        }

        msg = HIC  "\n~~~ ������� ~~~~ ��" NOR;
        message_vision(msg,me,target);
        msg = HIC "$N��̽��һ��, ����һ�������Ļ���, ǡ������΢��, ����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "�����������΢��,$n����ǰ�����˰�쵵��ļ���ɫ..." NOR;
        if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp")/3)
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIR "$N���Ʒ������Ļ������Ի�,�Ե�������ã...�� ���������ص�һ���ƺߣ�һ��Ѫ���Ӷ�����ӿ������\n" NOR,target);
        target->receive_wound("qi",extra*2);
        me->receive_heal("qi",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,ת����ȥ,��Ϊ�������Ի�...\n" NOR,target);
        }
        msg = HIY  "\n~~~ ������� ~~~~ ��" NOR; 
        message_vision(msg,me,target);
        msg = HIY "$N�ڿ�Ծ��, ���б�ò���, ������Ӱ, ��и�ɻ��Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIG "�����Ų��������,$n����ǰ�����˽�Ƶ��＾��ɫ..." NOR;
        if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp")/3)
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIC "$N���Ʒ������Ļ������Ի�,�Ե������ɢ....��������Ұ�ް�ĳ�Х�� һ��������$N������ӿ������\n" NOR,target);
        target->receive_wound("jing",extra);
        me->receive_heal("jing",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,��������,��Ϊ�������Ի�...\n" NOR,target);
        }
        msg = HIW  "\n~~~ Ʈѩ���� ~~~~ ��" NOR; 
        message_vision(msg,me,target); 
        msg = HIW "$N���˵���, ˫���Ƴ�,�����������ƬƬ��ѩ,��$n�����޾������У�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "�����ŷ׷ɵ�ѩ��,$n����ǰ�����˲�ã�Ķ�����ɫ..." NOR;
        if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp")/3)
        {
        message_vision(msg+"\n",me,target);

        message_vision( MAG "$N���Ʒ������Ļ������Ի�,�Եû�����....������������ײ��������һ��������$N������ӿ������\n" NOR,target);
        target->receive_wound("qi",extra*2);
        me->receive_heal("qi",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,פ������,��Ϊ�������Ի�...\n" NOR,target);
        }
        me->start_busy(4);
        me->add("neili", -500);
        //me->set("force_factor",0);
        //me->set("force",0);
        me->add_temp("apply/attack",-extra/10);
        return 1;
}
