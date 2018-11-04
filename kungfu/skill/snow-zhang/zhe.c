#include <ansi.h>
#include <combat.h>

#define ZHE "��" HIG "ֻ������" NOR "��"

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string final(object me, object target, int lvl);

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl, p;
        int count;
	int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHE "ֻ�ܿ���ʩչ��\n");

   if( (int)me->query_skill("bingxue-xinfa", 1) < 170 )
   return notify_fail("��ı�ѩ�ķ���򲻹���ʹ������"+HIW"��ѩ��÷"NOR+"����\n");

    if( (int)me->query_skill("snow-zhang", 1) < 100 )
   return notify_fail("��ķ�ѩӳ÷�Ʋ�������������ʹ�á�"+HIW"��ѩ��÷"NOR+"����\n");


        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ���㣬�޷�ʩչ" ZHE "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʩչ" ZHE "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "������ڤ�񹦣�ȫ���ֳ�һ����������Ȼ��˫�Ʒ��ڲ�Ϣ��ʩ"
                  "չ�����С�" HIG "ֻ������" HIW "����Я���������������֮�����ƾ�"
                  "����$n" HIW "��\n"NOR;  

        lvl = me->query_skill("snow-zhang", 1);

        ap = me->query_skill("strike") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("force");

        me->start_busy(4);

        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -300);
     
                // ��ڤ��������
                if (target->query("max_neili") * 3 / 5 > me->query("max_neili"))
                {
                        message_vision(msg, me, target);
                        message_vision(HIM "$N" HIM "һ�ƴ���$n" HIM "���ϣ���Ȼ����Ѫ���ڣ�һ������֮����"
                                     "���ɻ�����$N" HIM "������ס�������������ڡ�$N" HIM "�ƺ�һ����һ"
                                     "����Ѫ�³�����ɫ��ʱ���ϡ�" NOR, me, target);

                        me->receive_wound("qi", me->query("jiali") + random(me->query("jiali") / 2));

                        p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                        msg = "( $N" + eff_status_msg(p) + " )\n\n";
                        message_vision(msg, me, target);

                        me->apply_condition("xuanming_poison",10);

                        return 1;
                        
                } 
        

        target->apply_condition("ice_poison",50);
        target->apply_condition("xuantian_han",50);
        target->apply_condition("xuanming_poison",50);
                msg += HIR "$n" HIR "ֻ����ǰ��Ӱ�ζ���ͻȻ���ؿ�һ����֪����"
               "���ֻ���ؿڴ�һ�ɺ������𣬾�������������\n" NOR;
                                           
        } else
        {
                msg += HIY "$n" HIY "����$N" HIY "������ӿ����æ����Ծ����\n" NOR;
                me->add("neili", -180);
        }
        message_vision(msg, me, target);
attack_time=(int)me->query_skill("snow-zhang", 1) /40;
        if (attack_time > 7)
                attack_time = 7;
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 200);
        me->add("neili", -attack_time * 30);


	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N˫���������Ƴ���"+(i+1)+"�ƣ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -200);
        return 1;
}

