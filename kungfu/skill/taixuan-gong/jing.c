#include <ansi.h>
#include <combat.h>

#define JING "��" HIW "����̫����" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg, sub_msg;
        int ap, dp;
        object weapon;
        int flag = 0;
        int lvl;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

             weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�ã�\n");	

        if ((int)me->query_skill("force", 1) < 340)
                return notify_fail("���ڹ���Ϊ����������ʩչ" JING "��\n");

        if ((int)me->query("max_neili") < 9000)
                return notify_fail("��������Ϊ����������ʩչ" JING "��\n");

        lvl = (int)me->query_skill("taixuan-gong", 1);
        if (lvl < 340)
                return notify_fail("��̫������򲻹�������ʩչ" JING "��\n");


        if ((int)me->query("neili") < 850)
                return notify_fail("��������������������ʩչ" JING "��\n");

        if (me->query_skill("force", 1) < 300)
                return notify_fail("������ڹ����㣬����ʩչ" JING "��\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_vision(HIM "\n$N" HIM "�鲻�Խ���������Х����ʱ֮�䣬ǧ������ʽ���������ӿ"
                     "����ͷ��\n$N" HIM "���ֻ��裬���ǲ������򣬵������ۺ�����ʽ������������"
                     "���Ȳ��ش�����Ϣ��\n�಻�����������ʯ���ϵ�ǧ������ʽ����Ȼ��Ȼ�Ĵ���"
                     "�д������㣬����Ϯ��$n" HIM "��\n" NOR, me, target);


        if (flag)ap = lvl + me->query_skill("unarmed", 1);
        else ap = lvl + me->query_skill("parry", 1);

        // ��һ�У��ж϶Է�����
        dp = target->query_str() * 2 + target->query_skill("unarmed", 1) + 
             target->query_skill("parry", 1);

        message_vision(HIW "\n$N" HIW "ͻȻ��ֻ���������¡�ԨҺѨ����һ����һ���������š�����"
                     "����������\n���š����¡��������š���Ѩ��ȥ��\nһ�С�ʮ��ɱһ�ˡ���"  + 
                     "ȭ��������ʹ����������ʽԴԴ��������$n" HIW "���֡�\n" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
        target->add("neili", -(lvl + random(lvl)));
                msg =HIY "$n" HIY "ȴ��$N" HIY "�������ƻֺ룬�������������ֵ�������������"
                "���������ˣ�\n$n" HIY "�ƺ�һ�������˼������پ���Ϣ��ɢ��" + "˫��" + HIY 
                "������Ⱦ����Ѫ��\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "����˫�ۣ������Զԣ�����$N" HIC "֮��жȥ��\n" NOR;
        }
        message_vision(msg, me, target);

        // �ڶ��У��ж϶Է�����
        dp = target->query_int() * 2 + target->query_skill("dodge", 1) 
             + target->query_skill("parry", 1);

        message_vision(HIW "\n$N" HIW "�����������ѣ���Ϣ�������������š��Կ��Ϻ�ӧ�����׾�����"
                     "��ͼ��ת����\nͬʱ�����㵸�����Ǵ�ϲ�����ƴ���ա�\n" NOR, me);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg =HIY "$n" HIY "��Цһ��������$N" HIY "���з�ǳ֮������"
                                          "�������мܣ�\n��Ȼ�䣬�����͡���һ����" + "һȭ" +
                                          HIY "�Ѵ�͸$n" HIY "�����ţ���Ѫ����ӿ����\n" NOR;
        } else
        {
                msg = HIC "$n" HIC "����һЦ������$N" HIC "�����е�����������ʩ�о������л�ȥ��\n" NOR;
        }
        message_vision(msg, me, target);

        // �����У��ж϶Է�����
        dp = target->query_con() * 2 + target->query_skill("force", 1) + 
             target->query_skill("parry", 1);

        message_vision(HIW "\n���Կ��Ϻ�ӧ���ȱϣ�����ȥ���ǡ��⹳˪ѩ������$N" HIW "��"
                    "��˼����\nʯ���ϵ�ͼ��һ�������Ժ�����Ȼӿ�����ԡ������հ���ֱ����˭������¡���\n"
                    "һ���ǳɵ�ʹ�˳�����\n" NOR, me);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
if (userp(target))
target->add("jing",-damage/2);
if (userp(target))
		target->add("eff_jing",-damage/2);

                msg =HIY "$n" HIY "����һ��������$N" HIY "�⼸�������ޱȣ���ʽ�仯Ī�⣬"
                "������ȴ��Ȼ������\n����ԥ�䣬$n" HIY "ȴ�����У��ٸо������ã���"
                "��������\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "Ĭ���ڹ����ھ�����ȫ�������ֵ�ס$N" HIC "���С�\n" NOR;
        }
        message_vision(msg, me, target);

        // �����У��ж϶Է���
        dp = target->query_dex() * 2 + target->query_skill("dodge", 1) + 
             target->query_skill("parry", 1);

        message_vision(HIW "\n���á�˭������¡����׹������꣬$N" HIW "ֻ����Ϣ��ת"
                     "������������Ӣ����ʹ��ȥ��\n" NOR, me);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
if (!target->is_busy()) target->start_busy(4);

                msg =HIY "$N" HIY +  "ȭ�������ޱȣ���ʽʱ������������ʱ��"
                "�������裬���Ǽ�$n" HIY "�ѱ������ˡ�\n$N" HIY "��Ȼ��" + "ȭ��" + HIY "һ"
                "ת����ʽ��Ȼ�ӿ죬��$n" HIY "����Χס������һ˿��϶��\n" NOR;


        } else
        {
                msg = HIC "$n" HIC "�������������ͣ����μ��ˣ�˲��Ʈ����"
                      "�ɣ����Ŷ��$N" HIC "���С�\n" NOR;
        }
        message_vision(msg, me, target);
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(3);
        me->start_busy(2);
        me->add("neili", -400 - random(400));
        return 1;
}

