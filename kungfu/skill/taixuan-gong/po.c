#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define PO "��" HIC "�˷�����" NOR "��"

int perform(object me)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;


        me->clean_up_enemy();

        if (! me->is_fighting())
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PO "ֻ�ܿ���ʩչ��\n");
                
        if (me->query("max_neili") < 8500)
                return notify_fail("�����������Ϊ�����������޷�ʹ��" PO "��\n");

        if (me->query_skill("taixuan-gong", 1) < 260)
                return notify_fail("���̫������������죬����ʩչ" PO "��\n");

        if (me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("������û�м���̫����Ϊ�ڹ�������ʩչ" PO "��\n");

        if (me->query_skill_mapped("unarmed") != "taixuan-gong")
                return notify_fail("������û��׼��ʹ��̫����������ʩչ" PO "��\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");
        obs = me->query_enemy();

        if ((int)me->query("neili") < sizeof(obs) * 220)
                return notify_fail("��������������޷�����" PO "��\n");

       msg = HIW "ֻ��$N" HIW"������ʣ�����˼����ǧ����Ȼ�䣬$N" HIW "һ����̾��"
              "\n�漴˫�Ʋ�ͣ���ĳ������͵�ʯ���ϵ�̫��ͼ����һ����ӿ����ͷ��"
              "\n���Ǽ����ܿ�����𣬳������������硣������̫��������\n��" 
              NOR + HIC "�˷�����" NOR + HIW "����ת�ۼ䣬$N" HIW "˫��Խ��"
              "�������Ѳ�֪�����ؽ���������!\n �������˵�ս�ľ���\n" NOR;

        message_vision(msg, me);

        me->start_busy(3);

        ap = me->query_skill("force", 1) +
             me->query_skill("unarmed", 1) +
             me->query_skill("dodge", 1) +
             me->query_skill("taixuan-gong", 1) +
             me->query("con") * 10;
  
        me->add("neili", -(sizeof(obs) * 220));

        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") * 2 +
                     obs[i]->query_skill("unarmed", 1) +
                     obs[i]->query("con") * 10;

                if (ap * 2 / 3 + random(ap) > dp)
                {
                        switch (random(2))
                        {
                        case 0:
                                tell_object(obs[i], HIR "��ֻ����ǰ��ɳ�����Χ����������"
                                                    "һ���ھ��Ѿ����������\n" NOR);
                                break;

                        default:
                                tell_object(obs[i], HIR "��ֻ����ǰ��ɳ�����Χ��ɳ���裬"
                                                    "��Ȼ��ֻ��ǧ����ھ��Ѵ��������\n" NOR);
                                break;
                        }

                        damage = ap / 2 + random(ap / 2) + 600;

                        obs[i]->receive_damage("qi", damage, me);
                        obs[i]->receive_wound("qi", damage * 2 / 3 , me);

                        if (userp(obs[i]))
                        obs[i]->receive_damage("jing", damage / 4, me);
                        if (userp(obs[i]))
                        obs[i]->receive_wound("jing", damage / 6, me);

	                p = (int)obs[i]->query("qi") * 100 / (int)obs[i]->query("max_qi");

                        switch (random(5))
                        {
                        case 0:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "һ���Һ�������������������"
                                      "�ۡ���Ż��һ�����Ѫ��\n" NOR;
			        msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 1:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "���ɳ���Զ�����صĵ�����"
                                      "���ϣ��������ã���Ҳ�޷�վ����"
                                      "��\n" NOR;
			        msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 2:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "����бб���˼���������"
                                      "�ڵأ�ʹ�಻����"
                                      "��\n" NOR;
			        msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 3:
                                msg = HIR "�������" + obs[i]->name() +
                                      HIR "ֻ������ɳ���裬ȴ��Ҳ������"
                                      "��Ȼ�䣬ȴ̱���ڵء�\n" NOR;
			        msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "��æ�������ȴ��Ȼ׹�أ��˺۱��壬��"
                                      "Ѫ��ֹ��\n" NOR;
			        msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        obs[i]->start_busy(1);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -500);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIY "��ֻ����ɳ���𣬶�ʱ�����ֿ������ŵ�"
                                    "ס���С�\n" NOR);
                }
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }

        if (! flag) 
                message_vision(HIY "��ɳ��ͣ��ȴû���κ������ˡ�\n\n" NOR, me, 0, obs);

        return 1;
}
