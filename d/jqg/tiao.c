#include <ansi.h>
int do_tiao(string arg)
{
	object me;
	me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( !arg || arg != "shenyuan")
       		return notify_fail("��Ҫ��������\n");
	if( !me->query_temp("tiaoya")){
		write(HIR"�������������գ������ô����ȥֻ���׶༪�٣��㻹���ٿ���һ�°ɡ�\n"NOR);
		write(HIR"���������ã�yes�����ı�������ã�no����\n"NOR);
		me->set_temp("tiaoya", 1);
		return 1;
	}
	write("�㵽����ô�����ģ�\n");
	return 1;
}

int do_yes()
{
	object me = this_player(); 
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if( !me->query_temp("tiaoya") )
		return 0;
	message_vision(HIR"$N��ԥ�����������¶����ģ�����һ�գ�ӿ�����µ���ȥ��\n"NOR, me);
	me->delete_temp("tiaoya");
	message_vision(HIR"\n$N����忪����ֻ�о��������磬���µ�ֱ׹��ȥ��\n"NOR,me);
	if ((int)me->query("kar",1) >= 28){
		call_out("win", 1);
		return 1;
        	}
	call_out("fail", 1);
	return 1;	
	
}

int do_no()
{
	object me;
	me=this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if( !me->query_temp("tiaoya") )
		return 0;
	write(HIG"��˼������ȡ��������ȥ�ľ�����\n"NOR);
	me->delete_temp("tiaoya");
	return 1;
}

int win()
{
	object me;
	me=this_player();
	write(HIR"\n���������ȵ�Խ��Խ����������ȥ���ȵ�ԭ����һƬˮ̶��\n"NOR,);
	write(HIR"\n���ڿ��У������Ѿ����ܿ��ƣ�ֱ����ˮ����ȥ��\n"NOR);
	write(HIR"\n��ͨһ���������������ˮ����������һ�󷭹���������Ҫ���������๾�࣬\n"+
                 "����������һ����ˮ��\n"NOR);
       me->move(__DIR__"guditan1");
       tell_room(environment(me), "ֻ����һ���ҽУ�"+me->name() + "�����ֱ׹��������\n", ({ me }));
       tell_room(environment(me), me->name() + "�����澶ֱ������ȥ��\n", ({ me }));
       me->receive_damage("jing", 100);
       me->receive_damage("qi", 100);
       me->move(__DIR__"guditan2");
       tell_room(environment(me), me->name() + "������ֱ׹��������\n", ({ me }));
       tell_room(environment(me), me->name() + "�����澶ֱ������ȥ��\n", ({ me }));
       me->receive_damage("jing", 200);
       me->receive_damage("qi", 200);
       me->move(__DIR__"guditan3");
       tell_room(environment(me), me->name() + "������ֱ׹��������\n", ({ me }));
       tell_room(environment(me), me->name() + "�����澶ֱ������ȥ��\n", ({ me }));
       me->receive_damage("jing", 300);
       me->receive_damage("qi", 300);
       me->set("water", me->max_water_capacity()+200);
       me->move(__DIR__"guditan4");       
       tell_room(environment(me), me->name() + "������ֱ׹��������\n", ({ me }));
       message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
       return 1;
	
}

int fail()
{
	object me, tmp;
	object *ob;
	int i;
	me= this_player();
	write(HIR"\n���������ȵ�Խ��Խ����������ȥ���ȵ�ԭ����һƬˮ̶��\n"NOR,);
	write(HIR"\n���ڿ��У������Ѿ����ܿ��ƣ�ֱ����̶��һ���ʯͷ׹ȥ��\n"NOR, );
	write(HIR"\n�㼱ת���Σ���Ҫ�������������������ڿ��У�Ʈ�����Ļ벻�������ۿ���\n"+
                 "����ʯͷԽ��Խ���ˣ���ʱ�������в�������һ˿���⣺С��Ů�����ֲ����ң�\n"+
                 "����������ʲô��\n"NOR);
       me->move(__DIR__"gudi");
       me->set_temp("last_damage_from","����ɽ��ˤ");
       me->unconcious();
       me->die();
       	if (tmp = present("corpse", this_object())) 
	{
		ob = deep_inventory(tmp);
		i = sizeof(ob);
		while (i--) if (userp(ob[i])) ob[i]->move(this_object());
		destruct(tmp);
               if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
	}
	return 1;
}
