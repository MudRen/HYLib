#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if (duration < 1) {
          message_vision(HIY"$N���ڴ�ͨ���ؿ�Ѩ������Ϣ�ظ���������\n" NOR, me);
          me->set("max_qi",me->query("qiankun/qi"));
          me->set("max_neili",me->query("qiankun/neili"));
          me->delete("jiuyin/qiankun");
          return 0;
    }
   if (!duration) return 0;
   if( !living(me) ) {
          message_vision(HIR"$N��ס�ؿڣ��ƺ�һ�����ƺ���Ϣ��˳��\n" NOR, me); }
   else {
          message_vision(HIR"$N��ס�ؿڣ��ƺ�һ�����ƺ���Ϣ��˳��\n" NOR, me); }
   if (!me->is_busy()) me->start_busy(1 + random(3));
   me->set("jiali", 0);
   me->apply_condition("qiankun_wound", duration - 1);
   return CND_CONTINUE;
}

string query_type(object me)
{
        return "wound";
}

