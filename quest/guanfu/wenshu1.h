#include <ansi.h>

void init()
{
        call_out("dest", 1800);
	add_action("do_guankan", ({"guankan","kan"}));
	add_action("do_wancheng", ({"wancheng","wancheng"}));
}

int do_guankan(string arg)
{
	int now_time, time;
	object me;

	me = this_player();
	now_time = me->query_condition("guanfu_task"); 
	time = me->query_temp("guanfu_time");

	if(!arg) return 0;
	if( arg=="wenshu" ) {
if (me->query_temp("guanfu_target") && me->query_temp("ch_weizhi"))
{
		write(
			"\n����һ������֪������׽�ý����������飬�������������Ļ���һ��"
"\n�˵�ͷ��������һ��С�֣�����д�ţ�\n����������"+me->query_temp("guanfu_target")+"��������׽�á���"
"�ݷɸ봫�飬�ķ�Ŀǰ��û�ڡ�"+me->query_temp("ch_weizhi")+"��������\n");
		if(now_time > time*3/4) write("�������г����ʱ��ȥѰ��Ŀ�ꡣ\n");
		if(now_time > time/2 && now_time <= time*3/4) write("�Ѿ���ȥһС��ʱ���ˡ�\n");
		if(now_time > time/4 && now_time <= time/2) write("�㻹��һ���ʱ��ȥ׷��Ŀ�ꡣ\n");
		if(now_time > time/8 && now_time <= time/4) write("���ʱ���Ѿ������ˡ�\n");
		if(now_time > 0 && now_time <= time/8) write("�ٸ������Ѿ������µ�Ŀ���ˣ���Ҫץ��ʱ���ˡ���\n");
		return 1;
}
else {			write(
			"\n����һ������֪������׽�ý����������飬�������������Ļ���һ��"
"\n�˵�ͷ�񣬵�����������ﷸ�Ѿ�������������......\n");
}

	}
}

int do_wancheng(string arg)
{
// object ob;
	object me, target;
	int exp,pot,gfjob_times,now_time;

	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	target = present(arg, environment(me));
	now_time = me->query_condition("guanfu_task");

	if(!target) return notify_fail("�Ҳ������������\n");
	if(target->query("id") != "corpse") return notify_fail("�㲢û���������\n");
	if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("�Ǹ�������Ŀ�꣡\n");
	if(target->query("victim_user")) return notify_fail("�ٺ٣������ף���\n");
	if(target->query("userp")) return notify_fail("�ٺ٣������ף���\n");
        if(target->query("kill_by") != me) return notify_fail("������һ����Ŀ���Ѿ�����ɱ�ˡ�\n");
        if(target->query_temp("mark/dune1")) return notify_fail("���Ѿ���һ���Ѿ�����ɱ����ʬ���ˡ�\n");

	me->add("gf_job",1);
	gfjob_times=(int)me->query("gf_job");
	if (gfjob_times < 1) gfjob_times = 1;
    message_vision(HIW"$N��Цһ�����ӻ����ͳ����鿴�˿���΢���ھ�����������з����ȥ��"
"\n�������黯��ƬƬѩƬ��������$n���ϡ�\n"NOR, me, target);
    write(WHT"�ܺã���ɹ������������Ŀǰ���Ѿ�Ϊ�ٸ�����"+gfjob_times+"�ι��ס�\n"NOR);
	target->set("long", target->query("long")+"�������������ֽƬ��\n");
        target->set_temp("mark/dune1",1);
//	if(me->query("potential") > me->query("max_pot")) 
//      me->set("potential", me->query("max_pot"));
	me->delete_temp("guanfu_time");
	me->clear_condition("guanfu_task");
	me->clear_condition("gf_busy");
	me->delete_temp("guanfu_target");
	me->delete_temp("ch_weizhi");
	me->delete_temp("path_rooms");
	me->delete_temp("gstart_rooms");
	me->delete_temp("mark/gkill3");

	if ((int)me->query("combat_exp")<120000){
         pot=250+random(me->query("max_pot")*3/2);
                if (pot > 1550) exp =1550;
         exp=((5+random(10))*80); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>120000 && 
	me->query("combat_exp")<380000){
         pot=260+random(me->query("max_pot"));
                if (pot >1500) pot =1500;
         exp=((5+random(10))*80); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
		destruct(this_object());
		return 1;
	}
	if ((int)me->query("combat_exp")>380000 && 
         me->query("combat_exp")<780000){
         pot=260+random(me->query("max_pot")*3/2);
                if (pot > 1550) pot =1550;
         exp=((5+random(10))*80); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>780000 && 
         me->query("combat_exp")<1000000){
         pot=260+random(me->query("max_pot")*3/2);
                if (pot > 1600) pot =1600;
         exp=((5+random(10))*80); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>1000000 && 
         me->query("combat_exp")<60000000){
         pot=100+random(me->query("max_pot")*3/2);
                if (pot > 1600) pot =1600;
         exp=((2+random(2))*90); 
         me->add("potential",pot);
         me->add("combat_exp",exp);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
         destruct(this_object());
         return 1;
	}
	pot=260+random(me->query("max_pot")*3/2);
                   if (pot > 1600) pot =1600;
	exp=((5+random(10))*80); 
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->add("gf_job",1);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
	destruct(this_object());
	return 1;
}

void dest()
{
       object me;
       me = this_player();
       write("�����Ѿ��������ģ�������ˣ������Ѿ�ûʲ�����ˣ���ֻ�����ֶ�����\n", me);  
       destruct(this_object());
}