//castigate����ն
#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 1200)
	return notify_fail("��ķ���̫���ˣ�\n");

        
        msg = BLU"һ���޴�ĺ�ɫ�������$N"BLU"�����ϴ�����!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//�Ժڰ�����Ŀ��������
       if ((int)target->query("magicgift")==5)
{
damagic=900+damage*3;
                target->receive_damage("qi", damagic);
damagic=900+damage;
                target->receive_wound("qi", damagic);
}
//�Թ�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==6)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=900+damage*3;
target->receive_damage("qi", 900+damage*3);
target->receive_wound("qi", 900+damage);
}

        msg += BLU"$n"BLU"�ĸ�����ʧ���˺�ɫ�����!!\n"NOR;
                 if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"$n"HIG"����Ծ���ӹ���һ�ѡ�\n"NOR;
		message_combatd(msg, me, target);
        }
        msg = HIW"һ���޴�İ�ɫ�������$N"HIW"�����ϴ�����!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//�Ժڰ�����Ŀ��������
       if ((int)target->query("magicgift")==5)
{
damagic=500+damage*3;
                target->receive_damage("qi", damagic);
damagic=500+damage;
                target->receive_wound("qi", damagic);
}
//�Թ�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==6)
{
damagic=6800+damage*5;
                target->receive_damage("qi", damagic);
damagic=6800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIW"$n"HIW"�ĸ�����ʧ���˰�ɫ�����!!\n"NOR;
                 if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"$n"HIG"����Ծ���ӹ���һ�ѡ�\n"NOR;
		message_combatd(msg, me, target);
        }
        msg = HIY"һ���޴�Ľ�ɫ�������$N"HIY"�����ϴ�����!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//�Ժڰ�����Ŀ��������
       if ((int)target->query("magicgift")==5)
{
damagic=800+damage*3;
                target->receive_damage("qi", damagic);
damagic=800+damage;
                target->receive_wound("qi", damagic);
}
//�Թ�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==6)
{
damagic=6800+damage*5;
                target->receive_damage("qi", damagic);
damagic=6800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIY"$n"HIY"�ĸ�����ʧ���˽�ɫ�����!!\n"NOR;
                 if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"$n"HIG"����Ծ���ӹ���һ�ѡ�\n"NOR;
		message_combatd(msg, me, target);
        }
		COMBAT_D->report_status(target);
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
me->add("neili",-880);
if (wizardp(me))
tell_object(me, "����ɱ��Ϊ"+damagic+"�㡣\n" NOR);

	return 1;
	
}
int perform(object me, object target)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIB"������ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 6000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-dark",1)< 750)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");
	msg = HIB "$N"HIB"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;


       msg += HIB"$N"HIB"� �Ⱥڰ���Ҫ��ڵ�������������\n"NOR;
       msg += HIB"$N"HIB"� ��ҹ��Ҫ�����������������\n"NOR;
       msg += HIB"$N"HIB"� �ڻ���֮����֮ΰ����ڰ���������\n"NOR;
       msg += HIB"$N"HIB"� ��ɫ�ĺڰ�֮������������\n"NOR;
       msg += HIB"$N"HIB"� �ڻ���֮����֮ΰ����ڰ���������\n"NOR;
       msg += HIB"$N"HIB"� ��������������Ը�����귢��..\n"NOR;
       msg += HIB"$N"HIB"� �����赲����ǰ����޴�֮����������������֮��,��������ͬ�ȵĻ����.\n"NOR;
msg += BLK"    ������������������������\n"NOR;
msg += BLK"               *\       \n"NOR;
msg += BLK"             /   \\      \n"NOR;
msg += BLK"        * ��/��*��\\�� *  \n"NOR;
msg += BLK"         \ /       \\ /  \n"NOR;
msg += BLK"          *  �� ��  *    \n"NOR; 
msg += BLK"         / \\      / \\   \n"NOR;
msg += BLK"        * ��\\��*��/�� *   \n"NOR;
msg += BLK"             \\  /       \n"NOR;
msg += BLK"               *         \n"NOR;
msg += BLK"            ����ն!!      \n"NOR;
msg += BLK"    ������������������������  \n"NOR;

	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
	return 1;
}


