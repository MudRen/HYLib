// pi.c ����ٵ�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon,weapon2;
	int damage,i;
	string msg,str;
        int ap, dp;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("������ٵء�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("���á��������ء����б����е���\n");

	if ((int)me->query_skill("hujia-daofa", 1) < 90)
		return notify_fail("��ĺ��ҵ���������죬����ʹ�á�����ٵء���\n");
	                        
	if ((int)me->query_skill("force") < 250)
		return notify_fail("����ڹ���Ϊ�����ߡ�\n");
			
	if( (int)me->query("neili") < 800 )
		return notify_fail("����������̫��������ʹ�á��������ء���\n");
			
	msg = HIC "$N" HIC "һ����Ц��˫�ֽ���" + weapon->name() +
              HIC "����������һ������ȫ����$n" HIC "Ѹ����ȥ��\n\n"NOR;

	if (me->query_temp("hu/freeze") || random(3)==0)
	{
		msg += HIW + weapon->name() +
                HIW "�������ˣ�����˺�ѿ�����ƬƬѩ��Ʈ�䣬��δ�����ȼ���$n" HIW "üë�������˱�����˪��\n\n"NOR;
	}

        ap = me->query_skill("blade") + me->query_skill("force");
        if (living(target))
                 dp = target->query_skill("force") + target->query_skill("parry");
        else     dp = 0;

        if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
                damage += me->query("jiali");
                me->add("neili", -500);
		if (!objectp(weapon2 = target->query_temp("weapon")))
		{	
			target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage/2 + random(damage/2),me);
			msg += HIR "ֻ��$n" HIR "һ���ҽУ��ؿڸ�"
                        	"����һ���޴�Ŀ��ӣ���Ѫ��ӿ�����\n"NOR;
			if (me->query_temp("hu/freeze")  || random(3)==0)
			{
				damage /= 3;
				target->receive_damage("qi",damage,me);
                                target->receive_wound("qi",damage/2 + random(damage/2),me);
				msg += HIR "\n$n" HIR "����ҡ�μ䣬�о���"
                        		+ weapon->name() + HIR + 
                                        "��һ��̹ǵĺ����������ڣ��������һ����Ѫ��\n" NOR;
			}
		} else
		{
			msg += HIR "$n" HIR "��״�����æ����" + weapon2->name() + HIR + 
                                "�ֵ�����$N������ޱߵ�һ���£�" + weapon2->name() + HIR +
                                "�������Ƭ��\n" NOR;
			for (i = 0;i < 2 + random(5);i++)
			{
				msg += HIB "��Ƭ��ɢ�ɽ���������$n�����壡\n" NOR;
				target->receive_damage("qi",damage/7,me);
                                        target->receive_wound("qi",damage/15 + random(damage/15),me);
			}
			msg += HIR + weapon->name() + HIR "����δ������������$n" + HIR + 
                                "���ؿڣ�$n����ش�����Ѫ���������\n" NOR;

			weapon2->set_name("���ѵ�" + weapon2->query("name"));
                        weapon2->move(environment(target));
			weapon2->set("value", 0);
			weapon2->set("weapon_prop", 0);
			target->reset_action();
			target->receive_damage("qi",damage/2,me);
                                        target->receive_wound("qi",damage/4 + random(damage/4),me);

			if (me->query_temp("hu/freeze")  || random(3)==0)
			{
				damage /= 4;
				target->receive_damage("qi",damage,me);
				target->receive_wound("qi",random(damage),me);
				msg += HIR "\n$n" HIR "����ҡ�μ䣬�о���"
                        		+ weapon->name() + HIR + 
                                        "��һ��̹ǵĺ����������ڣ��������һ����Ѫ��\n" NOR;
			}
		}
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
		me->start_busy(3);
		target->start_busy(2);
	} else 
	{
		msg += HIY "$n" HIY "���Ʋ�������ˣ����ձܹ�$N"
                       HIY "����ǿ���ٵأ����������У������ѿ���һ������ӣ�\n"NOR;
                me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
