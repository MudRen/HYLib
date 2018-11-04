// huaiyun.c
// by angle

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

void shengle(object me);
int birth1(object me);
void birth2(object me);

int update_condition(object me, int duration)
{
	if ( duration == 10 ){
		tell_object(me, HIY "�������Χ���˺�����͵͵���㣬����ò����ڣ�\n" NOR );
		message("vision", me->name() + HIY "��ɬ�ĵ���ͷ����Ū���Լ����½ǡ�\n" NOR,
		environment(me), me);
	}
	else if (duration == 9 ){
			tell_object(me, HIY "�������Χ���˶�����֣�����ָָ��㣬�������ᣡ\n" NOR );
			message("vision", me->name() + HIY "�����㣬������Ƿ����ʲô�Ƶġ���\n" NOR,
			environment(me), me);
	}
	else if (duration == 8 ){
			tell_object(me, HIY "�������Χ���˶���Ц�����Ŀ����㣬���������Ѿ����������㡭����\n" NOR );
			message("vision", me->name() + HIY "��һ���쳣�����Ŀ�⣬�����������Լ��Ķ��ӡ�\n" NOR,
			environment(me), me);
	}
	else if (duration == 7 ){
			tell_object(me, HIY "�������Χ���������綼����������ã������ޱȵ��泩��\n" NOR );
			message("vision", me->name() + HIY "һ������˰������Ϣ���ǻ�����ĸ����Ŀ�ⲻʱɨ������Χ��\n" NOR,
			environment(me), me);
	}
	else if (duration == 6 ){
			tell_object(me, HIY "�������Χ���˶����ż�����е�Ŀ��ע�����㣬�ѵ��ǡ������ˣ�\n" NOR );
			message("vision", me->name() + HIY "�Ѿ��ж�ʮ�ֵĳٻ��ˣ���ʱ��ͣ����������\n" NOR,
			environment(me), me);
	}

	else if (duration == 0 ){
			tell_object(me, HIY "��Χ���˶����ȵĺϲ�������ͣ�һ���Ǽ�����ʲô������飡\n����
�������Ͼ�Ҫ���ˣ���Ͻ�������ɷ�ؼҰɣ������������Σ�յģ�" NOR );
			message("vision", me->name() + HIY "���Ŵ��Ķ��ӣ������˵��ϣ�����һ������ʹ������飡\n" NOR,
			environment(me), me);
                        me->delete("long");
			me->clear_condition("huaiyun");
			call_out("shengle", 60, me);
		     }
	me->apply_condition("huaiyun", duration - 1);
	return 1;
}

void shengle(object me)
{
	object obj = find_player(me->query("fuqi/father"));
	if((int)(me->query("mud_age")/86400) < 6 )
	{
		message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ��������$N����̫С�����ʺ�������\n����$N�ĺ���
�����ˣ��ÿ�������\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
//		me->clear_condition("huaiyun");
		me->unconcious();
	}
	else if( !environment(me)->query("home_host"))
	{
		message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ������������Ļ���ʵ����̫�����ˣ�\n����$N�ĺ���
�����ˣ��ÿ�������\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
//		me->clear_condition("huaiyun");
		me->unconcious();
	 }
	 else if (!obj || !userp(obj) || !find_player(obj->query("id")))
	 {
		message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ�������ڹؼ�ʱ���������û���غ�����ߣ�\n����$N�ĺ���
�����ˣ��ÿ�������\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
//		me->clear_condition("huaiyun");
		me->unconcious();
	 }
	 else if (userp(present(obj, environment(me)))&& environment(me)->query("home_host"))
	 {
		me->set_temp("is_bearing",1);
		me->start(100);
		obj->start(100);
		message_vision(HIY "\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n" NOR, me,obj);
		call_out("birth1",15,me,obj);
//		me->clear_condition("huaiyun");
	 }
      me->clear_condition("huaiyun");
	 return ;
}
int birth1(object me)
{        object obj = find_player(me->query("fuqi/father"));
	 message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n"+
		 "\nӤ���Ѿ�̽����ͷ������\n"NOR,me,obj);
	 call_out("birth2",15,me,obj);
	 return 1;
}

void birth2(object me)
{
	object obj = find_player(me->query("fuqi/father"));
	object baby;
	int number;
	message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n"+
		"\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n"NOR, me);
	me->start_busy(1);
	obj->start_busy(1);
	me->set("neili",0);
	me->set("qi",0);
	me->set("jing",0);
	baby = new("/d/taohuacun/npc/baby");
	baby->set("long", baby->query("long")+"����"+obj->query("name")+"��"+me->query("name")+"�ĺ��ӡ�\n");
	if (random(100)<50)
	{
		baby->set("gender","����");
		baby->set_name("С"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
	}
	else
	{
		baby->set("gender","Ů��");
		baby->set_name("С"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
	}
	me->add("child",1);
	obj->add("child",1);
	baby->set("parents",({me->query("id"),obj->query("id")}));
	number = me->query("child");
	me->set("child_"+number+"/gender",baby->query("gender"));
	me->set("child_"+number+"/long",baby->query("long"));
	me->set("child_"+number+"/name",baby->query("name"));
	me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
	me->set("child_"+number+"/parents",baby->query("parents"));
	number = obj->query("child");
	obj->set("child_"+number+"/gender",baby->query("gender"));
	obj->set("child_"+number+"/long",baby->query("long"));
	obj->set("child_"+number+"/name",baby->query("name"));
	obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
	obj->set("child_"+number+"/parents",baby->query("parents"));
	me->delete_temp("is_bearing");
	me->save();
	obj->save();
//this needs to be put at the last since
//can only move the baby after it's parameters are set.
	if(!baby->move(environment(me)))
	baby->move(environment(environment(me)));
}
