// yuce.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        int n;
        int my_exp, ob_exp,damage;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("���߾�ֻ����ս���жԶ���ʹ�á�\n");


//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

        if ((skill = me->query_skill("never-defeated", 1)) < 100)
                return notify_fail("��Ĳ����񹦻�򲻹�������ʩչ���߾���\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����������ˡ�\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ��\n");
                
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -120);
        //weapon->add_amount(-1);

        msg = HIC "$N" HIC "��ָһ��һ����ֻ����Х�ƿ���������������һ" +
             weapon->query("unit") + weapon->name() + HIC "��������" +
             "����$n" HIC "��\n" NOR;

        me->start_busy(3);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        if (random(my_exp) > ob_exp * 2 / 3)
        {
if (me->query("zhuanfinal/4") ==1 && random(2)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$Nʹ�������ɾ�!!$Nȫ����˺��˺ܶ�!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(2)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$Nʹ���˶��ɾ�!!$NͻȻ�����ֿ���!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(2)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$Nʹ�������ɾ�!!$NͻȻ�����ָ���!\n"NOR;
}
                damage=target->query("qi")/2;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR + "ֻ����" + weapon->name() + HIR "ȥ��ǡ��������磡$n"
                       HIR + "�������ܣ������˸����У��ҽ�һ"
                       "�������˼�����\n" NOR;
               message_vision(msg, me, target);
        } else
        {

                msg += CYN "����$p" CYN "��æһ���������$P" HIG "������" +
                       weapon->name() + CYN "��\n" NOR;
                message_vision(msg, me, target);
        }

        me->reset_action();
        return 1;
}
