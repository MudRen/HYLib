//Cracked by Kafei
// zhuan.c �򹷰����־�
// fear@xkx 99.12

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

int perform(object me, object target)
{
        string* msghit, msg;
        object weapon;
        int zhuan_busy;
        int zhuan_cost;
        int zhuan_duration;
        string *limb, type, limb_hurt;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        ||          !living (target) )
                return notify_fail("ת�־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jing", -5);
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("������ʹ�ð��־���\n");

        if( me->query_temp("pfmfeng",1) )
                return notify_fail("������ʹ�÷��־���\n");

        if( me->query_temp("zhuan",1) )
                return notify_fail("������ʹ��ת�־���\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷�ʩչ���־���\n");

        if( me->query_skill("huntian-qigong") < 100 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ���־���\n");

        if( me->query_skill("dagou-bang") < 100 )
                return notify_fail("��Ĵ򹷰�����Ϊ���㣬������ʹ�÷��־���\n");
        if( me->query_skill("staff") < 100 )
                return notify_fail("��Ļ��������ȷ���Ϊ���㣡\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�������������\n");

        if( me->query("jing") <= 600 )
                return notify_fail("��ľ���������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");

        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("�������ʹ��ת�־�����\n");

                msghit = ({
                        "\n$Nʹ���ˡ�ת���־���������಻�ϣ�һ�㲻�У��ֵ�һѨ����Ӱֻ��$n�����Ѩ�ϻ�����ȥ��\n",
                        "\n$N�ֱ۶������ѱ�Ϊ��ת���־��������������������󼱻�СȦ�������ݰ㼱����ת��\n"
                });
                msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

        if(random(me->query("combat_exp")) * me->query_skill("staff") > random(target->query("combat_exp")) * (target->query_skill("dodge")+ target->query_skill("parry"))/3)
        {
                msghit = ({
                	"\n$N���󶶵����죬$nת��Ҳ�����죬����"+ (string)weapon->name()+"�������ݵĳ�����Ҳ�Ǹ��ŵ��������ת��\n",
                	"$n���¼Ӿ��������û�ת����$p��Ծ���죬��������������\n",
                	"$n����$N�ɱ���Ծ����תȦ�ӣ��ٰ�����$n���ġ�Ȧ��ԽתԽ�󣬱Ƶ����˲��ò����ܡ�\n"
                });
                msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

                zhuan_busy= me->query_skill("staff")/15;
                
                target->add("qi",-me->query_skill("staff"));
                target->add("eff_qi",-me->query_skill("staff"));
                target->start_busy(2);
                target->add("neili",-me->query_skill("staff"));
                me->set_temp("zhuan",1);
        
                me->start_busy( 1 + random(2));
                
                zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);
                
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, zhuan_busy :), zhuan_duration);
                }
        else
        {
                msghit = ({
                	"$n��ȻԾ�ߣ����ڰ�գ�����ץס���ˣ�"+(string)weapon->name()+"��ʱ�㲻ת�ˣ�$N������ˤ�˳�ȥ��\n",
                	"$Nʹ�����أ�ʧ������֮�£���$nһ��ץס���⣬��˳��һ�����������˴���ֱˤ�˳�ȥ��\n"
                });
                msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                me->start_busy( 2);
                me->add("qi", -me->query_skill("staff")/5);
                message_vision(msg, me, target);
        
        }

        zhuan_cost = me->query_skill("staff") / 2;
        me->add("neili", -zhuan_cost );
        me->add("jing", -zhuan_cost/2 );

        return 1;
}


private int remove_effect(object me, object target, int zhuan_busy)
{
        object weapon;
        me->delete_temp("zhuan");
        if(objectp(me) && objectp(target) && target->is_fighting(me) )
                message_vision(HIG"\n$N����֮����Ѹб仯���顣\n"NOR ,me,target); 
        return 1;
}

