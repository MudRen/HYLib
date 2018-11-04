#include <ansi.h>
#include <combat.h>

#define ZHAO "��" HIY "�������" NOR "��"

inherit F_SSERVER;

         
int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 
        int ap, dp; 
        int damage; 


        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail(ZHAO "ֻ����ս���жԶ���ʹ�á�\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("�������ֲ���ʩչ" ZHAO "��\n"); 
         
        if (me->query_skill("force") < 300) 
                return notify_fail("����ڹ�����Ϊ�������޷�ʩչ" ZHAO "��\n"); 
        
        if (me->query_skill("piaoxue-zhang", 1) < 180) 
                return notify_fail("���Ʈѩ��������Ϊ�������޷�ʩչ" ZHAO "��\n"); 
         
        if (me->query("neili") < 1000 || me->query("max_neili") < 3500) 
                return notify_fail("��������������޷�ʩչ" ZHAO "��\n"); 



        if (me->query_skill_mapped("strike") != "piaoxue-zhang") 
                return notify_fail("��û�м���Ʈѩ�����ƣ��޷�ʩչ" ZHAO "��\n"); 


       

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ȫ��������ʱ�����ŷ���ȫ�������ž��"
              "�죬��Ȼһ����$n" HIY "\nȫ���ĳ�������һ���еУ�����һ"
              "�С�������ա���\n" NOR;
         
        ap = me->query_skill("strike") +
             me->query_skill("force") +
             me->query("str") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("force") +
             me->query("con") * 10;

        damage = me->query_skill("strike");

        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                me->add("neili", -800);
                me->start_busy(5);
                msg += HIW "ֻ����Ȼһ�����죬$n" HIW "�ѱ�һ�����У���$N"
                       HIW "ֻ��ȫ���������罭����\n��������ˮ�齻�ڣ���"
                       "ʱ��ʧ����Ӱ���١�\n" NOR; 
        } else
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -800);
                me->start_busy(3);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ����Ȼһ�����죬$n" HIR "��$N"
                                           HIR "һ�����У����ӱ��絾�ݰ�ƽƽ�ɳ�"
                                           "����\n��ˤ�ڵ��£�Ż��һ�����Ѫ����"
                                           "Ҳ������\n" NOR;

        } else 
        { 
                me->add("neili", -500);
                me->start_busy(4);
                msg += CYN "����$p" CYN "������񣬼�ʱ������" 
                       CYN "$P" CYN "������ǣ�����㿪����һ����\n" NOR; 
        }
        message_combatd(msg, me, target);
       
        return 1; 
}

