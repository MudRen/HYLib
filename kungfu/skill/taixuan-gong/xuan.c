
#include <ansi.h>

inherit F_SSERVER;

#define XUAN "��" HIW "̫������" NOR "��"
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp,t;
        object weapon;

        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(XUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
	if ((int)me->query("neili") < 800)
		return notify_fail("��������������޷�ʩչ" XUAN "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ��������ʹ��" XUAN "��\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("����ڹ���򲻹�������ʩչ" XUAN "��\n");

	if ((lvl = (int)me->query_skill("taixuan-gong", 1)) < 240)
		return notify_fail("���̫�����������������޷�ʹ��" XUAN "��\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");
                
             weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�ã�\n");	

             if (me->query_skill_mapped("unarmed") != "taixuan-gong"
                 || me->query_skill_prepared("unarmed" != "taixuan-gong"))
                       return notify_fail("��û��׼��̫�������޷�ʹ��" XUAN "��\n");

        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n��ʱ��$N" HIW "ֻ��˼����ӿ����������˫�ۣ��ٲ����$n"
              HIW "����мܣ�ֻ��ʩ�й�����\n��ʱ���͵�ʯ���ϵ�ǧ������"
              "ʽ��ת���Ѵ�$N" HIW "�ĵ״������㣬������$n" HIW "Ϯȥ��\n" NOR;

	message_vision(msg, me, target);
	me->add("neili", -600);
        ap = me->query_skill("taixuan-gong, 1");
        dp = target->query_skill("dodge", 1);
       
        if (ap / 3 + random(ap) > dp)
                  count = ap / 8;
  
        else count = 0;
t=9;
if (me->query("double_attack"))
t=4;
        me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 800);
        for (i = 0; i < t; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(3);

        	COMBAT_D->do_attack(me, target, 0, i * 2);
        }
        me->add_temp("apply/damage", -800);
        me->add_temp("apply/attack", -80);
	me->start_busy(2);
	return 1;
}

