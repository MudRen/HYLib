// da.c ���ߴ��ߴ�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int lvl,b1,b2;
 
	weapon = me->query_temp("weapon");

        if( !target )
		return notify_fail("��Ҫ�������ߣ�\n");

        if ( target->query("race")!="Ұ��")
                return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");

	if( strsrch(target->query("name"), "��")<0)
                return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");		
	if( target->query("owner"))
                return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");		
                
         if( (int)me->query_skill("wudu-shengong",1) < 10 )
                return notify_fail("����嶾����Ϊ��������\n");

        if( !living(target) )
                return notify_fail("��������ʱ���ᶯ���ˣ��㲻���ٴ��ˡ�\n");

	if( (int)me->query_skill("shedu-qiqiao", 1) < 20 )
		return notify_fail("����߶����ɻ��������, ���ܴ��� !\n");

	if( (int)me->query_skill("force") < 30 )
		return notify_fail("����ڹ�����Ϊ����, ���ܴ��� !\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�����ڵ�����������\n");

        if( weapon )
                msg = HIG "\n$N�趯���е�" + weapon->name() + "������" +
                      target->name() + "���ߴ���˹�ȥ��\n" NOR;
        else
                msg = HIG "\n$N���˫ָ��Ѹ���ޱȵĳ���" +
                      target->name() + "���ߴ���˹�ȥ��\n" NOR;

        lvl = (int) me->query_skill("shedu-qiqiao", 1) +
              (int) me->query_skill("dodge");
        lvl = lvl * lvl / 10 * lvl;
        if( lvl / 2 + random(lvl) > (int) target->query("combat_exp") )
        {
                msg += HIM "��ž����������" + target->name() + "���ߴ��ϡ�\n";
                lvl = (int) me->query_skill("force");
                lvl = lvl * 13 / 10;
                lvl = lvl * lvl / 10 * lvl;
                if ( lvl / 2 + random(lvl) > (int) target->query("combat_exp") )
                {
                        msg += HIM + target->name() + "��������ζ����£��Ͳ��ٶ�����\n" + NOR;
                        message_vision(msg, me);
   if (target->query("qi") > 30000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
                } else
                {
                        msg += HIW + "�����뵽" + target->name() + "������һ����"
                               "��Ȼ�������£�����\n\n" + NOR;
                        message_vision(msg, me);
                        target->kill_ob(me);
                }
        } else
        {
                msg += HIW "Ȼ��" + target->name() + "����һ�������˹�ȥ��\n\n" NOR;
                message_vision(msg, me);
                target->kill_ob(me);
        }


	me->add("neili", -50);
	me->start_busy(2);

	return 1;
}
