//Cracked by Kafei
// feng.c �򹷰����־�
// fear@xkx 99.12

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

int perform(object me, object target)
{
        string* msghit, msg;
        object weapon;
        int  feng_busy;
        int feng_addspeed;
        int feng_cost;
        int feng_duration;
        int feng_parry;
        string *limb, type, limb_hurt;
	int skills;

        skills = me->query_skill("dagou-bang")/10;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        ||          !living (target) )
                return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jing", -5);
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("������ʹ�ð��־���\n");

        if( me->query_temp("pfmfeng",1) )
                return notify_fail("������ʹ�÷��־���\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷�ʩչ���־���\n");

        if( me->query_skill("force") < 250 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ���־���\n");

        if( me->query_skill("staff") < 200 )
                return notify_fail("��Ļ��������ȷ���Ϊ���㣡\n");

        if( me->query_skill("dagou-bang") < 100 )
                return notify_fail("��Ĵ򹷰�����Ϊ���㣬������ʹ�÷��־���\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�������������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");


        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("�������ʹ�÷��־�����\n");

                msghit = ({
                        "\n$N����򹷰����еġ��⡹�־�������ȫ�Ǻ�ʹ��������������һ��"+(string)weapon->query("name")+HIG"����һƬ��ǽ���������š�\n",
                        "\n$N���һ��������"+(string)weapon->query("name")+HIG"��ʹ���򹷰����ġ��⡹�־���������ס�Ż���\n",
                        "\n$N����"+(string)weapon->query("name")+HIG"��ʹ���򹷰����ġ��⡹�־�����ס��ǰ����ס���ơ�\n",
                        "\n$N����"+(string)weapon->query("name")+HIG"��ʹ���򹷰����е�һ�С���Ȯ��·�����������⡹�־���\n"
                });
                msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

        if(random(me->query("combat_exp"))  > random(target->query("combat_exp")))
        {
                msghit = ({
                        "���⡹�־����Ǿ����ͻ���壬$n���в�֧�����¹���ȫ����ס��\n",
                        "ֻ����ӰƮƮ�����⡹�־���ʱ��$n��ǰ����֮�ؾ�����ס�ˡ�\n",
            "$nͻ��"+(string)weapon->query("name")+HIY"���������޷���һʱ��Ȼ��������Թ��롣\n"
                });
                msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

                feng_busy= me->query_skill("staff")/15;
                feng_addspeed=me->query_skill("staff")/50 ;
                feng_parry = feng_busy * 10;
                if(me->set_temp("powerup",1))
                	feng_parry += me->query_skill("force")/3;
                
        me->add_temp("apply/defense",  skills*2);
        me->add_temp("apply/attack",  skills);

//                me->set_temp("apply/parry", );
//                me->set_temp("apply/speed", );
                target->add("qi",-me->query_skill("staff")/5);
                target->add("eff_qi",-me->query_skill("staff"));
                target->set_temp("feng",1);
                me->set_temp("pfmfeng",1);
        
                me->start_busy( 1 + random(2));

        feng_duration= feng_addspeed + feng_busy/( weapon->weight()/1000);
                
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, feng_parry, feng_addspeed  :), feng_duration);
//                call_out("remove_effect",2 + feng_busy/( weapon->weight()/1000),me,target,feng_busy);
                }
        else
        {
                msghit = ({
                        "$n��ʱ������ʱ�ϣ���û�б���ס��\n",
                        "$n���ٱ��У���æ�м����������ܿ��ˡ��⡹�־���\n"
                });
                msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                me->start_busy( 2);
                message_vision(msg, me, target);
        
        }

        feng_cost = me->query_skill("staff") / 2;
        me->add("neili", -feng_cost );

        return 1;
}


private int remove_effect(object me, object target, int feng_parry, int feng_addspeed)
{
	int skills;
        object weapon;
        skills = me->query_skill("dagou-bang")/10;
        me->add_temp("apply/defense",  -skills*2);
        me->add_temp("apply/attack",  -skills);

        if(target)
                target->delete_temp("feng");
        me->delete_temp("pfmfeng");
        if(objectp(me) && objectp(target) && target->is_fighting(me) )
                message_vision(HIG"\n$N�İ��ж��䣬�򹷰��ġ��⡹�־���Ȼ�߽⡣\n"NOR ,me,target); 
        return 1;
}