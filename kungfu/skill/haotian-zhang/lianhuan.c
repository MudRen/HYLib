///kungfu/skill/chunyang-quan/lianhuan.c ��������
// sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        string weapon;
        int damage;
        string *limb, type, result, str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if( objectp(me->query_temp("weapon")) )
                return notify_fail("������������ֲ���ʩչ��\n");

        if( (int)me->query_skill("haotian-zhang", 1) < 120 )
                return notify_fail("�������Ʋ�����죬����ʹ���������С�\n");

        if( (int)me->query_skill("xiantian-qigong", 1) < 100 )
                return notify_fail("������칦������죬����ʹ���������С�\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("����������̫��������ʹ���������С�\n");

        if( me->query("neili") <= 200 )
                return notify_fail("�����������ʹ���������У�\n");


        message_vision(HIR "$Nŭ��һ�����վ�ȫ����ͻȻ����㹥��ȭ���ơ����������У�\n\n" NOR, me, target);

        me->add_temp("apply/attack",80);
        me->set_temp("lianhuan",1);

        message_vision(HIW"��һ�У�\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIM"�ڶ��У�\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack",-80);

        message_vision( HIC"\n������$NͻȻ�ڿշ���ʹ��һ��ԧ�������ȣ����ȷ�۵糸��������$n\n",me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
        {
                if( ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("cuff") + me->query_skill("force"))*2/3) )
                {
                        message_vision(HIR"ֻ��$Nһ���ҽУ����������������Ŀڡ�����$nһ������ͻȻƽƽ�ɳ����ڵ�һ�죬���������������֮�⣬ֱͦͦ�����ڵ��£���Ҳ������\n\n"NOR, target,target );
                        target->receive_wound("qi", (int)me->query_skill("strike")*2, me);
                        target->receive_damage("qi", (int)me->query_skill("strike")*2,  me);
                        me->add("neili", -me->query("jiali"));
                }
                else
                {
                        damage = random(((int)me->query_skill("cuff"))+me->query("jiali"))*( 1 + random(me->query("jiajin")/5) ) ;
                        if(damage > 2500) damage = 2500;
                        if(damage < 300) damage = 300;
                        me->add("neili", -me->query("jiali")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", (int)me->query_skill("strike"), me);

                        limb = target->query("limbs");
                        type = "����";
                        message_vision(HIY"ֻ��$Nһ���ҽУ���������������$P"+limb[random(sizeof(limb))]+"�������$P��ˤ�˸���ͷ��\n"NOR,target);

                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                me->start_busy(1+random(2));
        }
        else if( ( random( target->query_skill("dodge") ) >  me->query_skill("unarmed")*2/3) && random(5) == 1 )
        {
                message_vision(HIR"$N�;��þ�����������֪�����æ���������$n���˸��գ��װ��Լ����ص���һ�ӡ�\n\n"NOR, target,me );
                me->receive_damage("qi", 30+random(50),  me);
                me->start_busy(1+random(2));
                str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
                message_vision("($N"+str+")\n", me);
        }
        else
        {
                message_vision( HIG"$N�ۼ���һ���������ͣ�����˫��һ�㣬Ծ���ĳߣ��㿪��$n��һ�У�����Ҳ����һ���亹��\n\n" NOR,  target,me);
                target->start_busy(1+random(2));
                me->start_busy(1);
        }

        me->delete_temp("lianhuan");

        me->add("neili", -200);
        me->start_busy( 1+random(2) );

        return 1;
}


