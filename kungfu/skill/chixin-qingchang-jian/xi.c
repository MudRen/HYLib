// hua.c  ������ ֮ �������־�
// by Bbadboy

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int attackp, defendp;


        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("sucked") )
                return notify_fail("��ո��˹��������һ��!\n");

        if((int)me->query_skill("chixin-qingchang-jian", 1) < 150)
                return notify_fail("��ĳ����鳤���ȼ�������\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "sword")
                  return notify_fail("������һ������ʼʱ�����н����֣�\n");


        if( (int)me->query("neili",1) < 500 )
                return notify_fail("�������������\n");

        if( (int)target->query("max_neili") <= 100 )
                return notify_fail( target->name() + "���Ѿ�û���κ������ˣ�\n");

          message_vision( HIR "$NͻȻ�����ü������ᣬ���б����������ǰһ�ͣ�������$n�Ĳ�֪ʲô��λƮȥ��\n" NOR,
                me, target );

        attackp = me->query_skill("force", 1) + me->query_skill("chixin-qingchang-jian", 1) + me->query_skill("sword", 1) / 2;
        defendp = target->query_skill("force") + target->query_skill("dodge");

        me->set_temp("sucked", 1);

        if( attackp / 2 + random(attackp) > defendp || !living(target) )
        {
                  message_vision(HIY "$pһʱ�������ܣ�ֻ�û�����˫�ֽ�����һ��,˫�ֵ�ʱ�类ճסһ��Ľ����ڽ����ϡ���\n" NOR, me, target );
                tell_object(me, HIB "���" + target->name() + "��ˣ���������ڤ�񹦣����Է�����������������...\n" NOR);
                 message_vision(HIY "$p�ƺ���˵ʲô������ȫ���������ֳ�����ʹ��ı��飬˫��ȴ�ֳ��Ѳ�������\n" NOR, me, target );
                tell_object(
                        target, HIB "����������΢΢һ��������ԴԴ������˳�ŶԷ�$w��ס����ӿȥ����\n" + 
                        "��ʱ����һ����ȫȻ�᲻������������ֻ���ζԷ���ȡ��������������\n" 
                        NOR);

                if( !target->is_killing(me) ) me->kill_ob(target);


                target->add("neili", -1*((int)me->query_skill("chixin-qingchang-jian", 1) + target->query("jiali")) );
                if ( target->query("neili") <1 ) target->set("neili",0);
                me->add("neili", (int)me->query_skill("chixin-qingchang-jian", 1) + target->query("jiali") );

                me->start_busy(7);
                target->start_busy(1 + random(7));
                me->add("neili", -200);

                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ��Ѹ�ٵرܿ�����һ����\n" NOR, me, target);
                me->start_busy(4);
                call_out("del_sucked", 17, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}

