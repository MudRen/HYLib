// in_zhuibu.c

// by QingP



#include <ansi.h>

#include <condition.h>



inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{

	if ( duration < 1 ) {

		if (!me->query_condition("after_zhuibu"))

		{

			if (me->query_temp("ץ/thief"))

				me->delete_temp("ץ/thief");

			else if (me->query_temp("ץ/caihua zei"))

				me->delete_temp("ץ/caihua zei");

			else if (me->query_temp("ץ/jiangyang dadao"))

				me->delete_temp("ץ/jiangyang dadao");

			else if (me->query_temp("ץ/chaoting qinfan"))

				me->delete_temp("ץ/chaoting qinfan");

			else if (me->query_temp("ץ/shanzhai dawang"))

				me->delete_temp("ץ/shanzhai dawang");



			me->set("title",me->query("oldtitle"));

			me->delete("oldtitle");

			me->apply_condition("after_zhuibu", 7);

			tell_object(me, HIW"��û��ָ����ʱ����ץ���ӷ����˼��Ѿ������ˣ�\n"NOR);

		}



		return 0;

       	}



	me->apply_condition("in_zhuibu", duration - 1);

	

	return 1;

}