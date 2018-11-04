// counterattack.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31mÐ¡Àî·Éµ¶[37mÖ»ÄÜ¶ÔÕ½¶·ÖÐµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");
	if((int) me->query_skill("feidao",1) <= 300)
		return notify_fail("ÄãµÄ·Éµ¶¾ø¼¼»¹²»¹»¾«´¿£¬²»ÄÜ·¢³öÐ¡Àî·Éµ¶¡£\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "throwing")
                        return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        me->add("neili",-200);
       if(userp(me) && !((int)(me->query("max_qi")/me->query("qi"))>=3))
             return notify_fail("Äã»¹Ã»ÊÜÖØÉË£¬Ìå»á²»µ½ÉúÓëËÀµÄÄÇÖÖ¾³½ç¡£\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

        me->add("neili",-200);
	message_vision(RED"$NÄ¿²»×ª¾¦µØ¶¢×Å$n£¬×¼±¸·¢³öÖÂÃüÒ»»÷¡£\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(5)+5);
	me->start_busy(5);
	return 1;
}
void kill_him(object me, object target)
{
	string msg;
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
msg = HIY "$NÊ¹³ö·Éµ¶¾ø¼¼ÖÐÀýÎÞÐé·¢µÄ" + HIR "Ð¡Àî·Éµ¶" +HIY "£¬$nÖ»¾õµÃÑÛÇ°Ò»»¨£¬ÑÊºíÒÑ±»¶Ô´©¶ø¹ý£¡£¡£¡" ;
msg +=  "\nÒ»¹ÉÑª¼ýÅçÓ¿¶ø³ö£®£®$nµÄÑÛ¾¦ËÀÓã°ãµÄÍ»ÁË³öÀ´£®£®\n" NOR;

	message_vision(msg, me, target);
if (target->query("qi") > 30000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
	}
	return ;
}
