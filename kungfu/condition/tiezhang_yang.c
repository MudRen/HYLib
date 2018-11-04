#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tiezhang_yang"; }

string chinese_name() { return "ÌúÕÆ´¿Ñô¾¢"; }



int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + RED"ÃÆºßÒ»Éù£¬Ë«Ä¿Í¹³ö£¬×ì½ÇÉø³ö¼¸Ë¿ÏÊÑª¡£\n"NOR, environment(me), me);
                tell_object(me, RED "ÄãÖ»¾õµ¤Ìï´¦ÓÐÈç»ð·Ù£¬±ãËÆÓÐÇ§Íò¸ÖÕëÒ»ÆëÔúÈëÌåÄÚ¡££¡\n" NOR );
me->add("neili",-me->query("neili")/4);
        if (!me->is_busy())
        me->start_busy(3);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}





