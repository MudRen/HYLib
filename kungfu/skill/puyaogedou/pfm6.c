// chan.c ̫�������������־�

#include <ansi.h>

inherit F_SSERVER;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
});
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
                
        if( (int)me->query_skill("puyaogedou", 1) < 40 )
                return notify_fail("��ĵȼ�������죬����ʹ�á�����\n");
        if( me->query("up1") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");
        if( me->query("pfm6") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");


        msg = HIG "ֻ��$N��һ�ţ�һ�����صĶ�������$n��\n";

if (me->query("up1")==1)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$n����һ���Һ�ˤ���ڵأ�������ʹ���������һ�ţ�\n" NOR;
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
	       target->apply_condition("snake_poison",10 );
	       target->apply_condition("wugong_poison",10 );
	       target->apply_condition("chanchu_poison",10);
target->apply_condition(du[random(sizeof(du))], 15);
            } else {
                msg += "����$n����׼����һ����¿�������������ˡ�\n" NOR;
                me->start_busy(random(3));
        }
        message_combatd(msg, me, target);
}
if (me->query("up1")==2)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
                msg += HIR "$n����һ���Һ�ˤ���ڵأ�������ʹ���������һ�ţ�\n" NOR;
	       target->apply_condition("snake_poison",30 );
	       target->apply_condition("wugong_poison",30 );
	       target->apply_condition("zhizhu_poison",30 );
	       target->apply_condition("xiezi_poison",30 );
	       target->apply_condition("chanchu_poison",30);
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
            } else {
                msg += "����$n����׼����һ����¿�������������ˡ�\n" NOR;
                me->start_busy(random(3));
        }
        message_combatd(msg, me, target);
}

        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

