// gua.c ���񹦡����ӵ��ҡ�
#include <ansi.h>
#include <combat.h>

#define GUA            "��" HIM "���ӵ���" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp, pp;
        
        if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail(GUA "ֻ����ս���жԶ���ʹ�á�\n");
                
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");
                
        if ((int)me->query_skill("mingyu-gong", 1) < 300)
                return notify_fail("��������Ϊ�������޷�ʩչ" GUA "��\n");
            if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n");              
        if ((int)me->query_skill("sword", 1) < 300)
                return notify_fail("�㽣����Ϊ�������޷�ʩչ" GUA "��\n");
                
        if ((int)me->query("neili") < 500)
                return notify_fail("�����������������޷�ʩչ" GUA "��\n");
                
        if (me->query_skill_mapped("sword") != "mingyu-gong")
                return notify_fail("��û�н����������ڽ������޷�ʹ��" GUA "��\n");
                
        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
               
        me->add("neili", -300);
        
        ap =  me->query_skill("sword");
        dp =  target->query_skill("dodge");
        fp = target->query_skill("force");
        pp = target->query_skill("parry");

        message_vision(HIW "\n$N" HIW "����һ��������" + weapon->name() + HIW "�漴��ͣ�趯������˰��"
                        "�����������񹦾�����" HIM "���ӵ���" HIW "��\n��ͻȻ" + weapon->name() + HIW 
                        "�ó��ı��Ӽ������·Ϯ��$n���Ʋ��ɵ���\n" NOR, me, target);        
        msg = HIM "$N" HIM "������ȫ���뽣������һ������ͷֱ����\n" NOR;
        if (ap * 11 / 20 + random(ap) < fp)
                msg += CYN "$n" CYN "ƾ�������ǿ���ڹ���Ӳ�ǵ������С�\n" NOR;
        else
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "��֪����֮ǿ���м�֮�¾���$N"
                                           HIR "��һ����ÿ�����Ѫ���������ˡ�\n" NOR;
        }
        msg += HIM "\n$N" HIM "Ȧת" + weapon->name() + HIM "�������鶯������ֱָҪ������������������ǵء�\n" NOR;
        if (ap * 11 / 20 + random(ap) < dp)
                msg += CYN "$n" CYN "����ȴ�Ƚ��ƻ��죬���ݵ��������С�\n" NOR;
        else
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "�������Ƶ���켫��$n" HIR "�������ü���"
                                           "���мܣ�ֻ��$N" HIR "����������$n"
                                           HIR "������ʱ��Ѫ���죡\n" NOR;

        }
        msg += HIM "\n$N" HIM "����һ��������$p" HIM "���ģ�����֮�죬��λ֮׼�����˷���ʤ����\n" NOR;
        if (ap * 11 / 20 + random(ap) < pp)
                msg += CYN "$n" CYN "���ڿ��У��������У�ֻ�ܻӳ�һ�У�������$N"
                       CYN "���ϣ���һ������ƮȻ��ȥ��\n" NOR;
        else
        {
               damage = me->query_skill("sword");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "���ڿ��У��������ü����У�ֻ��$N"
                                           HIR "�˽��ӹ���$n" HIR "�����Һ�����Ѫ���·ɽ���\n" NOR;
        }
        msg += HIM "\n$N" HIM "�ȴ�ʮ�ɹ���������Ӱ����������$Nһ���Ϯ��$n��\n" NOR;
        if (me->query_skill("martial-cognize", 1) * 2 / 3 + random(me->query_skill("martial-cognize", 1)) <
            target->query_skill("martial-cognize", 1))
                msg += CYN "$n" CYN "������ѧ��տ��������ʵ��$n"
                       CYN "ȫ������$N��\n" NOR;
        else
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "���ҳ��У�ȴ��ֻ������Ӱ��"
                                           HIR "����Ҳͬʱ�ദ���У�\n" NOR;

        }
        me->start_busy(3);
        message_combatd(msg, me, target);
        return 1;
}

