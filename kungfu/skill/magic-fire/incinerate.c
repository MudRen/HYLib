//fireball.c  ������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(RED"����ħ���ȵ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-fire",1)< 700)
	return notify_fail("��Ļ�ϵħ��̫���ˣ�\n");

	msg = HIB "$N"HIB"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += HIB"$N"HIB"� ΰ��Ļ���֮������չʾ��ΰ��������������ɣ���\n"NOR;
msg += HIB"$N"HIB"� �գ����գ��������϶ȣ����Ѫ����Լ���Ӱ��ͶٵĴ�����������Ļ𰡣���\n"NOR;
       msg += HIR"��Ѫ�������У�һ��"HIY"����"HIR"��$n"HIR"��ȥ��\n"NOR;
msg += HIY"$N"HIB"��ɱ��ף���һ�ж��ջٰɣ���ħ���ȵ�������\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-fire", 1);
//�Ի�����Ŀ��������
       if ((int)target->query("magicgift")==1)
{
damagic=2500+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);

damagic=2000+damage;
                target->receive_wound("qi", damagic);
}
//��ˮ����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==2)
{
damagic=6500+damage*8;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
damagic=6500+damage*4;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=2000+damage*3;
target->receive_damage("qi", 2000+damage*3);
target->receive_wound("qi", 2000+damage*2);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
target->start_busy(1);
msg += HIR"                                         \n"NOR;
msg += HIR"                                    .ze$$e.     \n"NOR;
msg += HIR"                 .ed$$$eee..      .$$$$$$$P^^     \n"NOR;
msg += HIR"              z$$$$$$$$$$$$$$$$$ee$$$$$$^     \n"NOR;
msg += HIR"           .d$$$$$$$$$$$$$$$$$$$$$$$$$^     \n"NOR;
msg += HIR"         .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$e..     \n"NOR;
msg += HIR"       .$$****""""***$$$$$$$$$$$$$$$$$$$$$$$$$$$be.    \n"NOR; 
msg += HIR"                        ^^**$$$$$$$$$$$$$$$$$$$$$$$L     \n"NOR;
msg += HIR"                          z$$$$$$$$$$$$$$$$$$$$$$$$$     \n"NOR;
msg += HIR"                        .$$$$$$$$P**$$$$$$$$$$$$$$$$     \n"NOR;
msg += HIR"                       d$$$$$$$^              4$$$$$     \n"NOR;
msg += HIR"                     z$$$$$$$$$                $$$P^    \n"NOR;
msg += HIR"                    d$$$$$$$$$F                $P^     \n"NOR;
msg += HIR"                    $$$$$$$$$$F      \n"NOR;
msg += HIR"                     *$$$$$$$$^     \n"NOR;
msg += HIR"                       ^***^^      \n"NOR;
msg += HIR"                                         \n"NOR;
        msg += HIR"��������������!!$n�ĸ������˻�ĵ���!!\n"NOR;
        msg += HIR"$nȫ������֮��������!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
damagic=1500+damage;
                target->receive_damage("qi", damagic);
damagic=1000+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
msg += HIR"                                         \n"NOR;
msg += HIR"                                    .ze$$e. \n"NOR;
msg += HIR"                 .ed$$$eee..      .$$$$$$$P^^ \n"NOR;
msg += HIR"              z$$$$$$$$$$$$$$$$$ee$$$$$$^ \n"NOR;
msg += HIR"           .d$$$$$$$$$$$$$$$$$$$$$$$$$^ \n"NOR;
msg += HIR"         .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$e.. \n"NOR;
msg += HIR"       .$$****""""***$$$$$$$$$$$$$$$$$$$$$$$$$$$be.\n"NOR; 
msg += HIR"                        ^^**$$$$$$$$$$$$$$$$$$$$$$$L \n"NOR;
msg += HIR"                          z$$$$$$$$$$$$$$$$$$$$$$$$$ \n"NOR;
msg += HIR"                        .$$$$$$$$P**$$$$$$$$$$$$$$$$ \n"NOR;
msg += HIR"                       d$$$$$$$^              4$$$$$ \n"NOR;
msg += HIR"                     z$$$$$$$$$                $$$P^\n"NOR;
msg += HIR"                    d$$$$$$$$$F                $P^ \n"NOR;
msg += HIR"                    $$$$$$$$$$F  \n"NOR;
msg += HIR"                     *$$$$$$$$^ \n"NOR;
msg += HIR"                       ^***^^  \n"NOR;
msg += HIR"                                         \n"NOR;
//        msg += HIR"   ��(��#*#@#*#��)¡  \n"NOR;
//        msg += RED"      ��(*#@#*)¡  \n"NOR;
//        msg += HIY"        ��(@)¡  \n"NOR;
//        msg += YEL"     ��(��*@*��)¡  \n"NOR;
        msg += HIR"��������������!!$n�ĸ������˻�ĵ���!!\n"NOR;
        msg += HIY"$pʹ��ȫ�����ֿ����ף������Ǹ�����֮�������ˡ�\n"NOR;
		message_combatd(msg, me, target);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);                       
                me->start_busy(4);
                me->add("neili", -2000);
        return 1;
}
