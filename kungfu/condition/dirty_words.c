// zhongkui_qiushi.c
#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{


     if (duration < 1) {
         message("channel:rumor",sprintf(HIM"��ҥ�ԡ�ĳ�ˣ���˵%s(%s)����������������å�η���ų����ˡ�\n"NOR,
         me->query("name"),me->query("id")),users());
         if (file_name(environment(me))=="/d/death/qiushi"){
         tell_object(me, HIY "��ֻ��һ�����Ƽ���㱻�ӳ��˵������ң�ԭ���Ѿ�����ͷţ���ϲ����ϲ��\n\n" NOR);
         me->move("/d/city/wumiao");
         message("vision",HIY "ͻȻһ���һ�����ϵ���������ԭ���ǻ���ͷŵ�"+me->query("name")+HIY"��\n" NOR, environment(me), me);
         }
         me->set("startroom", "/d/city/wumiao");
         me->save();
         return 0;
	 }

     if (!wizardp(me) && file_name(environment(me)) !="/d/death/qiushi") {
         tell_object(me,HIC"�����Ÿ��ֳ���������ǰ��������λ�û�����أ���ԹԵĸ��ҹ���ȥ����\n\n\n"NOR);
         message_vision(HIC"�����Ÿ���ͻȻ���֣�һ˦���ף���ס$N�Ĳ������˾��ߡ�\n\n\n"NOR,me);
         me->move("/d/death/qiushi");
         }

     me->apply_condition("dirty_words", duration - 1);
     return 1;
}
