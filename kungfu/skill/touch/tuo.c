//Cracked by Roath
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object armor;
        int damage, jiali, jiajin, ap, dp, pp, dmg, lvl, my_exp, max_dmg;
        string *limbs, limb, type, result, str, dodge_skill;

        my_exp = me->query("combat_exp");
        type = "����";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("�㲻�ǿ��֡�\n");

       if( !objectp(armor = target->query_temp("armor/cloth") ))
	        return notify_fail("��������û�д��°���\n");

	if ( target->query_temp("armor/cloth")=="equipped")
		return notify_fail("��������û�д��°���\n");

        message_vision(HIM "��Ȼ֮�䣬$N���һ��������$p��ǰ��˫�ַ���������ʹ��ʮ�����ġ��ѡ����־���\n\n" NOR, me,target);
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jing", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");


        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

//        if (wizardp(me))
//                printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);   // check overflow

        ap = (ap+random(ap*2))/3.5;

        if( ap > dp ) {
            if( target->query_temp("armor/cloth")){
    			tell_object(target,HIY"��ֻ�����ϵķ������������ڣ��Ѿ����ˡ��ѡ��־��ˣ�\n"NOR);
                	armor = target->query_temp("armor/cloth");
                     		message_vision(HIW"ֻ��$N���ϵ�$n"+HIW+"�ѱ��ѿ�������¶���˰װ׵ļ��⣡\n"NOR, target, armor);
		        armor->unequip();
            } 
        }
	else {
		message_vision(HIY"��ѽ��$N�����ѡ��־�ʧ���ˣ�\n"NOR,target);
// ��Ȼ�Ǹ�Ц pfm, ����Ҳ���� busy time, ������� #10 pfm tuo ��
		me->start_busy(2);
	}
        return 1;
}
